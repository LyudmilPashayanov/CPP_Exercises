#pragma once
#include "IPersistable.h"

std::ostream& operator<<(std::ostream& os, const IPersistable& obj)
{
	obj.ToTextData(os);
	return os;
}