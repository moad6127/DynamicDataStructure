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
		std::cout << "����� ����� �����ϼ��� : " << std::endl
			<< "[1] EnQueue" << std::endl
			<< "[2] DeQueue" << std::endl
			<< "[3] Exit" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case EnQueue:
		{
			int value{};
			std::cout << "���� �Է��ϼ��� : ";
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
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}
