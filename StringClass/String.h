#pragma once
class String
{
private:
	char* pmString;

public:
	String(const char* string);
	~String();
	void Print();
};

