#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float CalculPerimetre(float cote){
    return cote * 4;
}

float CalculSurface(float cote){
    return cote*cote;
}

double CalculDiagonale(float cote){
    double diagonale = cote*cote + cote*cote;
    diagonale = sqrt(diagonale);
    return diagonale;
}


void PartieUne(){
    int entier = 0;
    float reel = 0;

    printf("Entrez un entier \n");

    scanf("%d",&entier);

    printf("Entrez un reel \n");

    scanf("%f", &reel);

    printf("Voici votre entier : %d et voici votre reel : %f \n", entier, reel);

    float perimetre = CalculPerimetre(reel);

    float surface = CalculSurface(reel);

    double diagonale = CalculDiagonale(reel);

    printf("Le perimètre est : %f , la surface est %f, la diagonale est %lf \n", perimetre, surface, diagonale);

}

int AnneeBis(int annee){
    if((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)){
        return 28;
    } else {
        return 29;
    }
}

int CalculNbJourMois(int mois, int annee){

    int grandMois[7] = {1, 3, 5, 7, 8, 10, 12};
    int petitMois[4] = {4, 6, 9, 11};

    int nbJour = 0;

    if(mois == 2){
        return nbJour = AnneeBis(annee);
    }else if(mois == 4 || mois == 6 || mois == 9 || mois == 11){
        return nbJour = 30;
    }else {
        return nbJour = 31;
    }
     
}


void Date(){

    int mois = 0;
    int annee = 0;

    int nbJours = 0;

    printf("Entrez un mois \n");

    scanf("%d", &mois);

    printf("Entrez une année \n");

    scanf("%d", &annee);

    nbJours = CalculNbJourMois(mois, annee);

    printf("Votre mois possède %d jours \n", nbJours);

}

void DifferenceHeure(){

    int heure1 , minute1 , seconde1 = 0;
    int heure2 , minute2 , seconde2 = 0;

    int temps1 = 0;
    int temps2 = 0;

    printf("Entrez une heure, minute, et seconde \n");
    scanf("%d %d %d", &heure1, &minute1, &seconde1);

    temps1 = seconde1 + minute1 * 60 + heure1 * 3600;

    printf("Entrez une autre heure, minute, et seconde \n");
    scanf("%d %d %d", &heure2, &minute2, &seconde2);

    temps2 = seconde2 + minute2 * 60 + heure2 * 3600;

    printf("Heure 1 %d \n Heure 2 %d \n", temps1, temps2);
}

int main(int argc , char** argv){

    PartieUne();

    Date();

    DifferenceHeure();

} 