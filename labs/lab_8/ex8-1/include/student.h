#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student {
public:
    Student(const std::string& aName="", int anId=0, double aGpa=0.0);
    std::string getName() const;
    void setName(const std::string& aName); 
    int getId() const;
    void setId(int anId);
    double getGpa() const;
    void setGpa(double aGpa);
    
private:
    std::string name;
    int id;
    double gpa;    
};
#endif // STUDENT_H