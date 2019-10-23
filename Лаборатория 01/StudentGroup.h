#ifndef STUDENTGROUP_H
#define STUDENTGROUP_H
#include <list>
#include <iostream>
#include "Student.h"
class StudentGroup
{
    public:
        StudentGroup();
        virtual ~StudentGroup();

        void addStudent(Student student);
        void deleteStudent(Student student);
        Student getStudentByFIO(string FIO);
        list<Student> getSortedListByAlphabet();
        list<Student> getSortedListByRating();

        //объявление дружеских функций компораторов для сравнения двух студентов
        friend bool comAlphabet(Student& a, Student& b);
        friend bool comRating(Student& a, Student& b);
        //дружеская функция перегрузки оператора вывода
        friend ostream &operator<<(ostream &stream, StudentGroup &obj);

    protected:

    private:
        list<Student> students;
        int maxStudents;
       
      
};

#endif // STUDENTGROUP_H
