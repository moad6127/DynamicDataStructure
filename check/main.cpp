#include<iostream>
#include<random>
int main()
{

	//C style
		//srand((unsigned int)time(nullptr));
		//for (int i = 0; i < 20; i++)
		//{
		//	std::cout << rand() << " ";
		//}

		//std::cout << std::endl;
	//C++ style
	std::random_device rd;
	std::mt19937 gen(rd()); //functor : function + Object

	for (int i = 0; i < 20; i++)
	{
		std::cout << (gen()%6) + 1  << " "; //1~6������ ���� ������ �Ѵ�.

	}
	std::cout << std::endl;

	std::uniform_int_distribution<> dist(1, 6); //������ �յ��ϰ� �Ѵ�.
	for (int i = 0; i < 20; i++)
	{
		std::cout << dist(gen)<<" ";
	}
	std::cout << std::endl;
}