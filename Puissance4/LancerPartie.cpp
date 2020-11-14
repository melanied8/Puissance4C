#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "PlateauP4.h"
#include "JoueurP4.h"

void LancerPartie()
{

    //Rejouer
    int rejouer=1;

    while(rejouer==1)
    {
    //Etape 1 : on intitialise le plateau
    struct Plateau plateauJeu;
    initialiserPlateau(&plateauJeu);

    //Etape 2 : on initialise les joueurs
    struct Joueur joueur1;
    struct Joueur joueur2;

    //Savoir qui joue ce tour:
    char* prenom;
    char symbole;
    int compteurTour=0;
    int choixColonne;


    int choixMode = choixModeJeu();

        //Mode joueur vs joueur
    if(choixMode==1)
    {
        //Etape 4: Prénom + symbole + tour des joueurs
        declarationJoueurs(&joueur1,&joueur2);

        //tant que le plateau n'est pas rempli
        while(compteurTour!=plateauJeu.ligne*plateauJeu.colonne)
        {
        //On incrémente le compteur tant que la partie n'est pas finie
         compteurTour = (compteurTour%2)+1;

        //Etape 5 : On détermine quel joueur doit jouer
        if(compteurTour==joueur1.tour)
        {
            prenom=joueur1.prenom;
            symbole=joueur1.symbole;
        }

        else
        {
            prenom=joueur2.prenom;
            symbole=joueur2.symbole;
        }

        //Etape 6 : On demande au joueur le choix de la colonne
        choixColonne = demandeColonne(prenom,&plateauJeu);

        //Etape 7 : On met vérifie la position la plus basse
        LigneLibre(&plateauJeu,choixColonne);

        //Etape 8 : On met le jeton
        MettreJeton(&plateauJeu,choixColonne,symbole);
        afficherPlateau(&plateauJeu);

        //Etape 9 : On regarde s'il y a 4 jetons alignés
        if(Gagnant(&plateauJeu)==true)
        {
            printf("\n%s",prenom);
            printf(" a gagne! Felicitations!");
            break;
        }

        //On arrête la partie si le plateau est rempli
        if(PartieNulle(&plateauJeu)==true)
        {
            printf("\nLa partie est nulle! Fin de la partie");
        }

        }
    }//fin du mode joueur vs joueur


    //Mode joueur vs machine
    if(choixMode==2)
    {
        //Prénom + symbole + tour des joueurs
        declarationJoueurMachine(&joueur1,&joueur2);

        //tant que le plateau n'est pas rempli
        while(compteurTour!=plateauJeu.ligne*plateauJeu.colonne)
        {
        //On incrémente le compteur tant que la partie n'est pas finie
         compteurTour = (compteurTour%2)+1;

        //On détermine quel joueur doit jouer
        if(compteurTour==joueur1.tour)
        {
            prenom=joueur1.prenom;
            symbole=joueur1.symbole;

            //Etape 5 : On demande au joueur le choix de la colonne
            choixColonne = demandeColonne(prenom,&plateauJeu);
        }

        //C'est au tour de la machine de jouer
        else
        {
            prenom=joueur2.prenom;
            symbole=joueur2.symbole;

            //On détermine quelle colonne la machine va jouer
            choixColonne=GenererNombreAlea(&plateauJeu);
        }

        //On met vérifie la position la plus basse
        LigneLibre(&plateauJeu,choixColonne);

        //On met le jeton
        MettreJeton(&plateauJeu,choixColonne,symbole);
        afficherPlateau(&plateauJeu);

        //On regarde s'il y a 4 jetons alignés (A ENLEVER PROCHAINEMENT)
        if(Gagnant(&plateauJeu)==true)
        {
            printf("\n%s",prenom);
            printf(" a gagne! Felicitations!");
            break;
        }
            //On arrête la partie si le plateau est rempli
            if(PartieNulle(&plateauJeu)==true)
            {
                printf("\nLa partie est nulle! Fin de la partie");
            }
        }
    }//Fin du mode machine vs machine

    //On libère la mémoire allouée

    free(&plateauJeu);
    printf("\nVoulez-vous rejouer? Tapez 1 pour rejouer, 2 pour quitter");
    scanf("%d", &rejouer);

    while(rejouer<1 || rejouer >2)
    {
        printf("\nErreur.Veuillez taper 1 ou 2");
        scanf("%d",&rejouer);
    }

    }

    printf("Au revoir ! :) ");

}
