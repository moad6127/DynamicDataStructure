#include"Stack.h"
#include<iostream>
void CreateStack(StackList& stack, const int value)
{
	Stack* pNew = new Stack{};
	pNew->stackValue = value;

	pNew->pPrev = stack.pTarget;
	stack.pTarget = pNew;
}

void PrintStack(const StackList& stack)
{
	Stack* pPrint{stack.pTarget};
	std::cout << "----STACK----" << std::endl;
	if (pPrint == nullptr)
	{
		std::cout << "��� �ֽ��ϴ�." << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	else
	{
		do
		{
			std::cout << pPrint->stackValue << std::endl;
			pPrint = pPrint->pPrev;
		} while (pPrint != nullptr);
	}
	std::cout << "-------------" << std::endl;
}

void DeleteStack(StackList& stack)
{
	Stack* backUp;
	backUp = stack.pTarget;
	if (backUp == nullptr)
	{
		return;
	}
	else
	{
		stack.pTarget = stack.pTarget->pPrev;
	}
	delete backUp;
}

void UserInfo(StackList& stack)
{
	int command{};
	
	while (command != Exit)
	{
		PrintStack(stack);
		std::cout << "����� ����� �����ϼ���: " << std::endl;
		std::cout << "Create[1]" << std::endl
			<< "DeleteStack[2]" << std::endl
			<< "Exit[3]" << std::endl;
		std::cout << "--------" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case Create:
		{
			int value{};
			std::cout << "���� �Է��ϼ��� : ";
			std::cin >> value;
			CreateStack(stack, value);
			break;
		}
		case Delete:
			DeleteStack(stack);
			break;
		case Exit:
			break;
		default:
			std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl;
			break;
		}
	}
}
