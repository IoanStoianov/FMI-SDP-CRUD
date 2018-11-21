
#include "pch.h"
#include "Parser.h"

Parser::Parser(vector<ICommand*> newCommandList, IRepository* _db) {
	db = _db;
	for (int i = 0; i < newCommandList.size(); i++)
		commandList.push_back(newCommandList[i]);
	
}

void Parser::parse(const string line) {
	for (int i=0; i< commandList.size(); i++) {
		if (line.find(commandList[i]->toString()) != string::npos) {
			commandList[i]->execute(db);
		}
	}
}

