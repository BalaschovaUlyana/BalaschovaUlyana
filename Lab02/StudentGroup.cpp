#include "stdafx.h"
#include "StudentGroup.h"
#include <algorithm>
#pragma warning(disable: 4018)
using namespace std;
StudentGroup::StudentGroup()
{
	int maxStudents = 20;
}

StudentGroup::~StudentGroup()
{
}

void StudentGroup::addStudent(Student* student)
{
	///если размер списка меньше чем максимальное количество студентов в группе
	///то добавить студента в список группы
	if (StudentGroup::students.size() <= StudentGroup::maxStudents)
	{
		students.push_back(student);
		/*
		if (getStudentByFIO(student->getFIO()) == NULL)
			students.push_back(student);
		else
			cout << "Ошибка! Студента с этим ФИО уже есть в группе." << endl;
		*/
	}
	else
		cout << "----Добавление студента " << student->getFIO() << " невозможно в группе уже есть 20 студентов" << endl;
}

void StudentGroup::deleteStudent(Student* student)
{
	if (student == NULL)
	{
		cout <<"Переданный аргумент равен NULL"<< endl;
		return;
	}
	//иду в цикле до последнего элемента списка
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->equalStudent(student))
		{
			if (students[i]->type == "Член студенческого совета")
			{
				cout << "Данного студента не возможно отчислить. Он член студенческого совета" << endl;
				return;
			}
			else
			{
				cout << "________-!!!!Студент " << student->getFIO() << " был успешно удален из группы." << endl;
				students.erase(students.begin() + i);
				return;
			}
		}
	}
	cout << "Студента: " << student->getFIO() << " нет в группе." << endl;
}

void StudentGroup::changeTypeStudent(Student* student)
{
	if (student == NULL)
	{
		cout << "Переданный аргумент равен NULL" << endl;
		return;
	}
	
	//идём в цикле до последнего элемента списка
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i]->equalStudent(student))
		{
			cout <<endl<< "Текущий тип студента: " << student->type << endl;
			cout << "Введите 1 чтобы изменить его тип на Обычного студента"<<endl;
			cout << "Введите 2 чтобы изменить его тип на ботаника" << endl;
			cout << "Введите 3 чтобы изменить его тип на члена студенческого совета" << endl;
			int type = 0;
			cin >> type;
			if (type == 0)return;
			if (type == 1) {
				students[i] = new NormalStudent(student->secondName, student->firstName, student->patronymic, student->rating);
			}
			if (type == 2) {
				students[i] = new BotanistStudent(student->secondName, student->firstName, student->patronymic, student->rating);
			}
			if (type == 3) {
				students[i] = new CouncilMemberStudent(student->secondName, student->firstName, student->patronymic, student->rating);
			}
			cout << "!!!!Студент " << student->getFIO() << " был успешно изменен на другой тип." << endl<<endl;
			return;
		}
		
	}
	cout << "Студента: " << student->getFIO() << " нет в группе." << endl;
}

Student* StudentGroup::getStudentByFIO(string FIO)
{
	///переводим полученную строку с ФИО в нижний регистр
	std::transform(FIO.begin(), FIO.end(), FIO.begin(), ::tolower);
	for (int i = 0; i < students.size(); i++)
	{
		string tempFIO = students[i]->getFIO();
		///переводим ФИО текущего студента группы в нижний регистр
		std::transform(tempFIO.begin(), tempFIO.end(), tempFIO.begin(), ::tolower);
		//сравниваем их фамилии
		if (tempFIO == FIO)
		{
			///возвращаем разыменновый итератор на текущего студента
			return students[i];
		}
		
	}
	return NULL;
	//return nullptr;
}

///метод компаратора для сравнения двух фамилий в лексикографическом порядке
bool comAlphabet(Student* a, Student* b)
{
	return a->getFIO() < b->getFIO();
}

list<Student*> StudentGroup::getSortedListByAlphabet()
{
	///делаем копию списка студентов
	list<Student*> tempList = getListStudent();
	///сортируем копию  методом компаратора
	tempList.sort(comAlphabet);
	///возвращаем копию списка
	return tempList;
}


///метод компаратора для сравнения двух студентов по рейтингу
bool comRating(Student* a, Student* b)
{
	return a->getRating() < b->getRating();
}

list<Student*> StudentGroup::getSortedListByRating()
{
	list<Student*> tempList = getListStudent();
	tempList.sort(comRating);
	return tempList;
}

list<Student*> StudentGroup::getListStudent()
{
	list<Student*> tempList;
	for (int i = 0; i < students.size(); i++)
	{
		tempList.push_back(students[i]);
	}
	return tempList;
}

/// метод перегружающий стандартный вывод класса
ostream& operator<<(ostream& stream, StudentGroup& obj)
{
	cout << "!!!!!!!!Студенты группы" << endl;

	for (int i = 0; i < obj.students.size(); i++)
	{
		stream << *obj.students[i];
	}
	return stream;
}
