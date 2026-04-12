#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gestion_rh.h"

// 1. Génération du matricule (ex: 2026 -> 26A01)
// Format : 2 chiffres année, 1 lettre, 2 chiffres aléatoires
void genererMatricule(char *dest, int annee) {
    int deux_derniers_chiffres = annee % 100;
    char lettre = 'A' + (rand() % 26);
    int reste = rand() % 100;
    sprintf(dest, "%02d%c%02d", deux_derniers_chiffres, lettre, reste);
}

// 2. Création d'un employé
Employer* createEmployer(char name[], int age, float salaire, char date_adm[]) {
    Employer *nouvel = (Employer*)malloc(sizeof(Employer));
    if (nouvel == NULL) return NULL;

    strcpy(nouvel->nom, name);
    nouvel->age = age;
    nouvel->salaire = salaire;
    strcpy(nouvel->date_embauche, date_adm);
    
    // On génère le matricule automatiquement (année 2026 par défaut)
    genererMatricule(nouvel->matricule, 2026);
    
    nouvel->suivant = NULL;
    return nouvel;
}

// 3. Ajouter au début de la liste
void ajouterEnTete(Employer **liste, Employer *nouveau) {
    nouveau->suivant = *liste;
    *liste = nouveau;
}

// 4. Ajouter à la fin de la liste
void ajouterEnFin(Employer **liste, Employer *nouveau) {
    if (*liste == NULL) {
        *liste = nouveau;
        return;
    }
    Employer *temp = *liste;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveau;
}

// 5. Ajouter au milieu (après un matricule précis)
void ajouterAuMilieu(Employer *liste, Employer *nouveau, char matriculeCible[]) {
    Employer *temp = liste;
    while (temp != NULL && strcmp(temp->matricule, matriculeCible) != 0) {
        temp = temp->suivant;
    }
    if (temp != NULL) {
        nouveau->suivant = temp->suivant;
        temp->suivant = nouveau;
    }
}

// 6. Vérifier la retraite (exemple 60 ans)
void verifierRetraite(Employer *liste) {
    Employer *temp = liste;
    printf("\n--- Employés proches de la retraite ---\n");
    while (temp != NULL) {
        if (temp->age >= 60) {
            printf("%s (%s) est éligible à la retraite.\n", temp->nom, temp->matricule);
        }
        temp = temp->suivant;
    }
}

// 7. Enregistrer une démission (suppression par matricule)
void enregistrerDemission(Employer *liste, char matriculeCible[]) {
    // Note: Pour une suppression propre, il faudrait passer l'adresse du pointeur de tête
    // Ici on simule juste en "sautant" l'élément suivant s'il correspond
    Employer *temp = liste;
    while (temp != NULL && temp->suivant != NULL) {
        if (strcmp(temp->suivant->matricule, matriculeCible) == 0) {
            Employer *aSupprimer = temp->suivant;
            temp->suivant = temp->suivant->suivant;
            free(aSupprimer);
            printf("Démission enregistrée pour le matricule %s\n", matriculeCible);
            return;
        }
        temp = temp->suivant;
    }
}

// 8. Bonus d'ancienneté (Exemple simple : +5% pour tous)
void appliquerBonusAnciennete(Employer *liste) {
    Employer *temp = liste;
    while (temp != NULL) {
        temp->salaire *= 1.05;
        temp = temp->suivant;
    }
    printf("Bonus de 5%% appliqué à tout le personnel.\n");
}

// 9. Affichage complet
void afficherPersonnel(Employer *liste) {
    Employer *temp = liste;
    printf("\n%-10s | %-20s | %-3s | %-10s | %-10s\n", "MATRICULE", "NOM", "AGE", "SALAIRE", "EMBAUCHE");
    printf("----------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-10s | %-20s | %d | %-10.2f | %-10s\n", 
               temp->matricule, temp->nom, temp->age, temp->salaire, temp->date_embauche);
        temp = temp->suivant;
    }
}