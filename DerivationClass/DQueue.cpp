#include<iostream>
#include "DQueue.h"

DQueue::DQueue() :m_pNext{nullptr}
{
}

DQueue::~DQueue()
{
}

void DQueue::NewCreate(int value)
{
	if (this->m_pHead == nullptr)
	{
		this->mValue = value;
		this->m_pHead = this;
		this->m_pTail = this;
	}
	else
	{
		DQueue* pNew = new DQueue();
		pNew->mValue = value;

		static_cast<DQueue*>(this->m_pTail)->m_pNext = pNew;
		this->m_pTail = pNew;
		pNew->m_pTail = pNew;
	}
}

void DQueue::Delete()
{
	DQueue* pBack = static_cast<DQueue*>(this->m_pNext);
	if (this->m_pHead == nullptr)
	{
		return;
	}
	else if (static_cast<DQueue*>(this->m_pHead)->m_pNext == nullptr)
	{
		this->m_pHead = nullptr;
		this->m_pTail = nullptr;
		this->mValue = NULL;
	}
	else
	{
		this->mValue = (this->m_pNext)->mValue;
		this->m_pNext = pBack->m_pNext;
		delete pBack;
	}
}

void DQueue::Print() const
{
	DQueue* pPrint = static_cast<DQueue*>(this->m_pHead);
	if (pPrint == nullptr)
	{
		std::cout << "비어 있습니다." << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	else
	{
		while (pPrint->m_pNext != nullptr)
		{
			std::cout << pPrint->mValue <<" ";
			pPrint = pPrint->m_pNext;
		}
		std::cout << pPrint->mValue << std::endl;
		std::cout << "=============" << std::endl;
	}
}
