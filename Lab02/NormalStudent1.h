#pragma once
#include "Student.h"
using namespace std;
class NormalStudent :
	public Student
{
public:
	NormalStudent(const string& secondName, const string& firstName, const string& patronymic, const int& rating) : Student(secondName, firstName, patronymic) 
	{
		this->rating = rating;
		type = "Обычный студент";
	};
	virtual ~NormalStudent();
	void setRating(int rating);
protected:

private:
};
