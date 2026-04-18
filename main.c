#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gestion_rh.h"
#include "boutique.h"
#define ROUGE "\033[31m"
#define VERT "\033[32m"
#define RESET "\033[0m"

int main(void){

//initialisation des liste à NULL
employe *listRH = NULL;
produit *stockproduit = NULL;

// menue principal
    printf("===================================================================\n");
    printf("***************     SYSTEME DE GESTION INTEGRE    *****************\n");
    printf("===================================================================\n");
    printf("1. Gestion des Ressource Humaine\n");
    printf("2. Gestion du stock\n");
    printf( ROUGE "3. Quitter\n" RESET);
    int choix ;
    printf("\n");
    printf("choix:_");
    scanf("%d",&choix);

    //menu secondaire
    switch (choix)
    {
    case 1 :{ 
        int choix ;
        char name[50];
        char date_admission[11];
        int age ;
        float salaire ;

//GESTION RH
    printf("========================= Gestion RH =========================\n");
    printf("1.ajoutez un nouvel employé\n");
    printf("2.Affichez la liste des employes\n");
    printf("3.Enregistrer une demission\n");
    printf("4.Vérifiez la retraite\n");
    printf("5.Bonus d'anciènneté\n");
    printf("\n");
    printf("choix :_");
    scanf("%d",&choix);
printf("\nveillez patientez..........");

    switch(choix)
    {

//crée un nouvel employé
        case 1:
        {
            int choix ; 

    printf("1. Ajoutez au debut | 2. Ajoutez après un matricule precis | 3. Ajoutez a la fin\n");
        printf("choix :_");
        scanf("%d",&choix);
printf("\nveillez patientez..........");

    if (choix=1)
    {
    printf("entrez le nom :");
    scanf("%s\n", name);
    printf("entrez l'age : ");
    scanf("%d\n",&age);
    printf("entez le salaire :");
    scanf("%f\n",&salaire);
    printf("entrez la date date d'admission: ");
    scanf("%s",date_admission);
printf("\nveillez patientez..........");

    employe *emp = createEmployer(char name[], int age,float salaire,char date_admission[]);
    if(emp!=NULL)
        ajouterEnTete(&listRH ,&emp);

    printf("l'employe VERT"%s"RESET à été ajouté avec succes !",emp->name);
    }
 if (choix=2)
    {
    printf("entrez le nom :");
    scanf("%s\n", name);
    printf("entrez l'age : ");
    scanf("%d\n",&age);
    printf("entez le salaire :");
    scanf("%f\n",&salaire);
    printf("entrez la date date d'admission: ");
    scanf("%s",date_admission);
printf("\nveillez patientez..........");

    employe *emp = createEmployer(char name[], int age,float salaire,char date_admission[]);
char matriculecible [20];
    if(emp!=NULL){
        printf("entrer le matricule cible : ");
        scanf("%s",mateiculecible);
ajouterAuMilieu(&listRH ,&emp, char matriculecible[]);
    }
    
    printf("l'employe VERT"%s"RESET à été ajouté avec succes !",emp->name);
        }
 if (choix=3)
    {
    printf("entrez le nom :");
    scanf("%s\n", name);
    printf("entrez l'age : ");
    scanf("%d\n",&age);
    printf("entez le salaire :");
    scanf("%f\n",&salaire);
    printf("entrez la date date d'admission: ");
    scanf("%s",date_admission);
printf("\nveillez patientez..........");
    employe *emp = createEmployer(char name[], int age,float salaire,char date_admission[]);
    if(emp!=NULL)
        ajouterEnFin(&listRH ,&emp);

    printf("l'employe VERT"%s"RESET à été ajouté avec succes !",emp->name);
    
    }
        break;
    }
    //affichez la liste des employe
    case 2:
    afficherPersonnel(&listRH);
    break;
   //enregistrer une demition
   case 3:
   {
     char matriculecible[20];
     char validation[2]={'O';'N'};
     printf("entrez le matricule du demissionaires : ");
     scanf(ROUGE "%s" RESET , matriculecible);
     printf("\n êtes vous sur de vouloir validé cette demission ?  O/N   :_");
     scanf("%s", validation);
     if( validation[] = 'O'){
        enregistrerDemission(&ListRH , char matriculecible );
        printf(VERT"demission validé avec succes !\n"RESET);
     } else {
        printf(VERT "demission annuler\n" RESET)
        exit(0);
        return ;
     }
      break;
   }
   //verifier retraite 
   case 4: 
   verifierRetraite(&listRH);
    break;
  // bonus d'encienneté
  case 5:
  appliquerBonusAnciennete(&listRH);
  break ;

  default : 
  printf(ROUGE"choix non disponible ;"RESET);
  return ;
  break;
    }
    break;
}
//gestion du stock
case 2 :
{ 
     
    int choix ;
 printf("========================= Gestion du stock =========================\n");
    printf("1.Ajoutez un nouvel article\n");
    printf("2.Afficher l'etat du stock\n");
    printf("3.Rechercher un article \n");
    printf("4.mettre a jour la quantités\n");
    printf("5.determiner la valeur Total du stock\n");
    printf("\n");
    printf("choix :_");
    scanf("%d",&choix);
printf("\nveillez patientez..........");

char designation [30];
int qte;
double prix ; 

    switch (choix)
    {
        // ajoutez un article
    case 1:
    {
    printf("entrez la designation :");
    scanf("%s\n", designation);
    printf("entrez la quantite : ");
    scanf("%d\n",&qte);
    printf("entez le prix :");
    scanf("%lf\n",&prix);
printf("\nveillez patientez..........");

     produit *p = createArticle(char designation [], int qte, double prix) ;
     if(p!=NULL)
     ajouterArticle(&stockproduit ,&p);

    printf("le produit VERT"%s"RESET à été ajouté avec succes !",p->designation);
     
     break;
    }
    // affichez l'eteat de stock
    case 2:
    afficherStock(&stockproduit);
    break;
    //recherche d'un article 
    case 3:
    {
        char nomcible[20];
        printf("\nentrer le nom de l'article que vous recherchez ! :_");
        scanf("%s",nomcible);
printf("\nveillez patientez..........");

        if (nomcible=rechercheArticle(&stockproduit))
        printf(VERT"produit disponible\n"RESET);
        if(nomcible=NULL)
        printf(ROUGE"ce produit n'existe pas !\n"RESET);

        break;
    }
    case 4:
    {
        char nomcible[20];
        int variation ;
        printf("\nentrez le nom de l'article dont vous voulez mettre a jour la quantite ! :_");
        scanf("%s",nomcible);
        printf("\nentrez la quantite que vous aimeriez ajouter! :_");
        scanf("%d",variation);
printf("\nveillez patientez..........");

        modifierQuantite(&stockproduit, char nomcible[], int variation);
     break;
    }
    case 5:
    char validation[2]={'O';'N'};
    printf("voulez vous connaitre la valeur total de votre stock ? : _");
    scanf("%s",validation);
printf("\nveillez patientez..........");

    if( validation[] = 'O'){
        printf(VERT"la valeur total du stock est : "RESET);
        calculerValeurStock(&stockproduit);
     } else {
        printf(VERT "bonne continuation !\n" RESET)
        exit(0);
        return ;
     }

    default:
  printf(ROUGE"choix non disponible ;"RESET);
        break;
    }
    //zone atteinte
    break;
}
case 3:
printf("\nveillez patientez..........");

printf("\nfermeture du programme.....\n");
return ;
break;
  default:
  printf(ROUGE"choix non disponible ;"RESET);
        break;
    }

    return 0;
}
