#include "Array.h"
#include "String.h"



int main()
{
	String str("forChristSake");
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
	std::cout << compare << std::endl;


	return 0;
}