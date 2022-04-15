#pragma once
class LinkedList
{
protected:
	int mValue;
	LinkedList* m_pHead;
	LinkedList* m_pTail;

public:

	LinkedList();
	virtual ~LinkedList();
	virtual void NewCreate(int val) =0;
	virtual void Delete()= 0;
	virtual void Print() const = 0;
};

