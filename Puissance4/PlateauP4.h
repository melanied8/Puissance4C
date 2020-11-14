#ifndef PLATEAUP4_H_INCLUDED
#define PLATEAUP4_H_INCLUDED


struct Plateau{
    int colonne;
    int ligne;
    char* plateauJeu;
};

void intitPlateau(Plateau* plateau, int ligne, int colonne);

int getLigne(const Plateau*);
int getColonne(const Plateau*);
char* getPlateauJeu(const Plateau*);

//Initialiser le plateau
void initialiserPlateau(Plateau* plateau);

//Afficher le plateau
void afficherPlateau(const Plateau* plateau);

//On demande la colonne au joueur
int demandeColonne(const char* prenom,const Plateau* plateau);

//On v�rifie que la colonne n'est pas pleine
bool Verification(const Plateau*,int choixColonne);

//On v�rifie la position la plus basse
int LigneLibre(const Plateau*,int colonne);

//On met le jeton
void MettreJeton(Plateau* plateau, int colonne, char numeroJoueur);

//On v�rifie si 4 jetons sont align�s � la verticale
bool Verticale(const Plateau*);

//On v�rifie si 4 jetons sont align�s � l'horizontale
bool Horizontale(const Plateau*);

//On v�rifie si 4 jetons sont align�s en diagonale droite
bool DiagonaleDroite(const Plateau*);

//On v�rifie si 4 jetons sont align�s en diagonale gauche
bool DiagonaleGauche(const Plateau*);

//On d�termine si un joueur a gagn� : utile pour le mode joueur vs machine
bool Gagnant(const Plateau*);

//On d�termine quelle colonne la machine va jouer
int GenererNombreAlea(const Plateau*);

//Tests unitaires
void PlateauP4_test();

//Plateau rempli
bool PartieNulle(const Plateau*);


#endif // PLATEAUP4_H_INCLUDED
