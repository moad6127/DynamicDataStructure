#include<iostream>
#include"DQueue.h"
#include"DStack.h"
#include"func.h"


void UserInfo(DStack& st, DQueue& Qe)
{
	int command{};
	while (command != First::EXIT)
	{
		std::cout << "[1] STACK" << std::endl;
		std::cout << "[2] QUEUE" << std::endl;
		std::cout << "[3] EXIT" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case First::STACK:
			StackInfo(st);
			break;
		case First::QEUEU:
			QueueInfo(Qe);
			break;
		case First::EXIT:
			break;
		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}

void StackInfo(DStack& st)
{
	int command{};

	while (command != second::EXIT)
	{
		std::cout << "====STACK====" << std::endl;
		st.Print();
		std::cout << "����� ����� �����ϼ��� : " << std::endl
			<< "[1] PUSH" << std::endl
			<< "[2] POP" << std::endl
			<< "[3] EXIT" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case second::NewCreate:
		{
			int value{};
			std::cout << "���� �Է��ϼ��� :";
			std::cin >> value;
			st.NewCreate(value);
			break;
		}
		case second::Delete:
			st.Delete();
			break;
		case second::EXIT:
			break;
		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}


void QueueInfo(DQueue& Qe)
{
	int command{};

	while (command != second::EXIT)
	{
		std::cout << "====QUEUE====" << std::endl;
		Qe.Print();
		std::cout << "����� ����� �����ϼ��� : " << std::endl
			<< "[1] EnQueue" << std::endl
			<< "[2] DeQueue" << std::endl
			<< "[3] EXIT" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case second::NewCreate:
		{
			int value{};
			std::cout << "���� �Է��ϼ��� :";
			std::cin >> value;
			Qe.NewCreate(value);
			break;
		}
		case second::Delete:
			Qe.Delete();
			break;
		case second::EXIT:
			break;
		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}

