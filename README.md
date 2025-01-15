# Labyrinth

## Instructions 
- infinite random rooms (chained up, down, left, right)
- portals (fixed bijection)
- levers (destroy room to regenerate it)
- background & random environment
- hahstable for storing room pointers

## Ideas
- keep talking & nobody explodes
- demineur
- no game
- questions with AI

# Git
git add --all
git commit -m "ajout de set_left"
git push // envoie le code à github
git pull
git status
git checkout -b mabranche
git checkout -b nom_branche // créé branche
git checkout nom_branche // change de branche
git push -u origin nom_branche // push depuis une nouvelle branche

# To do list
- [] Room aléatoire (seed random)
- [] Téléporteur bijectif
- [] Dans chaque salle, afficher distance de la exit room (taxicab distance)
- [] Si entre dans une salle avec un portail, créer direct l'autre salle avec une seed compatible
- [] Fonction qui affiche la room (décore)
- [] Seed influence portail, type de pièce (labyrinthe, dining room, accueil, ...)
- [] Dans chaque salle on laisse un espace au milieu pour le portail
- [] Si destroy room portail, destroy les deux