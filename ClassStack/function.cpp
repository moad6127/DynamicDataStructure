#include<iostream>
#include"Stack.h"
#include"function.h"

void UserInfo(StackList& list)
{
	int command{};

	while (command != EXIT)
	{
		std::cout << "====STACK====" << std::endl;
		list.PrintStack();
		std::cout << "사용할 기능을 선택하세요 : " << std::endl
			<< "[1] PUSH" << std::endl
			<< "[2] POP" << std::endl
			<< "[3] EXIT" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case PUSH:
		{
			int value{};
			std::cout << "값을 입력하세요 :";
			std::cin >> value;
			list.StackPush(value);
			break;
		}
		case POP:
			list.StackPop();
			break;
		case EXIT:
			break;
		default:
			std::cout << "잘못된 명령어 입니다." << std::endl;
			break;
		}
	}
}