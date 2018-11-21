#include "Student.h"


#include "pch.h"
#include "Student.h"


Student::Student(long long _FN, char* _firstName, char* _lastName, short _grade)
{
	firstName = new char[strlen(_firstName) + 1];
	strcpy(firstName, _firstName);

	lastName = new char[strlen(_lastName) + 1];
	strcpy(lastName, _lastName);
	FN = _FN;
	grade = _grade;
}
Student::Student()
{
	firstName = nullptr;
	lastName = nullptr;
	FN = 0;
	grade = 0;
}

char* Student::getFirstName() {
	return firstName;
}

char* Student::getLastName() {
	return lastName;
}

long long Student::getFN() {
	return FN;
}

short Student::getGrade() {
	return grade;
}

Student::~Student()
{
	delete[] firstName;
	delete[] lastName;
}


