#include <iostream>
#include "DoubleList.h"


int main()
{
	DoubleList<int> list;
	list.AddToHead(10);
	list.AddToHead(12);
	list.AddToHead(8);
	list.AddToHead(23);
	list.AddToTail(1);
	list.AddToHead(1);
	list.Show();
	list.DeleteFromTail();
	list.Show();
	list.DeleteFromHead();
	list.Show();
	list.DeleteAll();
	list.Show();
	list.AddToHead(1);
	list.AddToHead(2);
	list.AddToHead(3);
	list.AddToHead(4);
	list.AddToHead(5);
	list.Insert(2, 555);
	list.Insert(4, 555);
	list.Show();
	list.DeleteN(1);
	list.Show();
	list.DeleteN(3);
	list.Show();
	std::cout << list.Find(555) << std::endl;
	std::cout << list.Find(1) << std::endl;
	list.AddToHead(6);
	list.AddToHead(6);
	list.AddToHead(3);
	list.AddToHead(6);
	list.Show();
	std::cout << list.Replace(3000, 3) << std::endl;
	std::cout << list.Replace(6000, 6) << std::endl;
	std::cout << list.Replace(1, 100000) << std::endl;
	list.Show();
	return 0;
}