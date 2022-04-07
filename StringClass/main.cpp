#include <iostream>
#include"String.h"

int main()
{
	String empty;
	String s1{ "hello" };
	String s2("World!!");
	String s3{ s1 };
	String s4;

	empty = s1;
	std::cout << empty << std::endl;
	String size{ 10 };
	s3 += s2;
	s4 = s1 + s2;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << size.GetString() << std::endl;
	std::cout << size.GetLength() << std::endl;
	std::cout << s1[0] << s1[1] << s1[2] << std::endl;;
	s1[0] = 'w';
	s1[1] = 'o';
	s1[2] = 'r';
	s1[3] = 'l';
	s1[4] = 'd';
	std::cout << s1 << std::endl;
}
