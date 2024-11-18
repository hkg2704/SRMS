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
void searchStudent()
{
    FILE *file =fopen("student.txt","rb");
    if(file==NULL)
    {
        printf("No files Found");
        return;
    }
    int id;
    printf("Enter Student ROLL.no to search: ");
    scanf("%d", &id);

    Student s;
    int found=0;
    
    while(fread(&s,sizeof(Student),1,file))
    {if(s.roll==id){
        printf("ROLL\tNAME\tCLASS\n");
        printf("%d\t%s\t%s\n",s.roll,s.name,s.class);
        found=1;
        break;
    }
    }
    if(found==0)
    {
        printf("Student not found");
    }
    fclose(file);
    
    
}
void displayStudent()
{
    FILE *file =fopen("student.txt","rb");
    if(file==NULL)
    {
        printf("No files Found");
        return;
    }
    Student s;
    printf("ROLL\tNAME\tCLASS\n");
    while(fread(&s,sizeof(Student),1,file))
    {
        printf("%d\t%s\t%s\n",s.roll,s.name,s.class);
    }
    fclose(file);
}
void updateStudent()
{
    FILE *file =fopen("student.txt","rb");
    if(file==NULL)
    {
        printf("No files Found");
        return;
    }
    int id;
    printf("Enter Student ROLL.no to search: ");
    scanf("%d", &id);

    Student s;
    int found=0;
    
    while(fread(&s,sizeof(Student),1,file))
    {
        if(s.roll==id){
            printf("Enter new age: ");
            scanf("%d", &s.roll);
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);
            printf("Enter new marks: ");
            scanf("%s", &s.class);

            fseek(file,-sizeof(Student),SEEK_CUR);
            fwrite(&s,sizeof(Student),1,file);
            printf("Student Details Updated\n");
            found=1;
            break;
            
    }
    }
    if(found==0)
    {
        printf("Student not found");
    }
    fclose(file);
}
void deleteStudent()
{
    
}
int main() {
    int choice;

    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Display All Students\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}