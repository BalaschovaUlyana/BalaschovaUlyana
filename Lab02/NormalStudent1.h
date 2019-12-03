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
	};
	virtual ~NormalStudent();
	void setRating(int rating);
	string getType() { return "Обычный студент"; }
protected:

private:
}; 


