#include<iostream>
#include "DStack.h"

DStack::DStack() : m_prev{nullptr}
{
}

DStack::~DStack()
{
}

void DStack::NewCreate(int value)
{
	if (this->m_pHead == nullptr)
	{
		this->mValue = value;
		this->m_pHead = this;
		this->m_pTail = this;
	}
	else
	{
		DStack* pNew = new DStack(*this); //자기자신 복사생성
		pNew->mValue = value;

		pNew->m_prev = static_cast<DStack*>(this->m_pTail);
		this->m_pTail = pNew;
		pNew->m_pTail = pNew;
		
	}

}

void DStack::Delete()
{
	DStack* pBack = static_cast<DStack*>( this->m_pTail);
	if (pBack == nullptr)
	{
		return;
	}
	else
	{
		this->m_pTail = static_cast<DStack*>(this->m_pTail)->m_prev;
		delete pBack;
	}
	
}

void DStack::Print() const
{
	DStack* pPrint;
	pPrint = static_cast<DStack*>(this ->m_pTail);
	if (pPrint == nullptr)
	{
		std::cout << "비어 있습니다." << std::endl;
		std::cout << "-------------" << std::endl;
		return;
	}
	else
	{
		while (pPrint->m_prev != nullptr)
		{
			std::cout << pPrint->mValue << std::endl;
			pPrint = pPrint->m_prev;
		}
		std::cout << pPrint->mValue << std::endl;
		std::cout << "=============" << std::endl;
	}

}
