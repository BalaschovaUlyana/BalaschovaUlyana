// Lab01 OOP.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "StudentGroup.h"
#include <iterator>
using namespace std;

//обявления функций
void addStudents(StudentGroup &group); //передача в функцию обьекта по ссылке
void addStudents2(StudentGroup &group);

void printList(list<Student> students);

int main()
{
    setlocale(LC_ALL, "Russian");
    //инициализация обьектов
    StudentGroup group;
    StudentGroup group2;

    addStudents(group);
    addStudents2(group2);

    Student student3 = group.getStudentByFIO("Исакова Юлия Павловна");
    string answer = " Cтудент ";
    string answer2 = " найден в группе.";
    if(student3.getRating()==0){answer="";answer2="";}
    cout<<endl<<"!!!Результат поиска: "<<answer<<student3.getFIO()<<answer2<<endl<<endl;

    cout << group << endl;

    group.deleteStudent(student3);

    cout<<"!!!!!!Отсортированный список в лексикографическом порядке"<<endl;
    printList(group.getSortedListByAlphabet());


    cout<<"!!!!!!!Отсортированный список по рейтингу"<<endl;
    printList(group2.getSortedListByRating());

    cout << group2 << endl;

    group2.deleteStudent(student3);
    cout << group2 << endl;

    string temp;
    cin>>temp;
}

void printList(list<Student> students)
{
    cout<<"!!Начало отсортированного списка!!"<<endl;
    //обьявляем итератор на первый элемент списка
    auto it = students.begin();
    //идём в цикле до последнего элемента списка
    while(it!=students.end())
    {
        //вызываем функцию для печати студента
        it->printStudent();
        it++;
    }
    cout<<"!!Конец отсортированного списка!!"<<endl<<endl;
}

void addStudents(StudentGroup& group)
{
    Student stud;
    stud.setFio("Иванов","Александр","Александрович"); stud.setRating(5);
    group.addStudent(stud);
    Student stud1;
    stud1.setFio("Крюкова","Ольга","Петровна"); stud1.setRating(4);
    group.addStudent(stud1);
    Student stud2;
    stud2.setFio("Дудник","Андрей","Романович"); stud2.setRating(5);
    group.addStudent(stud2);
    Student stud3;
    stud3.setFio("Медведев","Дмитрий","Алексеевич"); stud3.setRating(4);
    group.addStudent(stud3);
    Student stud4;
    stud4.setFio("Тараканов","Борис","Давидович"); stud4.setRating(3);
    group.addStudent(stud4);
    Student stud5;
    stud5.setFio("Багдасарян","Рафаэль","Макарович"); stud5.setRating(3);
    group.addStudent(stud5);
    Student stud6;
    stud6.setFio("Васильев","Михаил","Петрович"); stud6.setRating(2);
    group.addStudent(stud6);
    Student stud7;
    stud7.setFio("Горбунов","Арсений","Альбертович"); stud7.setRating(3);
    group.addStudent(stud7);
    Student stud8;
    stud8.setFio("Воронцов","Георгий","Максимович"); stud8.setRating(4);
    group.addStudent(stud8);
    Student stud9;
    stud9.setFio("Архипов","Гавриил","Русланович"); stud9.setRating(5);
    group.addStudent(stud9);
    Student stud10;
    stud10.setFio("Панов","Евгений","Владиславович"); stud10.setRating(5);
    group.addStudent(stud10);
    Student stud11;
    stud11.setFio("Петров","Фёдор","Вениаминович"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("Рогов","Харитон","Романович"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("Игнатьев","Юрий","Филатович"); stud11.setRating(3);
    group.addStudent(stud11);
    stud11.setFio("Быкова","Анна","Семёновна"); stud11.setRating(4);
    group.addStudent(stud11);
    stud11.setFio("Большакова","Ксения","Валерьяновна"); stud11.setRating(5);
    group.addStudent(stud11);
    stud11.setFio("Исакова","Юлия","Павловна"); stud11.setRating(1);
    group.addStudent(stud11);
    stud11.setFio("Молчанова","Ирина","Викторовна"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("Юдина","Кристина","Юрьевна"); stud11.setRating(3);
    group.addStudent(stud11);
    stud11.setFio("Некрасова","Лиза","Владимировна"); stud11.setRating(4);
    group.addStudent(stud11);
    stud11.setFio("Одинцова","Диана","Всеволодовна"); stud11.setRating(5);
    group.addStudent(stud11);
    stud11.setFio("Исакова","Екатерина","Георгьевна"); stud11.setRating(2);
    group.addStudent(stud11);
}

void addStudents2(StudentGroup& group)
{
    Student stud;
    stud.setFio("Иванов","Александр","Александрович"); stud.setRating(5);
    group.addStudent(stud);

    Student stud1;
    stud1.setFio("Крюкова","Ольга","Петровна"); stud1.setRating(4);
    group.addStudent(stud1);

    Student stud2;
    stud2.setFio("Дудник","Андрей","Романович"); stud2.setRating(5);
    group.addStudent(stud2);

    Student stud3;
    stud3.setFio("Медведев","Дмитрий","Алексеевич"); stud3.setRating(4);
    group.addStudent(stud3);

    Student stud4;
    stud4.setFio("Тараканов","Борис","Давидович"); stud4.setRating(3);
    group.addStudent(stud4);

    Student stud11;
    stud11.setFio("Исакова","Юлия","Павловна"); stud11.setRating(1);
    group.addStudent(stud11);
}

