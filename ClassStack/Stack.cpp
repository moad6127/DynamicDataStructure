#include<iostream>
#include "Stack.h"
#include"function.h"


StackList::StackList() : pmTail{nullptr}
{
}


void StackList::StackPush( const int value)
{
	Stack* pNew = new Stack;
	pNew->SetValue(value);
	pNew->SetPrev(pmTail);
	pmTail = pNew;
}

void StackList::StackPop()
{
	Stack* pBack{pmTail};
	if (pBack == nullptr)
	{
		return;
	}
	else
	{
		pmTail = pmTail->ReturnPrev();
	}
	delete pBack;
	
}

void StackList::PrintStack()
{
	Stack* pPrint{ pmTail };
	if (pPrint == nullptr)
	{
		std::cout << "비어 있습니다." << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	else
	{
		while (pPrint != nullptr)
		{
			std::cout << pPrint->RetrunValue() << std::endl;
			pPrint = pPrint->ReturnPrev();
		}

		std::cout << "=============" << std::endl;
	}
}

Stack::Stack() : mValue{0}, mPrev{nullptr}
{
}

int Stack::RetrunValue()
{
	return mValue;
}

void Stack::SetValue(const int value)
{
	mValue = value;
}

void Stack::SetPrev(Stack* stack)
{
	mPrev = stack;
}

Stack* Stack::ReturnPrev()
{
	return mPrev;
}
