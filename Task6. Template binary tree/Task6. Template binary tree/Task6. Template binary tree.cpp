#include "pch.h"
#include <iostream>
#include "Tree.h"
#include "Interface.h"

int main()
{
   
	//Interface<int> obj;
	//obj.menu();

	Tree<int> tr;
	tr.push(10);
	tr.push(15);
	tr.push(5);
	tr.push(17);
	tr.push(12);
	tr.push(7);
	tr.push(2);
	tr.push(16);
	tr.show(tr.getRoot());
	std::cout << std::endl;

	tr.pop(15);
	tr.show(tr.getRoot());
	/*tr.pop(7);
	tr.pop(15);
	tr.pop(12);
	tr.show(tr.getRoot());*/


	

	//tr.pop(15);
	//Tree<int>::Iterator it, it1;
	
	//it = tr.begin();
	
	//Tree<int>::Iterator it;
	//it = tr.begin();
	///*for (it = tr.begin(); it != tr.end(); it++)
	//	cout << *it << " ";*/

	//cout << *it << " ";
	//it++;
	//cout << *it << " ";
	//it++;
	//cout << *it << " ";
	//it++;
	//cout << *it << " ";
	//it++;
	//cout << *it << " ";
	//it++;
	//cout << *it << " ";
	//cout << endl;
	//
	//it--;
	//cout << *it << " ";
	//it--;
	//cout << *it << " ";
	//it--;
	//cout << *it << " ";
	//it--;
	//cout << *it << " ";
	//it--;
	//cout << *it << " ";
	//it--;
	
	
}



