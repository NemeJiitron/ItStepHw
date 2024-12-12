#include "Contact.h"
#include <iostream>
#include <string>

Contact::Contact(String& num, String& country, String& city)
	:_phonenum(num), _country(country), _city(city)
{

}

Contact::Contact(Contact& other)
	:_phonenum(other._phonenum), _country(other._country), _city(other._city)
{
	
}

Contact::Contact(Contact&& other) noexcept
	:_phonenum(std::move(other._phonenum)), _country(std::move(other._country)), _city(std::move(other._city))
{
	
}

Contact& Contact::operator=(Contact&& other)
{
	_phonenum = std::move(other._phonenum);
	_country = std::move(other._country);
	_city = std::move(other._city);
	return *this;
}


Contact::Contact(String& num)
	:_phonenum(num), _country(), _city()
{}
Contact::Contact(String& num, String& country)
	:_phonenum(num), _country(country), _city()
{}
Contact::~Contact()
{
	
}

void Contact::Show()
{
	std::cout << "Phone number - " << _phonenum;
	std::cout << "Country - " << _country;
	std::cout << "City - " << _city;
}
