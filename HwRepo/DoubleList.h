	#pragma once
	#include <iostream>
	#include <string>

	template <typename T>
	class DoubleNode
	{
	public:
		T value;
		Node* next;
		Node* prev;

		Node(const T& value) : value(value), next(nullptr), prev(nullptr)
		{}

		void print() const
		{
			std::cout << value;
		}
	};

	template<typename T>
	class List
	{
	public:
		DoubleNode<T>* head;
		List() : head{ nullptr }
		{}

		void add(const T& value)
		{
			DoubleNode<T>* nodePtr = new DoubleNode<T>(value);
			head->prev = nodePtr;
			nodePtr->next = head;
			head = nodePtr;
		}

		void remove()
		{
			if (head != nullptr)
			{
				DoubleNode<T>* nodePtr = head;
				head = head->next;
				head->prev = nullptr;
				delete nodePtr;
			}
		}
		DoubleNode<T>* findPrev(const T& value) const
		{
			if (head == nullptr)
			{
				return nullptr;
			}
			for (DoubleNode<T>* nodePtr = head->next;
				nodePtr != nullptr;
				nodePtr = nodePtr->next)
			{
				if (nodePtr->value == value)
				{
					return nodePtr->prev;
				}
			}
			return nullptr;
		}
	
	};