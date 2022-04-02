#pragma once



class Stack
{

	int mValue;
	Stack* mPrev;
public:
	Stack();
	int RetrunValue();
	void SetValue(const int value);
	void SetPrev(Stack* stack);
	Stack* ReturnPrev();
};
class StackList
{



	Stack* pmTail;
public:
	StackList();
	void UserInfo();
	void StackPush(const int value);
	void StackPop();
	void PrintStack();
};


