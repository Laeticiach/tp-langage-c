#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Déclaration des variables externes
extern int points;                  //déclaration du score global
extern char nom_utilisateur[100];   //déclaration du nom de l'utilisateur

//fonction pour sauvegarder le score dans le fichier
void sauvegarder_score() {
    FILE *fichier = fopen("scores.txt", "a");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des scores. \n");
        return;
    }
    //sauvegarder le core avec le nom de l'utilisateur
    fprintf(fichier, "Nom: %s, Score: %d/n", nom_utilisateur, points);
    fclose(fichier);
}

//fonction pour charger le score à partir du fichier
void charger_scores() {
    FILE *fichier = fopen("scores.txt", "r");
    if (fichier == NULL) {
        printf("Aucun fichier de scores trouvé. Il sera créé lors de la sauvegarde. \n");
        return;
    }
    char ligne[200];
    int score =0;
    int trouve =0;

    //Parcourir les lignes du fichier pour chercher un acore correspondant au nom de l'utilisateur
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        if(strstr(ligne, nom_utilisateur))  {
            //Trouver le score du joueur
            sscanf(ligne, "Nom: %s, Score: %d", nom_utilisateur, &score);
            points = score; //Score trouvé
            trouve = 1;
            break; //Sortir une fois le score trouvé
        }
    }
    if (!trouve){
        printf("Aucun score trouvé pour %s, Nouveau joueur ?\n", nom_utilisateur);
    }

    fclose(fichier);
}



// Fonction addition
void addition() {
    int a = rand() % 101;
    int b = rand() % 101;
    int reponse, reponse_correcte = a + b;
    int tentative = 1;

    printf("%d + %d = ?\n", a, b);

    while (tentative <= 3) {
        printf("Entrer le résultat (tentative %d) : ", tentative);
        scanf("%d", &reponse);

        if (reponse == reponse_correcte) {
            if (tentative == 1) {
                printf("Bravo! Vous avez gagné(e) 10 points.\n");
                points += 10;
            }else if (tentative == 2) {
                 printf("Bravo! Vous avez gagné(e) 5 points.\n");
                 points += 5;
            }else {
                printf("Bravo! Vous avez gagné(e) 1 point.\n");
                points += 1;
            }
            return;

        } else {
            if (tentative < 3) {
                printf("Désolé(e), essayez encore...\n");
            }
        }
        tentative++;
    }

    printf("La bonne réponse était %d.\n", reponse_correcte);
}

void soustraction() {
    int a = rand() % 101;
    int b = rand() % 101;
    if (a < b) {
        int tmp = a; a = b; b = tmp;
    }
    int reponse, reponse_correcte = a - b;
    int tentative = 1;

    printf("%d - %d = ?\n", a, b);

    while (tentative <= 3) {
        printf("Entrer le résultat (tentative %d) : ", tentative);
        scanf("%d", &reponse);

        if (reponse == reponse_correcte) {
            if (tentative == 1) {
                printf("Bravo! Vous avez gagné(e) 10 points.\n");
                points += 10;
            } else if (tentative == 2) {
                printf("Bravo! Vous avez gagné(e) 5 points.\n");
                points += 5;
            } else {
                printf("Bravo! Vous avez gagné(e) 1 point.\n");
                points += 1;
            }
            return;
        } else if (tentative < 3) {
            printf("Désolé(e), essayez encore...\n");
        }
        tentative++;
    }

    printf("La bonne réponse était %d.\n", reponse_correcte);
}

void multiplication() {
    int a = rand() % 11;
    int b = rand() % 11;
    int reponse, reponse_correcte = a * b;
    int tentative = 1;

    printf("%d x %d = ?\n", a, b);

    while (tentative <= 3) {
        printf("Entrer le résultat (tentative %d) : ", tentative);
        scanf("%d", &reponse);

        if (reponse == reponse_correcte) {
            if (tentative == 1) {
                printf("Bravo! Vous avez gagné(e) 10 points.\n");
                points += 10;
            } else if (tentative == 2) {
                printf("Bravo! Vous avez gagné(e) 5 points.\n");
                points += 5;
            } else {
                printf("Bravo! Vous avez gagné(e) 1 point.\n");
                points += 1;
            }
            return;
        } else if (tentative < 3) {
            printf("Désolé(e), essayez encore...\n");
        }
        tentative++;
    }

    printf("La bonne réponse était %d.\n", reponse_correcte);
}

void division() {
    int b = rand() % 10 + 1;
    int resultat = rand() % 11;
    int a = b * resultat;

    int reponse, reponse_correcte = a / b;
    int tentative = 1;

    printf("%d / %d = ?\n", a, b);

    while (tentative <= 3) {
        printf("Entrer le résultat (tentative %d) : ", tentative);
        scanf("%d", &reponse);

        if (reponse == reponse_correcte) {
            if (tentative == 1) {
                printf("Bravo! Vous avez gagné(e) 10 points.\n");
                points += 10;
            } else if (tentative == 2) {
                printf("Bravo! Vous avez gagné(e) 5 points.\n");
                points += 5;
            } else {
                printf("Bravo! Vous avez gagné(e) 1 point.\n");
                points += 1;
            }
            return;
        } else if (tentative < 3) {
            printf("Désolé(e), essayez encore...\n");
        }
        tentative++;
    }

    printf("La bonne réponse était %d.\n", reponse_correcte);
}


void tables_multiplication() {
    int table;
    int score_temporaire = 0; // total pour cette table

    printf("Choisissez une table (1 à 10) : ");
    scanf("%d", &table);

    for (int i = 1; i <= 10; i++) {
        int reponse, reponse_correcte = table * i;
        int tentative = 1;

        while (tentative <= 3) {
            printf("%d x %d = ? (tentative %d) : ", table, i, tentative);
            scanf("%d", &reponse);

            if (reponse == reponse_correcte) {
                if (tentative == 1) {
                    printf("Bravo! 10 points.\n");
                    score_temporaire += 10;
                } else if (tentative == 2) {
                    printf("Bravo! 5 points.\n");
                    score_temporaire += 5;
                } else {
                    printf("Bravo! 1 point.\n");
                    score_temporaire += 1;
                }
                break;
            } else if (tentative < 3) {
                printf("Désolé(e), essayez encore...\n");
            }
            tentative++;
        }

        if (tentative > 3) {
            printf("Perdu ! La bonne réponse était %d.\n", reponse_correcte);
        }
    }

    // Ajouter les points au score global
    points += score_temporaire;

    // Affichage du total de cette série
    printf("Vous avez terminé la table de %d avec un score de %d points.\n", table, score_temporaire);
}




// Menu principal
void afficher_menu() {
    int choix;

    do {
        printf("+-------------------------------------+\n");
        printf("| 1 : Addition                        |\n");
        printf("| 2 : Soustraction                    |\n");
        printf("| 3 : Multiplication                  |\n");
        printf("| 4 : Tables des multiplications      |\n");
        printf("| 5 : Divisions                       |\n");
        printf("| 6 : Voir scores précédents          |\n");
        printf("| 0 : Sortir du jeu                   |\n");
        printf("+-------------------------------------+\n");
        printf("Quel est votre choix?");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                addition();
                break;
            case 2:
                soustraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                tables_multiplication();
                break;
            case 5:
                division();
                break;
            case 6:
                printf("Vous avez %d points.\n", points);
                break;
            case 0:
                printf("Merci d'avoir joué ! Vous avez terminé avec %d points.\n", points);
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);
}
