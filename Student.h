#pragma once

#include "pch.h"

class Student {
private:
	char* firstName;
	char* lastName;
	long long FN;
	short grade;
public:
	Student();
	Student(long long, char*, char*, short);
	Student& operator=(const Student &) = delete;
	Student(const Student &) = delete;
	char* getFirstName();
	char* getLastName();
	long long getFN();
	short getGrade();
	~Student();
/*
	friend istream & operator>>(istream &, Student &);
	friend ostream & operator<<(ostream &, Student &);*/
};


