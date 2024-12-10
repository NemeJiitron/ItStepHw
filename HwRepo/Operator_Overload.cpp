#include "Array.h"
#include "String.h"

using Arrayint = Array<int>;

int main()
{
	/*String str("forChristSake");
	String str2("forLuciSake");
	str.Show();
	str2.Show();
	str = str2;
	str.Show();
	String str3;
	str3 = str + str2;
	str3.Show();
	String str4("forChristSake");
	str4 += str;
	str4.Show();
	std::cout << str[0] << std::endl;
	std::cout << str[1] << std::endl;
	std::cout << str;
	bool compare = str == str2;
	std::cout << compare << std::endl;
	compare = str == str4;
	std::cout << compare << std::endl;
	compare = str != str2;
	std::cout << compare << std::endl;
	compare = str != str4;
	std::cout << compare << std::endl;*/

	Arrayint arr(10, 1);
	Arrayint arr2(5, 1);
	arr.Show();
	arr2.Show();
	arr = arr2;
	arr.Show();
	Arrayint arr3;
	arr3 = arr + arr2;
	arr3.Show();
	Arrayint arr4(10, 1);
	arr4 += arr3;
	arr4.Show();
	std::cout << arr4[0] << std::endl;
	std::cout << arr4[1] << std::endl;
	std::cout << arr;
	std::cout << std::endl;
	arr.Show();
	arr2.Show();
	arr4.Show();
	bool compare = arr == arr2;
	std::cout << compare << std::endl;
	compare = arr == arr4;
	std::cout << compare << std::endl;
	compare = arr != arr2;
	std::cout << compare << std::endl;
	compare = arr != arr4;
	std::cout << compare << std::endl;

	Arrayint arrcmp;
	arrcmp = arr * arr2;
	arrcmp.Show();
	return 0;
}