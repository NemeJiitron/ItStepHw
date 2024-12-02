#include "Student.h"
#include <iostream>

Student::Student(char* name, char* dateOfB, Contact& contact, College& college)
	:_contact(contact), _college(college)
{
	size_t size = strlen(name) + 1;
	_name = new char[size];
	strcpy_s(_name, size, name);
	size_t size2 = strlen(dateOfB) + 1;
	_dateOfB = new char[size2];
	strcpy_s(_dateOfB, size2, dateOfB);
}

Student::Student(Student&& other) noexcept
	: _contact(std::move(other._contact)), _college(std::move(other._college))
{
	_name = other._name;
	_dateOfB = other._dateOfB;
}


Student::~Student()
{
	delete[] _name;
	delete[] _dateOfB;
}

void Student::Show()
{
	std::cout << "Name - " << _name << std::endl;
	std::cout << "Birthdate - " << _dateOfB << std::endl;
	std::cout << "College info: " << std::endl;
	_college.Show();
	std::cout << "Contact info: " << std::endl;
	_contact.Show();
}


