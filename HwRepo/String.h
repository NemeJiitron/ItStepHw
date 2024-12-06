#pragma once
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
	String(const String& str);
	void Show();
	void GetString();
};

