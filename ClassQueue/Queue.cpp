#include<iostream>
#include "Queue.h"



Queue::Queue() : mValue{0}, pmNext{nullptr}
{
}

void Queue::SetValue(const int value)
{
	mValue = value;
}

void Queue::setNext(Queue* queue)
{
	pmNext = queue;
}

int Queue::ReturnValue()
{
	return mValue;
}

Queue* Queue::ReturnNext()
{
	return pmNext;
}

QueueList::QueueList() : pmHead{nullptr}, pmTail{nullptr}
{
}

void QueueList::PrintQueue()
{
	Queue* pPrint{ pmHead };
	if (pmHead == nullptr)
	{
		std::cout << "비어있음" << std::endl;
	}
	else
	{
		while (pPrint != nullptr)
		{
			std::cout << pPrint->ReturnValue() << " ";
			pPrint = pPrint->ReturnNext();
		}
		std::cout << std::endl;
	}
	std::cout << "=============" << std::endl;
}

void QueueList::EnQueue(const int value)
{
	Queue* pNew = new Queue;
	pNew->SetValue(value);
	if (pmHead == nullptr)
	{
		pmHead = pNew;
	}
	else
	{
		pmTail->setNext(pNew);
	}
	pmTail = pNew;
}

void QueueList::DeQueue()
{
	Queue* pBack{ pmHead };
	if (pmHead == nullptr)
	{
		return;
	}
	else
	{
		pmHead = pmHead->ReturnNext();
	}
	delete pBack;
}
