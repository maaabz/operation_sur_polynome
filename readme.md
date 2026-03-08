# Polynôme App

> Calculatrice de polynômes en C — addition, multiplication, dérivation, intégration, développements limités et méthode de Newton.

**Auteurs :** Mathieu & Paolo

---

## Compilation

Le programme dépend de la librairie mathématique `math.h`. Compilez avec `gcc` :

    gcc main.c -o polynome_app -lm

| Flag | Rôle |
|------|------|
| `-o polynome_app` | Nom du fichier exécutable généré |
| `-lm` | Lie `libm.a` — requis pour `pow()` |

---

## Utilisation

    ./polynome_app

Le programme affiche un **menu interactif** depuis le terminal.

---

## Menu des opérations

| # | Opération | Description |
|---|-----------|-------------|
| 1 | **Additionner** | Somme de deux polynômes |
| 2 | **Multiplier** | Produit de deux polynômes |
| 3 | **Dériver** | Dérivée d'un polynôme |
| 4 | **Intégrer sur un segment** | Intégrale définie sur `[a ; b]` |
| 5 | **DL_n(a)** | Développement limité d'ordre `n` autour de `a` |
| 6 | **Trouver une racine (Newton)** | Méthode de Newton sur `[a ; b]` |
| 7 | **Quitter** | Ferme le programme |

---

## Saisie d'un polynôme

Pour chaque polynôme, le programme demande le **degré** puis les **coefficients** dans l'ordre croissant.

Exemple pour P(X) = 5 + 2X − 3X² :

    Degré : 2
    a_0   : 5
    a_1   : 2
    a_2   : -3

---

## Journalisation

Toutes les opérations sont enregistrées dans **`journal.log`** (même répertoire que l'exécutable), incluant les résultats et succès/échecs de la méthode de Newton.

---

## Structure du code

| Fonction | Rôle |
|----------|------|
| `main()` | Boucle principale — gestion du menu |
| `entreepolynome()` | Saisie du degré et des coefficients |
| `afficherpolynome()` | Affichage des coefficients |
| `polynome_vers_texte()` | Conversion en chaîne lisible (pour le log) |
| `sommepolynome()` | Addition de deux polynômes |
| `produitpolynome()` | Multiplication de deux polynômes |
| `deriveepolynome()` | Calcul et affichage de la dérivée |
| `calculer_derivee()` | Retourne coefficients et degré de la dérivée |
| `valeurpoint()` | Évaluation de P en un point `a` |
| `integraleintervalle()` | Intégrale définie via F(b) − F(a) |
| `devlimite()` | Développement de Taylor d'ordre `n` |
| `methodenewton()` | Itérations de Newton : x_(i+1) = x_i − P(x_i)/P'(x_i) |
