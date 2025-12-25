#include <string>
using namespace std;
class Employee {
public:
    //task1
    //complete the public section of the class here
    Employee(const string& name, int id, double salary); //Declare constructor

    const string& getName() const;
    int getID() const;
    double getSalary() const;

    void setName(const string& name);
    void setID(int id);
    void setSalary(double salary);
private:
    //task2
    //complete the private section of the class here
    string name;
    int id;
    int salary;
};