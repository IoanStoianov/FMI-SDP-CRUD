#include "pch.h"
#include "ICommand.h"

class CreateCommand: public ICommand {
public:
	CreateCommand() {};
	void execute(IRepository* db) const {
		char fname[256];
		char lname[256];
		long long fn;
		short grade;
		cin >> fn >> fname >> lname>> grade;
		char *cstr = new char[256];
		char *cstr2 = new char[256];
		strcpy(cstr, fname);
		strcpy(cstr2, lname);
	
		Student st(fn, cstr, cstr2, grade);
		delete[] cstr;
		delete[] cstr2;
		db->Create(&st);
	}
	string toString() const  {
		return "create";
	}
};