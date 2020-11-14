#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <malloc.h>
#include "PlateauP4.h"
#include "JoueurP4.h"
#include "unittest.h"


void PlateauP4_test()
{
    //initialiser le plateau
    Plateau plateauTest;
    const char* tableauTest;
    plateauTest.colonne=7;
    plateauTest.ligne=6;

    Plateau plateauTest2;
    const char* tableauTest2;
    plateauTest2.colonne=7;
    plateauTest2.ligne=6;

    //Pour les tests n°1
    tableauTest=(char*)malloc(plateauTest.colonne*plateauTest.ligne*sizeof(char))+1;
    plateauTest.plateauJeu=(char*)malloc(plateauTest.colonne*plateauTest.ligne*sizeof(char))+1;

    //Pour les tests n°2
    tableauTest2=(char*)malloc(plateauTest2.colonne*plateauTest2.ligne*sizeof(char))+1;
    plateauTest2.plateauJeu=(char*)malloc(plateauTest2.colonne*plateauTest2.ligne*sizeof(char))+1;


    tableauTest= {"O      O      X      X      X      XXXX   "};

    tableauTest2 ={"OXOOXXOOXOXOOOOXOXXXOXOXOOOXXXOXOXOXOOXOOO"};

    //On recopie la chaîne dans le plateauTest
    mystrcpy(plateauTest.plateauJeu,tableauTest);

    //On recopie la chaîne dans le plateauTest2
    mystrcpy(plateauTest2.plateauJeu,tableauTest2);

 /*Affichage du plateauJeu n1 ={'O',' ',' ',' ',' ',' ',' ',
                                'O',' ',' ',' ',' ',' ',' ',
                                'X',' ',' ',' ',' ',' ',' ',
                                'X',' ',' ',' ',' ',' ',' ',
                                'X',' ',' ',' ',' ',' ',' ',
                                'X','X','X','X',' ',' ',' '};     */


 /*Affichage du plateauJeu n2 ={'O','X','O','O','X','X','O',
                                'O','X','O','X','O','O','O',
                                'O','X','O','X','X','X','O',
                                'X','O','X','O','O','O','X',
                                'X','X','O','X','O','X','O',
                                'X','O','O','X','O','O','O'};     */

    //On affiche le plateau(plus pratique pour visualiser les tests
    afficherPlateau(&plateauTest);

    //Tests pour le plateauTest
    printf("Test pour le plateauTest n1 : \n");
    assertTrue(Horizontale(&plateauTest),"il y a 4 jetons alignes a l'horizontale :");
    assertTrue(Verticale(&plateauTest),"Il y a 4 jetons alignés a la verticale");
    assertFalse(DiagonaleDroite(&plateauTest),"il n'y a pas 4 jetons alignes en diagonale droite :");
    assertFalse(DiagonaleGauche(&plateauTest),"il n'y a pas 4 jetons alignes en diagonale gauche :");
    assertFalse(Verification(&plateauTest,1),"La colonne 1 est pleine");
    assertTrue(Verification(&plateauTest,2),"La colonne 2 n'est pas pleine");
    assertTrue(Verification(&plateauTest,3),"La colonne 3 n'est pas pleine");
    assertTrue(Verification(&plateauTest,4),"La colonne 4 n'est pas pleine");
    assertTrue(Verification(&plateauTest,5),"La colonne 5 n'est pas pleine");
    assertTrue(Verification(&plateauTest,6),"La colonne 6 n'est pas pleine");
    assertTrue(Verification(&plateauTest,7),"La colonne 7 n'est pas pleine");
    assertTrue(Gagnant(&plateauTest),"Il a 4 jetons alignes");
    assertFalse(PartieNulle(&plateauTest),"Le plateau n'est pas rempli");

    //On affiche le plateau(plus pratique pour visualiser les tests
    afficherPlateau(&plateauTest2);

    //Tests pour le plateauTest2
    printf("\nTest pour le plateauTest n2 : \n");
    assertTrue(DiagonaleDroite(&plateauTest2),"il y a 4 jetons alignes en diagonale droite :");
    assertTrue(DiagonaleGauche(&plateauTest2),"il y a 4 jetons alignes en diagonale gauche :");
    assertTrue(PartieNulle(&plateauTest2),"Le plateau est rempli");
    assertFalse(Horizontale(&plateauTest2),"il n'y a pas 4 jetons alignes a l'horizontale :");
    assertFalse(Verticale(&plateauTest2),"Il n'y a pas 4 jetons alignes a la verticale");
    assertFalse(Verification(&plateauTest2,1),"La colonne 1 est pleine");
    assertFalse(Verification(&plateauTest2,2),"La colonne 2 est pleine");
    assertFalse(Verification(&plateauTest2,3),"La colonne 3 est pleine");
    assertFalse(Verification(&plateauTest2,4),"La colonne 4 est pleine");
    assertFalse(Verification(&plateauTest2,5),"La colonne 5 est pleine");
    assertFalse(Verification(&plateauTest2,6),"La colonne 6 est pleine");
    assertFalse(Verification(&plateauTest2,7),"La colonne 7 est pleine");
}


void joueurTest()
{
    //Déclarer un nom de joueur
    Joueur joueurTest;

    const char* prenom= "Mélanie";
    joueurTest.prenom=(char*)malloc(mystrlen(prenom)*sizeof(char));
    mystrcpy(joueurTest.prenom,prenom);
    joueurTest.symbole='X';
    joueurTest.tour=1;

    //Le joueur s'appelle Mélanie, son jeton est 'X', et commence en premier
    //initJoueur(&joueurTest,joueurTest.prenom,'X',1);

    assertEquals('X',getSymbole(&joueurTest),"Le symbole du joueur");
    assertEquals(1,getTour(&joueurTest),"Le tour du joueur");
    assertEquals(7u,mystrlen(joueurTest.prenom),"Nombre de lettres dans le prenom du joueur");
}



