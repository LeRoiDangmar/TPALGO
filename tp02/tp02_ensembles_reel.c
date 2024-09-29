
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DATA;

void print(DATA array[], int size){
    for(int i = 0; i < size; i++ ){
        printf("%d \n",array[i]);
    }
}

void random_fill(DATA array[], int size){
    for (int i = 0; i < size; i++) {
        array[i] = -1 + rand() % (1 - (-1) + 1);
    }
}


void tri_linaire_une_passe(DATA array[], int size) {
    int bas = 0, milieu = 0, haut = size - 1;
    
    while (milieu <= haut) {
        if (array[milieu] == -1) {
            // Échanger array[bas] et array[milieu]
            int temp = array[bas];
            array[bas] = array[milieu];
            array[milieu] = temp;
            bas++;
            milieu++;
        } else if (array[milieu] == 0 ) {
            milieu++;
        } else { 
            // Échanger array[milieu] et array[haut]
            int temp = array[haut];
            array[haut] = array[milieu];
            array[milieu] = temp;
            haut--;
        }
    }
}

int main(){
    const int size = 30;
    DATA tabchar[size];

    random_fill(tabchar, size);
    print(tabchar, size);

    printf("\n\n TRIE \n\n");

    tri_linaire_une_passe(tabchar, size);
    print(tabchar, size);
}