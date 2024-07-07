#pragma once
#ifndef LINKEDLIST1_H
#define LINKEDLIST1_H
#include <stdexcept>
using namespace std;

// 210511

template<typename T>
class Node
{
public:
	T element;
	Node<T>* next;

	Node()
	{
		next = NULL;
	}

	Node(T element)
	{
		this->element = element;
		next = NULL;
	}
};

template<typename T>
class LinkedList
{
public:
	LinkedList();
	void addFirst(T elemenet);
	void addLast(T element);
	T getFirst();
	T getLast();
	T removeFirst();
	T removeLast();
	void add(T element);
	void add(int index, T element);
	void clear();
	bool contains(T element);
	T get(int index);
	int indexOf(T element);
	bool isEmpty();
	int lastIndexOf(T element);
	void remove(T element);
	int getSize();
	T removeAt(int index);
	T set(int index, T element);
private:
	Node<T>* head, * tail;
	int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = tail = NULL;
	size = 0;
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
	Node<T> *newNode = new Node<T>(element);
	newNode->next = head;
	head = newNode;
	size++;
	if (tail == NULL)
		tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
	//Node<T>* newNode = new Node<T>(element);
	if (tail == NULL)
		head = tail = new Node<T>(element);
	else
	{
		//tail = newNode;
		tail->next = new Node<T>(element);
		tail = tail->next;
	}
	size++;
}

template<typename T>
T LinkedList<T>::getFirst()
{
	if (size == 0) //head == NULL
		throw runtime_error("Index out of range");
	else
		return head->element;
}

template<typename T>
T LinkedList<T>::getLast()
{
	if (size == 0) //head == NULL
		throw runtime_error("Index out of range");
	else
		return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst()
{
	if (size == 0)
		throw runtime_error("No elements in the list");
	else
	{
		Node<T>* temp = head;
		head = head->next;
		if (head == NULL) tail = NULL;
		size--;

		//temp 지우기 전에 별도로 저장
		T element = temp->element;
		delete temp;
		return element;
	}
}

template<typename T>
T LinkedList<T>::removeLast()
{
	if (size == 0)
		throw runtime_error("No elements in the list");
	else if (size == 1)
	{
		Node<T>* temp = tail;
		head = tail = NULL;
		size = 0;
		T element = temp->element;
		delete temp; //delete tail로 실수하지 말것
		return element;
	}
	else
	{
		Node<T>* current = head;
	//	while (current->next != tail)
		for(int i=0;i<size-2;i++)
			current = current->next;
		Node<T>* temp = tail;
		tail = current;
		tail->next = NULL;
		size--;
		T element = temp->element;
		delete temp;
		return element;		
	}
}

template<typename T>
void LinkedList<T>::add(T element)
{
	addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
	if (index == 0)
		addFirst(element);
	else if (index >= size)
		addLast(element);
	else
	{
		Node<T>* current = head;
		for (int i = 1; i < index; i++)
			current = current->next;

		//insert between current(변경전 previous_Index) & current->next (변경전 index)
		Node<T>* temp = current->next;
		current->next = new Node<T>(element);
		(current->next)->next = temp;
		size++;
	}
}

template<typename T>
T LinkedList<T>::set(int index, T element)
{
	if (index == 0)
	{
		addFirst(element);
	}
	else if (index >= size)
	{
		addLast(element);
	}
	else
	{
		Node<T>* current = head;
		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		Node<T>* temp = current->next;
		current->next = new Node<T>(element);
		(current->next)->next = temp;
		size++;
	}
	return element;
}

template<typename T>
void LinkedList<T>::clear()
{
	while (head != NULL)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
	size = 0;
}

template<typename T>
bool LinkedList<T>::contains(T element)
{
	if (size == 0)
	{
		cout << "No containings : Bool result =";
		//throw runtime_error("There's no containings");
		return 0;
	}
	else
	{
		cout << "There's containings : Bool result =";
		Node<T>* temp = head;
		for (int i = 0; i <= size; i++)
		{
			if (temp->element == element)
				return 1;
			temp = temp->next;
		}
		return 0;
	}
}

template<typename T>
T LinkedList<T>::get(int index)
{
	if (index<0 || index>size - 1)
		throw runtime_error("Index out of range");

	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	return temp->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element)
{
	int cnt = 0;
	Node<T>* temp = head;
	for (int i = 0; temp->element == element; i++)
	{
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	return (size == 0);
	// return (head==NULL);
}

template<typename T>
int LinkedList<T>::getSize()
{
	// int cnt=0;
	// Node<T>* temp = head;
	// for (int i = 0; temp->next == tail; i++)
	// {
	// 	temp = temp->next;
	// 	cnt++;
	// }
	// return cnt;
	return size;
}
template<typename T>
void LinkedList<T>::remove(T element)
{
	Node<T>* current = head;
	for (int i = 0; i < size; i++)
	{
		if (current->element == element)
			removeAt(i);
		current = current->next;
	}
}
template<typename T>
int LinkedList<T>::lastIndexOf(T element)
{
	int cnt = 0;
	Node<T>* temp = head;
	for (int i = 0; i < size; i++)
	{
		if (temp->element == element)
		{
			cnt = i;
		}
		temp = temp->next;
	}
	return cnt;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
	if (index < 0 || index >= size)
		throw runtime_error("index out of range");
	else if (index == 0)
		return removeFirst();
	else if (index == size - 1)
		return removeLast();
	else
	{
		Node<T>* current = head;
		for (int i = 1; i < index; i++)
		{
			current = current->next;
		}

		Node<T>* previous = current;
		current = current->next;
		previous->next = current->next;
		T element = current->element;
		size--;
		delete current;
		return element;
	}
}

#endif