#define MAX_LINE_LENGTH 100
#define BUF_SIZE 65536

typedef struct Employe{
    int code;
    char nom[50];
    char prenom[50];
    struct date_naiss{
        int day;
        int month;
        int year;
    }dns;
    char poste[100];
    float salaire;
}Emp;

typedef struct list
{
    Emp* head;
}Liste;