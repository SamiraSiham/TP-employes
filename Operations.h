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
    char line[100];
    int found = 0;
    emp = malloc(500 * sizeof(Emp*));
    int num = 0;
    FILE* pf = fopen("employees.txt","r");
    FILE* pf1 = fopen("temp.txt","w");
    if (pf == NULL) {
        printf("File doesn't open !\n");
        return;
    }
    if (pf1 == NULL) {
        printf("Temp File doesn't open !\n");
        return;
    }

    // printf("%d\n",fscanf(pf, 
    // "%d %s %s %d/%d/%d %s",
    // &emp->code,emp->nom,emp->prenom,&emp->dns.day, 
    // &emp->dns.month, &emp->dns.year,emp->poste));


    while (fscanf(pf, 
    "%d %s %s %d/%d/%d %s",
    &emp[num].code, &emp[num].nom,&emp[num].prenom,&emp[num].dns.day, 
    &emp[num].dns.month, &emp[num].dns.year,&emp[num].poste) == 7  
    ){
        while(fgets(line, sizeof(line), pf) != NULL){
        num++;
        }
        // if(found){
        //     pf = fopen("employees.txt","w");
        //     pf1 = fopen("temp.txt","r");
        //     num = 0;
        //     char line2[100];
        //     while (fscanf(pf1, 
        //     "%d %s %s %d/%d/%d %s",
        //     &emp[num].code,emp[num].nom,emp[num].prenom,&emp[num].dns.day, 
        //     &emp[num].dns.month, &emp[num].dns.year,emp[num].poste) == 7  
        //     && fgets(line2, sizeof(line2), pf1) != NULL){
        //         fprintf(pf,"\n%d %s %s %d/%d/%d %s %.2f",emp[num].code , &emp[num].nom, &emp[num].prenom , emp[num].dns.day, emp[num].dns.month , emp[num].dns.year, &emp[num].poste , emp[num].salaire);
        //         num++;
        //     }
        // }
        // fclose(pf);
        // fclose(pf1);
    }
    
    for(int i=0; i<num; i++) {
        printf("%d\n", emp[i].code);
        if(codeEmp == emp[i].code){
            printf("found code");
            found = 1;
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
            
            // fprintf(pf,"\n%d %s %s %d/%d/%d %s %.2f",emp[num].code , &emp[num].nom, &emp[num].prenom , emp[num].dns.day, emp[num].dns.month , emp[num].dns.year, &emp[num].poste , emp[num].salaire);
        }
    }



    // while(fgets(line, sizeof(line), pf)){
    //     fscanf(pf, 
    // "%d %s %s %d/%d/%d %s",
    // &emp.code,emp.nom,emp.prenom,&emp.dns.day, 
    // &emp.dns.month, &emp.dns.year,emp.poste);
    //     if(emp.code == codeEmp){
    //         // printf("here");
    //         found = 1;
    //         fflush(stdin);
            // printf("Nom : ");
            // scanf("%s", emp.nom);

            // printf("Prenom : ");
            // scanf("%s", emp.prenom);

            // printf("Date de naissance\n");
            // printf("Jour : ");
            // scanf("%d", emp.dns.day);
            
            // printf("Mois : ");
            // scanf("%d", emp.dns.month);
            
            // printf("Annee : ");
            // scanf("%d", emp.dns.year);
            
            // printf("Poste : ");
            // scanf("%s", emp.poste);
            
            // printf("Salaire : ");
            // scanf("%f", emp.salaire);
    //     }
    //     fwrite(&emp, sizeof(Emp), 1, pf1);
    //     // num++;
    // }
    // fclose(pf);
    //     fclose(pf1);
    
}