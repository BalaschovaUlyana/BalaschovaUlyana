#include "stdafx.h"
#include <iostream>
#include "StudentGroup.h"
#include <iterator>
#include <vector>
using namespace std;

//обявления функций
void addStudents(StudentGroup& group); //передача в функцию обьекта по ссылке

void printList(list<Student*> students);

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Группа 1" << endl;
	StudentGroup group;
	addStudents(group);
	cout << group << endl;

	cout << "!!!!!!Отсортированный список в лексикографическом порядке" << endl;
	printList(group.getSortedListByAlphabet());
	
	cout << "!!!!!!!Отсортированный список по рейтингу" << endl;
	printList(group.getSortedListByRating());

	Student *stud = group.getStudentByFIO("Крюкова Ольга Петровна");
	if (stud != NULL)
	{
		cout << "Найденный студент" << endl;
		cout << *stud;
	}
	else
	{
		cout << "Данного ФИО нет в группе" << endl;
	}
	int type = 1;

	group.changeTypeStudent(stud,type);

	cout << group << endl;

	group.deleteStudent(stud);
	cout << group << endl;
	
	cout << endl << endl << "Группа 2" << endl;

	StudentGroup group2;
	addStudents(group2);

	cout << group2 << endl;
	

	Student *stud2 = group2.getStudentByFIO("Иванов Александр Александрович");
	if (stud2 != NULL)
	{
		cout << "Найденный студент" << endl;
		cout << *stud2;
	}
	else
	{
		cout << "Данного ФИО нет в группе" << endl;
	}

	type = 2;

	group2.changeTypeStudent(stud2,type);
	cout << group2 << endl;
	
	string temp;
	cin >> temp;
}

void printList(list<Student*> students)
{
	cout << "	!!Начало отсортированного списка!!" << endl;
	// итератор на первый элемент списка
	auto it = students.begin();
	//идём в цикле до последнего элемента списка
	while (it != students.end())
	{
		//вызываем функцию для печати студента
		cout <<"		"<< **it;
		it++;
	}
	cout << "	!!Конец отсортированного списка!!" << endl << endl;
	
}

void addStudents(StudentGroup& group)
{
	Student* stud = new BotanistStudent("Крюкова", "Ольга", "Петровна", 1);
	group.addStudent(stud);

	stud = new NormalStudent("Иванов", "Александр", "Александрович", 1);
	group.addStudent(stud);

	stud = new CouncilMemberStudent("Дудник", "Андрей", "Романович", 1);
	group.addStudent(stud);
}
