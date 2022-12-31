#include <stdio.h>
#include<stdlib.h>
#include "agence.h"

int exist(int n,liste_des_voyages l) /*retourne 1 si la référence n existe dans la liste des voyages l  */
{
    int test=1;
    while (l!=NULL && test)
    {
        if(l->val.numero==n)
            test=0;
        l=l->suiv;
    }
    return (!test);
}
void ajouter_voyage (liste_des_voyages *l)
{   system("cls");
    liste_des_voyages p;
    voyage v;
    printf("\n       ************** Ajout d'un vol **************\n");
    printf("\nVeuillez saisir l'aereport de depart: ");
    scanf("%s",v.depart);
    printf("Veuillez saisir la destination du voyage: ");
    scanf("%s",v.destination);
    printf("Veuillez saisir le jour du voyage: ");
    scanf("%i",&v.date.jour);
    printf("Veuillez saisir le mois du voyage: ");
    scanf("%i",&v.date.mois);
    printf("Veuillez saisir l'annee du voyage: ");
    scanf("%i",&v.date.annee);
    printf("veuillez saisir l'heure du voyage:\n");
    printf("heure: ");
    scanf("%i",&v.heure_depart.heure);
    printf("minutes: ");
    scanf("%i",&v.heure_depart.minutes);
    do
    {
        printf("Veuillez saisir la refernce du voyage: ");
        scanf("%i",&v.numero);
        if (exist(v.numero,*l))
            printf("Cette reference existe deja dans la liste des voyages\n");
    }while (exist(v.numero,*l));
    p=malloc(sizeof(struct noeud));
    p->val=v;
    p->suiv=*l;
    *l=p;
}
void afficher_voyage(liste_des_voyages l)
{
    int n,test=1;
    printf("\n       ************** Affichage d'un vol **************\n");
    printf("\nVeuillez saisir la refernce du voyage a afficher: ");
    scanf("%i",&n);
    printf("\n");
    while(l!=NULL && test)
    {
        if(l->val.numero==n)
        {
            afficher(l->val);
            test=0;
        }
        l=l->suiv;
    }
    if (test)
        printf("Desole, la reference inseree ne correspond a aucun vol.\n");
}
void supprimer_voyage(liste_des_voyages *l)
{   system("cls");
    liste_des_voyages aux=*l;
    int test=1,ref;
    printf("\n       ************** Suppression d'un vol **************\n");
    printf("\nVeuillez saisir la refernce du voyage a supprimer: ");
    scanf("%i",&ref);
    printf("\n");
    if (exist(ref,aux))
    {
        if (aux->val.numero==ref)   /*l'élément à supprimer se trouve dans la tete de la liste*/
        {
            afficher(aux->val);
            aux=aux->suiv;
            free(*l);
            *l=aux;
            printf("Ce vol a ete supprimee avec success.\n");
        }
        else
        {
            while (aux!=NULL && test)
            {
                if (aux->suiv->val.numero==ref)
                {
                    afficher(aux->suiv->val);
                    free(aux->suiv);
                    aux->suiv=aux->suiv->suiv;
                    test=0;
                    printf("Ce vol a ete supprime avec success.\n");
                }
                aux=aux->suiv;
            }
        }
    }
    else
        printf("Desole, la reference inseree ne correspond a aucun vol.\n");
}
void modifier_voyage(liste_des_voyages *l)
{
    int test=1,ref,choix,choix2=1;
    liste_des_voyages aux=*l;
    printf("\n       ************** Modification d'un vol **************\n");
    printf("\nVeuillez saisir la refernce du voyage a modifier: ");
    scanf("%i",&ref);
    printf("\n");
    while(test && aux!=NULL)
    {
        if(ref==aux->val.numero)
        {
            afficher(aux->val);
            while (choix2)
            {
                printf("\n1: modifier la date du vol\n");
                printf("2: modifier l'heure du vol\n");
                do
                {
                    printf("Veuillez choisir une option: ");
                    scanf("%i",&choix);
                }while(choix!=1 && choix!=2);
                if(choix==1)
                {
                    printf("veuillez saisir la nouvelle date:\n");
                    printf("jour: ");
                    scanf("%i",&aux->val.date.jour);
                    printf("mois: ");
                    scanf("%i",&aux->val.date.mois);
                    printf("annee: ");
                    scanf("%i",&aux->val.date.annee);
                }
                else
                {
                    printf("veuillez saisir la nouvelle heure de depart:\n");
                    printf("heure: ");
                    scanf("%i",&aux->val.heure_depart.heure);
                    printf("minutes: ");
                    scanf("%i",&aux->val.heure_depart.minutes);

                }
                printf("Pour effectuer une nouvelle modification sur ce vol saisir '1' sinon saisir '0': ");
                scanf("%i",&choix2);
            }
            test=0;
        }
        aux=aux->suiv;
    }
    if (test)
        printf("Desole, la reference inseree ne correspond a aucun vol.\n");
}
void afficher(voyage v) /*cette fonction prend un voyage en paramètre et l'affiche*/
{
    printf("****   Details du vol correspondant  ****\n");
    printf("- Ce vol est programme le %i/%i/%i a %i:%i\n",v.date.jour,v.date.mois,v.date.annee,v.heure_depart.heure,v.heure_depart.minutes);
    printf("- Aereport de depart: %s\n",v.depart);
    printf("- Destination: %s\n",v.destination);
    printf("- Reference du voyage : %i\n",v.numero);
}
void rechercher_voyage (liste_des_voyages l) /*recherche les voyages disponibles entre deux dates*/
{   system("cls");
    liste_des_voyages aux;
    int test=1,i=0;
    date d1,d2;
    printf("\n       ************** Recherche d'un vol entre deux dates **************\n");
    printf("\nVeuillez saisir une date debut:\n");
    printf("jour: ");
    scanf("%i",&d1.jour);
    printf("mois: ");
    scanf("%i",&d1.mois);
    printf("annee: ");
    scanf("%i",&d1.annee);
    printf("Veuillez saisir une date fin:\n");
    printf("jour: ");
    scanf("%i",&d2.jour);
    printf("mois: ");
    scanf("%i",&d2.mois);
    printf("annee: ");
    scanf("%i",&d2.annee);
    date_suivante(&d2); /*pour inclure d2 dans la recherche*/
    while(d1.jour!=d2.jour || d1.mois!=d2.mois || d1.annee!=d2.annee)
    {
        aux=l;
        while (aux!=NULL)       /*parcourir la liste des voyages pour chercher un voyage de date d1*/
        {
            if(aux->val.date.jour==d1.jour && aux->val.date.mois==d1.mois && aux->val.date.annee==d1.annee)
                {
                    i++;
                    printf("\n     ****** Vol %i ******\n",i);
                    afficher(aux->val);
                    test=0;
                }
            aux=aux->suiv;
        }
        date_suivante(&d1);
    }
    if(test)
        printf("Aucun vol n'est enregistre entre ces deux dates.\n");
}
void date_suivante(date *d)
{
    if(d->mois==1 || d->mois==3 || d->mois==5 || d->mois==7 || d->mois==8 || d->mois==10)
    {
        if (d->jour<31)
            d->jour+=1;
        else
        {
            d->mois+=1;
            d->jour=1;
        }
    }
    else if (d->mois==2)
    {
        if (d->jour<28)
            d->jour+=1;
        else
        {
            d->mois=3;
            d->jour=1;
        }
    }
    else if (d->mois==12)
    {
        if (d->jour<31)
            d->jour+=1;
        else
        {
            d->mois=1;
            d->jour=1;
            d->annee+=1;
        }
    }
    else
    {
        if (d->jour<30)
            d->jour+=1;
        else
        {
            d->mois+=1;
            d->jour=1;
        }
    }
}
