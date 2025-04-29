#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//D�claration des variables
int points = 0;
char nom_utilisateur[100];

//D�claration des fonctions externes
void afficher_menu();
void charger_scores();
void sauvegarder_scores();
void addition();
void soustraction();
void multiplication();
void division();
void table_multiplication();

int main () {
    //Demande du nom utilisateur
    printf("Enter votre nom: ");
    scanf("%s", nom_utilisateur);

    //charger de scores
    charger_scores();

    //Initialiser de nombres al�atoires
    srand(time(NULL));

    //Afficher du menu et gestion des choix
    afficher_menu();

    return 0;
}

