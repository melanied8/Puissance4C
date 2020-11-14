#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PlateauP4.h"
#include "JoueurP4.h"

//On initialise le plateau
void initialiserPlateau(Plateau* plateau)
{
    //On initialise la taille des lignes et colonnes
    plateau->ligne=6;
    plateau->colonne=7;

    //On initialise le plateau
    plateau->plateauJeu =(char*)malloc(plateau->ligne * plateau->colonne *sizeof(char))+1;


    for (int i=0;i<plateau->colonne * plateau->ligne;i++)
    {
        plateau->plateauJeu[i]=' ';
    }
}

//On affiche le plateau
void afficherPlateau(const Plateau* plateau)
{
    //Saut de ligne (plus propre)

    printf("\n");
    int indice=0;

    //Plafond du plateau
    printf("-----------------------------\n");

    for(int i=0; i<plateau->ligne;i++)
    {
        for(int j=0; j<plateau->colonne;j++)
        {
            printf("|");
            printf(" %c ",plateau->plateauJeu[j+indice]);
        }
        indice+=plateau->colonne;
        printf("| \n");
        printf("-----------------------------\n");
    }
    printf("  1   2   3   4   5   6   7");
    printf("\n");
}


//renvoie la ligne
int getLigne(const Plateau* plateau){
    return plateau->ligne;
}

//renvoie la colonne
int getColonne(const Plateau* plateau){
    return plateau->colonne;
}

//renvoie le tableau
char* getPlateau(const Plateau* plateau){
    return plateau->plateauJeu;
}

//On demande la colonne au joueur
int demandeColonne(const char* prenom,const Plateau *plateau)
{
        int choixColonne;
        printf("C'est au tour de %s\n",prenom);
        printf("Veuillez choisir une colonne");
        scanf("%d",&choixColonne);

        //Si la colonne est invalide ou colonne pleine, on redemande la colonne au joueur
        while(choixColonne<1 || choixColonne>7 ||Verification(plateau,choixColonne)!=true)
        {
            getchar();
            printf("Colonne invalide, veuillez reessayer");
            scanf("%d",&choixColonne);
        }

        return choixColonne;
}

//On vérifie que la colonne n'est pas pleine
bool Verification(const Plateau *plateau,int colonne)
{
    int compteur=0;
    int indice=0;

    for (int i=0; i<plateau->ligne;++i)
    {
        if(plateau->plateauJeu[(colonne-1)+indice]==' ')
        {
            compteur++;
        }
        indice+=plateau->colonne;
    }
    //S'il y a au moins une case de libre
    if(compteur!=0)
        return true;

    else
        return false;

}

//On recherche la position la plus basse
int LigneLibre(const Plateau *plateau,int colonne)
{
    int place=0;
    int indice=0;

    for (int i=0; i<plateau->ligne;i++)
    {
        if(plateau->plateauJeu[(colonne-1)+indice]==' ') //colonne-1 car indice du tableau -1
        {
            place=(colonne-1)+indice;
        }
            //On regarde la colonne en-dessous
            indice+=plateau->colonne;
    }

    return place;
}

//On met le jeton
void MettreJeton(Plateau* plateau, int colonne, char symboleJoueur)
{
    int placeLibre = LigneLibre(plateau,colonne);

    plateau->plateauJeu[placeLibre]=symboleJoueur;
}

//On regarde si 4 jetons sont alignés à la verticale
bool Verticale(const Plateau *plateau)
{
    int indice=0;

    //On passe à la colonne suivante
    for (int j=0; j < plateau->colonne;j++)
    {
       indice=0;
       int compteurCroix=0;
       int compteurRond=0;

       //On balaye toute la colonne
        for (int i=0; i<plateau->ligne;i++)
        {
            if(plateau->plateauJeu[indice+j]=='X')
            {
            compteurCroix++;
            compteurRond=0;
            }
            if(plateau->plateauJeu[indice+j]=='O')
            {
            compteurCroix=0;
            compteurRond++;
            }

            if(plateau->plateauJeu[indice+j]==' ')
            {
            compteurCroix=0;
            compteurRond=0;
            }
            if (compteurCroix>=4 || compteurRond>=4)
            {
                return true;
                break;
            }
            indice+=plateau->colonne;
        }
    }

    return false;
}


