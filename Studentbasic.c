#include<stdio.h>

typedef struct{
    int roll;
    char name[20];
    char class[6];
}Student;

void addStudent()
{
    FILE *file =fopen("student.txt","ab");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.roll);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter class: ");
    scanf("%s",s.class);

    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}
int main()
{
    Student s;
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        addStudent();
        break;
    }
    return 0;
}