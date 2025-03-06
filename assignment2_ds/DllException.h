#pragma once
#include <string>
#include <iostream>

using namespace std;

class DllException
{
public:
	DllException(string e);
	string getError();
	void setError(string e);
private:
	string error;
};

