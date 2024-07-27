#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

struct EmployeeDetails {
    string name;
    int age;
    string address;
    string contactNumber;
};

struct EmployeeSalary {
    int hoursWeek;
    double hourlyRate;
    double regularPay;
    double overtimePay;
    double grossPay;
    double netPay;
    double totalDeductions;
};

struct Employee {
    EmployeeDetails details;
    EmployeeSalary salary;
};

struct Deduction {
    string name;
    double amount;
    Deduction* next;
};

struct Node {
    Employee employee;
    Deduction* deductions;
    Node* next;
};

class Inventory {
public:
    Inventory() : head(nullptr) {}
    void generatePayslip();
    void inputEmployeeDetailsAndSalary();
    void displayAllEmployeeDetails();
    void deleteEmployee();
    void printMenuBox(const string& title);
    void printLoginBox(const string& title);
    void menu();
    void continueOrExit();
private:
    Node* head;
    Node* createNode(const Employee& emp);
    void appendNode(Node* newNode);
    Node* findEmployee(const string& name);
    void removeNode(Node* nodeToRemove);
    void addDeduction(Deduction*& head, const string& name, double amount);
    void printDeductions(Deduction* head);
    double calculateTotalDeductions(Deduction* head);
    void calculateDeductions(double grossSalary, double& sss, double& gsis, double& philhealth, double& savings);
};

Node* Inventory::createNode(const Employee& emp) {
    Node* newNode = new Node();
    newNode->employee = emp;
    newNode->deductions = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void Inventory::appendNode(Node* newNode) {
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* Inventory::findEmployee(const string& name) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->employee.details.name == name) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void Inventory::removeNode(Node* nodeToRemove) {
    if (head == nullptr || nodeToRemove == nullptr) {
        return;
    }
    if (head == nodeToRemove) {
        head = head->next;
        delete nodeToRemove;
        return;
    }
    Node* temp = head;
    while (temp->next != nodeToRemove) {
        temp = temp->next;
    }
    temp->next = nodeToRemove->next;
    delete nodeToRemove;
}

void Inventory::printMenuBox(const string& title) {
    cout << "\n\t\t\t==============================================\n";
    cout << "\t\t\t" << title << "\n";
    cout << "\t\t\t==============================================\n";
}

void Inventory::printLoginBox(const string& title) {
    cout << "\n\t\t\t" << title << "\n";
}

void Inventory::menu() {
    system("cls");
    int choice;
    cout << "\n\n\t\t\t==============================================\n";
    cout << "\t\t\tMenu\n";
    cout << "\t\t\t1. Employee Details and Salary \n";
    cout << "\t\t\t2. Generate Payslip\n";
    cout << "\t\t\t3. Delete Employee Data\n";
    cout << "\t\t\t4. Exit program\n";
    cout << "\t\t\t==============================================";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        inputEmployeeDetailsAndSalary();
        break;
    case 2:
        generatePayslip();
        break;
    case 3:
        deleteEmployee();
        break;
        case 4:
      system("cls");
      printLoginBox("Exiting program");
      cout << "\n\t\t\t\tTHANK YOU FOR USING HR MANAGEMENT SYSTEM !!!!!!\n"
           << endl;
      exit(0);
    default:
        cout << "\t\t\tInvalid choice. Exiting program. Goodbye!\n";
        exit(0);
    }
}

void Inventory::continueOrExit() {
    int choice;

    cout << "\n\n\t\t\tSelect your choice\n";
    cout << "\t\t\t1. Go back to menu\n";
    cout << "\t\t\t2. Exit program\n";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        menu();
        break;
    case 2:
        system("cls");
        printLoginBox("Exiting program");
        cout << "\n\t\t\t\tTHANK YOU FOR USING HR MANAGEMENT SYSTEM !!!!!!\n" << endl;
        exit(0);
    default:
        cout << "\t\t\tInvalid choice. Exiting program. Goodbye!\n";
        exit(0);
    }
}

