#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "JoueurP4.h"

//Initialisation des joueurs
void initJoueur(Joueur* joueur, char* prenom, char symbole, int tour){
    joueur->prenom = prenom;
    joueur->symbole = symbole;
    joueur->tour=tour;
}

//On demande au joueur quel mode de jeu il veut jouer
int choixModeJeu ()
{
    int choixMode;

    printf("\nBienvenue sur Puissance4! \nQuel mode de jeu voulez-vous choisir?\n");
    printf("1) Joueur contre joueur\n");
    printf("2) Joueur contre machine\n");
    scanf("%d", &choixMode);

    while(choixMode <1 || choixMode>2)
    {
        getchar();
        printf("Erreur. Veuillez reessayer");
        scanf("%d",&choixMode);
    }
    return choixMode;
}

//On compte le nb de lettres dans un mot
unsigned int mystrlen(const char* s)
{
    int i=0;
    while(s[i]!='\0')
    {
        ++i;
    }
    return i;
}

//On recopie un mot dans un autre
void mystrcpy(char* s1, const char* s2) {
    int i;
    for(i =0; s2[i] != '\0' ; ++i)
        s1[i] = s2[i];
    s1[i]=0;
}

//Pour retirer le \n après une chaîne de caractères
void retirer_retourChariot(char* chaine)
{
  int i;
  for(i=0;chaine[i] != '\0';i++)
  {
    if(chaine[i] == '\n')
    {
      chaine[i] = '\0';
    }
  }
}

//On déclare les joueurs (mode joueur vs joueur)
void declarationJoueurs (Joueur* joueur1,Joueur* joueur2){
    char* prenom1;
    char* prenom2;
    //On alloue la taille des prénoms
    prenom1=(char*)malloc(20*sizeof(char));
    prenom2=(char*)malloc(20*sizeof(char));


    //On demande les prénoms aux joueurs
    printf("Quel est le prenom du joueur 1?");
    getchar();
    fgets(prenom1,20,stdin);


    printf("Quel est le prenom du joueur 2?");
    fgets(prenom2,20,stdin);

    //On enlève le \n des prénoms
    retirer_retourChariot(prenom1);
    retirer_retourChariot(prenom2);

    //On alloue la taille des prénoms des joueurs
    joueur1->prenom=(char*)malloc(mystrlen(prenom1)*sizeof(char));
    joueur2->prenom=(char*)malloc(mystrlen(prenom2)*sizeof(char));


    //On détermine le tour des joueurs
    int place;
    printf("%s, voulez-vous etre: 1)premier.e ou 2)deuxieme ?",prenom1);
    scanf("%d",&place);

    while(place<1 || place>3)
    {
        getchar();
        printf("Erreur, veuillez taper 1 ou 2");
        scanf("%d",&place);
    }

    if(place==1)
    {
        initJoueur(joueur1,prenom1,'X',1);
        initJoueur(joueur2,prenom2,'O',2);

    }
    if(place==2)
    {
        initJoueur(joueur1,prenom1,'X',2);
        initJoueur(joueur2,prenom2,'O',1);
    }
}

void declarationJoueurMachine (Joueur* joueur1,Joueur* joueur2)
{
    char* prenom1;
    char* prenom2="Machine";

    //On alloue la taille du prénom
    prenom1=(char*)malloc(20*sizeof(char));

    //On demande les prénoms aux joueurs
    printf("Quel est le prenom du joueur 1?");
    getchar();
    fgets(prenom1,20,stdin);

    //On enlève le \n des prénoms
    retirer_retourChariot(prenom1);
    retirer_retourChariot(prenom2);

      //On détermine le tour des joueurs
    int place;
    printf("%s, voulez-vous etre: 1)premier.e ou 2)deuxieme ?",prenom1);
    scanf("%d",&place);

    while(place<1 || place>3)
    {
        getchar();
        printf("Erreur, veuillez taper 1 ou 2");
        scanf("%d",&place);
    }

    if(place==1)
    {
        initJoueur(joueur1,prenom1,'X',1);
        initJoueur(joueur2,prenom2,'O',2);

    }
    if(place==2)
    {
        initJoueur(joueur1,prenom1,'X',2);
        initJoueur(joueur2,prenom2,'O',1);
    }
}


//On renvoie le prénom du joueur
char* getPrenom(const Joueur* joueur){
    return joueur->prenom;
}

//On renvoie le symbole du joueur
char getSymbole(const Joueur*joueur){
    return joueur->symbole;
}

//On renvoie le numéro de tour du joueur
int getTour(const Joueur*joueur ){
    return joueur->tour;
}
