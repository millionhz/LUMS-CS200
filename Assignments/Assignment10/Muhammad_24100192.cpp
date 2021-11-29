#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Student;

class Teacher
{
private:
    string name;
    int num_of_students;
    Student *students[100];

protected:
public:
    Teacher();
    Teacher(string);
    string getName();
    void addStudnet(Student *);
    void print();
};

class Student
{
private:
    string name;
    int num_of_teachers;
    Teacher *teachers[100];

protected:
public:
    Student();
    Student(string);
    string getName();
    void addTeacher(Teacher *);
    void print();
};

/***************/

Teacher::Teacher() {}

Teacher::Teacher(string name)
{
    this->name = name;
    num_of_students = 0;
}

string Teacher::getName()
{
    return name;
}

void Teacher::addStudnet(Student *new_student)
{
    students[num_of_students] = new_student;
    num_of_students++;
}

void Teacher::print()
{
    for (int i = 0; i < num_of_students; i++)
    {
        cout << "Teacher " << name << " teaches student " << students[i]->getName() << endl;
    }
}

/***************/

Student::Student() {}

Student::Student(string name)
{
    this->name = name;
    num_of_teachers = 0;
}

string Student::getName()
{
    return name;
}

void Student::addTeacher(Teacher *new_teacher)
{
    teachers[num_of_teachers] = new_teacher;
    num_of_teachers++;

    new_teacher->addStudnet(this);
}

void Student::print()
{
    for (int i = 0; i < num_of_teachers; i++)
    {
        cout << "Student " << name << " is taught by teacher " << teachers[i]->getName() << endl;
    }
}

/***************/

int main()
{
    const int num_of_teachers = 5;
    Teacher *teachers = new Teacher[num_of_teachers];
    string teacher_names[num_of_teachers] = {
        "Nouman",
        "Umer",
        "Imdaad",
        "Arshad",
        "Ata",
    };

    const int num_of_students = 10;
    Student *students = new Student[num_of_students];
    string student_names[num_of_students] = {
        "Hamza",
        "Potato",
        "Maaz",
        "Moiz",
        "Humaira",
        "Haneen",
        "Ayesha",
        "Imaan",
        "Sarim",
        "Usman",
    };

    for (int i = 0; i < num_of_teachers; i++)
    {
        teachers[i] = Teacher(teacher_names[i]);
    }

    const int size = 5;
    int arr[size] = {0, 1, 2, 3, 4};

    for (int i = 0; i < num_of_students; i++)
    {
        students[i] = Student(student_names[i]);

        srand(time(0));
        random_shuffle(arr, arr + size);

        for (int j = 0; j < 3; j++)
        {
            students[i].addTeacher(&teachers[arr[j]]);
        }
    }

    cout << "Calling print on Teachers: " << endl
         << endl;
    for (int i = 0; i < num_of_teachers; i++)
    {
        teachers[i].print();
        cout << endl;
    }

    cout << "Calling print on Students: " << endl
         << endl;

    for (int i = 0; i < num_of_students; i++)
    {
        students[i].print();
        cout << endl;
    }

    delete[] students;
    delete[] teachers;

    return 0;
}