void Inventory::inputEmployeeDetailsAndSalary() {
    system("cls");
    printMenuBox("Employee Details & Salary: ");

    Employee newEmployee;

    cout << "\t\t\tEnter the employee's name: ";
    cin >> newEmployee.details.name;

    cout << "\t\t\tEnter the employee's age: ";
    cin >> newEmployee.details.age;

    cin.ignore();

    cout << "\t\t\tEnter the employee's address: ";
    getline(cin, newEmployee.details.address);

    cout << "\t\t\tEnter the employee's contact number: ";
    getline(cin, newEmployee.details.contactNumber);

    cout << "\t\t\tEnter the employee's hours worked for the week: ";
    cin >> newEmployee.salary.hoursWeek;

    cout << "\t\t\tEnter the hourly rate of pay: ";
    cin >> newEmployee.salary.hourlyRate;

    if (newEmployee.salary.hoursWeek <= 40) {
        newEmployee.salary.regularPay = newEmployee.salary.hoursWeek * newEmployee.salary.hourlyRate;
        newEmployee.salary.overtimePay = 0.0;
    } else {
        newEmployee.salary.regularPay = 40 * newEmployee.salary.hourlyRate;
        newEmployee.salary.overtimePay = (newEmployee.salary.hoursWeek - 40) * (newEmployee.salary.hourlyRate * 1.5);
    }

    newEmployee.salary.grossPay = newEmployee.salary.regularPay + newEmployee.salary.overtimePay;

    Node* newNode = createNode(newEmployee);
    appendNode(newNode);
    cout << "\n\t\t\tEmployee data stored successfully.\n";
    cin.ignore();
    cin.get();

    int choice;

    system("cls");
    cout << "\n\n\t\t\t==============================================\n";
    cout << "\t\t\tSelect your choice\n";
    cout << "\t\t\t1. View all employee's data\n";
    cout << "\t\t\t2. Add more employee's data\n";
    cout << "\t\t\t3. Go back to menu\n";
    cout << "\t\t\t4. Exit program\n";
    cout << "\t\t\t==============================================";
    cout << "\n\t\t\tEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        displayAllEmployeeDetails();
        break;
    case 2:
        inputEmployeeDetailsAndSalary();
        break;
    case 3:
        menu();
        break;
    case 4:
        system("cls");
        printLoginBox("Exiting program");
        cout << "\n\t\t\t\tTHANK YOU FOR USING HR MANAGEMENT SYSTEM !!!!!!\n" << endl;
        exit(0);
    default:
        cout << "\t\t\tInvalid choice. Exiting program. Goodbye!\n";
        exit(0);
    }
}

void Inventory::displayAllEmployeeDetails() {
    system("cls");

    printMenuBox("Employee Details & Salary: ");

    if (head == nullptr) {
        cout << "\n\t\t\tNo employee data available.\n";
        continueOrExit();
        return;
    }

    cout << "\n\n\t\t\tAll Employee Details\n";
    cout << "\t\t\t==============================================\n";

    Node* temp = head;
    while (temp != nullptr) {
        const Employee& employee = temp->employee;
        cout << "\n\t\t\tEmployee Name:      " << employee.details.name << endl;
        cout << "\t\t\tAge:                " << employee.details.age << endl;
        cout << "\t\t\tAddress:            " << employee.details.address << endl;
        cout << "\t\t\tContact Number:     " << employee.details.contactNumber << endl;

        cout << "\n\t\t\tRegular Pay:        " << employee.salary.regularPay << endl;
        cout << "\t\t\tOvertime Pay:       " << employee.salary.overtimePay << endl;
        cout << "\t\t\tHourly Rate Pay:    " << employee.salary.hourlyRate << endl;
        cout << "\t\t\tGross Pay:          " << employee.salary.grossPay << endl;

        cout << "\t\t\t==============================================\n";

        temp = temp->next;
    }

    continueOrExit();
}

void Inventory::deleteEmployee() {
    system("cls");

    printMenuBox("Delete Employee: ");

    string searchName;
    cout << "\t\t\tEnter the name of the employee to delete: ";
    cin >> searchName;

    Node* nodeToDelete = findEmployee(searchName);
    if (nodeToDelete != nullptr) {
        removeNode(nodeToDelete);
        cout << "\n\t\t\tEmployee '" << searchName << "' has been deleted successfully.\n";
    } else {
        cout << "\n\t\t\tEmployee '" << searchName << "' not found.\n";
    }

    continueOrExit();
}

void Inventory::addDeduction(Deduction*& head, const string& name, double amount) {
    Deduction* newDeduction = new Deduction{name, amount, head};
    head = newDeduction;
}

void Inventory::printDeductions(Deduction* head) {
    Deduction* current = head;
    while (current != nullptr) {
        cout << "\t\t\t" << current->name << ": " << current->amount << endl;
        current = current->next;
    }
}

double Inventory::calculateTotalDeductions(Deduction* head) {
    double total = 0;
    Deduction* current = head;
    while (current != nullptr) {
        total += current->amount;
        current = current->next;
    }
    return total;
}

void Inventory::calculateDeductions(double grossSalary, double& sss, double& gsis, double& philhealth, double& savings) {
    sss = min(800.0, grossSalary * 0.0363);
    gsis = min(600.0, grossSalary * 0.09);
    philhealth = min(900.0, grossSalary * 0.035);
    savings = grossSalary * 0.1; // Assuming savings is 10% of gross salary
}

