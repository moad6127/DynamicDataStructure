#include <iostream>
#include"String.h"

int main()
{
	String myString{"hello"};
	String myString2{ " world"};
	String s3{ myString + myString2 };
	s3.Print();
}