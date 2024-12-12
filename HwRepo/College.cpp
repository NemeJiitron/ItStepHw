#include "College.h"
#include <iostream>


College::College(Contact& contactt, String& name)
	: _contact(contactt), _name(name)
{

}

College::College(College& other)
	: _contact(other._contact), _name(other._name)
{
}

College::College(College&& other) noexcept
	: _contact(std::move(other._contact)), _name(std::move(other._name))
{
	
}

College& College::operator=(College&& other)
{
	_name = std::move(other._name);
	_contact = std::move(other._contact);
	return *this;
}

College::~College()
{
	
}

void College::Show()
{
	std::cout << "College - " << _name;
	_contact.Show();
}
