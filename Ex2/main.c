#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    char name[50];
    int age;
    float salary;
} employee_t;

void emp_info(employee_t emp) {
    printf("Name: %s, Age: %d, Salary: %.2f\n", emp.name, emp.age, emp.salary);
}

int emp_aveage_age(employee_t emp[], int n) {
    int total_age = 0;
    for (int i = 0; i < n; i++) {
        total_age += emp[i].age;
    }
    return n > 0 ? total_age / n : 0;
}


void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "wb");
    if (!fp) {
        perror("Failed to open file for writing");
        return;
    }
    fwrite(emp, sizeof(employee_t), n, fp);
    fclose(fp);
    printf("Data written to employee.bin successfully.\n");
}

void emp_readfile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "rb");
    if (!fp) {
        perror("Failed to open file for reading");
        return;
    }
    fread(emp, sizeof(employee_t), n, fp);
    fclose(fp);
    printf("Data read from employee.bin successfully.\n");
}

int main() {
    int n = 3;
    employee_t employees[3] = {
        {"Alice", 30, 50000.0},
        {"Bob", 25, 45000.0},
        {"Charlie", 28, 48000.0}
    };

    printf("Original employee data:\n");
    for (int i = 0; i < n; i++) {
        emp_info(employees[i]);
    }

    emp_writefile(employees, n);

    memset(employees, 0, sizeof(employees));

    emp_readfile(employees, n);

    printf("\nEmployee data read from file:\n");
    for (int i = 0; i < n; i++) {
        emp_info(employees[i]);
    }

    int avg_age = emp_aveage_age(employees, n);
    printf("\nAverage age of employees: %d\n", avg_age);

    return 0;
}
