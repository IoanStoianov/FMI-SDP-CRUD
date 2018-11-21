#pragma once

#include "Student.h"

class IRepository
{
public:
	virtual bool Create(Student* student) = 0;
	virtual bool Delete(long long id) = 0;
	virtual void Read(long long id) = 0;
};

