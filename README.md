<h1>HR Management Operation System
<h2> Overview

<h3>This program is designed to manage employee details and payroll operations efficiently, providing a user-friendly interface for HR administrators to handle various tasks related to employee management. The key features and functionalities of the system are as follows:

### Features:

1. **User Authentication**:
   - **Sign Up**: New users can create an account by providing a username and password, ensuring secure access to the system. Both the username and password must be at least 8 characters long.
   - **Log In**: Existing users can log in to the system using their credentials. The program verifies the username and password against stored records for authentication.

2. **Main Menu**:
   - Once logged in, users are presented with a main menu that offers various options:
     - **Employee Details and Salary**: Users can input and store detailed information about employees, including personal details and salary information.
     - **Generate Payslip**: The system can generate detailed payslips for employees, including deductions and net pay calculations.
     - **Delete Employee Data**: Users can delete an employee's data from the system.
     - **Exit Program**: Users can exit the application.

3. **Employee Management**:
   - **Input Employee Details and Salary**: Users can enter an employee's name, age, address, contact number, hours worked in a week, and hourly rate. The system calculates the regular pay, overtime pay, and gross pay based on the input.
   - **Store Employee Data**: The entered employee data is stored in a linked list, enabling efficient management and retrieval of employee information.

4. **Payroll Calculation**:
   - The system calculates standard deductions such as SSS, GSIS, PhilHealth, and savings based on the gross salary. These deductions are calculated using predefined percentages and limits.
   - **Generate Payslip**: For each employee, the system generates a payslip that includes detailed information about the employee, gross pay, deductions, and net pay. The payslip is printed in a formatted manner for easy readability.

5. **Delete Employee Data**:
   - Users can search for an employee by name and delete their data from the system. The system updates the linked list accordingly.

6. **Navigation and User Interaction**:
   - The system features a menu-driven interface that guides users through various options and tasks. After completing an operation, users are prompted to either return to the main menu or exit the program, ensuring smooth navigation.

### Implementation Details:

- **Data Structures**:
  - The system uses several structs to organize employee data:
    - `EmployeeDetails`: Stores personal details such as name, age, address, and contact number.
    - `EmployeeSalary`: Stores salary details such as hours worked, hourly rate, regular pay, overtime pay, gross pay, net pay, and total deductions.
    - `Employee`: Combines `EmployeeDetails` and `EmployeeSalary` into a single struct.
    - `Deduction`: Stores information about a specific deduction and is used to create a linked list of deductions.
    - `Node`: Represents an employee node in the linked list, containing an `Employee` and a pointer to the next node.

- **Class `Inventory`**:
  - Manages the linked list of employees and provides various methods to handle employee data, including adding new employees, generating payslips, deleting employees, and calculating deductions.

- **User Interface**:
  - The system uses `cout` for printing messages and menus to the console and `cin` for taking user input. The interface is designed to be intuitive and straightforward, guiding users through each step of the process.

### Conclusion:

The HR Management Operation System is a comprehensive tool for managing employee details and payroll. It combines secure user authentication, efficient data storage using linked lists, detailed payroll calculation, and a user-friendly interface to provide a seamless experience for HR administrators. This system streamlines the process of managing employee data and generating payslips, making HR tasks more efficient and organized.


