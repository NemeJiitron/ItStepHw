#include "Student.h"
#include <iostream>

Student::Student(String& name, String& dateOfB, Contact& contact, College& college)
	:_contact(contact), _college(college), _name(name), _dateOfB(dateOfB)
{
	
}

Student::Student(Student&& other) noexcept
	: _contact(std::move(other._contact)), _college(std::move(other._college)), _name(std::move(other._name)), _dateOfB(std::move(other._dateOfB))
{
	
}

Student& Student::operator=(Student&& other)
{
	_college = std::move(other._college);
	_contact = std::move(other._contact);
	_name = std::move(other._name);
	_dateOfB = std::move(other._dateOfB);
	return *this;

}


Student::~Student()
{
	
}

void Student::Show()
{
	std::cout << "Name - " << _name;
	std::cout << "Birthdate - " << _dateOfB;
	std::cout << "College info: " << std::endl;
	_college.Show();
	std::cout << "Contact info: " << std::endl;
	_contact.Show();
}


