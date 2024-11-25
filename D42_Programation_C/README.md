# D42 - Consolidation des compétences en C

## Bases du langage




## Codage d'un jeu en CLI

Nous allons coder un jeu en ligne de commande.

Il s'agit d'un jeu de cartes à deux joueurs, où chaque carte possède les attributs suivants :
- Un niveau (1, 2 ou 3)
- Une couleur (blanc, gris, noir, bleu, orange, rouge, violet, rose, jaune, vert)
- Une force (2, 3, 4, 5, 6, 10)

À chaque tour, le joueur va piocher une carte puis en jouer une carte dans un tableau de 15 cartes (3 lignes x 5 colonnes) en suivant les règles suivantes :
- Une carte de niveau 1 ne peut être jouée que sur la première ligne, 2 sur 2 ligne etc...
- Une carte de niveau 2 ne peut être jouée que si une carte de niveau 1 est sur la première ligne directement en dessous, même mécanique pour le niveau 3

Quand un joueur ne peut plus jouer de cartes, le 2e joueur peut jouer 3 tours puis le jeu s'arrête.
On calcule alors quelle est la force de chaque joueur en sommant la force de chaque carte dans le tableau, la force la plus élevée remporte la partie.

Créez une structure Carte représentant les cartes, utilisez des enum pour les attributs.
Créez ensuite une fonction qui affiche l'état de la partie dans le terminal (chaque carte sera représentée par une chaine "niveau-couleur-force"). Il faudra afficher la main et le tableau de chaque joueur.
Créez un prompt de l'utilisateur pour qu'à chaque tour il choisisse une carte et l'ajoute à son tableau; si la carte ne peut être jouée, la saisie est refusée. Il pourra rentrer -1 pour passer.
Le jeu affiche ensuite l'état de la partie une fois la carte jouée.
