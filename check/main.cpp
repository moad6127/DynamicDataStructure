#include<iostream>
#include<random>
#include<vector>
int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0,9);

	std::vector<int> deck{ 1,2,3,4,5,6,7,8,9,10 };
	
	std::shuffle(deck.begin(), deck.end(),gen);
	for (auto& e : deck)
	{
		std::cout << e << " ";
	}

}