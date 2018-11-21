#include "pch.h"
#include "IRepository.h"
#include "Student.h"

class DbRepository: public IRepository {
private:
	fstream dbFile;

public:
	 bool Create(Student* student) {
		dbFile.open("StudentsGrades.db", ios::app | ios::binary);
		
		if (!dbFile) {
			cerr << "File couldn’t be opened!\n";
			return false;
		}
		long long fn = student->getFN();
		dbFile.write((char*)&fn, sizeof(long long));
		dbFile.write(student->getFirstName(), 256);
		dbFile.write(student->getLastName(), 256);
		short grade = student->getGrade();
		dbFile.write((char*)&grade, sizeof(short));
		dbFile.close();
		cout << "Record saved!" << endl;
		return true;
	}
	virtual bool Delete(long long id) {
		return 0;
	}
	virtual void Read(long long id) {
		dbFile.open("StudentsGrades.db", ios::in | ios::binary);

		if (!dbFile) {
			cout << "File couldn’t be opened!\n";
			
		}
		dbFile.seekg(0, ios::end);
		long end = dbFile.tellg();
		dbFile.seekg(0, ios::beg);
		for (long g = 0; g < end; g = dbFile.tellg()) {
			long long temp;
			dbFile.read((char*)&temp, sizeof(long long));
			if (temp == id) {
				char fname[256];
				dbFile.read((char*)&fname, 256);
				char lname[256];
				dbFile.read((char*)&lname, 256);
				cout << temp << " " << fname << " " << lname << endl;
				dbFile.close();
				return;
			}
			else dbFile.seekp(512 + sizeof(short), ios::cur);
		}
		dbFile.close();
		cout <<"Record not found!" << endl;
	}
};
