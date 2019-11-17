#pragma once
#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H
#include <list>
#include <iostream>
#include <vector>
#include "NormalStudent1.h"
#include "BotanistStudent.h"
#include "CouncilMemberStudent.h"
#include "Student.h"

class StudentGroup
{
public:
	StudentGroup();
	virtual ~StudentGroup();
	
	void addStudent(Student* student);
	void deleteStudent(Student* student);
	void changeTypeStudent(Student* student);
	
	Student* getStudentByFIO(string FIO);
	
	list<Student*> getSortedListByAlphabet();
	list<Student*> getSortedListByRating();
	
	//дружественная функция перегрузки оператора вывода
	friend ostream& operator<<(ostream& stream, StudentGroup& obj);
	vector<Student*> students;
protected:

private:
	list<Student*> getListStudent();
	int maxStudents;
};

#endif // STUDENTGROUP_H
