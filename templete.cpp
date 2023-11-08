
/*
Write a C program to sort records containing roll, name, and marks 
of n students in ascending order of marks they obtained using Selection Sort.

*/

#include <stdio.h>
#include <string.h>

typedef struct Student {
    int roll;
    char name[50];
    float marks;
}stu;

void selectionSort( stu arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j].marks < arr[minIndex].marks) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            
            stu temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    stu students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1 );
        students[i].roll = i + 1;

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    selectionSort(students, n);

    printf("\nSorted list of students in ascending order of marks:\n");
    printf("Roll\tName\tMarks\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll, students[i].name, students[i].marks);
    }

    return 0;
}