#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int roll;
    float marks;
} Student;

Student students[MAX];
int student_count = 0;

void add_student() {
    if (student_count < MAX) {
        printf("Enter name: ");
        scanf(" %[^\n]", students[student_count].name);
        printf("Enter roll number: ");
        scanf("%d", &students[student_count].roll);
        printf("Enter marks: ");
        scanf("%f", &students[student_count].marks);
        student_count++;
    } else {
        printf("Student list is full!\n");
    }
}

void view_students() {
	int i;
    printf("\nStudent Records:\n");
    for (i = 0; i < student_count; i++) {
        printf("Name: %s, Roll: %d, Marks: %.2f\n", students[i].name, students[i].roll, students[i].marks);
    }
}

void search_student() {
    int roll,i;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    for (i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            printf("Name: %s, Roll: %d, Marks: %.2f\n", students[i].name, students[i].roll, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

void delete_student() {
    int roll,i,j;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    for (i = 0; i < student_count; i++) {
        if (students[i].roll == roll) {
            for (j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student record deleted.\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student Record\n2. View All Records\n3. Search Student Record\n4. Delete Student Record\n5. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: delete_student(); break;
            case 5: exit(0); break;
            default: printf("Invalid option!\n");
        }
    }
    return 0;
}
