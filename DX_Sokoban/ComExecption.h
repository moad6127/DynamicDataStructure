#pragma once
#include<Windows.h>
#include<exception>
#include<string>
#include<sstream>

class com_exception : public std::exception
{
private:
	HRESULT mReseult;
	std::string mDescription;

public:
	com_exception(HRESULT hr) : mReseult{ hr }
	{
	}
	com_exception(HRESULT hr, std::string msg) :mReseult{ hr }, mDescription{ msg }
	{

	}
	virtual const char* what() const override
	{
		std::stringstream ss;
		ss << "Failure with Code : " << mReseult << std::endl <<
			mDescription<<std::endl;

		return ss.str().c_str();
	}
};

inline void ThrowIfFailed(HRESULT hr,std::string msg = "")
{
	if (FAILED(hr))
	{
		throw com_exception(hr,msg);
	}
}