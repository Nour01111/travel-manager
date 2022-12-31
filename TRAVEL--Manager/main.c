#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "agence.h"

int main()

{



    printf("************************************************************************************************************************\n");
    printf("\t \t \t \t  \t \t TRAVEL MANAGER\n");
    printf("************************************************************************************************************************\n");
    int n,l;
    char user[10],pwd[10];
    printf("\n");
    printf("user: \t");
    scanf("%s",user);
    printf("\n mot de passe:\t");
    scanf("%s",pwd);
    if(strcmp(user,"admin")==0 && strcmp(pwd,"1234")==0)
    {
        system("cls");
        int choix=1,n;
        liste_des_voyages l=NULL;
        while(choix)
        {
          printf("\n          **************   Menu   **************\n");
          printf("1: Ajouter un voyage\n");
          printf("2: Afficher la description d'un voyage\n");
          printf("3: Supprimer un voyage\n");
          printf("4: Modifier un voyage\n");
          printf("5: Recherche des voyages disponibles selon des dates precises\n");
          printf("\nVeuillez saisir le numero d'une operation: ");
          scanf("%i",&n);
          if(n==1)
             ajouter_voyage(&l);
          else if (n==2)
             afficher_voyage(l);
          else if (n==3)
             supprimer_voyage(&l);
          else if (n==4)
             modifier_voyage(&l);
          else if (n==5)
             rechercher_voyage(l);
          printf("\nVeuillez saisir '1' pour effectuer une autre operation ou '0' pour quitter le programme: ");
          scanf("%i",&choix);
         }
    }



















}


