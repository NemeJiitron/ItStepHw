#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(char* num, char* country, char* city)
{
	size_t size1 = strlen(num) + 1;
	_phonenum = new char[size1];
	strcpy_s(_phonenum, size1, num);
	if (country != nullptr) {
		size_t size2 = strlen(num) + 1;
		_country = new char[size2];
		strcpy_s(_country, size2, country);
	}
	if (city != nullptr)
	{
		size_t size3 = strlen(num) + 1;
		_city = new char[size3];
		strcpy_s(_city, size3, city);
	}

}

Contact::Contact(Contact& other)
{
	size_t size1 = strlen(other._phonenum) + 1;
	_phonenum = new char[size1];
	strcpy_s(_phonenum, size1, other._phonenum);
	size_t size2 = strlen(other._country) + 1;
	_country = new char[size2];
	strcpy_s(_country, size2, other._country);
	size_t size3 = strlen(other._city) + 1;
	_city = new char[size3];
	strcpy_s(_city, size3, other._city);
}

Contact::Contact(Contact&& other) noexcept
{
	_phonenum = other._phonenum;
	_country = other._country;
	_city = other._city;
	other._phonenum = nullptr;
	other._country = nullptr;
	other._city = nullptr;
}


Contact::Contact(char* num)
	: Contact(num, nullptr, nullptr)
{}
Contact::Contact(char* num, char* country)
	: Contact(num, nullptr, country)
{}
Contact::~Contact()
{
	delete[] _phonenum;
	delete[] _city;
	delete[] _country;
}

void Contact::Show()
{
	std::cout << "Phone number - " << _phonenum << std::endl;
	std::cout << "Country - " << _country << std::endl;
	std::cout << "City - " << _city << std::endl;
}
