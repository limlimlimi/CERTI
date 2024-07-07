#include <iostream>
#include <string>
#include "LinkedList1.h"
using namespace std;

// 210511

void printList(LinkedList<string> list)
{
	if (list.getSize() == 0)
		cout << "list is empty \n";
	else if(list.getSize() != 0)
	{
		for (int i = 0; i < list.getSize(); i++)
			cout << list.get(i) << " ";
	}
}

int main_Linkedlist()
{

	// LinkedList();
	// void addFirst(T elemenet);
	// void addLast(T element);
	// T getFirst();
	// T getLast();
	// T removeFirst();
	// T removeLast();
	// void add(T element);
	// void add(int index, T element);
	// void clear();
	// bool contains(T element);
	// T get(int index);
	// int indexOf(T element);
	// bool isEmpty();
	// int lastIndexOf(T element);
	// void remove(T element);
	// int getSize();
	// T removeAt(int index);
	// T set(int index, T element);

	LinkedList<string> list;

	list.addFirst("A"); //A
	cout << "TEST : addFirst(A) : ";
	printList(list);
	list.addFirst("B"); //B A
	cout << "\nTEST : addFirst(B) : ";
	printList(list);
	list.addLast("C"); //B A C
	cout << "\nTEST : addLast(C) : ";
	printList(list);
	list.add("D"); //B A C D
	cout << "\nTEST : add(D) : ";
	printList(list);
	list.add(1, "E"); //B E A C D
	cout << "\nTEST : add(1,E) : ";
	printList(list);
	list.removeFirst(); //E A C D
	cout << "\nTEST : removeFirst() : ";
	printList(list);
	list.removeLast(); //E A C
	cout << "\nTEST : removeLast() : ";
	printList(list);
	list.set(1, "F");//E F A C
	cout << "\nTEST : set(1,F) : "; 
	printList(list);
	list.removeAt(0); //F A C
	cout << "\nTEST : removeAt(0) : ";
	printList(list);
	cout << "\nTEST : remove(A) : ";
	list.remove("A");//F C
	printList(list);
	cout << "\nTEST : getSize() : " << list.getSize() << endl; //2
	cout << "TEST : indexOf() : " << list.indexOf("F") << endl; //0
	cout << "TEST : lastIndexOf() : " << list.lastIndexOf("F") << endl; //0
	
	cout << "TEST : getFirst() : "<< list.getFirst() << endl; //F
	cout << "TEST : getLast() : " << list.getLast() << endl; //C
	cout << "TEST : get(1) : " << list.get(1) << endl; //C
	cout << "TEST : isEmpty() : " << list.isEmpty() << endl; //0
	cout << "TEST : contains(F) : ";
	cout << list.contains("F"); //1
	
	cout << "\nTEST : list.clear ";
	list.clear(); 
	//printList(list);
	
	cout << "\nTEST : isEmpty() : " << list.isEmpty() << endl; //1
	cout << "TEST : contains(F) : ";
	cout << list.contains("F")<<endl; //0

	return 0;
}