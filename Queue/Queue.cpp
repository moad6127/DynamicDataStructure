#include"Queue.h"
#include<iostream>
void UserInfo(QueueList& list)
{
	int command{};
	while (command != Exit)
	{
		PrintQueue(list);
		std::cout << "����� ����� �����ϼ���: " << std::endl;
		std::cout << "CreateQueue[1]" << std::endl
			<< "DeleteQueue[2]" << std::endl
			<< "Exit[3]" << std::endl;
		std::cout << "--------" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case Create:
		{
			int value{};
			std::cout << "���� �Է��� �ּ���: ";
			std::cin >> value;
			CreateQueue(list, value);
			break;
		}
			
		case Delete:
			DeleteQueue(list);
			break;
		case Exit:
			break;
		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}

void PrintQueue(const QueueList& list)
{
	Queue* pCount{list.pHead};
	std::cout << "----Queue----" << std::endl;
	if (list.pHead == nullptr)
	{
		std::cout << "�������" << std::endl;
	}
	else
	{
		while(pCount != nullptr)
		{
			std::cout << pCount->queueValue << " ";
			pCount = pCount->pNext;
		}
		std::cout << std::endl;
		
	}
	std::cout << "-------------" << std::endl;
}

void CreateQueue(QueueList& list,const int value)
{
	Queue* pNew = new Queue{};
	pNew->queueValue = value;
	pNew->pNext = nullptr;
	if (list.pHead == nullptr)
	{
		list.pHead = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
	}
	list.pTail = pNew;
}

void DeleteQueue(QueueList& list)
{
	Queue* pbackUp{ list.pHead };
	if (list.pHead == nullptr)
	{
		return;
	}
	else
	{
		list.pHead = list.pHead->pNext;
	}
	delete pbackUp;
}
