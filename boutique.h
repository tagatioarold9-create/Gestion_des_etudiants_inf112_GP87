#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include "prototype.h" // Indispensable pour avoir la structure avec 'int etat'

/* ---------------------------------------------------------
   INTERFACE DE GESTION DU STOCK (BINÔME 2)
   Ce fichier gère le cycle de vie des produits : 
   0: Rayon | 1: Vendu | 2: Périmé | 3: Volé
   --------------------------------------------------------- */

/**
 * Crée un produit et initialise l'état à 0 (En rayon) par défaut.
 * (L'allocation mémoire par malloc est faite dans le .c)
 */
Produit* createProduit(char name[], char serie[], double prix, int jours);

/**
 * Ajoute un produit créé à la liste chaînée du stock.
 */
void ajouterAuStock(Produit **tete, Produit *nouveau);

/**
 * Change l'état d'un produit spécifique via son numéro de série.
 * Utile pour le Binôme 4 (Ventes) pour passer l'état de 0 à 1.
 */
void modifierEtatProduit(Produit *tete, char serie[], int nouvelEtat);

/**
 * Détecte les écarts entre le stock théorique (état 0) et le stock réel.
 */
void verifierVols(Produit *tete, char nomProduit[], int quantitePhysique);

/**
 * Parcourt le stock et change l'état à 2 si la date est dépassée.
 */
void marquerPerimes(Produit *tete);

/**
 * Affiche l'inventaire complet incluant la valeur de l'état.
 */
void afficherInventaire(Produit *tete);

#endif