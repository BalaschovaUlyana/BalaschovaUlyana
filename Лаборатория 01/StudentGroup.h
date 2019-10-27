#pragma once
#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H
#include <list>
#include <iostream>
#include "Student.h"
class StudentGroup
{
public:
	StudentGroup();
	virtual ~StudentGroup();
	void addStudent(Student& student);
	void deleteStudent(Student& student);
	Student* getStudentByFIO(string FIO);
	list<Student> getSortedListByAlphabet();
	list<Student> getSortedListByRating();
	//дружественная функция перегрузки оператора вывода
	friend ostream& operator<<(ostream& stream, StudentGroup& obj);

protected:

private:
	list<Student> students;
	int maxStudents;
};

#endif // STUDENTGROUP_H
