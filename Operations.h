int count_lines(FILE* file)
{
    char buf[BUF_SIZE];
    int counter = 0;
    for(;;)
    {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        int i;
        for(i = 0; i < res; i++)
            if (buf[i] == '\n')
                counter++;

        if (feof(file))
            break;
    }

    return counter;
}

int verifyCode(int codeEmp){
    Emp* emp;
    char line[100];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return 1;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste) == 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(emp[i].code == codeEmp){
            
            return 1;
        }
    }
    return 0;
}

void add_employee(FILE* fd){
    Emp* emp;

    int i;

    emp = (Emp*)calloc(1, sizeof(Emp));

    printf("Code : ");
    scanf("%d", &emp[i].code);
    
    if(verifyCode(emp[i].code) == 1){
        printf("This code already exists\n");
        return;
    }

    printf("Nom : ");
    scanf("%s", &emp[i].nom);

    printf("Prenom : ");
    scanf("%s", &emp[i].prenom);

    printf("Date de naissance\n");
    printf("Jour : ");
    scanf("%d", &emp[i].dns.day);
    
    printf("Mois : ");
    scanf("%d", &emp[i].dns.month);
    
    printf("Annee : ");
    scanf("%d", &emp[i].dns.year);
    
    printf("Poste : ");
    scanf("%s", &emp[i].poste);
    
    printf("Salaire : ");
    scanf("%f", &emp[i].salaire);

    fprintf(fd,"\n%d %s %s %d/%d/%d %s %.2f",emp[i].code , &emp[i].nom, &emp[i].prenom , emp[i].dns.day, emp[i].dns.month , emp[i].dns.year, &emp[i].poste , emp[i].salaire);
}





void show_by_code(int codeEmp){
    Emp* emp;
    char line[100];
    char code[5];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste) == 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(emp[i].code == codeEmp){
            printf("%d %s %s %d/%d/%d %s\n",emp[i].code,emp[i].nom,emp[i].prenom,emp[i].dns.day, emp[i].dns.month, emp[i].dns.year,emp[i].poste);
            return;
        }
    }
    printf("not found\n");
    return;
}

void show_by_nom(char* nom){
    Emp* emp;
    char line[100];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste) == 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(strcmp(emp[i].nom , nom) == 0){
        // if(emp[i].nom == nom){
            printf("%d %s %s %d/%d/%d %s\n",emp[i].code,emp[i].nom,emp[i].prenom,emp[i].dns.day, emp[i].dns.month, emp[i].dns.year,emp[i].poste);
            return;
        }
    }
    printf("not found\n");
    return;
}

void show_by_prenom(char* prenom){
    Emp* emp;
    char line[100];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste) == 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(strcmp(emp[i].prenom , prenom) == 0){
        // if(emp[i].nom == nom){
            printf("%d %s %s %d/%d/%d %s\n",emp[i].code,emp[i].nom,emp[i].prenom,emp[i].dns.day, emp[i].dns.month, emp[i].dns.year,emp[i].poste);
            return;
        }
    }
    printf("not found\n");
    return;
}

