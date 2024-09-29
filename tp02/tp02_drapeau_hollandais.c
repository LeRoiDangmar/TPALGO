#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char DATA;

void print(DATA array[], int size){
    for(int i = 0; i < size; i++ ){
        printf("%c \n",array[i]);
    }
}

void random_fill(DATA array[], int size){
    int couleur;
    for (int i = 0; i < size; i++) {
        couleur = 1 + rand() % (3 - 1 + 1);
        switch (couleur)
        {
        case 1:
            array[i] = 'R';
            break;
        
        case 2:
            array[i] = 'W';
            break;

        case 3:
            array[i] = 'B';
            break;

        default:
            break;
        }
    }
}


void tri_linaire_une_passe(DATA array[], int size) {
    int bas = 0, milieu = 0, haut = size - 1;
    
    while (milieu <= haut) {
        if (array[milieu] == 'R') {
            // Échanger array[bas] et array[milieu]
            int temp = array[bas];
            array[bas] = array[milieu];
            array[milieu] = temp;
            bas++;
            milieu++;
        } else if (array[milieu] == 'W') {
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