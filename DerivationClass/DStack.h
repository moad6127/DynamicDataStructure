#pragma once
#include "LinkedList.h"
class DStack :
    public LinkedList
{
    DStack* m_prev;

public:
    DStack();
    ~DStack() override;
    void NewCreate(DStack* stack,int value) override;
    void Delete() override;
    void Print() const override;
};

