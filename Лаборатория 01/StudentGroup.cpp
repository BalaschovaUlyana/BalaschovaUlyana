#include "Stdafx.h"
#include "StudentGroup.h"
#include <algorithm>
using namespace std;
StudentGroup::StudentGroup()
{
	
}

StudentGroup::~StudentGroup()
{
}

void StudentGroup::addStudent(Student& student)
{
	///если размер списка меньше чем максимальное количество студентов в группе
	///то добавить студента в список группы
	if (StudentGroup::students.size() <= StudentGroup::maxStudents)
	{
		students.push_back(student);
	}
	else
		cout << "----Добавление студента " << student.getFIO() << " невозможно в группе уже есть 20 студентов" << endl;
}

void StudentGroup::deleteStudent(Student& student)
{
	if (&student == NULL)
	{
		cout <<"NULL"<< endl;
		return;
	}
	//обьявляю итератор на первый элемент списка
	auto it = students.begin();
	//иду в цикле до последнего элемента списка
	while (it != students.end())
	{
		//если текущий студент имеет те же ФИО и рейтинг что и переданный студент
		if (it->equalStudent(student))
		{
			///удаляю студента из списка группы
			students.erase(it);
			cout << "!!!!Студент " << student.getFIO() << " был успешно удален из группы." << endl;
			cout << endl;
			return;
		}
		it++;
	}
	cout << "Студента: " << student.getFIO() << " нет в группе." << endl;
}
Student* StudentGroup::getStudentByFIO(string FIO)
{
	///переводим полученную строку с ФИО в нижний регистр
	std::transform(FIO.begin(), FIO.end(), FIO.begin(), ::tolower);
	auto it = students.begin();
	while (it != students.end())
	{
		string tempFIO = it->getFIO();
		///переводим ФИО текущего студента группы в нижний регистр
		std::transform(tempFIO.begin(), tempFIO.end(), tempFIO.begin(), ::tolower);
		//сравниваем их фамилии
		if (tempFIO == FIO)
		{
			///возвращаем разыменновый итератор на текущего студента
			return &(*it);
		}
		it++;
	}
	
	return nullptr;
}
///метод компоратор для сравнение двух фамилий в лексикографическом порядке
bool comAlphabet(Student& a, Student& b)
{
	return a.getFIO() < b.getFIO();
}

list<Student> StudentGroup::getSortedListByAlphabet()
{
	///делаю копию списка студентов
	list<Student> tempList = students;
	///сортирую копию за методом компоратором
	tempList.sort(comAlphabet);
	///возвращаю копию списка
	return tempList;

}
///метод компоратор для сравнение двух студентов по рейтингу
bool comRating(Student& a, Student& b)
{
	return a.getRating() < b.getRating();
}

list<Student> StudentGroup::getSortedListByRating()
{
	list<Student> tempList = students;
	tempList.sort(comRating);
	return tempList;

}
/// метод перегружающий стандартный вывод класса
ostream& operator<<(ostream& stream, StudentGroup& obj)
{
	cout << "!!!!!!!!Студенты группы" << endl;
	auto it = obj.students.begin();
	while (it != obj.students.end())
	{
		stream << it->getFIO() << " " << it->getRating() << endl;
		it++;
	}
	return stream;
}

