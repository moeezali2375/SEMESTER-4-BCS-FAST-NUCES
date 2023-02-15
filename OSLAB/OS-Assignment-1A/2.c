#include <stdio.h>
#include <string.h>
void print_student_name(char array[][100], int students)
{
    for (int i = 0; i < students * 3; i++)
    {
        printf("%s", array[i]);
    }
}
int main(int argc, char *argv[])
{
    //! Reads the file
    FILE *fp = fopen(argv[1], "r");
    char array[1024][100];
    int student_number = 0;
    while (!feof(fp))
    {
        fgets(array[student_number], sizeof(array[student_number]), fp);
        // printf("%s", array[student_number]);
        student_number++;
    }
    student_number /= 3;
    //! MENU
    printf("\nWelcome to Student Management System!\n");
    char choice;
    do
    {
        printf("Select a choice: \n");
        printf("1. Add a student! \n");
        printf("2. Read a student! \n");
        printf("3. Delete a student! \n");
        printf("4. SAVE AND EXIT! \n");
        printf("X. Exit! \n");
        scanf("%c", &choice);
        if (choice == '1')
        {
            //! READING NAME
            char name[50];
            printf("Enter student name: ");
            scanf("%s", name);
            array[student_number * 3][0] = 'N';
            array[student_number * 3][1] = 'a';
            array[student_number * 3][2] = 'm';
            array[student_number * 3][3] = 'e';
            array[student_number * 3][4] = ':';
            int k = 0;
            int i = 5;
            for (; k < strlen(name); i++, k++)
            {
                array[student_number * 3][i] = name[k];
            }
            array[student_number * 3][i] = '\n';
            array[student_number * 3][i + 1] = '\0';
            //! READING ROLL NUMBER
            char roll_number[50];
            printf("Enter student roll number: ");
            scanf("%s", roll_number);
            array[student_number * 3 + 1][0] = 'R';
            array[student_number * 3 + 1][1] = 'o';
            array[student_number * 3 + 1][2] = 'l';
            array[student_number * 3 + 1][3] = 'l';
            array[student_number * 3 + 1][4] = ' ';
            array[student_number * 3 + 1][5] = 'N';
            array[student_number * 3 + 1][6] = 'o';
            array[student_number * 3 + 1][7] = ':';
            k = 0;
            i = 8;
            for (; k < strlen(roll_number); i++, k++)
            {
                array[student_number * 3 + 1][i] = roll_number[k];
            }
            array[student_number * 3 + 1][i] = '\n';
            array[student_number * 3 + 1][i + 1] = 0;
            //! READING EMAIL
            char email[50];
            printf("Enter student email: ");
            scanf("%s", email);
            array[student_number * 3 + 2][0] = 'E';
            array[student_number * 3 + 2][1] = 'm';
            array[student_number * 3 + 2][2] = 'a';
            array[student_number * 3 + 2][3] = 'i';
            array[student_number * 3 + 2][4] = 'l';
            array[student_number * 3 + 2][5] = ':';
            k = 0;
            i = 6;
            for (; k < strlen(email); i++, k++)
            {
                array[student_number * 3 + 2][i] = email[k];
            }
            array[student_number * 3 + 2][i] = '\n';
            array[student_number * 3 + 2][i + 1] = 0;
            // HELP:Number of students increased!
            student_number++;
        }
        if (choice == '2')
        {
            printf("Total students: %d\n", student_number);
            int temp;
            printf("Enter the student number you want to read: ");
            scanf("%d", &temp);
            temp--;
            if (temp >= 0 && temp < student_number)
            {
                printf("%s", array[temp * 3]);
                printf("%s", array[temp * 3 + 1]);
                printf("%s", array[temp * 3 + 2]);
            }
            else
            {
                printf("No student in the record!\n");
            }
        }
        if (choice == '3')
        {
            printf("Total students: %d\n", student_number);
            int temp;
            printf("Enter the student number you want to delete: ");
            scanf("%d", &temp);
            temp--;
            if (temp >= 0 && temp < student_number)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = temp * 3; j < student_number * 3 - 1; j++)
                    {
                        strcpy(array[j], array[j + 1]);
                    }
                }
                student_number--;
            }
            else
            {
                printf("No student in the record!\n");
            }
        }
        if (choice == '4')
        {
            fclose(fp);
            fp = fopen(argv[1], "w");
            for (int i = 0; i < student_number*3; i++)
            {
                fputs(array[i], fp);
            }
            fclose(fp);
            choice = 'x';
        }
    } while (choice != 'x');
}