#include <stdio.h>
#include <stdlib.h>

struct employee {
   int id;
   char name[20];
   int age;
   float salary;
};

void write_employee_details(FILE *fp) {
   struct employee emp;
   printf("Enter id: ");
   scanf("%d", &emp.id);
   printf("Enter name: ");
   scanf("%s", emp.name);
   printf("Enter age: ");
   scanf("%d", &emp.age);
   printf("Enter salary: ");
   scanf("%f", &emp.salary);

   fseek(fp, (emp.id - 1) * sizeof(struct employee), SEEK_SET);
   fwrite(&emp, sizeof(struct employee), 1, fp);
}

void read_employee_details(FILE *fp) {
   struct employee emp;
   int id;
   printf("Enter id to read details: ");
   scanf("%d", &id);

   fseek(fp, (id - 1) * sizeof(struct employee), SEEK_SET);
   fread(&emp, sizeof(struct employee), 1, fp);

   printf("\nID: %d\n", emp.id);
   printf("Name: %s\n", emp.name);
   printf("Age: %d\n", emp.age);
   printf("Salary: %.2f\n", emp.salary);
}

int main() {
   FILE *fp;
   int choice;

   fp = fopen("employee.dat", "rb+");
   if (fp == NULL) {
      fp = fopen("employee.dat", "wb");
      if (fp == NULL) {
         printf("Error opening file\n");
         exit(1);
      }
   }

   while (1) {
      printf("1. Write employee details\n");
      printf("2. Read employee details\n");
      printf("3. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            write_employee_details(fp);
            break;
         case 2:
            read_employee_details(fp);
            break;
         case 3:
            fclose(fp);
            exit(0);
         default:
            printf("Invalid choice\n");
      }
   }

   fclose(fp);
   return 0;
}
