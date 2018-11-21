#pragma once
#include "pch.h"
#include "ICommand.h"
#include "IRepository.h"
class Parser {
private:
	vector<ICommand*> commandList;
	IRepository* db;
public:
	Parser(vector<ICommand*> commandList, IRepository* db);
	void parse(string line);
};