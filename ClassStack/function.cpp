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
		std::cout << "����� ����� �����ϼ��� : " << std::endl
			<< "[1] PUSH" << std::endl
			<< "[2] POP" << std::endl
			<< "[3] EXIT" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case PUSH:
		{
			int value{};
			std::cout << "���� �Է��ϼ��� :";
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
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}