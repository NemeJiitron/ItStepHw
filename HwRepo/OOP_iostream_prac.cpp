#include <iostream>
#include "Student.h"
#include "Array.h"


int main()
{

	/*String num = "09901902";
	String country = "Ukraine";
	String city = "Odesa";
	Contact college_cont(num, country, city);
	college_cont.Show();
	String cname = "STC";
	College college(college_cont, cname);
	String name = "Matt";
	String dateofB = "01.01.01";
	Student matt(name, dateofB, college_cont, college);
	matt.Show();*/

	Array<int> arr1(10, true);
	arr1.Show();
	arr1.Save("array1Save.txt");
	Array<int> arr2(10);
	arr2.Show();
	arr2.Load("array1Save.txt");
	arr2.Show();
	return 0;
}