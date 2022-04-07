#include <iostream>
#include"String.h"

int main()
{
	String empty;
	String s1{ "hello" };
	empty = s1;
	std::cout << empty << std::endl;
	String size{ 10 };

}
