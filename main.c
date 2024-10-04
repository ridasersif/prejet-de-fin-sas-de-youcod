#include <stdio.h>
#include <string.h>

char nom[100][50];
char prenom[100][50];
char telephone[100][20];
int age[100];
char statut[100][10];
int reference[100];
char date[100][10];
int nombre = 10 ;
int choix;
float somme;
int etat;
//***************************************************************************
void les_Choix() {
    printf("\n******** Menu des Choix *************\n");
    printf("1. Ajouter une reservation\n");
    printf("2. Modifier une reservation\n");
    printf("3. Supprimer une reservation\n");
    printf("4. Afficher les details d'une reservation\n");
    printf("5. Afficher toutes les reservations\n");
    printf("6. Trier les reservations par nom \n");
    printf("7. Rechercher une reservation par reference\n");
    printf("8. Rechercher une reservation par nom\n");
    printf("9. Calculer la moyenne d'age des patients\n");
    printf("10. Afficher le nombre de patients par tranche d'age\n");
    printf("11. Afficher les statistiques par statut\n");
    printf("12. Quitter\n");
    printf("Veuillez entrer votre choix : ");
    scanf("%d", &choix);
}
void etat_statut(int i)
{
    go:
    printf("Entrez le statut\n");
    printf("1.valide:\t");
    printf("2.reporte:\t");
    printf("3.annule:\t");
    printf("4.traite:\n");
    scanf("%d",&etat);
    switch(etat){
    case 1:
        strcpy(statut[nombre],"valide");
        printf("statut est : %s\n",statut);
        break;
    case 2:
        strcpy(statut[nombre],"reporte");
        printf("statut est : %s\n",statut);
        break;
    case 3:
        strcpy(statut[nombre],"annule");
        printf("statut est : %s\n",statut);
    break;
    case 4:
        strcpy(statut[nombre],"traite");
        printf("statut est : %s\n",statut);
    break;
    default:
        printf ("entrez un nomber enter 1 et 4.\n");
        goto go;
    }
}
//**************************************************************************************************************************
void Ajouter(){
    if (nombre < 100) {
        printf("Entrez le nom: ");
        scanf("%s", nom[nombre]);
        printf("Entrez le prenom: ");
        scanf("%s", prenom[nombre]);
        printf("Entrez le telephone: ");
        scanf("%s", telephone[nombre]);
        printf("Entrez l'age: ");
        scanf("%d", &age[nombre]);
        //printf("Entrez le statut (valide, reporte, annule, traite): ");
        //scanf("%s", statut[nombre]);
        etat_statut(nombre);
        printf("Entrez la date (jj/mm/aaaa): ");
        scanf("%s", date[nombre]);
        reference[nombre]=nombre+1;
        printf("Reference : %d\n", reference[nombre]);
        nombre++;
        printf("Reservation ajoutee avec succes!\n");
    } else {
        printf("Le nombre maximum de reservations a ete atteint.\n");
    }
}
//**************************************************************************************************************************
void Modifier()
{

    int ref;
    printf("Entrez la refrence de la reservation à modifier : ");
    scanf("%d", &ref);

    for (int i = 0; i <nombre; i++) {
        if (reference[i]==ref) {
            printf("Modification de la reservation %d\n", ref);
            printf("Entrez le nouveau nom: ");
            scanf("%s",nom[i]);
            printf("Entrez le nouveau prenom: ");
            scanf("%s",prenom[i]);
            printf("Entrez le nouveau telephone: ");
            scanf("%s", telephone[i]);
            printf("Entrez le nouvel age: ");
            scanf("%d", &age[i]);
           // printf("Entrez le nouveau statut (validé, reporté, annulé, traité): ");
            //scanf("%s", statut[i]);
            etat_statut(i);
            printf("Entrez la nouvelle date (jj/mm/aaaa): ");
            scanf("%s", date[i]);
            printf("Reservation modifiée avec succès !\n");
            return;
        }
    }
}
//****************************************************************************************************************
void supprimer()
{
    int ref;
    printf("Entrez la reference de la reservation a supprimer : ");
    scanf("%d",&ref);
    int x=0;
    for (int i = 0; i < nombre; i++) {
        if (reference[i]==ref) {
            // Décalage des elements du tableau bax
            for (int j = i; j < nombre - 1; j++) {
                strcpy(nom[j], nom[j + 1]);
                strcpy(prenom[j], prenom[j + 1]);
                strcpy(telephone[j], telephone[j + 1]);
                age[j] = age[j + 1];
                strcpy(statut[j], statut[j + 1]);
                reference[j]=reference[j + 1];
                strcpy(date[j], date[j + 1]);
            }
            nombre--;  // Diminuer le nombre de réservations
            printf("Reservation supprimee avec succes !\n");
            x++;
            break;
        }
    }
   if(x==0) printf("Reference non trouvee.\n");
}
//*************************************************************************************
void Afficher_details()
{
     int ref;
    printf("Entrez la reference : ");
    scanf("%d",&ref);
    int x=0;
    for (int i = 0; i < nombre; i++) {
        if (reference[i]==ref) {
            printf("\nDetails de la reservation %d :\n", ref);
            printf("*Nom : %s\n", nom[i]);
            printf("*Prenom : %s\n", prenom[i]);
            printf("*Telephone : %s\n", telephone[i]);
            printf("*Age : %d\n", age[i]);
            printf("*Statut : %s\n", statut[i]);
            printf("*Date : %s\n", date[i]);
            x++;
            break;
        }
    }
    if(x==0) printf("Reference non trouvee.\n");
}
//**********************************************************************************
void Afficher_toutes()
{
    for(int i=0;i<nombre;i++){
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    printf("*Referenc %d\n*Nom:%s   *Prenom:%s    *Tel:%s   *Age:%d   *Statut:%s   *Dat:%s\n",
    reference[i],nom[i],prenom[i],telephone[i],age[i],statut[i],date[i]);
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    }
}
//**********************************************************************************
void Trier_nom() {
    if (nombre <= 1) {
        printf("Il n'y a pas assez de reservations a trier.\n");
    }

    for (int i = 0; i < nombre - 1; i++) {
        for (int j = 0; j < nombre - i - 1; j++) {
            if (strcmp(nom[j], nom[j + 1]) > 0) {
                char tempNom[50], tempPrenom[50], tempTelephone[20], tempStatut[10], tempDate[10];
                int tempAge, tempReference;
//=========================================================================================
                strcpy(tempNom, nom[j]);
                strcpy(nom[j], nom[j + 1]);
                strcpy(nom[j + 1], tempNom);
//=========================================================================================
                strcpy(tempPrenom, prenom[j]);
                strcpy(prenom[j], prenom[j + 1]);
                strcpy(prenom[j + 1], tempPrenom);
//=========================================================================================
                strcpy(tempTelephone, telephone[j]);
                strcpy(telephone[j], telephone[j + 1]);
                strcpy(telephone[j + 1], tempTelephone);
//=========================================================================================
                tempAge = age[j];
                age[j] = age[j + 1];
                age[j + 1] = tempAge;
//=========================================================================================
                strcpy(tempStatut, statut[j]);
                strcpy(statut[j], statut[j + 1]);
                strcpy(statut[j + 1], tempStatut);
//=========================================================================================
                tempReference = reference[j];
                reference[j] = reference[j + 1];
                reference[j + 1] = tempReference;
//=========================================================================================
                strcpy(tempDate, date[j]);
                strcpy(date[j], date[j + 1]);
                strcpy(date[j + 1], tempDate);
            }
        }
    }

    printf("Les reservations ont ete triees par nom avec succes.\n");
}
void Rechercher_par_referenc()
{
   Afficher_details();

}
    void Rechercher_par_nom()
{
    char nom_cherch[50];
    printf("entrez le nom a reherchez");
    scanf("%s",nom_cherch);
    int x=0;
    for(int i=0;i<nombre;i++){

        if (strcmp(nom_cherch,nom[i])==0){
            printf("les information sur le nom que vous recherchez sont :");
            printf("Nom : %s\n", nom[i]);
            printf("Prenom : %s\n", prenom[i]);
            printf("Telephone : %s\n", telephone[i]);
            printf("Age : %d\n", age[i]);
            printf("Statut : %s\n", statut[i]);
            printf("Date : %s\n", date[i]);
            printf("referenc : %d\n",reference[i]);
            x++;
        }
    }
    if (x==0)printf("le nom que vouz entre n'existe pas");


}
float Calculer_moyenne_age()
{   // float moyenn;

     somme=0.0;
    for(int i=0;i<nombre;i++){
            somme=somme+age[i];
    }
    if(nombre>0) printf("le moyenne est : %.2f",somme/nombre);
    else {
        return 0;
    }
}
void Afficher_prtients_par_tranche_age(){
        int m=0;
        int mm=0;
        int mmm=0;
        for(int i=0;i<nombre;i++){
            if(age[i]<=18) m++;
            else if(age[i]>18) mm++;
            else mmm++;
        }
        printf("\n*Nombre de patients entre 0 et 18 ans : %d\n",m);
        printf("\n*Nombre de patients entre 19 et 35 ans : %d\n",mm);
        printf("\n*Nombre de patients de plus de 36 ans : %d\n",m);


    }
    void Statistiques(){
        int validi = 0;
        int reporte =0;
        int annule = 0;
        int traite = 0;
        for (int i=0;i<nombre;i++){
            if(strcmp(statut[i],"valide")==0)
            validi++;
            else if(strcmp(statut[i],"reporte")==0)
            reporte++;
            else if(strcmp(statut[i],"annule")==0)
            annule++;
            else if(strcmp(statut[i],"traite")==0)
            traite++;
        printf("\n===>les statistiques par statut :\n");
        printf("*Nombre de patients avec statut \"valide\" :%d\n",validi);
        printf("*Nombre de patients avec statut \"reporte\" :%d\n",reporte);
        printf("*Nombre de patients avec statut \"annule\" :%d\n",annule);
        printf("*Nombre de patients avec statut \"traite\" :%d\n",traite);



        }
    }
