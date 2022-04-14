#include "DStack.h"

DStack::DStack() : m_prev{nullptr}
{
}

DStack::~DStack()
{
}

void DStack::NewCreate(DStack* stack,int value)
{
	DStack* pNew = new DStack;
	pNew->mValue = value;

	if (pNew->m_pHead == nullptr)
	{
		pNew->m_pHead = pNew;
		pNew->m_pTail = pNew;
	}
}

void DStack::Delete()
{
}

void DStack::Print() const
{
}
