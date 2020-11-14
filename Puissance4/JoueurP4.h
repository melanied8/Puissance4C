#ifndef JOUEURP4_H_INCLUDED
#define JOUEURP4_H_INCLUDED

struct Joueur
{
   char* prenom;
   char symbole;
   int tour;
};

//On demande au joueur quel mode de jeu il veut jouer
int choixModeJeu();

//On initialise les joueurs
void initJoueur(Joueur* joueur, const char* prenom, const char symbole, const int tour);

//On renvoie le prénom d'un joueur
char* getPrenom(const Joueur*);

//On renvoie le symbole d'un joueur
char getSymbole(const Joueur*);

//On renvoie le "tour" d'un joueur
int getTour(const Joueur*);

//On déclare les joueurs : demande de prénom, qui veut commencer en premier... (mode joueur vs joueur)
void declarationJoueurs (Joueur* j1,Joueur* j2);

//On initialise le joueur (mode joueur vs machine)
void declarationJoueurMachine (Joueur* joueur1,Joueur* joueur2);

//On compte le nb de lettres dans un mot
unsigned int mystrlen(const char* s);

//On recopie un mot dans un autre
void mystrcpy(char* s1, const char* s2);

//On détermine qui joue le tour
void aQuiLeTour(char* prenom,char* symbole,const Joueur*,const Joueur*,const int compteurTour);

//retirer le \n dans une chaîne de caractères
void retirer_retourChariot(char* chaine);

//Tests unitaires pour la structure joueur
void joueurTest();

#endif // JOUEURP4_H_INCLUDED
