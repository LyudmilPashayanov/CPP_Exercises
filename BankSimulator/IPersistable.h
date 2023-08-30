#pragma once
#include <iostream>

class IPersistable
{
	friend std::ostream& operator<<(std::ostream& os, const IPersistable& obj);
public:
	virtual std::string Print() const = 0;
	virtual void ToTextData(std::ostream& os) const = 0;
	virtual ~IPersistable() = default;
};


