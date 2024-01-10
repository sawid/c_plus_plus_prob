#include <iostream>
#include <vector>

using namespace std;
class Student
{
private:
    std::string name;
    int studentId;
    std::string classname;
public:
    Student(std::string name, int studentId, std::string classname) : name(name), studentId(studentId), classname(classname) {

    }

    string getName() {
        return name;
    }
};

class School
{
private:
    vector<Student> students;
public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    Student* getStudent(string name) {
        for (auto& student : students) {
            if (student.getName() == name)
            {
                return &student;
            }
            
        }
    }
};


int main() {
    
}