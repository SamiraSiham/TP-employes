#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employes.h"
#include "Operations.h"

int main(){
    FILE* fd; 
    // char str[100];
    fd = fopen("employees.txt","a+");
    if (fd == NULL) {
        perror("Error opening file");
        return -1;
    }
    
    int choix;
    // char subchoice;
    char nom[50];
    char prenom[50];
    int code;
    // Emp* emp;

    do{
        printf("********************************************************\n");
        printf("[1] ADD AN EMPLOYEE\n[2] SEARCH BY CODE\n[3] SEARCH BY LAST NAME\n[4] SEARCH BY FIRST NAME\n[5] DELETE AN EMPLOYEE\n[6] UPDATE EMPLOYEE\n[0] EXIT THE PROGRAM\n");
        printf("********************************************************\n");
        printf("Entrez votre choix : ");
        scanf("%d",&choix);

        // if(choix > 4 || choix < 0){
        //     printf("Choice unavailable, try again\n");
        //     // break;
        // }

        switch (choix)
        {
            case 1:
                add_employee(fd);
                break;
            case 2:
                printf("Enter employee code: ");
                scanf("%d",&code);
                show_by_code(code);
                break;
            case 3:
                printf("Enter employee last name: ");
                scanf("%s",&nom);
                show_by_nom(nom);
                // show all employees function;
                // show_all_employees();
                break;
            case 4:
                printf("Enter employee first name: ");
                scanf("%s",&prenom);
                show_by_prenom(prenom);
                // delete_employee();
                break;
            case 5:
                printf("Enter employee code: ");
                scanf("%d",&code);
                delete_employee(code);
                // delete employee function
                break;
            case 6:
                // update employee function
                printf("Enter employee code: ");
                scanf("%d",&code);
                update_employee(code);
                break;
        }
    }while(choix != 0);

    // show_single_employee(1111);
    return 0;
}