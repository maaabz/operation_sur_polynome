#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Le code se compile avec : gcc main.c -o main -lm

void entreepolynome(int *degre, int coeffs[]);
void afficherpolynome(int *degre, int coeffs[]);
void sommepolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]);
void produitpolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]);
void deriveepolynome(int *degre1, int coeffs1[]);
void integraleintervalle(int *degre1, int coeffs1[], float a, float b);

void calculer_derivee(int degree, int coeffse[], int *degres, int coeffss[]);
float valeurpoint(float a , int coeffs[], int *degre1); // valeur en a
void devlimite(int *degre1, int coeffs1[], float a, int n);   // Développement limité, en un point a, à l’ordre n :

void methodenewton(int *degre1, int coeffs1[], float a, float b, int n);



int main(){

bool quitter = false;
int choix;

int degre1;
int poly1[100];
int degre2;
int poly2[100];

while(!quitter) {printf("\n ===== OPERATIONS SUR POLYNOMES ===== \n");
    printf("1)            Additioner \n");
    printf("2)            Multiplier \n");
    printf("3)            Dériver \n");
    printf("4)      Intégrer sur un segment \n");
    printf("5)             DL_n(a) \n");
    printf("6)      Trouver une racine (Newton) \n");
    printf("7)             Quitter\n");
    printf("\n Quelle est votre choix ? : \n");
    scanf("%d",&choix);
    
    switch (choix) {
        case 1 : 
        printf("\n-----SAISIT DU 1ER POLYNOME-----\n") ; entreepolynome(&degre1,poly1); printf("\n-----SAISIT DU 2EME POLYNOME-----\n") ;entreepolynome(&degre2,poly2); sommepolynome(&degre1, poly1, &degre2, poly2) ; break;

        case 2 :
        printf("\n-----SAISIT DU 1ER POLYNOME-----\n") ; entreepolynome(&degre1,poly1); printf("\n-----SAISIT DU 2EME POLYNOME-----\n"); entreepolynome(&degre2,poly2);produitpolynome(&degre1, poly1, &degre2, poly2); break;
        
        case 3 : entreepolynome(&degre1,poly1) ; deriveepolynome(&degre1, poly1) ; break;

        case 4 : printf("\n-----SAISIT DU POLYNOME-----\n") ;entreepolynome(&degre1,poly1) ;
        float a; float b; printf("\nQuelle est le segment d'intégration [a;b] ?\n");
        printf("Choisissez a :\n"); scanf("%f",&a) ;  printf("Choisissez b :\n") ; scanf("%f",&b) ; integraleintervalle(&degre1, poly1, a,b); break;
        
        case 5 : printf("\n-----SAISIT DU POLYNOME-----\n"); entreepolynome(&degre1,poly1) ; printf("Pour votre DL_N(a), que vaut n et a ?\n"); int nn ; float aa; 
        printf("Choisissez a :\n"); scanf("%f",&aa) ;  printf("Choisissez n :\n") ; scanf("%d",&nn) ; devlimite(&degre1, poly1, aa, nn) ; break;

        case 6 : printf("\n-----SAISIT DU POLYNOME-----\n") ; entreepolynome(&degre1,poly1) ; printf("Vous souhaitez trover la/les racine(s) eventuelle(s) du polynomes saisit sur un intervalle [a;b]. \n");
        float a1; float b1; printf("Choisissez a :\n"); scanf("%f",&a1) ;  printf("Choisissez b :\n") ; scanf("%f",&b1) ; methodenewton(&degre1, poly1,a1,b1,100000) ;
        break;

        case 7 : quitter = true ; printf("\nCiao\n");
    }

    }

return 0;

}



void entreepolynome(int *degre, int coeffs[]){

printf("Quelle est le degré de votre polynome (entier naturel) ? \n");
scanf("%d",degre);
printf("Quelle sont ses coefficiants ? (Par ordre croissant a_0,a_1...a_degre)\n");
for(int i = 0; i<= *degre; i++) {
    printf("a_%d = \n",i);
    int a;
    scanf("%d",&a);
    coeffs[i] = a;


}

afficherpolynome(degre,coeffs);



}


void afficherpolynome(int *degre, int coeffs[]){
printf("\n");
for(int i = 0;i<=*degre;i++){ printf("a_%d = %d \n",i,coeffs[i]); } 
}


void sommepolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]){
    
int a = 0; // si a est nulle, deg(poly1)<=deg(poly2)

int degremax;
if(*degre1<*degre2){ degremax = *degre2;}
else{degremax = *degre1; a = 1;}


int degremin;
if(*degre1<*degre2){ degremin = *degre1;}
else{degremin = *degre2;}

int somme[degremax+1];
for(int i = 0; i<=degremin; i++) { somme[i] = coeffs1[i]+coeffs2[i];}

if(a==0){
for(int i = degremin + 1; i<=degremax ; i++) {somme[i] = coeffs2[i];} }


if(a==1){
for(int i = degremin + 1; i<=degremax ; i++) {somme[i] = coeffs1[i];} }

printf("La somme de ces deux polynomes est : \n ");
afficherpolynome(&degremax,somme);


}


void produitpolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]){

int a = 0; // si a est nulle, deg(poly1)<=deg(poly2)

int degrepoly = *degre1 + *degre2;


int premier[degrepoly+1];
int deuxieme[degrepoly+1];

for(int k = 0 ; k <= *degre1 ; k ++) {premier[k]=coeffs1[k];}
for(int k = 0 ; k <= *degre2 ; k ++) {deuxieme[k]=coeffs2[k];}
for(int k = *degre1 + 1  ; k <= degrepoly ; k ++) {premier[k]=0;}
for(int k = *degre2 + 1  ; k <= degrepoly ; k ++) {deuxieme[k]=0;}

int produit[degrepoly+1];

for(int k = 0 ; k <= degrepoly ; k ++) {
    int res = 0;
    for(int p = 0; p<=k ; p++) {
        res += premier[p]*deuxieme[k-p];

}
produit[k]=res; 
}

printf("Le produit de ces deux polynomes est : \n ");
afficherpolynome(&degrepoly,produit);


}


void deriveepolynome(int *degre1, int coeffs1[]){

if(*degre1==0){printf("La dérivée de ce polynome est le polynome nulle \n"); return ;}

int degrederive = *degre1 - 1;
int derive[*degre1];
for(int k = 0 ; k <= degrederive ; k ++) {derive[k]=coeffs1[k+1]*(k+1);}

printf("La derivée du polynome saisie est : \n ");
afficherpolynome(&(degrederive),derive);
return;
}

void calculer_derivee(int degree, int coeffse[], int *degres, int coeffss[]) {
    if(degree == 0) {
        *degres = 0;
        coeffss[0] = 0;
        return;
    } 
    *degres = degree - 1;
    for(int k = 0; k <= *degres; k++) {
        coeffss[k] = coeffse[k+1] * (k+1);
    }
}




    
void integraleintervalle(int *degre1, int coeffs1[], float a, float b){

float FA = 0.0;
float FB = 0.0;
for(int k = 0 ; k <= *degre1 ; k ++) {FA+=((float)coeffs1[k]*pow(a,k+1))/(k+1);}
for(int k = 0 ; k <= *degre1 ; k ++) {FB+=((float)coeffs1[k]*pow(b,k+1))/(k+1);}
float integraleab = FB-FA;
printf("L'intégrale de %f à %f du polynome vaut %f \n",a,b, integraleab);
}


float valeurpoint(float a , int coeffs[], int *degre1){

float res = 0;
for(int i = 0; i<=*degre1 ; i++) { res+= coeffs[i]*pow(a,i);}
return res;
}



void devlimite(int *degre1, int coeffs1[], float a, int n){

int aderiver[*degre1];
for(int i = 0 ; i<= *degre1 ; i++) {aderiver[i]=coeffs1[i];}

int deg = *degre1;
for(int i = 0; i<=n ; i++){
    float b = valeurpoint(a, aderiver, &deg);
    int fact = 1;
    for(int j = 1; j <= i; j++) fact *= j;
    printf("%f*(X-a)^%d \n", b/fact, i);

    
    int deg2;
    int derive2[100];
    calculer_derivee(deg, aderiver, &deg2, derive2);
    deg = deg2;
    for(int k=0; k<=deg2; k++) aderiver[k] = derive2[k];
}

}



void methodenewton(int *degre1, int coeffs1[], float a, float b, int n){

float xo = (a+b)/2;
float eps = 0.00001; // il s'agit de notre précision

for(int i = 0 ; i<=n ; i++){
    float px = valeurpoint(xo,coeffs1,degre1);

    int degre_derive;
    int coeffsderive[100];   
    calculer_derivee(*degre1, coeffs1, &degre_derive, coeffsderive);
    float dpx = valeurpoint(xo, coeffsderive, &degre_derive);
    if(fabs(dpx) < 0.00000001) { printf("Division par 0 impossible (dérivée nulle)\n"); return;}

    float nouvx = xo - px/dpx;
    if (fabs(nouvx - xo)<eps) {printf("Une racine (presque exact) de P est %f \n", nouvx); return;}

    xo = nouvx;

}

printf("Aucune racine n'a pu etre approximée dans cet intervalle. \n");

}