void update_employee(int codeEmp){
    Emp* emp;
    Emp* emp2;
    char line[100];
    char code[5];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    FILE* pf2 = fopen("temp.txt","w");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    if (pf2 == NULL) {
        printf("Temp File doesn't open !\n");
        return;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s %.2f",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste , &emp[num].salaire) >= 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(emp[i].code == codeEmp){
            printf("found code\n");
            // found = 1;
            printf("Nom : ");
            scanf("%s", &emp[i].nom);

            printf("Prenom : ");
            scanf("%s", &emp[i].prenom);

            printf("Date de naissance\n");
            printf("Jour : ");
            scanf("%d", &emp[i].dns.day);
            
            printf("Mois : ");
            scanf("%d", &emp[i].dns.month);
            
            printf("Annee : ");
            scanf("%d", &emp[i].dns.year);
            
            printf("Poste : ");
            scanf("%s", &emp[i].poste);
            
            printf("Salaire : ");
            scanf("%f", &emp[i].salaire);
        }
        fprintf(pf2, "%d %s %s %d/%d/%d %s %.2f\n",emp[i].code,emp[i].nom,emp[i].prenom,emp[i].dns.day, emp[i].dns.month, emp[i].dns.year,emp[i].poste, emp[i].salaire);
    }
    fclose(pf);
    fclose(pf2);
    free(emp);
    
    FILE* pf3;
    FILE* pf4;
    pf3 = fopen("temp.txt","r");
    pf4 = fopen("employees.txt","w");

    if (pf3 == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    if (pf4 == NULL) {
        printf("Temp File doesn't open !\n");
        return;
    }
    printf("here\n");

    int num2 = 0;
    char line2[100];
    emp2 = malloc(500 * sizeof(Emp*));
    while (fscanf(pf3, 
    "%d %s %s %d/%d/%d %s %.2f",
    &emp2[num2].code,emp2[num2].nom,emp2[num2].prenom,&emp2[num2].dns.day, 
    &emp2[num2].dns.month, &emp2[num2].dns.year,emp2[num2].poste , &emp2[num2].salaire) >= 7  
    && fgets(line2, sizeof(line2), pf3) != NULL) {
        num2++;
    }

    printf("%d\n",num2);

    for(int j = 0; j < num2; j++){
        printf("%d %s %s %d/%d/%d %s %.2f\n",emp2[j].code,emp2[j].nom,emp2[j].prenom,emp2[j].dns.day, emp2[j].dns.month, emp2[j].dns.year,emp2[j].poste, emp2[j].salaire);
        fprintf(pf4 , "%d %s %s %d/%d/%d %s %.2f",emp2[j].code,&emp2[j].nom,&emp2[j].prenom,emp2[j].dns.day, emp2[j].dns.month, emp2[j].dns.year,emp2[j].poste, emp2[j].salaire);
    }

    fclose(pf3);
    fclose(pf4);
    free(emp2);
}

void delete_employee(int codeEmp){
    Emp* emp;
    Emp* emp2;
    char line[100];
    char code[5];
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    FILE* pf2 = fopen("temp.txt","w");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    if (pf2 == NULL) {
        printf("Temp File doesn't open !\n");
        return;
    }
    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s %.2f",
    &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,emp[num].poste , &emp[num].salaire) >= 7  
    && fgets(line, sizeof(line), pf) != NULL) {
        num++;
    }
    for(int i = 0; i < num; i++){
        if(emp[i].code == codeEmp){
            printf("found code\n");
            printf("%d %s %s %d/%d/%d %s %.2f\n",emp[i].code,emp[i].nom,emp[i].prenom,emp[i].dns.day, emp[i].dns.month, emp[i].dns.year,emp[i].poste, emp[i].salaire);
            for(int j=0; j < num; j++) {
                if( i != j) {
                    fprintf(pf2, "%d %s %s %d/%d/%d %s %.2f\n",emp[j].code,emp[j].nom,emp[j].prenom,emp[j].dns.day, emp[j].dns.month, emp[j].dns.year,emp[j].poste, emp[j].salaire);
                }
            }
        }
    }
    fclose(pf);
    fclose(pf2);
    free(emp);
    
    FILE* pf3;
    FILE* pf4;
    pf3 = fopen("temp.txt","r");
    pf4 = fopen("employees.txt","w");

    if (pf3 == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    if (pf4 == NULL) {
        printf("Temp File doesn't open !\n");
        return;
    }
    printf("here\n");

    int num2 = 0;
    char line2[100];
    emp2 = malloc(500 * sizeof(Emp*));
    while (fscanf(pf3, 
    "%d %s %s %d/%d/%d %s %.2f",
    &emp2[num2].code,emp2[num2].nom,emp2[num2].prenom,&emp2[num2].dns.day, 
    &emp2[num2].dns.month, &emp2[num2].dns.year,emp2[num2].poste , &emp2[num2].salaire) >= 7  
    && fgets(line2, sizeof(line2), pf3) != NULL) {
        num2++;
    }

    printf("%d\n",num2);

    for(int j = 0; j < num2; j++){
        printf("%d %s %s %d/%d/%d %s %.2f\n",emp2[j].code,emp2[j].nom,emp2[j].prenom,emp2[j].dns.day, emp2[j].dns.month, emp2[j].dns.year,emp2[j].poste, emp2[j].salaire);
        fprintf(pf4 , "%d %s %s %d/%d/%d %s %.2f\n",emp2[j].code,emp2[j].nom,emp2[j].prenom,emp2[j].dns.day, emp2[j].dns.month, emp2[j].dns.year,emp2[j].poste, emp2[j].salaire);
    }

    fclose(pf3);
    fclose(pf4);
    free(emp2);
}