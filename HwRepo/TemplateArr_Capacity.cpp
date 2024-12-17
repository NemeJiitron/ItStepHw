#include "Array.h"



int main()
{
	/*std::initializer_list<int> list = { 10, 20, 30, 40, 50 };
	std::cout << *(list.begin() + 1) << std::endl;
	for (auto i : list) {
		std::cout << i << " ";
	}*/
	Array<int> arr(10, true);
	arr.Show();
	arr.Errase(2);
	arr.Show();
	arr.Pop_Front();
	arr.Pop_Front();
	arr.Show();
	arr.Push_Back(6);
	arr.Push_Back(6);
	arr.Push_Back(6);
	arr.Push_Back(6);
	arr.Show();
	arr = { 1, 6, 1, 42, 4, 63, 1 };
	arr.Show();

	return 0;
}