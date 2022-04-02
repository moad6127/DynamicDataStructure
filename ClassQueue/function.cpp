#include<iostream>
#include"function.h"
#include"Queue.h"

void UserInFo(QueueList& list)
{
	int command{};
	while (command != Exit)
	{
		std::cout << "=====QUEUE=====" << std::endl;
		list.PrintQueue();
		std::cout << "사용할 기능을 선택하세요 : " << std::endl
			<< "[1] EnQueue" << std::endl
			<< "[2] DeQueue" << std::endl
			<< "[3] Exit" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case EnQueue:
		{
			int value{};
			std::cout << "값을 입력하세요 : ";
			std::cin >> value;
			list.EnQueue(value);
			break;
		}
		case DeQueue:
			list.DeQueue();
			break;
		case Exit:
			break;
		default:
			std::cout << "잘못된 명령어 입니다." << std::endl;
			break;
		}
	}
}
