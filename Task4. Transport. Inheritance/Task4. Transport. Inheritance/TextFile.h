#pragma once
#include "File.h"


template<typename T>
class TextFile : public File
{
private:
	
public:
	TextFile(const char* name) : File(name) {};
	~TextFile() {};

	void openForWrite();
	void openForRead();
	void readFromFile(Tree<T>& tree);
	void writeToFile(Node<T>* root);
	void read(T& obj);
	void write(T& obj);
	
};

template<typename T>
void TextFile<T>::openForWrite()
{
	out.open(fileName);
	if (!out.is_open())
		cout << "File:" << fileName << " is not open for write\n";
}

template<typename T>
void TextFile<T>::openForRead()
{
	in.open(fileName);
	if (!in.is_open())
		cout << "File:" << fileName << " is not open for read\n";
}

template<typename T>
void TextFile<T>::readFromFile(Tree<T>& tree)
{
	T obj;
	while (in.peek() == '\n')
		in.get();
	while (!in.eof())
	{
		in >> obj;
		tree.push(obj);
		in.peek();
	}
}

template<typename T>
void TextFile<T>::writeToFile(Node<T>* root)
{
	if (!root) return;
	out << root->data;
	writeToFile(root->left);
	writeToFile(root->right);
}

template<typename T>
void TextFile<T>::read(T& obj)
{
	in >> obj;
}

template<typename T>
void TextFile<T>::write(T& obj)
{
	out << obj;
}


