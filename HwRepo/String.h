#pragma once
#include<iostream>

class String
{
private:
	char* cStr;
	size_t length;
public:
	String();
	~String();
	String(size_t size);
	String(char*);
	String(const char* str);
	String(const String& str);
	String(String&& str);
	void Show();
	void GetString();
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	String operator+(const String& other);
	String& operator+=(const String& other);
	bool operator==(const String& other);
	bool operator!=(const String& other);
	bool operator<(const String& other);
	bool operator>(const String & other);
	char operator[](size_t index);
	friend std::ostream& operator<<(std::ostream& os, const String&);
};

