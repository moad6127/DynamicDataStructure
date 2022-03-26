#pragma once

enum Command
{
	Create = 1,
	Delete = 2,
	Exit = 3
};
struct Queue
{
	int queueValue{};

	Queue* pNext{};
};
struct QueueList
{
	Queue* pHead{};
	Queue* pTail{};
};

void UserInfo(QueueList& list);
void PrintQueue(const QueueList& list);
void CreateQueue(QueueList& list,const int value);
void DeleteQueue(QueueList& list);