bool Horizontale(const Plateau *plateau)
{
    int indice=0;

   //On passe à la ligne suivante
   for (int i=0; i< plateau->ligne;i++)
   {
       int compteurRond=0;
       int compteurCroix=0;

       //On balaye toute la ligne
       for (int j=0; j< plateau->colonne;j++)
       {
            if(plateau->plateauJeu[indice+j]=='X')
            {
            compteurCroix++;
            compteurRond=0;
            }
            if(plateau->plateauJeu[indice+j]=='O')
            {
            compteurCroix=0;
            compteurRond++;
            }

            if(plateau->plateauJeu[indice+j]==' ')
            {
            compteurCroix=0;
            compteurRond=0;
            }
            if (compteurCroix>=4 || compteurRond>=4)
            {
                return true;
                break;
            }
       }
       //Pour passer à la ligne suivante
       indice+=plateau->colonne;
   }
   return false;
}

bool DiagonaleDroite(const Plateau *plateau)
{
    int indice=plateau->colonne*(plateau->ligne-3); //On commence à la 4ème ligne du plateau

    for (int i= 0; i<plateau->ligne-3;++i)
    {
        int compteur=0;
        int indiceMontant=6;

        for (int j=0; j<plateau->colonne-3;++j)
        {
            compteur=0;
            indiceMontant=6;

            for (int k=0; k<3;++k)
            {

                if(plateau->plateauJeu[indice+j]!=' ' && plateau->plateauJeu[indice+j]==plateau->plateauJeu[indice+j-indiceMontant])
                {
                    ++compteur;

                    if(compteur>=3)
                    {
                        return true;
                        break;
                    }
                }
                if(plateau->plateauJeu[indice+j]==' ' || plateau->plateauJeu[indice+j]!=plateau->plateauJeu[indice+j-indiceMontant])
                    compteur=0;

                indiceMontant+=6;
            }

        }

        indice+=plateau->colonne;
    }
    return false;
}

bool DiagonaleGauche(const Plateau *plateau)
{
    int indice=(plateau->colonne-3)*(plateau->ligne); //On commence à la 4ème ligne du plateau

    for (int i= 0; i<plateau->ligne-3;++i)
    {
        int compteur=0;
        int indiceMontant=8;

        for (int j=0; j<plateau->colonne-3;++j)
        {
            compteur=0;
            indiceMontant=8;

            for (int k=0; k<3;++k)
            {

                if(plateau->plateauJeu[indice+j]!=' ' && plateau->plateauJeu[indice+j]==plateau->plateauJeu[indice+j-indiceMontant])
                {
                    ++compteur;

                    if(compteur>=3)
                    {
                        return true;
                        break;
                    }
                }
                if(plateau->plateauJeu[indice+j]==' ' || plateau->plateauJeu[indice+j]!=plateau->plateauJeu[indice+j-indiceMontant])
                    compteur=0;

                indiceMontant+=8;
            }

        }

        indice+=plateau->colonne;
    }

    return false;
}

bool Gagnant(const Plateau* plateauJeu)
{
     if (Horizontale(plateauJeu)==true || Verticale(plateauJeu)==true || DiagonaleDroite(plateauJeu)==true || DiagonaleGauche(plateauJeu)==true)
     {
         return true;
     }
     return false;
}

//Plateau rempli
bool PartieNulle(const Plateau* plateau)
{
    int compteur=0;

    for (int i=0; i<plateau->ligne*plateau->colonne;i++)
    {
        if(plateau->plateauJeu[i]==' ')
            ++compteur;
    }

    if(compteur==0) //Le plateau est rempli -> partie nulle
        return true;
    else
        return false;
}

//On détermine quelle colonne la machine va jouer
int GenererNombreAlea(const Plateau *plateau){
    int max = 7;
    int min = 1;
    srand(time(NULL));
    int nombreMystere = (rand() % (max - min + 1)) + min;
    while(nombreMystere<1 || nombreMystere>7 ||Verification(plateau,nombreMystere)!=true)
    {
        nombreMystere = (rand() % (max - min + 1)) + min;
    }
    return nombreMystere;
}
