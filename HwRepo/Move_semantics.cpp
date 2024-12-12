#include "Student.h"
#include "Array.h"
#include "String.h"
#include <iostream>

int main()
{
	//String str("lokkilla");
	//str.Show();
	//String str2("Chrispaul");
	//str2.Show();
	//str = std::move(str2);
	//str.Show();
	////str2.Show();

	//Array<int> arr(10, 1);
	//arr.Show();
	//Array<int> arr2(std::move(arr));
	//arr2.Show();
	//arr.Show();

	String number("09109409");
	String country("Ukraine");
	String city("Odesa");
	Contact contact(number, country, city);
	contact.Show();
	String name("Tech college");
	College college(contact, name);
	college.Show();
	String stname("Mattheeww");
	String bdate("09.09.09");
	Student st(stname, bdate, contact, college);
	st.Show();
	Student st2(std::move(st));
	st2.Show();
	st.Show();

	return 0;
}