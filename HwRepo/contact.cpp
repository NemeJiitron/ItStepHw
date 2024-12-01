#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(char* num, char* country, char* city)
{
	_phonenum = new char[strlen(num)];
	strcpy_s(_phonenum, strlen(num), num);
	if (country != nullptr) {
		_country = new char[strlen(country)];
		strcpy_s(_country, strlen(country), country);
	}
	if (city != nullptr)
	{
		_city = new char[strlen(city)];
		strcpy_s(_city, strlen(city), city);
	}

}

Contact::Contact(Contact& other)
{
	_phonenum = new char[strlen(other._phonenum)];
	strcpy_s(_phonenum, strlen(other._phonenum), other._phonenum);
	_country = new char[strlen(other._country)];
	strcpy_s(_country, strlen(other._country), other._country);
	_city = new char[strlen(other._city)];
	strcpy_s(_city, strlen(other._city), other._city);
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
