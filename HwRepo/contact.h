#pragma once
#include "String.h"
class Contact
{
private:
	String _phonenum;
	String _city;
	String _country;
public:
	Contact(String& num);
	Contact(String& num, String& country);
	Contact(String& num, String& country, String& city);
	Contact(Contact& other);
	Contact(Contact&& other) noexcept;
	Contact& operator=(Contact&& other);
	~Contact();
	void Show();
};

