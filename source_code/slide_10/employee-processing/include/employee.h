#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class Employee {
    private:
        int employeeId;
        std::string firstName, lastName;
    public:
        Employee(int id, const std::string& first, const std::string& last);
        void setFirstName(const std::string& first);
        void setLastName(const std::string& last);
        std::string getFullName() const;
        int getEmployeeId() const;
        void setEmployeeId(int id);
        std::string getLastName() const;
        std::string getFirstName() const;
        

};
#endif // EMPLOYEE_H 