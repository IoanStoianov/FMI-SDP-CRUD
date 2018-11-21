#pragma once
#include "pch.h"
#include "Student.h"
#include "IRepository.h"
class ICommand {
public:
	virtual void execute(IRepository* db) const = 0;
	virtual string toString() const = 0;
};