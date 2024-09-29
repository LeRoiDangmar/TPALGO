#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DATA;

void print2(DATA array[][3], int size){
    
    for(int j = 0; j < 3; j++){
        printf("Colonne %d \n", j);
        for(int i = 0; i < size; i++ ){
            printf("%d \n",array[i][j]);
        }
        printf("\n");
    }
}



void read2(DATA array[][3], int size){
    int valeur;
    for(int j = 0; j < 3; j++){
        printf("Colonne %d \n", j);
        for(int i = 0; i < size; i++ ){
            printf("Entrez la valeur %d \n" , i + 1);
            valeur = 0;
            scanf("%d", &valeur);
            array[i][j] = valeur;
        }
        printf("\n");
    }
}

DATA valeur_max2(DATA array[][3], int size){
    DATA valeur_max = 0;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < size; i++){
            if(array[i][j] > valeur_max){
                valeur_max = array[i][j];
            }
        }
    }
    
    return valeur_max;
}

int occurence2(DATA array[][3], int size, DATA el){
    int compteur = 0;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < size; i++){
            if(array[i][j] == el){
                compteur++;
            }
        }
    }
    return compteur;
}

bool is_sudoku( int array[3][3] ){

    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 3; i++){
            if(array[i][j] > 9 || array[i][j] < 1){
                return false;
            }
            if(occurence2(array, 3, array[i][j]) != 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    const int size = 3;
    DATA Tab2D[size][3];

    read2(Tab2D, size);
    print2(Tab2D, size);

    printf("La valeur max est %d\n", valeur_max2(Tab2D, size));

    if(is_sudoku(Tab2D)){
        printf("C'est un sudoku \n");
    }else {
        printf("C'est PAS un sudoku \n");
    }

    DATA Tab2Dsudoku[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printf("Table sudoku : \n");
    print2(Tab2Dsudoku, size);

    if(is_sudoku(Tab2Dsudoku)){
        printf("C'est un sudoku \n");
    }else {
        printf("C'est PAS un sudoku \n");
    }
}