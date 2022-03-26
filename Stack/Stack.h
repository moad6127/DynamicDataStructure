#pragma once

enum Command
{
	Create=1,
	Delete=2,
	Exit= 3
};
struct Stack
{
	int stackValue{};

	Stack* pPrev{nullptr};
};
struct StackList
{
	Stack* pTarget{nullptr};
};

void CreateStack(StackList& stack, const int value);
void PrintStack(const StackList& stack);
void DeleteStack(StackList& stack);
void UserInfo(StackList& stack);