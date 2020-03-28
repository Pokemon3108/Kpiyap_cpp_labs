#pragma once
#include "Tree.h"

using std::cout;
using std::endl;
using std::cin;

template <typename T>
class Interface
{
public:
	Interface()
	{}
	~Interface()
	{}
	void menu();
	bool action();
	
};

template<typename T>
inline void Interface<T>::menu()
{
	
	int n;
	
	do
	{
		cout << "Choose type: " << endl;
		cout << "1-int" << endl;
		cout << "2-double" << endl;
		cout << "0-End of program" << endl;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			Interface<int> obj1;
			if (!obj1.action()) return;
		}
		break;

		case 2:
		{
			Interface<double> obj2;
			if (!obj2.action()) return;
		}
		break;

		case 0:
			break;
		}
		
	} while (n);

}

template<typename T>
inline bool Interface<T>::action()
{
	Tree<T> tree;
	int n;
	do
	{
		cout << "\n1-Add element" << endl;
		cout << "2-Show tree" << endl;
		cout << "3-Delete element" << endl;
		cout << "4-Delete all tree" << endl;
		cout << "5-Create tree of new type" << endl;
		cout << "0-End of program" << endl;
		cin >> n;


		switch (n)
		{

		case 1:
			T obj1;
			cout << "\nInput element" << endl;
			cin >> obj1;
			tree.push(obj1);
			break;

		case 2:
			tree.showInOrder(tree.getRoot());
			
			break;

		case 3:
			T obj2;
			cout << "\nInput element" << endl;
			cin >> obj2;
			tree.pop(obj2);
			break;

		case 4:
			tree.destroyTree(tree.getRoot());
			break;

		case 5:
			return 1;
		case 0:
			return 0;
		}
	} while (n);
	
}



