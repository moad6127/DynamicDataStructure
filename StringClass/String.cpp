#include<iostream>
#include<cstring>
#include "String.h"


String::String() : mLength{0}
{
	mpString = new char[mLength]{};
}

String::String(const int index) : mLength{index}
{
	mpString = new char[mLength]{};
}

String::String(const String& string)
{
	mLength = string.mLength;
	mpString = new char[mLength + 1];
	strcpy_s(mpString, mLength + 1, string.mpString);
}

String::String(const char* string)
{
	int stringSize;
	stringSize = strlen(string);
	char* pString = new char[stringSize + 1];

	strcpy_s(pString, stringSize + 1, string);
	mpString = pString;
	mLength = stringSize;
}

String::~String()
{
	delete[] mpString;
	mpString = nullptr;
}

int String::GetLength()
{
	return mLength;
}

char* String::GetString()
{
	return mpString;
}



char* String::operator+(const String& string)
{
	int stringLength{ this->mLength + string.mLength };
	char* plusString = new char[stringLength + 1];
	for (int i = 0; i < this->mLength; i++)
	{
		plusString[i] = this->mpString[i];
	}
	for (int i = 0; i < string.mLength+1; i++)
	{
		plusString[i + mLength ] = string.mpString[i];
	}
	return plusString;
}

String& String::operator+=(const String& string)
{
	int newLength{ mLength + string.mLength };
	char* temp = new char[newLength + 1];
	for (int i = 0; i < mLength; i++)
	{
		temp[i] = mpString[i];
	}
	for (int i = 0;i<string.mLength+1;i++ )
	{
		temp[i + mLength] = string.mpString[i];
	}
	delete[] mpString;
	mpString = temp;
	mLength = newLength;
	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

String& String::operator=(const String& string)
{
	mLength = string.mLength;
	mpString = new char[mLength + 1];
	strcpy_s(mpString, mLength + 1, string.mpString);

	return *this;
	// TODO: 여기에 return 문을 삽입합니다.
}

char& String::operator[](const int& index)
{
	return mpString[index];
	// TODO: 여기에 return 문을 삽입합니다.
}

std::ostream& operator<<(std::ostream& os,const String& string)
{
	os << string.mpString;
	return os;
}
