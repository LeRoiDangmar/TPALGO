#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef float Mat33[3][3];

void printMat(Mat33 M){
    for(int j = 0; j < 3; j++){
        printf("Colonne %d \n", j);
        for(int i = 0; i < 3; i++ ){
            printf("%f \n",M[i][j]);
        }
        printf("\n");
    }
}

void readMat(Mat33 M){
    int valeur;
    for(int j = 0; j < 3; j++){
        printf("Colonne %d \n", j);
        for(int i = 0; i < 3; i++ ){
            printf("Entrez la valeur %d \n" , i + 1);
            valeur = 0;
            scanf("%d", &valeur);
            M[i][j] = valeur;
        }
        printf("\n");
    }
}

void SetId(Mat33 M){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            M[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }    
}

void somme(Mat33 A, Mat33 B, Mat33 ApB){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ApB[i][j] = A[i][j] + B[i][j];
        }
    }
}

void produit(Mat33 A, Mat33 B, Mat33 AfB) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            AfB[i][j] = 0; 
            for (int k = 0; k < 3; k++) {
                AfB[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main(){
    Mat33 A; 
    Mat33 B;
    Mat33 ApB;
    Mat33 AfB;

    printf("Matrice A : \n");
    readMat(A);
    printMat(A);

    printf("Matrice B : \n");
    readMat(B);
    printMat(B);

    somme(A, B, ApB);
    produit(A, B, AfB);

    printf("Somme A + B : \n");
    printMat(ApB);

    printf("Produit A x B : \n");
    printMat(AfB);

}