int main()
 {
     fakedata();
    do {
        les_Choix();
        switch (choix) {
            case 1:
                printf("Vous avez choisi d'ajouter une reservation.\n");
                Ajouter();
                break;
            case 2:
                printf("Vous avez choisi de modifier une reservation.\n");
                Modifier();
                break;
            case 3:
                supprimer();
                break;

            case 4:
                Afficher_details();
                break;
            case 5:
                Afficher_toutes();
                break;
            case 6:
                Trier_nom();
                break;
            case 7:
                Rechercher_par_referenc();
                break;
            case 8:
                Rechercher_par_nom();
                break;
            case 9: printf("%.2f\n",Calculer_moyenne_age());
                break;
            case 10:
                Afficher_prtients_par_tranche_age();
                break;
            case 11:
                Statistiques();
                break;

        }
    }while(choix!=12);
}
void fakedata() { // data 9dima

    strcpy(nom[0], "Ahmed");
    strcpy(prenom[0], "Ali");
    strcpy(telephone[0], "0612345678");
    age[0] = 25;
    strcpy(statut[0], "valide");
    strcpy(date[0], "01/10/2024");
    reference[0] = 1;

    strcpy(nom[1], "Mohamed");
    strcpy(prenom[1], "Hassan");
    strcpy(telephone[1], "0612345679");
    age[1] = 30;
    strcpy(statut[1], "reporte");
    strcpy(date[1], "02/10/2024");
    reference[1] = 2;

    strcpy(nom[2], "Fatima");
    strcpy(prenom[2], "Zahra");
    strcpy(telephone[2], "0612345680");
    age[2] = 20;
    strcpy(statut[2], "annule");
    strcpy(date[2], "03/10/2024");
    reference[2] = 3;

    strcpy(nom[3], "Youssef");
    strcpy(prenom[3], "Amine");
    strcpy(telephone[3], "0612345681");
    age[3] = 28;
    strcpy(statut[3], "traite");
    strcpy(date[3], "04/10/2024");
    reference[3] = 4;

    strcpy(nom[4], "Khadija");
    strcpy(prenom[4], "Amina");
    strcpy(telephone[4], "0612345682");
    age[4] = 32;
    strcpy(statut[4], "valide");
    strcpy(date[4], "05/10/2024");
    reference[4] = 5;

    strcpy(nom[5], "Omar");
    strcpy(prenom[5], "Khaled");
    strcpy(telephone[5], "0612345683");
    age[5] = 45;
    strcpy(statut[5], "reporte");
    strcpy(date[5], "06/10/2024");
    reference[5] = 6;

    strcpy(nom[6], "Sara");
    strcpy(prenom[6], "Leila");
    strcpy(telephone[6], "0612345684");
    age[6] = 26;
    strcpy(statut[6], "valide");
    strcpy(date[6], "07/10/2024");
    reference[6] = 7;

    strcpy(nom[7], "Amine");
    strcpy(prenom[7], "Said");
    strcpy(telephone[7], "0612345685");
    age[7] = 22;
    strcpy(statut[7], "traite");
    strcpy(date[7], "08/10/2024");
    reference[7] = 8;

    strcpy(nom[8], "Noura");
    strcpy(prenom[8], "Latifa");
    strcpy(telephone[8], "0612345686");
    age[8] = 35;
    strcpy(statut[8], "annule");
    strcpy(date[8], "09/10/2024");
    reference[8] = 9;

    strcpy(nom[9], "Hicham");
    strcpy(prenom[9], "Mounir");
    strcpy(telephone[9], "0612345687");
    age[9] = 40;
    strcpy(statut[9], "valide");
    strcpy(date[9], "10/10/2024");
    reference[9] = 10;
}
//***************************************************************************
