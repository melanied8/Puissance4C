# Puissance 4 en C/C++
IUT Paris Descartes - 2020 - Enseignant : ZIANE Mikal. </br>
Dans le cadre du cours d'algorithme, j'ai dû coder un puissance 4 en langage C. </br>

*Remarque : Beaucoup de fonctions propres au C++ ont été utilisées dans le programme*.

## Auteur
DANG Mélanie : melanie.dang8@gmail.com

## Règles du jeu
Le but du jeu est d'aligner une suite de 4 pions de même couleur sur une grille comptant 6 rangées et 7 colonnes. Chaque joueur dispose de 21 pions d'une couleur (par convention, en général jaune ou rouge). Tour à tour, les deux joueurs placent un pion dans la colonne de leur choix, le pion coulisse alors jusqu'à la position la plus basse possible dans la dite colonne à la suite de quoi c'est à l'adversaire de jouer. Le vainqueur est le joueur qui réalise le premier un alignement (horizontal, vertical ou diagonal) consécutif d'au moins quatre pions de sa couleur. Si, alors que toutes les cases de la grille de jeu sont remplies, aucun des deux joueurs n'a réalisé un tel alignement, la partie est déclarée nulle.

## Programmation

### Interface
<ul>
  <li> Mode console </li>
  <li> Menu en début de partie </li>
  <li> Grille de jeu </li>
</ul>

### Modes de jeu
2 modes de jeu possibles : 
<ul>
  <li> Joueur vs joueur </li>
  <li> Joueur vs machine </li>
</ul>
  
### Déroulement d'un tour
<ul>
  <li> On affiche le prénom et le jeton du joueur qui devra jouer ce tour-ci. </li>
  <li> On vérifie la validité du tour (colonne choisie valide par ex.). </li>
  <li> On regarde s'il y a victoire (4 jetons alignés) ou match-nul (plateau rempli). </li>
</ul>

### Tests unitaires
De nombreux tests unitaires ont été réalisé afin de vérifier la solidité et la validité des fonctions codées.
Ces tests sont effectués dès le début du lancement du programme.
