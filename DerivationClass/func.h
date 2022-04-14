#pragma once

namespace First
{
	enum FirstCommand
	{
		STACK =1,
		QEUEU =2,
		EXIT=3
	};
}
namespace second
{
	enum Command
	{
		NewCreate =1,
		Delete= 2,
		EXIT=3
	};
}

void UserInfo(DStack& st, DQueue& Qe);
void StackInfo(DStack& st);
void QueueInfo(DQueue& Qe);
