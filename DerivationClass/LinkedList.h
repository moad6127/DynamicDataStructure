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
	virtual void NewCreate(int val);
	virtual void Delete();
	virtual void Print() const;
};

