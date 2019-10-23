// Lab01 OOP.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "StudentGroup.h"
#include <iterator>
using namespace std;

//��������� �������
void addStudents(StudentGroup &group); //�������� � ������� ������� �� ������
void addStudents2(StudentGroup &group);

void printList(list<Student> students);

int main()
{
    setlocale(LC_ALL, "Russian");
    //������������� ��������
    StudentGroup group;
    StudentGroup group2;

    addStudents(group);
    addStudents2(group2);

    Student student3 = group.getStudentByFIO("������� ���� ��������");
    string answer = " C������ ";
    string answer2 = " ������ � ������.";
    if(student3.getRating()==0){answer="";answer2="";}
    cout<<endl<<"!!!��������� ������: "<<answer<<student3.getFIO()<<answer2<<endl<<endl;

    cout << group << endl;

    group.deleteStudent(student3);

    cout<<"!!!!!!��������������� ������ � ������������������ �������"<<endl;
    printList(group.getSortedListByAlphabet());


    cout<<"!!!!!!!��������������� ������ �� ��������"<<endl;
    printList(group2.getSortedListByRating());

    cout << group2 << endl;

    group2.deleteStudent(student3);
    cout << group2 << endl;

    string temp;
    cin>>temp;
}

void printList(list<Student> students)
{
    cout<<"!!������ ���������������� ������!!"<<endl;
    //��������� �������� �� ������ ������� ������
    auto it = students.begin();
    //��� � ����� �� ���������� �������� ������
    while(it!=students.end())
    {
        //�������� ������� ��� ������ ��������
        it->printStudent();
        it++;
    }
    cout<<"!!����� ���������������� ������!!"<<endl<<endl;
}

void addStudents(StudentGroup& group)
{
    Student stud;
    stud.setFio("������","���������","�������������"); stud.setRating(5);
    group.addStudent(stud);
    Student stud1;
    stud1.setFio("�������","�����","��������"); stud1.setRating(4);
    group.addStudent(stud1);
    Student stud2;
    stud2.setFio("������","������","���������"); stud2.setRating(5);
    group.addStudent(stud2);
    Student stud3;
    stud3.setFio("��������","�������","����������"); stud3.setRating(4);
    group.addStudent(stud3);
    Student stud4;
    stud4.setFio("���������","�����","���������"); stud4.setRating(3);
    group.addStudent(stud4);
    Student stud5;
    stud5.setFio("����������","�������","���������"); stud5.setRating(3);
    group.addStudent(stud5);
    Student stud6;
    stud6.setFio("��������","������","��������"); stud6.setRating(2);
    group.addStudent(stud6);
    Student stud7;
    stud7.setFio("��������","�������","�����������"); stud7.setRating(3);
    group.addStudent(stud7);
    Student stud8;
    stud8.setFio("��������","�������","����������"); stud8.setRating(4);
    group.addStudent(stud8);
    Student stud9;
    stud9.setFio("�������","�������","����������"); stud9.setRating(5);
    group.addStudent(stud9);
    Student stud10;
    stud10.setFio("�����","�������","�������������"); stud10.setRating(5);
    group.addStudent(stud10);
    Student stud11;
    stud11.setFio("������","Ը���","������������"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("�����","�������","���������"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("��������","����","���������"); stud11.setRating(3);
    group.addStudent(stud11);
    stud11.setFio("������","����","��������"); stud11.setRating(4);
    group.addStudent(stud11);
    stud11.setFio("����������","������","������������"); stud11.setRating(5);
    group.addStudent(stud11);
    stud11.setFio("�������","����","��������"); stud11.setRating(1);
    group.addStudent(stud11);
    stud11.setFio("���������","�����","����������"); stud11.setRating(2);
    group.addStudent(stud11);
    stud11.setFio("�����","��������","�������"); stud11.setRating(3);
    group.addStudent(stud11);
    stud11.setFio("���������","����","������������"); stud11.setRating(4);
    group.addStudent(stud11);
    stud11.setFio("��������","�����","������������"); stud11.setRating(5);
    group.addStudent(stud11);
    stud11.setFio("�������","���������","����������"); stud11.setRating(2);
    group.addStudent(stud11);
}

void addStudents2(StudentGroup& group)
{
    Student stud;
    stud.setFio("������","���������","�������������"); stud.setRating(5);
    group.addStudent(stud);

    Student stud1;
    stud1.setFio("�������","�����","��������"); stud1.setRating(4);
    group.addStudent(stud1);

    Student stud2;
    stud2.setFio("������","������","���������"); stud2.setRating(5);
    group.addStudent(stud2);

    Student stud3;
    stud3.setFio("��������","�������","����������"); stud3.setRating(4);
    group.addStudent(stud3);

    Student stud4;
    stud4.setFio("���������","�����","���������"); stud4.setRating(3);
    group.addStudent(stud4);

    Student stud11;
    stud11.setFio("�������","����","��������"); stud11.setRating(1);
    group.addStudent(stud11);
}
