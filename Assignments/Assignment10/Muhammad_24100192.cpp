#include <iostream>

using namespace std;

class Student;

class Teacher
{
private:
    string name;
    int num_of_students;
    static Student *students;

protected:
public:
    Teacher(string &name)
    {
        this->name = name;
        num_of_students = 0;
        students = nullptr;
    }

    string getName()
    {
        return name;
    }
};

class Student
{
private:
    string name;
    int num_of_teachers;
    static Teacher *teachers;

protected:
public:
    Student() {}

    Student(string &name)
    {
        this->name = name;
        num_of_teachers = 0;
        teachers = nullptr;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    return 0;
}