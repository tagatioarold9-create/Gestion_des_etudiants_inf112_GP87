#ifndef GESTION_RH_H
#define GESTION_RH_H

#include "prototype.h" 

void genererMatricule(char *dest, int annee);

Employer* createEmployer(char name[], int age, float salaire, char date_adm[]);

void ajouterEnTete(Employer **liste, Employer *nouveau);

void ajouterEnFin(Employer **liste, Employer *nouveau);

void ajouterAuMilieu(Employer *liste, Employer *nouveau, char matriculeCible[]);

void verifierRetraite(Employer *liste);

void enregistrerDemission(Employer *liste, char matriculeCible[]);

void appliquerBonusAnciennete(Employer *liste);

void afficherPersonnel(Employer *liste);

#endif // GESTION_RH_H