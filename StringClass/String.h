#pragma once
const int NULL_LENGTH{ 10 };
class String
{
	friend std::ostream& operator<<(const std::ostream& os, const String& string);
private:
	char* mpString;
	int mLength;

public:
	String();
	String(const String& string);
	String(const char* string);
	~String();
	int GetLength();
	char* GetString();
	void Print();
	char* operator+(const String& string);
	String& operator+=(const String& string);
	String& operator=(const String& string);
	String& operator[](const String& string);
	
};
std::ostream& operator<<(const std::ostream& os, const String& string);

