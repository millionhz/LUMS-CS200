#include <iostream>

using namespace std;

class Person
{
private:
    void setName(string in_name)
    {
        name = in_name;
    }

    void setCNIC(int in_cnic)
    {
        cnic = in_cnic;
    }

protected:
    string name;
    int cnic;

public:
    Person()
    {
        setName("");
        setCNIC(0);
    }

    Person(string name, int cnic)
    {
        setName(name);
        setCNIC(cnic);
    }

    string getName()
    {
        return name;
    }

    int getCNIC()
    {
        return cnic;
    }

    virtual ~Person() {}
};

class Employee : virtual public Person
{
private:
    void setID(int in_id)
    {
        id = in_id;
    }

    void setSalary(int in_salary)
    {
        salary = abs(in_salary);
    }

protected:
    int id;
    int salary;

    Employee(int id, int salary)
    {
        setID(id);
        setSalary(salary);
    }

public:
    Employee()
    {
        setID(0);
        setSalary(0);
    }

    Employee(string name, int cnic, int id, int salary)
        : Person(name, cnic)
    {
        setID(id);
        setSalary(salary);
    }

    int getEmployeeID()
    {
        return id;
    }

    int getSalary()
    {
        return salary;
    }

    virtual ~Employee() {}
};

class Student : virtual public Person
{
private:
    void setID(int in_id)
    {
        id = in_id;
    }

    void setCGPA(int in_cgpa)
    {
        cgpa = abs(in_cgpa);
    }

protected:
    int id;
    int cgpa;

    Student(int id, int cgpa)
    {
        setID(id);
        setCGPA(cgpa);
    }

public:
    Student()
    {
        setID(0);
        setCGPA(0);
    }

    Student(string name, int cnic, int id, int cgpa)
        : Person(name, cnic)
    {
        setID(id);
        setCGPA(cgpa);
    }

    int getStudentID()
    {
        return id;
    }

    int getCGPA()
    {
        return cgpa;
    }

    virtual ~Student() {}
};

class TeacherAssistant : public Employee, public Student
{
private:
protected:
public:
    TeacherAssistant() {}

    TeacherAssistant(string name, int cnic, int e_id, int salary, int s_id, int cgpa)
        : Person(name, cnic), Employee(e_id, salary), Student(s_id, cgpa)
    {
    }

    ~TeacherAssistant() {}
};

int main()
{

    TeacherAssistant s;
    return 0;
}