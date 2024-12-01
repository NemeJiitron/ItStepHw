#pragma once
class Contact
{
private:
	char* _phonenum;
	char* _city;
	char* _country;
public:
	Contact(char* num);
	Contact(char* num, char* country);
	Contact(char* num, char* country, char* city);
	Contact(Contact& other);
	Contact(Contact&& other) noexcept;
	~Contact();
	void Show();
};

