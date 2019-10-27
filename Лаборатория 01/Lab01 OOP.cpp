// Lab01 OOP.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "StudentGroup.h"
#include <iterator>
using namespace std;

//обявления функций
void addStudents(StudentGroup& group); //передача в функцию обьекта по ссылке
void addStudents2(StudentGroup& group);

void printList(list<Student> students);

int main()
{
	setlocale(LC_ALL, "Russian");
	//инициализация обьектов
	StudentGroup group;
	StudentGroup group2;

	addStudents(group);
	addStudents2(group2);
	cout << group << endl;

	auto student3 = group.getStudentByFIO("Крюкова Ольга Петровна");
	Student stud = (Student)*student3;
	if (student3 != NULL)
	{
		string answer = " Cтудент ";
		string answer2 = " найден в группе.";
		if (stud.getRating() == 0) { answer = ""; answer2 = ""; }
		cout << endl << "!!!Результат поиска: " << answer << stud.getFIO() << answer2 << endl << endl;

		cout << group << endl;

		group.deleteStudent(stud);
	}

	cout << "!!!!!!Отсортированный список в лексикографическом порядке" << endl;
	printList(group.getSortedListByAlphabet());


	cout << "!!!!!!!Отсортированный список по рейтингу" << endl;


	printList(group2.getSortedListByRating());
	cout << group2 << endl;

	group2.deleteStudent(stud);
	cout << group2 << endl;

	string temp;
	cin >> temp;
}

void printList(list<Student> students)
{
	cout << "!!Начало отсортированного списка!!" << endl;
	//обьявляем итератор на первый элемент списка
	auto it = students.begin();
	//идём в цикле до последнего элемента списка
	while (it != students.end())
	{
		//вызываем функцию для печати студента
		cout << *it << endl;
		it++;
	}
	cout << "!!Конец отсортированного списка!!" << endl << endl;
}

void addStudents(StudentGroup& group)
{
	Student stud( "Иванов","Александр","Александрович" );
	stud.setRating(5);
	group.addStudent(stud);

	Student stud1( "Крюкова","Ольга","Петровна" );
	stud1.setRating(4);
	group.addStudent(stud1);

	Student stud2( "Дудник","Андрей","Романович" );
	stud2.setRating(5);
	group.addStudent(stud2);
}

void addStudents2(StudentGroup& group)
{
	Student stud( "Иванов","Александр","Александрович" );
	stud.setRating(5);
	group.addStudent(stud);

	Student stud1( "Крюкова","Ольга","Петровна" );
	stud1.setRating(4);
	group.addStudent(stud1);

	Student stud2( "Дудник","Андрей","Романович" );
	stud2.setRating(5);
	group.addStudent(stud2);

}

