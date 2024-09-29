#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DATA;

void print(DATA array[], int size){
    for(int i = 0; i < size; i++ ){
        printf("%d \n",array[i]);
    }
}

void read(DATA array[], int size){
    int valeur;
    for(int i = 0; i < size; i++ ){
        printf("Entrez la valeur %d \n" , i + 1);
        valeur = 0;
        scanf("%d", &valeur);
        array[i] = valeur;
    }
}

void random_fill_int(DATA array[], int size, DATA vmin, DATA vmax){
    for (int i = 0; i < size; i++) {
    array[i] = vmin + rand() % (vmax - vmin + 1);
    }
}

void random_fill_float(DATA array[], int size, DATA vmin, DATA vmax){
    for (int i = 0; i < size; i++) {
        float scale = rand() / (float) RAND_MAX; 
        array[i] = vmin + scale * (vmax - vmin);
    }
}


DATA valeur_max(DATA array[], int size){
    DATA valeur_max = 0;
    for(int i = 0; i < size; i++){
        if(array[i] > valeur_max){
            valeur_max = array[i];
        }
    }
    return valeur_max;
}

void swap_elt(DATA array[], int size, int i, int j){
    DATA buffer;
    buffer = array[i];
    array[i] = array[j];
    array[j] = buffer;
}

int occurence(DATA array[], int size, DATA el){
    int compteur = 0;

    for(int i = 0; i < size; i++){
        if(array[i] == el){
            compteur++;
        }
    }
    return compteur;
}

int find_first(DATA array[], int size, DATA el){
    int place = -1; // si on retourne -1 alors on l'a pas trouvé

    for(int i = 0; i < size; i++){
        if(array[i] == el){
            place = i;
            return place;
        }
    }
    return place;
}

int find_last(DATA array[], int size, DATA el){
    int place = -1; // si on retourne -1 alors on l'a pas trouvé

    for(int i = size; i > 0; i--){
        if(array[i] == el){
            place = i;
            return place;
        }
    }
    return place;
}

void reverse(DATA array[], int size){
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}


void rotate_right(DATA array[], int size){
    int last = array[size -1];
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = last;
}

void rotate_left(DATA array[], int size){
    int first = array[0];
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    array[size - 1] = first;
}

bool is_palindrome(DATA array[], int size){
    for (int i = 0; i < size / 2; i++) {
        if (array[i] != array[size - 1 - i]) {
            return false;  // Si un élément ne correspond pas, ce n'est pas un palindrome
        }
    }
    return true;   
}


int main(int argc , char** argv){

    const int size = 20;
    DATA vmin = 0;
    DATA vmax = 20;

    DATA Tab1D[size];


    printf("------------On rempli et on affiche le tableau------------\n \n");

    read(Tab1D, size);
    print(Tab1D, size);

    printf("------------On rempli de random int et on affiche le tableau ------------\n \n");

    random_fill_int(Tab1D, size, vmin, vmax);
    print(Tab1D, size);

    printf("------------On rempli de random float et on affiche le tableau ------------\n \n");
    random_fill_float(Tab1D, size, vmin, vmax);
    print(Tab1D, size);

    printf("------------On donne la valeur max dans le tableau ------------\n \n");
    DATA valmax = valeur_max(Tab1D, size);
    printf("La valeur max du tu tableau est : %d \n",valmax);

    printf("------------On swap l'element 4 et 7  ------------\n \n");
    swap_elt(Tab1D, size, 4, 7);
    print(Tab1D, size);


    printf("------------On compte l'occurence de Entrez un nombre :   ------------\n \n");
    DATA element = 0;
    int occurenceelement = 0;
    scanf("%d", &element);
    occurenceelement = occurence(Tab1D, size, element);
    printf("L'element %d, apparait %d fois dans le tableau", element, occurenceelement);

    printf("------------On cherche la première occurence du même nombre :   ------------\n \n");
    int first = find_first(Tab1D, size, element);
    printf("L'element %d, apparait la première fois a l'indice %d dans le tableau \n", element, first);


    printf("------------On cherche la dernière occurence du même nombre :   ------------\n \n");
    int last = find_last(Tab1D, size, element);
    printf("L'element %d, apparait la dernière fois a l'indice %d dans le tableau \n", element, last);

    printf("------------On inverse le tableau :   ------------\n \n");
    reverse(Tab1D, size);
    print(Tab1D, size); 

    printf("------------On decale à droite:   ------------\n \n");
    rotate_right(Tab1D, size);
    print(Tab1D, size); 

    printf("------------On decale à gauche:   ------------\n \n");
    rotate_left(Tab1D, size);
    print(Tab1D, size); 

    printf("------------On regarde si c'est un palindrome:   ------------\n \n");
    if(is_palindrome(Tab1D, size)){
        printf("C'est un palindrome \n");
    }else{
        printf("Ce n'est pas un palindrome\n");
    }
}