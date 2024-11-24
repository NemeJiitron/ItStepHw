#pragma once
class Contact
{
private:
	char _phonenum[100];
	char _city[100];
	char _country[100];
public:
	Contact(char num[]);
	Contact(char num[], char country[]);
	Contact(char num[], char country[], char city[]);
	~Contact();
	void Show();
};

class contact
{
};

