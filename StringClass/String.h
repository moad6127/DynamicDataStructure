#pragma once
class String
{
	friend std::ostream& operator<<(std::ostream& os, const String& string);
private:
	char* mpString;
	int mLength;

public:
	String();
	String(const int index);
	String(const String& string);
	String(const char* string);
	~String();
	int GetLength();
	char* GetString();
	char* operator+(const String& string);
	String& operator+=(const String& string);
	String& operator=(const String& string);
	char& operator[](const int& index);
	
	
};
std::ostream& operator<<(const std::ostream& os, const String& string);

