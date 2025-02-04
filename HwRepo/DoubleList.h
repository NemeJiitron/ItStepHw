#pragma once
#include <iostream>
#include <string>

template <typename T>
class DoubleNode
{
public:
	T value;
	DoubleNode* next;
	DoubleNode* prev;

	DoubleNode(const T& value) : value(value), next(nullptr), prev(nullptr)
	{}

	void Show() const
	{
		std::cout << value << " -> ";
	}
};

template<typename T>
class DoubleList
{
public:
	DoubleNode<T>* head;
	DoubleNode<T>* tail;
	DoubleList() : head(nullptr), tail(nullptr)
	{}

	T Top()
	{
		return head->value;
	}

	void AddToHead(const T& value)
	{
		DoubleNode<T>* nodePtr = new DoubleNode<T>(value);
		if (head == nullptr)
		{
			head = nodePtr;
			return;
		}
		head->prev = nodePtr;
		nodePtr->next = head;
		head = nodePtr;
	}

	void AddToTail(const T& value)
	{
		DoubleNode<T>* nodePtr = new DoubleNode<T>(value);
		if (tail == nullptr)
		{
			tail = nodePtr;
			DoubleNode<T>* hptr = head;
			while (hptr->next != nullptr)
			{
				hptr = hptr->next;
			}
			hptr->next = tail;
			tail->prev = hptr;
			return;
		}
		nodePtr->prev = tail;
		tail->next = nodePtr;
		tail = nodePtr;
	}

	void DeleteFromHead()
	{
		if (head == nullptr)
		{
			throw std::exception("Error. Head is empty");
		}
		if (head->next != nullptr)
		{
			DoubleNode<T>* nodePtr = head;
			head = head->next;
			head->prev = nullptr;
			delete nodePtr;
		}
		else
		{
			delete head;
			head = nullptr;
		}	
	}

	void DeleteFromTail()
	{
		if (tail == nullptr)
		{
			throw std::exception("Error. Tail is empty");
		}
		DoubleNode<T>* nodePtr = tail;
		nodePtr->prev->next = nullptr;
		delete nodePtr;
	}

	void DeleteAll()
	{
		while (head != nullptr)
		{
			DeleteFromHead();
		}
		tail = nullptr;
	}
		
	void Show()
	{
		DoubleNode<T>* nodePtr = head;
		while (nodePtr != nullptr)
		{
			nodePtr->Show();
			nodePtr = nodePtr->next;
		}
		std::cout << std::endl;
	}
		
	void Insert(size_t index, T value)
	{
		if (head == nullptr)
		{
			throw std::exception("Error. Head is empty");
		}
		DoubleNode<T>* ptr = head;
		DoubleNode<T>* newptr = new DoubleNode<T>(value);
		for (size_t i = 0; i < index; i++)
		{
			if (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			else
			{
				throw std::exception("Error. Out of range");
			}
		}
		newptr->next = ptr;
		newptr->prev = ptr->prev;
		ptr->prev->next = newptr;
	}
	void DeleteN(size_t index) {
		if (head == nullptr)
		{
			throw std::exception("Error. Head is empty");
		}

		DoubleNode<T>* ptr = head;
		for (size_t i = 0; i < index; i++)
		{
			if (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			else
			{
				throw std::exception("Error. Out of range");
			}
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		delete ptr;
	}
	size_t Find(T value)
	{
		size_t index = 0;
		DoubleNode<T>* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->value == value)
			{
				return index;
			}
			index++;
			ptr = ptr->next;
		}
		return -1;
	}
	int Replace(T newvalue, T valToRep)
	{
		T res = 0;
		DoubleNode<T>* ptr = head;
		while (ptr != nullptr)
		{
			if (ptr->value == valToRep)
			{
				ptr->value = newvalue;
				res++;
			}
			ptr = ptr->next;
		}
		if (res == 0)
		{
			return -1;
		}
		return res;
	}

	DoubleList<T>& operator=(const DoubleList<T>& other)
	{
		DeleteAll();
		
		AddToHead(other.head->value);
		for (DoubleNode<T>* i = other.head->next; i != nullptr; i = i->next)
		{
			AddToTail(i->value);
		}

		
		return *this;
	}

	DoubleList<T> operator+(DoubleList<T>& other)
	{
		DoubleList<T> newlist;
		newlist.AddToHead(head->value);
		for (DoubleNode<T>* i = head->next; i != nullptr; i = i->next)
		{
			newlist.AddToTail(i->value);
		}
		newlist.AddToTail(other.head->value);
		for (DoubleNode<T>* i = other.head->next; i != nullptr; i = i->next)
		{
			newlist.AddToTail(i->value);
		}
		return newlist;
	}


};