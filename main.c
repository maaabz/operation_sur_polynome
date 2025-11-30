#include <stdio.h>

int entreepolynome(int *degre, int coeffs[]); //prend en entree le degré du polynomes et ses coeffs
void afficherpolynome(int *degre, int coeffs[]);
void sommepolynome(int *degre1, int coeffs1[], int *degre2, int coeffs2[]);


int main(){

int degre1;
int poly1[100];
int degre2;
int poly2[100];

entreepolynome(&degre1,poly1);
entreepolynome(&degre2,poly2);
sommepolynome(&degre1, poly1, &degre2, poly2);

return 0;


}

int entreepolynome(int *degre, int coeffs[]){

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
printf("Vous avez saisi le polynome suivant : \n");
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

afficherpolynome(&degremax,somme);

}