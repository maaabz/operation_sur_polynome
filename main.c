#include <stdio.h>
#include <string.h>
#include <math.h>

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

int degre1;
int poly1[100];
int degre2;
int poly2[100];

entreepolynome(&degre1,poly1);
entreepolynome(&degre2,poly2);
sommepolynome(&degre1, poly1, &degre2, poly2);
produitpolynome(&degre1, poly1, &degre2, poly2);
deriveepolynome(&degre1, poly1);
integraleintervalle(&degre1, poly1, 9.0, 100.0);
devlimite(&degre1, poly1, 2.0, 3);  // DL d'ordre 3 en x=2


return 0;


}

void entreepolynome(int *degre, int coeffs[]){

printf("Quelle est le degré de votre polynome (entier naturel) ? \n");
scanf("%d",degre);
printf("Quelle sont ses coefficiants ? (Par ordre croissant a_0,a_1...a_degre)\n");
for(int i = 0; i<= *degre; i++) {
    printf("a_%d = ",i);
    int a;
    scanf("%d",&a);
    coeffs[i] = a;


}

afficherpolynome(degre,coeffs);



}


void afficherpolynome(int *degre, int coeffs[]){
printf("Le polynome est : \n");
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

printf("SOMME ");
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

printf("PRODUIT ");
afficherpolynome(&degrepoly,produit);


}


void deriveepolynome(int *degre1, int coeffs1[]){

if(*degre1==0){printf("La dérivée de ce polynome est le polynome nulle \n"); return ;}

int degrederive = *degre1 - 1;
int derive[*degre1];
for(int k = 0 ; k <= degrederive ; k ++) {derive[k]=coeffs1[k+1]*(k+1);}

printf("DERIVEE ");
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
float eps = 0.1; // il s'agit de notre précision

for(int i = 0 ; i<=n ; i++){
    float px = valeurpoint(m,ledegre,*degre1);

    int degre_derive;
    int coeffsderive[100];   
    calculer_derivee(*degre1, coeffs1, &degre_derive, coeffsderive);
    float dpx = valeurpoint(x, coeffsderive, &degre_derive);

    if (dpx==0) {printf("Divison par 0 impossible");return;}

    float nouvx = xo - px/dpx;
    if (fabs(nouvx - xo)<eps) {printf("Une racine (presque exact) de P est %f", nouvx); return;}


}

    
}