#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(char num[], char country[], char city[])
{
	strcpy_s(_phonenum, 100, num);
	if (country != nullptr)
		strcpy_s(_country, 100, country);
	if (city != nullptr)
		strcpy_s(_city, 100, city);

}

Contact::Contact(char num[])
	: Contact(num, nullptr, nullptr)
{}
Contact::Contact(char num[], char country[])
	: Contact(num, nullptr, country)
{}
Contact::~Contact()
{
	/*delete[] _phonenum;
	delete[] _city;
	delete[] _country;*/
}

void Contact::Show()
{
	std::cout << "Phone number - " << _phonenum << std::endl;
	std::cout << "Country - " << _country << std::endl;
	std::cout << "City - " << _city << std::endl;
}
