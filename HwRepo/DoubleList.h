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
		DoubleList() : head{ nullptr }
		{}

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
			DoubleNode<T>* newnode = new DoubleNode<T>(value);
			DoubleNode<T>* nodePtr = head;
			while (nodePtr->next != nullptr)
			{
				nodePtr = nodePtr->next;
			}
			nodePtr->next = newnode;
			newnode->prev = nodePtr;

		}

		void DeleteFromHead()
		{
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
			DoubleNode<T>* nodePtr = head;
			while (nodePtr->next != nullptr)
			{
				nodePtr = nodePtr->next;
			}
			nodePtr->prev->next = nullptr;
			delete nodePtr;
		}

		void DeleteAll()
		{
			while (head != nullptr)
			{
				DeleteFromHead();
			}
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
			if (head != nullptr)
			{
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
						return;
					}
				}
				newptr->next = ptr;
				newptr->prev = ptr->prev;
				ptr->prev->next = newptr;
			}
		}
		void DeleteN(size_t index) {
			if (head != nullptr)
			{
				DoubleNode<T>* ptr = head;
				for (size_t i = 0; i < index; i++)
				{
					if (ptr->next != nullptr)
					{
						ptr = ptr->next;
					}
					else
					{
						return;
					}
				}
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				delete ptr;
			}
		}
		size_t Find(T value)
		{
			T index = 0;
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
			return NULL;
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

};