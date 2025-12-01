#include <stdio.h>
#include <string.h>

void entreepolynome(int *degre, int coeffs[]);
void afficherpolynome(int *degre, int coeffs[]);
void sommepolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]);
void produitpolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]);
void deriveepolynome(int *degre1, int coeffs1[]);
void integraleintervalle(int *degre1, int coeffs1[], int a, int b);

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

if(*degre1==0){printf("La dérivée de ce polynome est le polynome nulle");}

int degrederive = *degre1 - 1;
int derive[*degre1];
for(int k = 0 ; k <= degrederive ; k ++) {derive[k]=coeffs1[k+1]*(k+1);}

printf("DERIVEE ");
afficherpolynome(&(degrederive),derive);

}


void integraleintervalle(int *degre1, int coeffs1[], int a, int b){

int degreprimitive = *degre1 + 1;
int primitive[degreprimitive];
for(int k = 0 ; k <= degreprimitive ; k ++) {primitive[k]=coeffs1[k-1]/(k-1);}

}