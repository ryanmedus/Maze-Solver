#include "DllException.h"

DllException::DllException(string e)
{
	error = e;
}

string DllException::getError()
{
	return error;
}

void DllException::setError(string e)
{
	error = e;
}