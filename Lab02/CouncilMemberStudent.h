#pragma once
#include "Student.h"
class CouncilMemberStudent :
	public Student
{
public:
	CouncilMemberStudent(const string& secondName, const string& firstName, const string& patronymic, const int& rating) : Student(secondName, firstName, patronymic)
	{
		setRating(rating);
		type = "Член студенческого совета";
	}
	virtual ~CouncilMemberStudent() {}
	void setRating(int rating)
	{
		Student::rating = rating;
		if (rating < 3)
		{
			Student::rating = 3;
		}
	}
};
