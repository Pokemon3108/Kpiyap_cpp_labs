#pragma once
#include "File.h"
#include <fstream>

template<typename T>
class BinaryFile : public File
{
private:
	
public:
	BinaryFile(const char* name) : File(name) 
	{};
	~BinaryFile() {};

	void openForWrite();
	void openForRead();
	void readFromFile(Tree<T>& tree);
	void writeToFile(Node<T>* root);
	void read(T& obj);
	void write(T& obj);
};

template<typename T>
void BinaryFile<T>::openForWrite()
{
	out.open(fileName, std::ios::binary);
	if (!out.is_open())
		cout << "File:" << fileName << " is not open for write\n";
}

template<typename T>
void BinaryFile<T>::openForRead()
{
	in.open(fileName, std::ios::binary);
	if (!in.is_open())
		cout << "File:" << fileName << " is not open for read\n";
}

template<typename T>
void BinaryFile<T>::readFromFile(Tree<T>& tree)
{
	
	T obj;
	while (in.peek() == '\n')
		in.get();
	while (!in.eof())
	{
		obj.readBF(in);
		tree.push(obj);
		in.peek();
	}
	
}

template<typename T>
void BinaryFile<T>::writeToFile(Node<T>* root)
{
	if (!root) return;
	root->data.writeBF(out);
	writeToFile(root->left);
	writeToFile(root->right);
}

template<typename T>
void BinaryFile<T>::read(T& obj)
{
	if (!in.eof()) obj.readBF(in);
}

template<typename T>
void BinaryFile<T>::write(T& obj)
{
	if (!out.eof()) obj.writeBF(out);
}
