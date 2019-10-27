#pragma once
#include<string>
using namespace std;
class Student
{
public:
	Student(const string& secondName, const string& firstName, const string& patronymic);
	virtual ~Student();
	string getFIO();
	void setRating(int rating);
	int getRating();
	bool equalStudent(Student& student);
	friend ostream& operator<<(ostream& stream, Student& obj);


protected:

private:
	string firstName;
	string secondName;
	string patronymic;

	int rating;
};
