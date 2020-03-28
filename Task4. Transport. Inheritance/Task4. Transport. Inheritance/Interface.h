#pragma once
#include "Functor.h"
#include "Tree.h"
#include "Tractor.h"
#include "Bus.h"
#include "Plane.h"
#include "Helicopter.h"
#include "Submarine.h"
#include "SailBoat.h"
#include "Algorithm.h"
#include "InputError.h"
#include <vector>
#include "TextFile.h"
#include "BinaryFile.h"

template <typename T>
class Interface
{
public:
	
	Interface()
	{}
	~Interface()
	{}

	void menu();
	bool action(const char* filename);
	void searchMenu(T& obj, Functor& f);
	friend class Functor;
};

template<typename T>
inline void Interface<T>::menu()
{

	int n;
	int type;
	do
	{
		cout << "Choose type: " << endl;
		cout << "1-Helicopter" << endl;
		cout << "2-Plane" << endl;
		cout << "3-Bus" << endl;
		cout << "4-Tractor" << endl;
		cout << "5-Submarine" << endl;
		cout << "6-SailBoat" << endl;
		cout << "0-End of program" << endl;
		cin >> n;

		cout << "1-Binary file" << endl;
		cout << "0-Text file" << endl;
		cin >> type;
		switch (n)
		{
		case 1:
		{
			Interface<Helicopter> obj;
			if (type)
			{
				if (!obj.action("..\\files\\Helicopter.bin")) return;
			}
			else if (!obj.action("..\\files\\Helicopter.txt")) return;

			//if (!obj.action("..\\files\\Helicopter.txt")) return;
			//if (!obj.action("..\\files\\Helicopter.bin")) return;
		}
		break;

		case 2:
		{
			Interface<Plane> obj;
			if (type)
			{
				if (!obj.action("..\\files\\Plane.bin")) return;
			}
			else if (!obj.action("..\\files\\Plane.txt")) return;

			//if (!obj.action("..\\files\\Plane.txt")) return;
			//if (!obj.action("..\\files\\Plane.bin")) return;
		}
		break;


		case 3:
		{
			Interface<Bus> obj;
			if (type)
			{
				if (!obj.action("..\\files\\Bus.bin")) return;
			}
			else if (!obj.action("..\\files\\Bus.txt")) return;

			//if (!obj.action("..\\files\\Bus.txt")) return;
			//if (!obj.action("..\\files\\Bus.bin")) return;
		}
		break;
		case 4:
		{
			Interface<Tractor> obj;
			if (type)
			{
				if (!obj.action("..\\files\\Tractor.bin")) return;
			}
			else if (!obj.action("..\\files\\Tractor.txt")) return;

			//if (!obj.action("..\\files\\Tractor.txt")) return;
			//if (!obj.action("..\\files\\Tractor.bin")) return;
		}
		break;
		case 5:
		{
			Interface<Submarine> obj;
			if (type)
			{
				if (!obj.action("..\\files\\Submarine.bin")) return;
			}
			else if (!obj.action("..\\files\\Submarine.txt")) return;

			//if (!obj.action("..\\files\\Submarine.txt")) return;
			//if (!obj.action("..\\files\\Submarine.bin")) return;
		}
		break;
		case 6:
		{
			Interface<SailBoat> obj;
			if (type)
			{
				if (!obj.action("..\\files\\SailBoat.bin")) return;
			}
			else if (!obj.action("..\\files\\SailBoat.txt")) return;

			//if (!obj.action("..\\files\\SailBoat.txt")) return;
			//if (!obj.action("..\\files\\SailBoat.bin")) return;
		}
		break;
		case 0:
			break;
		}

	} while (n);

}

template<typename T>
bool Interface<T>::action(const char* filename)
{
	Tree<T> tree;
	
	TextFile<T> fileText(filename);
	BinaryFile<T> fileBinary(filename);
	if (filename[strlen(filename) - 1] == 't')
	{
		fileText.openForRead();
		fileText.readFromFile(tree);
	}
	else
	{
		fileBinary.openForRead();
		fileBinary.readFromFile(tree);
	}
	int n;
	do
	{
		cout << "\n1-Add element" << endl;
		cout << "2-Show tree" << endl;
		cout << "3-Delete element" << endl;
		cout << "4-Delete all tree" << endl;
		cout << "5-Find elements for parametres" << endl;
		cout << "6-Find for all parametres" << endl;
		cout << "7-Show size of tree" << endl;
		cout << "8-Find element by lower bound" << endl;
		cout << "9-Create tree of new type" << endl;
		cout << "0-End of program" << endl;
		cin >> n;



		switch (n)
		{

		case 1:
		{
			T obj;
			cout << "\nInput element" << endl;
			cin >> obj;
			tree.push(obj);
			break;
		}

		case 2:
		{
			T obj;
			obj.table(cout);
			tree.showInOrder(tree.getRoot());
			break;
		}

		case 3:
		{
			T obj;
			cout << "\nInput element" << endl;
			cin >> obj;
			tree.pop(obj);
			break;
		}

		case 4:
			tree.destroyTree(tree.getRoot());
			break;

		case 5:
		{
			T obj;
			Functor functorObj;
			searchMenu(obj, functorObj);
			std::vector<T> objVector=search(tree.begin(), tree.end(), obj, functorObj);
			if (objVector.size())
			{
				obj.table(cout);
				
				typename std::vector<T>::iterator it;
				for (it = objVector.begin(); it != objVector.end(); it++)
					cout << (*it);
			}
			break;
		}
		case 6:
		{
			T obj;
			cout << "\nInput element" << endl;
			cin >> obj;
			Node<T>* temp = tree.search(obj);
			if (!temp) cout << "There is no such element in tree";
			else cout << "Object has been found";
		}
		case 7:
		{
			
			int s = size(tree.begin(), tree.end());
			std::cout << "Size=" << s << endl;
			break;
		}
		case 8:
		{
			T obj;
			cout << "\nInput element" << endl;
			cin >> obj;
			typename Tree<T>::Iterator it;
			it=lower_bound(tree.begin(), tree.end(), obj);
			if (it.getPtr())
			{
				obj.table(cout);
				cout << *it;
			}
			else cout << "No element higher, than bound element" << endl;
		}
		
		case 9:
		case 0:
			if (filename[strlen(filename) - 1] == 't')
			{
				fileText.openForWrite();
				fileText.writeToFile(tree.getRoot());
			}
			else
			{
				fileBinary.openForWrite();
				fileBinary.writeToFile(tree.getRoot());
			}
			//file.openForWrite();
			//file.writeToFile(tree.getRoot());
			if (n) return 1;
			return 0;
		}
	} while (n);
	//return 1;
}

template<typename T>
void Interface<T>::searchMenu(T& obj, Functor & f)
{
	Functor func = f;
	int n,i;
	do
	{
		obj.chooseParameters();
		cin >> n;
		std::string strForSet = obj.getParameter(n);
		func.getSetFields().insert(strForSet);
		cout << "Choose one more parameter:" << endl << "1-Yes" << endl << "0-No"<<endl;
		cin >> i;
	} while (i);
	f = func;
}


