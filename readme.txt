FICHIER README pour le programme 'Mathieu et Paolo.c'

Ce document sert de guide pour la compilation, l'utilisation et la compréhension du programme C 'Mathieu et Paolo.c', qui implémente des opérations sur des polynômes.

---

COMPILATION DU PROGRAMME

Le code source a besoin de la librairie mathématique (math.h). Utilisez la commande suivante pour compiler le fichier avec gcc :

gcc Mathieu\ et\ Paolo.c -o polynome_app -lm

* -o polynome_app : Spécifie le nom du fichier exécutable (polynome_app). Vous pouvez choisir un autre nom.
* -lm : Lie la librairie mathématique (libm.a), nécessaire pour l'utilisation de la fonction pow().

---

UTILISATION

Une fois compilé, exécutez le programme depuis votre terminal :

./polynome_app

Le programme affichera un menu principal permettant de choisir différentes opérations sur des polynômes.

Menu d'Opérations

Le menu propose les options suivantes :

1) Additioner : Calcule la somme de deux polynômes.
2) Multiplier : Calcule le produit de deux polynômes.
3) Dériver : Calcule la dérivée du polynôme.
4) Intégrer sur un segment : Calcule l'intégrale définie du polynôme sur un intervalle [a;b].
5) DL_n(a) : Calcule le développement limité d'ordre n autour du point a.
6) Trouver une racine (Newton) : Applique la méthode de Newton pour approximer une racine sur un intervalle [a;b].
7) Quitter : Ferme le programme.

Saisie des Polynômes

Lorsqu'une opération nécessite un ou deux polynômes, le programme vous demandera :
1. Le degré du polynôme (entier naturel).
2. Les coefficients dans l'ordre croissant des puissances, de a_0 à a_degré (c'est-à-dire le coefficient de X^0, puis celui de X^1, etc.).

Exemple : Pour le polynôme P(X) = 5 + 2X - 3X^2 :
* Degré : 2
* a_0 : 5
* a_1 : 2
* a_2 : -3

---

JOURNALISATION (Log)

Toutes les opérations mathématiques effectuées sont enregistrées dans un fichier nommé journal.log dans le même répertoire que l'exécutable.

La fonction ecrire(const char *message) est utilisée pour ajouter une trace de l'opération et de son résultat (y compris les succès/échecs de la méthode de Newton) dans ce fichier.

---

STRUCTURE DU CODE

Le code est structuré autour de plusieurs fonctions principales :

* main() : Boucle principale du programme gérant le menu.
* entreepolynome() : Gère la saisie du degré et des coefficients d'un polynôme par l'utilisateur.
* afficherpolynome() : Affiche les coefficients d'un polynôme pour vérification.
* polynome_vers_texte() : Convertit les coefficients d'un polynôme en une chaîne de caractères lisible (utilisée pour la journalisation).
* sommepolynome() : Additionne deux polynômes.
* produitpolynome() : Multiplie deux polynômes.
* deriveepolynome() : Calcule et affiche la dérivée d'un polynôme.
* calculer_derivee() : Calcule la dérivée et retourne les coefficients et le nouveau degré.
* valeurpoint() : Évalue le polynôme en un point donné a.
* integraleintervalle() : Calcule l'intégrale définie sur l'intervalle [a;b] en utilisant la formule fondamentale du calcul intégral : Intégrale(a à b) P(x) dx = F(b) - F(a).
* devlimite() : Effectue le développement limité (série de Taylor) d'ordre n au point a. La formule utilisée est P(x) approx Somme(k=0 à n) [P^(k)(a) / k!] * (x-a)^k.
* methodenewton() : Implémente l'algorithme itératif de Newton pour trouver une racine : x_(i+1) = x_i - P(x_i) / P'(x_i).

---

AUTEURS ET REMERCIEMENTS

* Auteurs : Mathieu et Paolo
* Code source : Présent sur le github de maaabz