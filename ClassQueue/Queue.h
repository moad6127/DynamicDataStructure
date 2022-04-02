#pragma once
class Queue
{
	int mValue;

	Queue* pmNext;

public:
	Queue();
	void SetValue(const int value);
	void setNext(Queue* queue);
	int ReturnValue();
	Queue* ReturnNext();
};
class QueueList
{
	Queue* pmHead;
	Queue* pmTail;

public:
	QueueList();
	void PrintQueue();
	void EnQueue(const int value);
	void DeQueue();
};

