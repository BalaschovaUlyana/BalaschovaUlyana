#pragma once
#include "Student.h"
class BotanistStudent :
	public Student
{
public:
	BotanistStudent(const string& secondName, const string& firstName, const string& patronymic, const int& rating) : Student(secondName, firstName, patronymic)
	{
		setRating(rating);
		type = "Ботаник";
	}
	virtual ~BotanistStudent() {}
	void setRating(int rating)
	{
		Student::rating = rating;
		if (rating < 4)
		{
			srand(time(0));
			Student::rating = 4 + rand() % 2;
		}
	}
};
