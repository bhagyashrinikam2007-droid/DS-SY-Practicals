#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
    Employee* next; 
};

class EmployeeManagement {
private:
    Employee* head;

public:
    EmployeeManagement() {
        head = NULL;
    }

    void insertEmployee(int id, string name, string dept, double salary) {
                if (searchEmployee(id) != NULL) {
            cout << "\n[Error] Employee with ID " << id << " already exists!\n";
            return;
        }

        Employee* newEmp = new Employee();
        newEmp->id = id;
        newEmp->name = name;
        newEmp->department = dept;
        newEmp->salary = salary;
        newEmp->next = NULL;

        if (head == NULL) {
            head = newEmp;
        } else {
            Employee* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newEmp;
        }
        cout << "\nEmployee record inserted successfully!\n";
    }

    Employee* searchEmployee(int id) {
        Employee* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void deleteEmployee(int id) {
        if (head == NULL) {
            cout << "\n[Error] The list is empty!\n";
            return;
        }

        Employee* temp = head;
        Employee* prev = NULL;

        if (temp != NULL && temp->id == id) {
            head = temp->next;
            delete temp;
            cout << "\nEmployee record deleted successfully!\n";
            return;
        }

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "\n[Error] Employee Record Not Found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "\nEmployee record deleted successfully!\n";
    }

    void displayEmployees() {
        if (head == NULL) {
            cout << "\nNo employee records found.\n";
            return;
        }

        Employee* temp = head;
        cout << "\n------------------- EMPLOYEE RECORDS -------------------\n";
        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << " | Name: " << temp->name 
                 << " | Dept: " << temp->department 
                 << " | Salary: $" << temp->salary << "\n";
            temp = temp->next;
        }
        cout << "--------------------------------------------------------\n";
    }
};

int main() {
    EmployeeManagement ems;
    int choice, id;
    string name, dept;
    double salary;

    while (true) {
        cout << "\n====== Employee Management System ======\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee Record\n";
        cout << "3. Delete Employee Record\n";
        cout << "4. Display All Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id;
                cin.ignore(); 
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, dept);
                cout << "Enter Salary: ";
                cin >> salary;
                ems.insertEmployee(id, name, dept, salary);
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id;
                {
                    Employee* emp = ems.searchEmployee(id);
                    if (emp != NULL) {
                        cout << "\n--- Record Found ---\n";
                        cout << "ID: " << emp->id << "\n";
                        cout << "Name: " << emp->name << "\n";
                        cout << "Department: " << emp->department << "\n";
                        cout << "Salary: $" << emp->salary << "\n";
                    } else {
                        cout << "\n[Error] Employee Record Not Found!\n";
                    }
                }
                break;

            case 3:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                ems.deleteEmployee(id);
                break;

            case 4:
                ems.displayEmployees();
                break;

            case 5:
                cout << "\nExiting program. Goodbye!\n";
                return 0;

            default:
                cout << "\n[Invalid Choice] Please try again.\n";
        }
    }
    return 0;
}