#include "Stdafx.h"
#include "StudentGroup.h"
#include "Student.h"
#include <algorithm>
using namespace std;
StudentGroup::StudentGroup()
{
	maxStudents = 20;
}

StudentGroup::~StudentGroup()
{
}

void StudentGroup::addStudent(Student student)
{
	 
    ///���� ������ ������ ������ ��� ������������ ���������� ��������� � ������
    ///�� �������� �������� � ������ ������
    if(StudentGroup::students.size()<=StudentGroup::maxStudents)
    {
        students.push_back(student);
    }
    else
        cout<<"----���������� �������� "<<student.getFIO()<<" ���������� � ������ ��� ���� 20 ���������"<<endl;
}

void StudentGroup::deleteStudent(Student student)
{
    //��������� �������� �� ������ ������� ������
    auto it = students.begin();
    //��� � ����� �� ���������� �������� ������
    while(it!=students.end())
    {
        //���� ������� ������� ����� �� �� ��� � ������� ��� � ���������� �������
        if(it->equalStudent(student))
        {
            ///������� �������� �� ������ ������
            students.erase(it);
            std::cout<<"!!!!������� "<<student.getFIO()<<" ��� ������� ������ �� ������."<<endl;
            cout<<endl;
            return;
        }
        it++;
    }
    cout<<"��������: "<<student.getFIO()<<" ��� � ������."<<endl;
}
Student StudentGroup::getStudentByFIO(string FIO)
{
    ///��������� ���������� ������ � ��� � ������ �������
    std::transform(FIO.begin(), FIO.end(), FIO.begin(), ::tolower);
    auto it = students.begin();
    while(it!=students.end())
    {
        string tempFIO = it->getFIO();
        ///��������� ��� �������� �������� ������ � ������ �������
        std::transform(tempFIO.begin(), tempFIO.end(), tempFIO.begin(), ::tolower);
        //���������� �� �������
        if(tempFIO==FIO)
        {
            ///���������� ������������ �������� �� �������� ��������
            return *it;
        }
        it++;
    }
    Student studentNull;
    studentNull.setFio("�������","�������� ��� �","������.");
    studentNull.setRating(0);
    return studentNull;
}
///����� ���������� ��� ��������� ���� ������� � ������������������ �������
bool comAlphabet(Student& a, Student& b)
{
    return a.getFIO()<b.getFIO();
}

list<Student> StudentGroup::getSortedListByAlphabet()
{
	
    ///������ ����� ������ ���������
    list<Student> tempList = students;
    ///��������� ����� �� ������� ������������
    tempList.sort(comAlphabet);
    ///���������� ����� ������
    return tempList;

}
///����� ���������� ��� ��������� ���� ��������� �� ��������
bool comRating(Student& a, Student& b)
{
    return a.getRating()<b.getRating();
}

list<Student> StudentGroup::getSortedListByRating()
{
    list<Student> tempList = students;
    tempList.sort(comRating);
    return tempList;

}
/// ����� ������������� ����������� ����� ������
ostream &operator<<(ostream &stream, StudentGroup &obj)
{
    cout<<"!!!!!!!!�������� ������"<<endl;
    auto it = obj.students.begin();
    while(it!=obj.students.end())
    {
        stream<<it->getFIO()<<" "<<it->getRating()<<endl;
        it++;
    }
    return stream;
}
