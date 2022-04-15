#pragma once
#include "LinkedList.h"
class DQueue :
    public LinkedList
{
    DQueue* m_pNext;
public:
    DQueue();
    ~DQueue()override;
    void NewCreate(int value);
    void Delete() override;
    void Print() const override;

};