void Inventory::generatePayslip() {
    system("cls");

    printMenuBox("Employee Payslip: ");

    if (head == nullptr) {
        cout << "\n\t\t\tNo employee data available.\n";
        continueOrExit();
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        const Employee& employee = temp->employee;
        double sss, gsis, philhealth, savings;
        calculateDeductions(employee.salary.grossPay, sss, gsis, philhealth, savings);

        const string deductionNames[] = {"SSS Deduction", "GSIS Deduction", "PhilHealth Deduction", "Savings"};
        const double deductionAmounts[] = {sss, gsis, philhealth, savings};

        Deduction* current = temp->deductions;
        while (current != nullptr) {
            Deduction* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        temp->deductions = nullptr;

        for (int i = 0; i < 4; ++i) {
            addDeduction(temp->deductions, deductionNames[i], deductionAmounts[i]);
        }

        double totalDeductions = calculateTotalDeductions(temp->deductions);
        double netPay = employee.salary.grossPay - totalDeductions;

         temp->employee.salary.totalDeductions = totalDeductions;
        temp->employee.salary.netPay = netPay;


        cout << fixed << setprecision(2);
        cout << "\n\t\t\t==============================================\n";
        cout << "\t\t\tPayslip for: " << employee.details.name << endl;
        cout << "\t\t\t==============================================\n";
        cout << "\t\t\tEmployee Name:      " << employee.details.name << endl;
        cout << "\t\t\tAge:                " << employee.details.age << endl;
        cout << "\t\t\tAddress:            " << employee.details.address << endl;
        cout << "\t\t\tContact Number:     " << employee.details.contactNumber << endl;
        cout << "\t\t\t==============================================\n";
        cout << "\t\t\tHours Worked:       " << employee.salary.hoursWeek << endl;
        cout << "\t\t\tHourly Rate:        " << employee.salary.hourlyRate << endl;
        cout << "\t\t\tRegular Pay:        " << employee.salary.regularPay << endl;
        cout << "\t\t\tOvertime Pay:       " << employee.salary.overtimePay << endl;
        cout << "\t\t\tGross Pay:          " << employee.salary.grossPay << endl;
        printDeductions(temp->deductions);
        cout << "\t\t\t----------------------------------------------\n";
        cout << "\t\t\tTotal Deductions:   " << totalDeductions << endl;
        cout << "\t\t\tNet Pay:            " << netPay << endl;
        cout << "\t\t\t==============================================\n";

        temp = temp->next;
    }

    continueOrExit();
}
bool log_in()
{
    string username, password, fileUsername, filePassword;
    bool loggedIn = false;

    system("cls");
    cout << "\n\n\t\t\t==============================================\n";
    cout << "\t\t\tLog in to your account: \n";
    cout << "\t\t\tUsername: ";
    cin >> username;
    cout << "\t\t\tPassword: ";
    cin >> password;
    cout << "\t\t\t==============================================";

    ifstream f1("records.txt");
    while (f1 >> fileUsername >> filePassword)
    {
        if (fileUsername == username && filePassword == password)
        {
            loggedIn = true;
            break;
        }
    }
    f1.close ();

    if (loggedIn)
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tLogin successfull! \n";
        return true;
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tInvalid username or password. Please try again. \n";
        cout << "\t\t\t==============================================\n";
        cin.ignore();
        cin.get();
        return false;
    }

}
void sign_up()
{
   string username, password;

   while (true)
   {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tCreate username and password: \n";
        cout << "\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\tPassword: ";
        cin >> password;
        cout << "\t\t\t==============================================";

        if (username.length() >= 8 && password.length() >= 8)
        {
            ofstream f1 ("records.txt", ios::app);
            f1 << username << " "<< password << endl;
            f1.close();

            system("cls");
            cout << "\n\n\t\t\t==============================================\n";
            cout << "\t\t\tRegistration successfull!\n";
            cout << "\t\t\tGoing back to main menu now. . .\n";
            cout << "\t\t\t==============================================";
            cin.ignore();
            cin.get();
            return;
        }
        else
        {
            cout << "\n\t\t\tUsername and password must be at least 8 characters long. Please try again. ";
            cin.ignore();
            cin.get();
        }
   }
}

int main()
{
    while (true) 
    {
        system("cls");
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\t\tHR MANAGEMENT OPERATION SYSTEM " << endl;
        cout << "\t\t\t==============================================\n";
        cout << "\t\t\tPress any key to continue.";
        cin.get();
        system("cls");

        int choice;
        cout << "\n\n\t\t\t==============================================\n";
        cout << "\t\t\tMENU: \n";
        cout << "\t\t\t1. Sign up\n";
        cout << "\t\t\t2. Log in\n";
        cout << "\t\t\t3. Exit\n";
        cout << "\t\t\t==============================================";
        cout << "\n\n\n\t\t\tEnter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) 
        {
            case 1: 
                sign_up();
                break;

            case 2:
                if (log_in()) 
                {
                    string choice;
                    cout << "\t\t\tYou are now logged in." << endl;
                    cout << "\t\t\t==============================================\n";
                    cout << "\t\t\tDo you want to continue? \n";
                    cout << "\t\t\tYes\n";
                    cout << "\t\t\tNo\n";
                    cout << "\t\t\tEnter your choice (Yes/No): ";
                    cin >> choice;

                    if (choice == "Yes" || choice == "YES") 
                    {
                        Inventory inv;
                        inv.inputEmployeeDetailsAndSalary();
                    } else if (choice == "No" || choice == "NO") 
                    {
                        cout << "\t\t\tI understand, redirecting you now back to the main menu...";
                        cin.get();
                    } else {
                        cout << "\t\t\tInvalid choice. Returning to the main menu...";
                        cin.get();
                    }
                }
                break;

            case 3:
                cout << "\t\t\tExiting program...";
                cin.get();
                return 0;
            
            default:
                system("cls");
                cout << "\t\t\tPlease select from the options given above.\n" << endl;
                cin.get(); 
                break;
        }
    }
}
