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

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
    }

    virtual ~Person() {}
};

class Employee : virtual public Person
{
private:
    void setID(int in_id)
    {
        e_id = in_id;
    }

    void setSalary(int in_salary)
    {
        salary = abs(in_salary);
    }

protected:
    int e_id;
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

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Employee ID: " << e_id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual ~Employee() {}
};

class Student : virtual public Person
{
private:
    void setID(int in_id)
    {
        s_id = in_id;
    }

    void setCGPA(int in_cgpa)
    {
        cgpa = abs(in_cgpa);
    }

protected:
    int s_id;
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

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Student ID: " << s_id << endl;
        cout << "CGPA: " << cgpa << endl;
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

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "CNIC: " << cnic << endl;
        cout << "Employee ID: " << e_id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Student ID: " << s_id << endl;
        cout << "CGPA: " << cgpa << endl;
    }

    ~TeacherAssistant() {}
};

string inputName()
{
    string input;
    cout << "Enter Name >> ";
    cin >> input;

    return input;
}

int _IntegerInput(string prompt)
{
    int input;
    cout << "Enter " << prompt << " >> ";
    cin >> input;

    return input;
}

int inputCNIC()
{
    return _IntegerInput("CNIC");
}

int inputStudentID()
{
    return _IntegerInput("Student ID");
}

int inputCGPA()
{
    return _IntegerInput("CGPA");
}

int inputEmployeeID()
{
    return _IntegerInput("Employee ID");
}

int inputSalary()
{
    return _IntegerInput("Salary");
}

int main()
{
    const size_t size = 1000;
    Person *arr[size];

    size_t len = 0;

    while (len < 1000)
    {
        int option;

        cout << "Current Length of Array = " << len << endl
             << endl;

        cout << "   1. Add data" << endl;
        cout << "   2. Display data" << endl;
        cout << "   3. Exit" << endl;
        cout << "Choose an option >> ";
        cin >> option;

        if (option == 1)
        {
            int option;

            cout << "   1. Person" << endl;
            cout << "   2. Employee" << endl;
            cout << "   3. Student" << endl;
            cout << "   4. Teacher Assistant" << endl;
            cout << "Select Class >> ";
            cin >> option;

            if (option < 5 && option > 0)
            {
                if (option == 1)
                {
                    arr[len] = new Person(inputName(), inputCNIC());
                }
                else if (option == 2)
                {
                    arr[len] = new Employee(inputName(), inputCNIC(), inputEmployeeID(), inputSalary());
                }
                else if (option == 3)
                {
                    arr[len] = new Student(inputName(), inputCNIC(), inputStudentID(), inputCGPA());
                }

                else if (option == 4)
                {
                    arr[len] = new TeacherAssistant(inputName(), inputCNIC(), inputEmployeeID(), inputSalary(), inputStudentID(), inputCGPA());
                }

                len++;
            }
        }
        else if (option == 2)
        {
            cout << "Displaying all objects: " << endl
                 << endl;

            for (size_t i = 0; i < len; i++)
            {
                cout << "Object " << i + 1 << ":" << endl;

                arr[i]->display();
                cout << endl;
            }
        }
        else if (option == 3)
        {
            break;
        }
    }

    for (size_t i = 0; i < len; i++)
    {
        delete arr[i];
    }

    return 0;
}
