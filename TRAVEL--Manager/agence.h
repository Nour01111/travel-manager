#ifndef AGENCE_H_INCLUDED
#define AGENCE_H_INCLUDED


typedef struct
{
    int jour;
    int mois;
    int annee;
}date;
typedef struct
{
    int heure;
    int minutes;
}heure;
typedef struct
{
    char destination[30];
    char depart[30];
    date date;
    heure heure_depart;
    int numero; /*référence du voyage (unique pour chaque voyage)*/
}voyage;
struct noeud
{
    voyage val;
    struct noeud* suiv;
};
typedef struct noeud* liste_des_voyages;
void ajouter_voyage (liste_des_voyages *l);
void afficher_voyage(liste_des_voyages l);
void supprimer_voyage(liste_des_voyages *l);
void modifier_voyage (liste_des_voyages *l);
void rechercher_voyage (liste_des_voyages l);
#endif // AGENCE_H_INCLUDED


