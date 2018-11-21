#include "pch.h"
#include "ICommand.h"

class ExitCommand : public ICommand {
public:
	ExitCommand() {};
	void execute(IRepository* db) const {
		exit(0);
	}
	string toString() const {
		return "exit";
	}
};