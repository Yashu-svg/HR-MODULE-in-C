#include <stdio.h>
#include <string.h>

// Structure for Employee
struct Employee {
    int id;
    char name[50];
    int attendance;
    float baseSalary;
    float finalSalary;
    float performanceRating;
};

struct Employee emp[100];
int empCount = 0;

// Function declarations
void employeeManagement();
void attendanceManagement();
void payrollManagement();
void performanceEvaluation();
void recruitment();
void reportsAndAnalysis();
void saveChanges();

int main() {
    int choice;
    char user[20], pass[20];

    printf("\n=== HR MANAGEMENT SYSTEM ===\n");

    // Step 1: Login
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "1234") == 0) {
        printf("\nLogin Successful!\n");
    } else {
        printf("\nInvalid credentials. Exiting...\n");
        return 0;
    }

    // Step 2: Main Menu
    do {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Employee Management\n");
        printf("2. Attendance Management\n");
        printf("3. Payroll Management\n");
        printf("4. Performance Evaluation\n");
        printf("5. Recruitment\n");
        printf("6. Reports & Analysis\n");
        printf("7. Save Changes\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: employeeManagement(); break;
            case 2: attendanceManagement(); break;
            case 3: payrollManagement(); break;
            case 4: performanceEvaluation(); break;
            case 5: recruitment(); break;
            case 6: reportsAndAnalysis(); break;
            case 7: saveChanges(); break;
            case 8: printf("\nExiting system...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 8);

    printf("\nThank you for using the HR Management System.\n");
    return 0;
}

// Employee Management Module
void employeeManagement() {
    int ch;
    printf("\n--- EMPLOYEE MANAGEMENT ---\n");
    printf("1. Add Employee\n2. View Employees\n3. Delete Employee\nEnter choice: ");
    scanf("%d", &ch);

    if (ch == 1) {
        printf("Enter Employee ID: ");
        scanf("%d", &emp[empCount].id);
        printf("Enter Employee Name: ");
        scanf("%s", emp[empCount].name);
        printf("Enter Base Salary (per month): ");
        scanf("%f", &emp[empCount].baseSalary);
        emp[empCount].attendance = 0;
        emp[empCount].finalSalary = 0;
        emp[empCount].performanceRating = 0;
        empCount++;
        printf("Employee added successfully.\n");

    } else if (ch == 2) {
        printf("\n--- Employee List ---\n");
        for (int i = 0; i < empCount; i++) {
            printf("%d. %s (ID: %d, Base Salary: %.2f)\n",
                   i + 1, emp[i].name, emp[i].id, emp[i].baseSalary);
        }

    } else if (ch == 3) {
        int id, found = 0;
        printf("Enter Employee ID to delete: ");
        scanf("%d", &id);
        for (int i = 0; i < empCount; i++) {
            if (emp[i].id == id) {
                for (int j = i; j < empCount - 1; j++)
                    emp[j] = emp[j + 1];
                empCount--;
                found = 1;
                break;
            }
        }
        if (found) printf("Employee deleted.\n");
        else printf("Employee not found.\n");
    }
}

// Attendance Management
void attendanceManagement() {
    int id, found = 0, days;
    printf("\nEnter Employee ID: ");
    scanf("%d", &id);
    for (int i = 0; i < empCount; i++) {
        if (emp[i].id == id) {
            printf("Enter days present this month (out of 30): ");
            scanf("%d", &days);
            emp[i].attendance = days;
            found = 1;
            printf("Attendance updated.\n");
            break;
        }
    }
    if (!found) printf("Employee not found.\n");
}

// Payroll Management
void payrollManagement() {
    int id, found = 0;
    printf("\nEnter Employee ID for payroll: ");
    scanf("%d", &id);
    for (int i = 0; i < empCount; i++) {
        if (emp[i].id == id) {
            emp[i].finalSalary = (emp[i].attendance / 30.0) * emp[i].baseSalary;
            printf("\n--- Payroll Slip ---\n");
            printf("Employee Name: %s\n", emp[i].name);
            printf("Base Salary: %.2f\n", emp[i].baseSalary);
            printf("Attendance: %d/30 days\n", emp[i].attendance);
            printf("Final Salary: %.2f\n", emp[i].finalSalary);
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee not found.\n");
}

// Performance Evaluation
void performanceEvaluation() {
    int id, found = 0;
    printf("\nEnter Employee ID for evaluation: ");
    scanf("%d", &id);
    for (int i = 0; i < empCount; i++) {
        if (emp[i].id == id) {
            printf("Enter Performance Rating (1-5): ");
            scanf("%f", &emp[i].performanceRating);
            printf("Performance updated.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Employee not found.\n");
}

// Recruitment
void recruitment() {
    printf("\nRecruitment process started...\n");
    printf("Collecting applications, shortlisting candidates, scheduling interviews, and hiring.\n");
}

// Reports & Analysis
void reportsAndAnalysis() {
    printf("\n--- REPORTS & ANALYSIS ---\n");
    for (int i = 0; i < empCount; i++) {
        printf("ID: %d | Name: %s | Attendance: %d | Base Salary: %.2f | Final Salary: %.2f | Rating: %.1f\n",
               emp[i].id, emp[i].name, emp[i].attendance,
               emp[i].baseSalary, emp[i].finalSalary, emp[i].performanceRating);
    }
}

// Save Changes
void saveChanges() {
    printf("\nChanges saved to HR database (simulation).\n");
}