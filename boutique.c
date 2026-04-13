#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boutique.h"

// 1. Création d'un nouvel article
Article* createArticle(char designat[], int qte, float prix) {
    Article *nouvelArticle = (Article*)malloc(sizeof(Article));
    if (nouvelArticle == NULL) {
        printf("Erreur d'allocation memoire !\n");
        return NULL;
    }

    strcpy(nouvelArticle->designation, designat);
    nouvelArticle->quantite = qte;
    nouvelArticle->prix_unitaire = prix;
    nouvelArticle->suivant = NULL;

    return nouvelArticle;
}

// 2. Ajouter un article au stock (en fin de liste)
void ajouterArticle(Article **stock, Article *nouvel) {
    if (*stock == NULL) {
        *stock = nouvel;
        return;
    }
    Article *temp = *stock;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouvel;
}

// 3. Afficher l'état du stock
void afficherStock(Article *stock) {
    Article *temp = stock;
    printf("\n--- ETAT DU STOCK BOUTIQUE ---\n");
    printf("%-20s | %-10s | %-15s\n", "DESIGNATION", "QUANTITE", "PRIX UNITAIRE");
    printf("------------------------------------------------------------\n");
    while (temp != NULL) {
        printf("%-20s | %-10d | %-10.2f FCFA\n", 
               temp->designation, temp->quantite, temp->prix_unitaire);
        temp = temp->suivant;
    }
}

// 4. Rechercher un article par son nom
Article* rechercherArticle(Article *stock, char nomCible[]) {
    Article *temp = stock;
    while (temp != NULL) {
        if (strcmp(temp->designation, nomCible) == 0) {
            return temp;
        }
        temp = temp->suivant;
    }
    return NULL; // Non trouvé
}

// 5. Mettre à jour la quantité (Vente ou Réapprovisionnement)
void modifierQuantite(Article *stock, char nomCible[], int variation) {
    Article *art = rechercherArticle(stock, nomCible);
    if (art != NULL) {
        art->quantite += variation;
        printf("Nouvelle quantite pour %s : %d\n", nomCible, art->quantite);
    } else {
        printf("Article %s introuvable dans le stock.\n", nomCible);
    }
}

// 6. Calculer la valeur totale du stock
float calculerValeurStock(Article *stock) {
    float total = 0;
    Article *temp = stock;
    while (temp != NULL) {
        total += (temp->quantite * temp->prix_unitaire);
        temp = temp->suivant;
    }
    return total;
}