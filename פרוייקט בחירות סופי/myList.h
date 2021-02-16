#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
using namespace std;

/// Template algorithm replacing list
///Using Node.h


template <class T>
class myList
{

	int listSize;

public:

	//ctor
	myList() : head(new Node<T>), tail(new Node<T>)
	{
		head->setNext(tail);
		tail->setPrev(head);
		listSize = 0;
	}
	//dtor
	~myList()
	{
		delete head;
	}
	//iterator inside class
	class Iterator
	{

	public:
		Iterator(Node<T>* curr = 0) : n(curr) {}
		Iterator(const Iterator& curr) : n(curr.n) {}

		bool operator==(const Iterator& ptr) const
		{
			return (n == ptr.n);
		}

		bool operator!=(const Iterator& ptr) const
		{
			return (n != ptr.n);
		}

		Iterator& operator++()
		{

			n = n->getNext();
			return *this;
		}

		Iterator operator++(int)
		{
			n = n->getNext();
			return *this;
		}

		Iterator& operator--()
		{
			n = n->getPrev();
			return *this;
		}

		Iterator operator--(int)
		{
			n = n->getPrev();
			return *this;
		}

		T& operator*()
		{
			return *(n->getData());
		}

	private:
		Node<T>* n;
		friend class myList<T>;

	};
	//reverse iterator inside class
	class reverse_iterator : public Iterator
	{
	public:
		reverse_iterator(Node<T>* curr = 0) : n(curr) {}
		reverse_iterator(const reverse_iterator& curr) : n(curr.n) {}


		T& operator*()
		{
			return *(n->getData());
		}

		bool operator==(const reverse_iterator& ptr) const
		{
			return (n == ptr.n);
		}

		bool operator!=(const reverse_iterator& ptr) const
		{
			return (n != ptr.n);
		}

		reverse_iterator& operator++ ()
		{
			n = n->getPrev();
			return *this;
		}

		reverse_iterator operator++ (int)
		{
			n = n->getPrev();
			return *this;
		}

		reverse_iterator operator-- ()
		{
			n = n->getNext();
			return *this;
		}

		reverse_iterator operator-- (int)
		{
			n = n->getNext();
			return *this;
		}
	private:
		Node<T>* n;
		friend class myList<T>;
	};
	//setters:
	void insert(const T& arg)
	{
	
		Node<T>* newNode = new Node<T>(new T(arg));
		listSize++;
		Iterator first = begin();
		newNode->setNext(first.n);
		head->setNext(newNode);
		newNode->setPrev(head);
		first.n->setPrev(newNode);
	}

	void erase(const Iterator& node)
	{
		node.n->getPrev()->setNext(node.n->getNext());
		node.n->getNext()->setPrev(node.n->getPrev());
		node.n->setNext(nullptr);
		delete node.n;
	}

	void eraseRange(const Iterator& first, const  Iterator& last)
	{
		Iterator ptr;
		ptr = first;
		while (ptr != last)
		{
			ptr++;
			erase(ptr.n->getPrev());
		}

	}

	Iterator begin() { return head->getNext(); }
	Iterator cbegin() const { return head->getNext(); }
	Iterator end() { return tail; }
	Iterator cend() const { return tail; }
	reverse_iterator rbegin() { return tail->getPrev(); }
	reverse_iterator crbegin()const { return tail->getPrev(); }
	reverse_iterator rend() { return head; }
	reverse_iterator crend()const { return head; }
	int size() const { return listSize; }



private:
	Node<T>* head;
	Node<T>* tail;
};

