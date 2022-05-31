#include<Windows.h>

#include"Solitaire.h"

Solitaire myFamework;

int WINAPI WinMain(
	_In_ HINSTANCE hInstace,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpComLine,
	_In_ int nShowCmd
)
{
	int result{};
	try 
	{
		myFamework.Initialize(hInstace);

		result = myFamework.GameLoop();
	}
	catch (com_exception& e)
	{
		OutputDebugStringA(e.what());
	}
	
	return result;
}

