#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LancerPartie.h"
#include "testUni.h"


int main()
{
    //**TESTS UNITAIRES**
    PlateauP4_test();
    joueurTest();

    //On lance la partie
    LancerPartie();
}
