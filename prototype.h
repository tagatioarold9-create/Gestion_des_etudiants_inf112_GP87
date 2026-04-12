#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <time.h>

typedef struct Employer {
 char matricule[10];
 char name[50];
 int age;
 float salaire;
 int anciennete;
 char date_admission[11];

 struct Employer *suivant;
} Employer; 

typedef struct Produit {
 char name[40];
 char numero_de_serie[20];
 double prix;
 time_t date_peremption;
 int etat;
 struct Produit *suivant;
} Produit;

#endif //PROTOTYPE_H
