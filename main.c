#include <stdio.h>

int entreepolynome(int *degre, int coeffs[]); //prend en entree le degré du polynomes et ses coeffs
int sommepolynome(int degre1, int coeffs1[], int degre2, int coeffs2[], int resultat[]);


int main(){

int degre1;
int poly1[100];
int degre2;
int poly2[100];

entreepolynome(&degre1,poly1);

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

printf("Vous avez saisi le polynome suivant : \n");
for(int i = 0;i<=*degre;i++){ printf("a_%d = %d \n",i,coeffs[i]); }



}


int sommepolynome(int degre1, int coeffs1[], int degre2, int coeffs2[], int resultat[]){
int degremax;
if(degre1<degre2){ degremax = degre2};
else{degremax = degre1;}

for 

}


