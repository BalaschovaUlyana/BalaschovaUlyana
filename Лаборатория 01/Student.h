#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;
class Student
{
    public:
        Student();
        virtual ~Student();
        void setFio(string secondName,string firstName, string patronymic);
        string getFIO();
        void setRating(int rating);
        int getRating();
        bool equalStudent(Student student);
        void printStudent();


    protected:

    private:
        string firstName;
        string secondName;
        string patronymic;

        int rating;
};

#endif // STUDENT_H
