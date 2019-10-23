#include "Stdafx.h"
#include "Student.h"
#include <iostream>
using namespace std;

//конструктор класса
Student::Student()
{
    Student::firstName = "Имя";
    Student::secondName = "Фамилия";
    Student::patronymic = "Отчество";

    Student::rating = 1;
}

Student::~Student()
{
}

void Student::setFio(string secondName, string firstName, string patronymic)
{
    Student::firstName = firstName;
    Student::secondName = secondName;
    Student::patronymic = patronymic;
}

string Student::getFIO()
{
    return Student::secondName+" "+Student::firstName+" "+Student::patronymic;
}

void Student::setRating(int raiting)
{
    Student::rating = raiting;
}

int Student::getRating()
{
    return Student::rating;
}

//метод проверки одинаковых ФИО студентов и их оценок
bool Student::equalStudent(Student student)
{
    //если ФИО текущего студента такое же как и имя переданного студента
    //и их рейтинг одинаковый возвращаем TRUE;
    if(this->getFIO() == student.getFIO()
       && this->rating == student.rating)
        return true;
    return false;
}

void Student::printStudent()
{
    cout<<Student::getFIO()<<" "<<Student::getRating()<<endl;
}

