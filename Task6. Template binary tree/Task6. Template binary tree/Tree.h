#pragma once
#include <iostream>
#include <algorithm>
#include <stack>

using std::cout;
using std::endl;

template <typename T>
struct Node
{
	T data;
	Node<T> *left;
	Node<T> *right;
	Node<T> *parent;
};


template <typename T>
class Tree
{
private:

	Node<T> *root;

public:

	class Iterator
	{
	private:
		Node<T>* ptr;
	public:
		Iterator() = default;
		
		T& operator*();

		Iterator operator++(int);
		Iterator operator--(int);
		Iterator operator+=(int n);

		bool operator==(Iterator it);
		bool operator!=(Iterator it);
		
		friend class Tree;
	};


	Tree()
	{
		root = nullptr;
	}
	~Tree()
	{
		destroyTree(root);
	}
	Tree(T obj)
	{
		root->data = obj;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = nullptr;
	}

	void push(T obj);
	void insert(Node<T>* &root, T data, Node<T>* parent);
	Node<T> * search(const Node<T> & obj) const;

	void showInOrder(Node<T>* root) const;
	void show(Node<T>* root, int level = 0);

	void pop(T obj);
	void deleteItem(Node<T>* &ptr, T data);
	void deleteNodeItem(Node<T>*& nodeptr);
	void mostLeftItem(Node<T>* &nodeptr, T& value);

	void destroyTree(Node<T>* &root);

	Node<T>*& getRoot();

	Iterator begin();
	Iterator end();
};

template<typename T>
void Tree<T>::push(T obj)
{
	insert(root, obj,nullptr);
}

template<typename T>
void Tree<T>::insert(Node<T>* &root, T data, Node<T>* parent)
{
	if (!root)
	{
		root = new Node<T>;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		root->parent = parent;
	}
	else if (data < root->data)
		insert(root->left, data, root);
	else if (data > root->data)
		insert(root->right, data, root);

}


template <typename T>
Node<T>* Tree<T>::search(const Node<T>& obj) const
{
	Node<T>* temp = root;
	while (temp->data != obj.data && temp)
	{
		if (obj.data < temp->data)
			temp = temp->left;

		else if (obj.data > temp->data)
			temp = temp->right;

	}
	return temp;
}

template <typename T>
void Tree<T>::showInOrder(Node<T>* root) const
{
	if (!root) return;
	showInOrder(root->left);
	std::cout << root->data << ' ';
	showInOrder(root->right);

}

template<typename T>
void Tree<T>::show(Node<T>* root, int level)
{
	if (root)
	{
		show(root->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << root->data << endl;
		show(root->right, level + 1);
	}
}

template <typename T>
void Tree<T>::pop(T obj)
{
	deleteItem(root, obj);
}

template <typename T>
void Tree<T>::deleteItem(Node<T> * &ptr, T data)
{
	if (!ptr) return;
	else if (data == ptr->data)
		deleteNodeItem(ptr);
	else if (data < ptr->data)
		deleteItem(ptr->left, data);
	else deleteItem(ptr->right, data);
}

template <typename T>
void Tree<T>::deleteNodeItem(Node<T> * &nodeptr)
{
	Node<T>*delptr;
	T value = 0;
	if (!nodeptr->left && !nodeptr->right)
	{
		delete nodeptr;
		nodeptr = nullptr;
	}
	else if (!nodeptr->left || !nodeptr->right)
	{
		delptr = nodeptr;
		if (!nodeptr->left) nodeptr = nodeptr->right;
		else nodeptr = nodeptr->left;
		nodeptr->parent = delptr->parent;
		delete delptr;
	}
	else
	{
		mostLeftItem(nodeptr->right, value);
		nodeptr->data = value;
	}
}

template <typename T>
void Tree<T>::mostLeftItem(Node<T> * &nodeptr, T& value)
{
	if (!nodeptr->left)
	{
		value = nodeptr->data;
		Node<T>* delptr = nodeptr;
		nodeptr = nodeptr->right;
		if (nodeptr) nodeptr->parent = delptr->parent;
		delete delptr;
	}
	else mostLeftItem(nodeptr->left, value);
}

template <typename T>
void Tree<T>::destroyTree(Node<T>*&root)
{
	if (root)
	{

		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
		root = nullptr;
	}
}

template<typename T>
Node<T>*& Tree<T>::getRoot()
{
	return root;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::begin()
{
	Iterator it;
	
	Node<T>*curr = root;

	while (curr->left)
	{
		
		curr = curr->left;
		
	}
	
	it.ptr = curr;
	return it;
	
}
template<typename T>
typename Tree<T>::Iterator Tree<T>::end()
{
	Iterator it;

	Node<T>*curr = root;

	while (curr)
	{
		curr = curr->parent;

	}

	it.ptr = curr;
	return it;
}

template<typename T>
T & Tree<T>::Iterator::operator*()
{
	return this->ptr->data;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator++(int)
{
	Node<T>* temp;
	if (ptr->right)
	{
		ptr = ptr->right;
		while (ptr->left)
			ptr = ptr->left;
	}
	else
	{
		temp = ptr->parent;
		while (temp && ptr == temp->right)
		{
			ptr = temp;
			temp = temp->parent;
		}
		ptr = temp;
	}
	return *this;
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator--(int)
{
	Node<T>* temp;
	if (ptr->left)
	{
		ptr=ptr->left;
		while (ptr->right)
			ptr = ptr->right;
	}
	else
	{
		temp = ptr->parent;
		while (temp && ptr == temp->left)
		{
			ptr = temp;
			temp = temp->parent;
		}
		ptr = temp;
	}
	return *this;
		
}

template<typename T>
inline bool Tree<T>::Iterator::operator==(Iterator it)
{
	if (it.ptr == nullptr && this->ptr == nullptr) return true;
	if (it.ptr == nullptr || this->ptr == nullptr) return false;
	return **this == *it;
}

template<typename T>
bool Tree<T>::Iterator::operator!=(Iterator it)
{
	return !(*this == it);
}

template<typename T>
typename Tree<T>::Iterator Tree<T>::Iterator::operator+=(int n)
{
	for (int i = 0; i < n; ++i)
		(*this)++;
	return *this;
}
