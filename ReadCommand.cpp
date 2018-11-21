#include "pch.h"
#include "ICommand.h"

class ReadCommand : public ICommand {
public:
	ReadCommand() {};
	void execute(IRepository* db) const {
		long long fn;
		cin >> fn;
		db->Read(fn);
	}
	string toString() const {
		return "sequentialSearch";
	}
};