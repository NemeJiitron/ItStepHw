#include "College.h"
#include <iostream>


College::College(Contact& contactt, char* name)
	: _contact(contactt)
{
	size_t size = strlen(name) + 1;
	_name = new char[size];
	strcpy_s(_name, size, name);

}

College::College(College& other)
	: _contact(other._contact)
{
	size_t size = strlen(other._name) + 1;
	_name = new char[size];
	strcpy_s(_name, size, other._name);
}

College::College(College&& other) noexcept
	: _contact(std::move(other._contact))
{
	_name = new char[strlen(other._name)];
	strcpy_s(_name, strlen(other._name), other._name);
	other._name = nullptr;
}

College::~College()
{
	delete[] _name;
}

void College::Show()
{
	std::cout << "College - " << _name << std::endl;
	_contact.Show();
}
