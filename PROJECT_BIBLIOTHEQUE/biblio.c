#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

# include "biblio.h"






///////////////////////////////////////////////////////////////////////////////////////














/////////////////////////////////////////////////////////////////


void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}



////////////////////////////////////////////////////////////////

void menu_gestion_bibliotheque()

{
        printf("\n****************** BIBLIOTHEQUE *******************\n\n");
        printf("A. Gestion des livres :\n");
        printf("B. Gestion des adh\x82rents :\n");
        printf("C. Gestion des emprunts et des retours :\n");
        printf("Q. Quitter :\n\n");

}

////////////////////////////////////////////////////////////////

void menu_gestion_livre()

{
        printf("\n****************** GESTION(Livres) *******************\n\n");
        printf("1. affichage  les  livres :\n");
        printf("2. Ajouter    les  livres :\n");
        printf("3. Modifier   les  livres :\n");
        printf("4. Supprimer  les  livres :\n");
        printf("5. Quitter :\n\n");

}


//////////////////////////////////////////////////////////////////

void menu_recherhe_livres()

{       printf("\n****************** Recherche (livers) *******************\n\n");
        printf("1. les livres (bibliotheque):\n");
        printf("2. Les livres par genre :\n");
         printf("3. Les livres par titre:\n");
        printf("4. Les livres par auteur :\n");
        printf("5. Les livres par  Edition :\n");
        printf("6. Retour\n");

}

////////////////////////////////////////////////////////////////



void menu_gestion_adherant()

{
        printf("\n****************** GESTION(adherant) *******************\n\n");
        printf("1. affichage adherant:\n");
        printf("2. Ajouter adherant:\n");
        printf("3. Modifier adherant:\n");
        printf("4. Supprimer adherant:\n");
        printf("5. Retour :\n\n");

}



////////////////////////////////////////////////////////////////


 void menu_gestion_emprunt()
 {
     printf("\n****************** GESTION(emprunt) *******************\n\n");
        printf("1. affichage emprunt :\n");
        printf("2. modifier emprunt  :\n");
        printf("3. Ajouter emprunt   :\n");
        printf("4. supprimer emprunt :\n");
        printf("5. Retour:\n\n");
 }




 ///////////////////////////////////////////////////////////////


void menu_modifier_emprunt()
 {
        printf("\n****************** modifier(emprunt) *******************\n\n");
        printf("1. modifier les dates :\n");
        printf("2. ajouter les livres  :\n");
        printf("3. Retour :\n");

 }

















/////////////////////////////////////////////////////////////////



listlivre newlivre()

  {
    listlivre newl=(listlivre)malloc(sizeof(Clivre));

             if (newl!=NULL)
                {

                   printf("id :");
                   scanf("%d",&(newl->datalivre.id));


                   printf("titre :");
                   fflush(stdin);
                   gets(newl->datalivre.titre);


                   printf("auteur:");
                   gets(newl->datalivre.auteur);

                   printf("genre :");
                   gets(newl->datalivre.genre);
                   fflush(stdin);

                   printf("edition:");
                   gets(newl->datalivre.edition);
                   fflush(stdin);

                   newl->prc=NULL;
                   newl->next=NULL;

                   return newl;

                 }

             else
                 {
                  printf("la memoire est sature" );
                 }

}





/////////////////////////////////////////////////////////////////







listlivre ajout_livre(listlivre Ll)
{
      if(Ll==NULL)
      {
         Ll=newlivre();
         return Ll ;
      }

      else
      {

                    listlivre newl=newlivre();


                      Ll->prc=newl;
                      newl->next=Ll;
                      Ll=newl;




                       }
     return Ll;


}



/////////////////////////////////////////////////////////////////////////////////////////////////////////




listlivre modifier_Livre(listlivre L,int id)
{
    if(L==NULL)
    {
        printf("la liste est vide");
        return NULL;
    }
    else
    {
        listlivre tmp=L;
        while(tmp!=NULL&&tmp->datalivre.id!=id)
        {
            tmp=tmp->next;
        }
            if(tmp==NULL)
            printf("le livre n'existe pas !");
            else
            {
     printf("saisir le nouveau nom de livre     : ");
     fflush(stdin);
     gets(tmp->datalivre.titre);
    fflush(stdin);
     printf("saisir le nouveau nom de l'auteur de livre : ");
     gets(tmp->datalivre.auteur);
    fflush(stdin);
     printf("saisir le nouveau genre de livre   : ");
    gets(tmp->datalivre.genre);
    fflush(stdin);
     printf("saisir la nouvelle editon de livre : ");
     gets(tmp->datalivre.edition);
            }
    }
    return L;
}





/////////////////////////////////////////////////////////////////////////////////////////////








listlivre supp_livre(listlivre La,int id)
{
    if(La==NULL)
        printf("suppression impossible\n");

    else
    {   listlivre tmp=La;
        if(La->datalivre.id==id)
        {
            La=La->next;
            free(tmp);
        }
        else
        {
            while(tmp!=NULL&&tmp->datalivre.id!=id)
                tmp=tmp->next;
                if(tmp!=NULL)
                {
                      tmp->prc->next=tmp->next;
            if(tmp->next!=NULL)
                tmp->next->prc=tmp->prc;
                free(tmp);
                }
                else
                    printf("livre introuvable\n");


        }


    }
    return La;

}



////////////////////////////////////////////////////////////////////////////////////////////




void aff_livres(listlivre Ll)
{
    listlivre tmp = Ll;
   if(Ll==NULL)
   {
       printf("pas de livre");
   }
   else
   {


    while(tmp != NULL) {
        printf("-----------------------\n");
        printf("id: %d \n", tmp->datalivre.id);
        printf("titre : %s \n", tmp->datalivre.titre);
        printf("auteur: %s \n", tmp->datalivre.auteur);
        printf("genre : %s \n", tmp->datalivre.genre);
        printf("edition: %s \n", tmp->datalivre.edition);
        printf("-----------------------\n");

        tmp = tmp->next;
    }
     getch();
     system("cls");
   }
}
//////////////////////////////////////////////////////////////////////////////////////////////




void aff_livres_genre(listlivre Ll) {



    listlivre tmp = Ll;
    int found = 0;

    if (Ll == NULL) {
        printf("Pas de livre\n");
        return;
    }
char genre[100];
    printf("Entrez le genre: ");
    gets(genre);
    fflush(stdin);

    printf("Livres du genre %s:\n", genre);
    while (tmp != NULL) {
        if (strcmp(tmp->datalivre.genre,genre) == 0) {
            printf("-----------------------\n");
            printf("id: %d \n", tmp->datalivre.id);
            printf("titre : %s \n", tmp->datalivre.titre);
            printf("auteur: %s \n", tmp->datalivre.auteur);
            printf("genre : %s \n", tmp->datalivre.genre);
            printf("edition: %s \n", tmp->datalivre.edition);
            printf("-----------------------\n");
            found = 1;
        }
        tmp = tmp->next;
    }

    if (!found) {
        printf("Aucun livre trouvé pour ce genre.\n");
    }
    getch();
 system("cls");
}


//////////////////////////////////////////////////////////////////////////////////////////////


void aff_livres_auteur(listlivre Ll) {



    listlivre tmp = Ll;
    int found = 0;


    if (Ll == NULL) {
        printf("Pas de livre\n");
        return;
    }

    char auteur[100];
    printf("Entrez le nom de l'auteur: ");
    gets(auteur);

    printf("Livres de l'auteur %s:\n", auteur);
    while (tmp != NULL) {
        if (strcmp(tmp->datalivre.auteur, auteur) == 0) {
            printf("-----------------------\n");
            printf("id: %d \n", tmp->datalivre.id);
            printf("titre : %s \n", tmp->datalivre.titre);
            printf("auteur: %s \n", tmp->datalivre.auteur);
            printf("genre : %s \n", tmp->datalivre.genre);
            printf("edition: %s \n", tmp->datalivre.edition);
            printf("-----------------------\n");
            found = 1;
        }
        tmp = tmp->next;
    }

    if (!found) {
        printf("Aucun livre trouvé pour cet auteur.\n");
    }
    getch();
    system("cls");
}




////////////////////////////////////////////////////////////////////////////////////////


void aff_livres_titre(listlivre Ll) {





    listlivre tmp = Ll;
    int found = 0;


    if (Ll == NULL) {
        printf("Pas de livre\n");
        return;
    }
  char titre[100];
    printf("Entrez le titre : ");
    gets(titre);
    printf("Livres de titre %s:\n",titre);
    while (tmp != NULL) {
        if (strcmp(tmp->datalivre.titre, titre) == 0) {
            printf("-----------------------\n");
            printf("id: %d \n", tmp->datalivre.id);
            printf("titre : %s \n", tmp->datalivre.titre);
            printf("auteur: %s \n", tmp->datalivre.auteur);
            printf("genre : %s \n", tmp->datalivre.genre);
            printf("edition: %s \n", tmp->datalivre.edition);
            printf("-----------------------\n");
            found = 1;
        }
        tmp = tmp->next;
    }

    if (!found) {
        printf("Aucun livre trouvé pour ce titre.\n");
    }
    getch();
    system("cls");
}
















////////////////////////////////////////////////////////////////////////////////////////


void aff_livres_edition(listlivre Ll) {






    listlivre tmp = Ll;
    int found = 0;

    if (Ll == NULL) {
        printf("Pas de livre\n");
        return;
    }
 char edition[100];
    printf("Entrez le nom de l'édition : ");
     gets(edition);
    printf("Livres de l'édition %s:\n", edition);
    while (tmp != NULL) {
        if (strcmp(tmp->datalivre.edition, edition) == 0) {
            printf("-----------------------\n");
            printf("id: %d \n", tmp->datalivre.id);
            printf("titre : %s \n", tmp->datalivre.titre);
            printf("auteur: %s \n", tmp->datalivre.auteur);
            printf("genre : %s \n", tmp->datalivre.genre);
            printf("edition: %s \n", tmp->datalivre.edition);
            printf("-----------------------\n");
            found = 1;
        }
        tmp = tmp->next;
    }

    if (!found) {
        printf("Aucun livre trouvé pour cette édition.\n");
    }
    getch();
    system("cls");
}




///////////////////////////////////////////////////////////////////////////////////////


void aff_adherant(listeAdherant La)
{
    if(La==NULL)
        printf("liste est vide");
    else
         {listeAdherant tmp=La;
           while(tmp!=NULL)
      {    printf("-----------------------\n");
        printf("  id:%d\n  prenom:%s\n  nom:%s\n  adresse:%s\n",tmp->dataAdr.numadher,tmp->dataAdr.nom,tmp->dataAdr.prenom,tmp->dataAdr.adresse);
         printf("-----------------------\n");
        tmp=tmp->next;
    }
     getch();
     system("cls");

        }
}






//////////////////////////////////////////////////////////////////////////////////////////////






listeAdherant newadherant()
{
 listeAdherant newA =(listeAdherant)malloc(sizeof(Cadherant));

 if (newA!=NULL)
 {
    printf("saisir id  :");
    scanf("%d",&(newA->dataAdr.numadher));


    printf("saisir le nom:");
    scanf("%s",(newA->dataAdr.nom));


     printf("saisir le prenom:");
    scanf("%s",(newA->dataAdr.prenom));

    printf("saisir l'adresse:");

    scanf("%s",(newA->dataAdr.adresse));




    newA->prc=NULL;
    newA->next=NULL;
     return newA;
 }
 else
 {
      printf("la memoire est sature" );

 }


}

////////////////////////////////////////////////////////////////////////////////////////////




listeAdherant ajout_Adherant(listeAdherant La)
{
   listeAdherant newA = newadherant();
     if(La==NULL)
        {La=newA;
        return La;

        }
     else
        { listeAdherant tmp=La;
         while(tmp!=NULL&&(strcmp(newA->dataAdr.nom , tmp->dataAdr.nom )== 0))
       {
            tmp=tmp->next;
       }

       if(tmp!=NULL)
       {
               newA->next=tmp;
           if(tmp->prc!=NULL)
           {
               newA->prc=tmp->prc;
               newA->prc->next=newA;
           }
               tmp->prc=newA;
               La=newA;
       }
       else
       {
           tmp->prc->next=newA;
           newA->prc=tmp->prc;
       }
        return La;
    }


}





////////////////////////////////////////////////////////////////////////////////////////////////////




listeAdherant modifier_adherant(listeAdherant L,int nmr )
{
    if(L==NULL)
    {
        printf("la liste est vide");
        return NULL;
    }
    else
    {
        listeAdherant tmp=L;
        while(tmp!=NULL&&tmp->dataAdr.numadher!= nmr)
        {
            tmp=tmp->next;
        }
            if(tmp==NULL)
            printf("l adherant n'existe pas !");
            else
            {
       fflush(stdin);
       printf("saisir le nouveau nom      : ");
       gets(tmp->dataAdr.nom);
       fflush(stdin);
       printf("saisir le nouveau prenom  : ");
       gets(tmp->dataAdr.prenom);
       fflush(stdin);
       printf("saisir l adresse    : ");
       gets(tmp->dataAdr.adresse);
       fflush(stdin);
            }
    }
    return L;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////




listeAdherant supp_adherant(listeAdherant La,int id)
{
    if(La==NULL)

        printf("suppression impossible\n");

    else
    {   listeAdherant tmp=La;
        if(La->dataAdr.numadher == id)
        {
            La=La->next;
            free(tmp);
        }
        else
        {
            while(tmp!=NULL&&tmp->dataAdr.numadher!=id)
                tmp=tmp->next;
                if(tmp!=NULL)
                {
                      tmp->prc->next=tmp->next;
            if(tmp->next!=NULL)
                tmp->next->prc=tmp->prc;
                free(tmp);
                }
                else
                    printf("livre introuvable\n");


        }


    }
    return La;

}






///////////////////////////////////////////////////////////////////////////////////////////////////////////////




int is_valid_date(date emp, date retour) {
    if (retour.mois > emp.mois) {
        return 1;
    } else if (retour.mois == emp.mois && retour.jour > emp.jour) {
        return 1;
    } else {
        return 0;
    }
}




///////////////////////////////////////////////////////////////////////////////////////////////////////////////





emprint* new_emprint(int adherant_id, int livre_id) {
    emprint* newemp = (emprint*)malloc(sizeof(emprint));

    if (newemp != NULL) {
        printf("nmr emprint :");
        scanf("%d", &(newemp->nmrEMP));

        newemp->id_adherant_emp = adherant_id;

        newemp->liste_livre_emp = (livre_emp*)malloc(sizeof(livre_emp));

        if (newemp->liste_livre_emp != NULL) {
            newemp->liste_livre_emp->livre_id_emp = livre_id;

            printf("Enter la date d'emprint (jour mois) : ");
            scanf("%d %d", &(newemp->liste_livre_emp->date_emp.jour), &(newemp->liste_livre_emp->date_emp.mois));

            printf("Enter la date de retoure (jour mois) : ");
            scanf("%d %d", &(newemp->liste_livre_emp->date_retour.jour), &(newemp->liste_livre_emp->date_retour.mois));

            if (!is_valid_date(newemp->liste_livre_emp->date_emp, newemp->liste_livre_emp->date_retour)) {
                printf("Erreur: la date de retour doit être après la date d'emprint.\n");
                free(newemp->liste_livre_emp);
                free(newemp);
                return NULL;
            }

            newemp->liste_livre_emp->prec = NULL;
            newemp->liste_livre_emp->next = NULL;
        } else {
            printf("La memoire est saturee\n");
            free(newemp);
            return NULL;
        }

        newemp->prec = NULL;
        newemp->next = NULL;

        return newemp;
    } else {
        printf("La memoire est saturee\n");
        return NULL;
    }
}






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////






emprint* ajout_emp(emprint* Lm,listeAdherant La,listlivre Ll)
{


    int adherant_id;
    int livre_id;
    listeAdherant tmpa=La;
    printf("saisir nmr Adherant :");
    scanf("%d",&adherant_id);



              while(tmpa!=NULL&&tmpa->dataAdr.numadher!=adherant_id)
                   {
                      tmpa=tmpa->next;

                   }

                   if(tmpa!=NULL)
                      { emprint* tmp=Lm;

                        ////recherche dans les emprint si l adherant exist deja ////
                            while(tmp!=NULL&&tmp->id_adherant_emp!=adherant_id)
                                 {
                                   tmp=tmp->next;

                                 }

                                 if(tmp!=NULL)
                                 {
                                       printf("l adherent exist deja \n");
                                                        return ;


                                 }
                                 else

                                {

                                         //// ajouter une nouveau emprint ////////////

                                                listlivre tmpa=Ll;
                                                printf("saisir id livre :");
                                                scanf("%d",&livre_id);
                                            if (test_livre_emp(Lm,Ll,livre_id)==1)
                                               {
                                                   emprint* new_EMP = new_emprint(adherant_id,livre_id);
                                                   Lm=ajouter_emprint_debut( Lm,new_EMP);
                                                   system("cls");
                                                   return Lm;
                                                }
                                                else
                                                    {
                                                     system("cls");
                                                    return ;
                                                }



                                }
                      }

                 else
                      {
                        printf("adherant n exist pas deja dans la list des adherant");
                      }
      getch();
     system("cls");
}






////////////////////////ajoute emprint debut//////////////////////////////





emprint* ajouter_emprint_debut(emprint* Lm,emprint* new_EMP)

{


 if(Lm==NULL)
   Lm=new_EMP;

else
 {

       new_EMP->next=Lm;
       Lm->prec=new_EMP;
       Lm=new_EMP;

    }
   return Lm;
}



////////////////////////////////////////////////////////////////////////////////




livre_emp* ajouter_livre_emp(emprint* tmp,int livre_id)

 {
     livre_emp* newlivrEM =(livre_emp*)malloc(sizeof(livre_emp));

                                if (newlivrEM!=NULL)
                                {

                                  newlivrEM->livre_id_emp=livre_id;

                                  printf("Enter la date d'emprint : ");
                                  scanf("%d / %d ", &(newlivrEM->date_emp.jour), &(newlivrEM->date_emp.mois));

                                  printf("Enter la date de retoure : ");
                                  scanf("%d / %d ", &(newlivrEM->date_retour.jour), &(newlivrEM->date_emp.mois));



                                   newlivrEM->next=tmp->liste_livre_emp;
                                   tmp->liste_livre_emp->prec=newlivrEM;
                                   tmp->liste_livre_emp=newlivrEM;
                                   return tmp->liste_livre_emp ;
                                }
                                else
                                {
                                 printf("la memoire est sature" );
                                }

}

////////////////////////////////////////////////////////////////////////////

////

livre_emp* creer_livre_emp(int livre_id) {
    livre_emp* newlivreEM = (livre_emp*)malloc(sizeof(livre_emp));
    if (newlivreEM == NULL) {
        printf("La memoire est saturee.\n");
        return NULL;
    }

    newlivreEM->livre_id_emp = livre_id;

    printf("Enter la date d'emprunt (jour/mois) : ");
    scanf("%d / %d", &(newlivreEM->date_emp.jour), &(newlivreEM->date_emp.mois));

    printf("Enter la date de retour (jour/mois) : ");
    scanf("%d / %d", &(newlivreEM->date_retour.jour), &(newlivreEM->date_retour.mois));

    newlivreEM->next = NULL;
    newlivreEM->prec = NULL;

    return newlivreEM;
}

//////

/////////////////////////////////////////////////////////////////////////////////////





int verifier_livre_existe(listlivre Ll, int livre_id) {
    listlivre tmp = Ll;
    while (tmp != NULL) {
        if (tmp->datalivre.id == livre_id) {
            return 1;  // Le livre existe dans la bibliothèque
        }
        tmp = tmp->next;
    }
    return 0;  // Le livre n'existe pas dans la bibliothèque
}
////////////////////////////////////////////////////////////////////////////////




int verifier_livre_emprunte(emprint* Lm, int livre_id) {
    emprint* tmp = Lm;
    while (tmp != NULL) {
        livre_emp* livreTmp = tmp->liste_livre_emp;
        while (livreTmp != NULL) {
            if (livreTmp->livre_id_emp == livre_id) {
                return 1;  // Le livre est déjà emprunté
            }
            livreTmp = livreTmp->next;
        }
        tmp = tmp->next;
    }
    return 0;  // Le livre n'est pas emprunté
}




/////////////////////////////////////////////////////////////////////////////

//
//
void ajouter_livre_emprint(emprint* Lm, listlivre Ll) {
    int adherant_id, livre_id;

    printf("Entrer l'identifiant de l'adhérent : ");
    scanf("%d", &adherant_id);

    printf("Entrer l'identifiant du livre : ");
    scanf("%d", &livre_id);

    // Vérifier si le livre existe dans la bibliothèque
    if (!verifier_livre_existe(Ll, livre_id)) {
        printf("Le livre n'existe pas dans la bibliothèque.\n");
        return;
    }

    // Vérifier si le livre est déjà emprunté
    if (verifier_livre_emprunte(Lm, livre_id)) {
        printf("Le livre est déjà emprunté.\n");
        return;
    }

    emprint* tmp = Lm;

    // Rechercher l'emprunt correspondant à l'adhérent
    while (tmp != NULL) {
        if (tmp->id_adherant_emp == adherant_id) {
            livre_emp* livreTmp = tmp->liste_livre_emp;

            // Vérifier si le livre est déjà emprunté par cet adhérent
            while (livreTmp != NULL) {
                if (livreTmp->livre_id_emp == livre_id) {
                    printf("Le livre est déjà emprunté par cet adhérent.\n");
                    return;
                }
                livreTmp = livreTmp->next;
            }

            // Ajouter le nouveau livre à la liste des livres empruntés
            livre_emp* newlivreEM = creer_livre_emp(livre_id);
            if (newlivreEM == NULL) {
                return;
            }

            // Ajouter le nouveau livre à la tête de la liste des livres empruntés
            newlivreEM->next = tmp->liste_livre_emp;
            if (tmp->liste_livre_emp != NULL) {
                tmp->liste_livre_emp->prec = newlivreEM;
            }
            tmp->liste_livre_emp = newlivreEM;

            printf("Le livre a été ajouté avec succès à l'emprunt.\n");
            return;
        }
        tmp = tmp->next;
    }

    printf("Aucun emprunt trouvé pour l'adhérent %d.\n", adherant_id);
}

//
/////////////////////////////////////////////////////////////////////////////


//
//

int test_livre_emp(emprint* Lm,listlivre Ll,int livre_id)
 {


  listlivre tmpa=Ll;



          ////recherche livre si existe deja dans la liste des livres////
              while(tmpa!=NULL&&tmpa->datalivre.id!=livre_id)
                   {
                      tmpa=tmpa->next;

                   }

                   if(tmpa!=NULL)
                      { emprint* tmp=Lm;

          ////recherche dans les emprints si le livre existe deja ////////
                            while(tmp!=NULL)
                                 {
                                     livre_emp* tmpL=tmp->liste_livre_emp;
                                     while(tmpL!=NULL&&tmpL->livre_id_emp!=livre_id)
                                     {
                                         tmpL=tmpL->next;

                                     }
                                     if (tmpL!=NULL)
                                     {
                                          printf("LE LIVRE et EMPRINTER DEJA");
                                          getch();
                                                 return 0;

                                     }

                                   tmp=tmp->next;

                                 }
                                  //////// le livre n existe pas dans la liste des emprintes //////
                                 return 1;


                      }

                 else
                      {
                        printf("livre  n exist pas  dans la list des livres");
                      }
 }





//
//

/////////////////////////////////////////////////////////////////////



void afficher_emprints(emprint* Lm) {
    emprint* tmp_emp = Lm;
     if(Lm==NULL)
      {

        printf("liste est vide");
      }
      else{

    while (tmp_emp != NULL) {
            printf("--------------------------\n");
            printf(" Numero d'emprint: %d\n",tmp_emp->nmrEMP);
            printf(" ID Adherant: %d\n",tmp_emp->id_adherant_emp);


        livre_emp* tmp_livre = tmp_emp->liste_livre_emp;
        while (tmp_livre != NULL) {
            printf("  Livre ID: %d\n", tmp_livre->livre_id_emp);
            printf("  Date d'emprint: %d/%d\n", tmp_livre->date_emp.jour, tmp_livre->date_emp.mois);
            printf("  Date de retour: %d/%d\n", tmp_livre->date_retour.jour, tmp_livre->date_retour.mois);
            printf("-----------------------------\n");
            tmp_livre = tmp_livre->next;
        }

        tmp_emp = tmp_emp->next;
        printf("\n");
    }}
    getch();
     system("cls");

}







////////////////////////////////////////////////////////////////////////////////////////////////////////////


void supprimer_livre_emprunt(livre_emp** liste_livre_emp) {
    livre_emp* tmp = *liste_livre_emp;
    while (tmp != NULL) {
        livre_emp* to_delete = tmp;
        tmp = tmp->next;
        free(to_delete);
    }
    *liste_livre_emp = NULL;
}

void supprimer_emprint(emprint** Lm, int adherant_id) {
    emprint* tmp = Lm;
    emprint* prec = NULL;

    while (tmp != NULL) {
        if (tmp->id_adherant_emp == adherant_id) {
            // Supprimer tous les livres empruntés de cet emprunt
            supprimer_livre_emprunt(&(tmp->liste_livre_emp));

            // Supprimer l'emprunt lui-même
            if (prec == NULL) { // Si l'emprunt à supprimer est le premier de la liste
                *Lm = tmp->next;
                if (*Lm != NULL) {
                    (*Lm)->prec = NULL;
                }
            } else {
                prec->next = tmp->next;
                if (tmp->next != NULL) {
                    tmp->next->prec = prec;
                }
            }

            free(tmp);
            printf("L'emprunt de l'adhérent %d a été supprimé avec succès.\n", adherant_id);
            return;
        }

        prec = tmp;
        tmp = tmp->next;
    }

    printf("Aucun emprunt trouvé pour l'adhérent %d.\n", adherant_id);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void modifier_emprint_dates(emprint* Lm) {
    int adherant_id, livre_id;

    printf("Entrer l'identifiant de l'adhérent : ");
    scanf("%d", &adherant_id);

    printf("Entrer l'identifiant du livre : ");
    scanf("%d", &livre_id);

    emprint* tmp = Lm;

    // Rechercher l'emprunt correspondant à l'adhérent et au livre
    while (tmp != NULL) {
        if (tmp->id_adherant_emp == adherant_id) {
            livre_emp* livreTmp = tmp->liste_livre_emp;
            while (livreTmp != NULL) {
                if (livreTmp->livre_id_emp == livre_id) {
                    // Emprunt trouvé, demandez les nouvelles informations à l'utilisateur
                    printf("Modifier les informations de l'emprunt pour le livre ID %d:\n", livre_id);

                    printf("Entrer la nouvelle date d'emprunt (jour/mois) : ");
                    scanf("%d / %d", &(livreTmp->date_emp.jour), &(livreTmp->date_emp.mois));

                    printf("Entrer la nouvelle date de retour (jour/mois) : ");
                    scanf("%d / %d", &(livreTmp->date_retour.jour), &(livreTmp->date_retour.mois));

                    printf("Modification réussie.\n");
                    return;
                }
                livreTmp = livreTmp->next;
            }
        }
        tmp = tmp->next;
    }
    printf("Aucun emprunt trouvé pour l'adhérent %d avec le livre %d.\n", adherant_id, livre_id);
     getch();
     system("cls");
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void supper_emprint_simple(emprint** Lm, int adherant_id) {
    emprint* tmp = *Lm;
    emprint* prec = NULL;

    while (tmp != NULL) {
        if (tmp->id_adherant_emp == adherant_id) {
            if (prec == NULL) { // Si l'emprunt à supprimer est le premier de la liste
                *Lm = tmp->next;
                if (*Lm != NULL) {
                    (*Lm)->prec = NULL;
                }
            } else {
                prec->next = tmp->next;
                if (tmp->next != NULL) {
                    tmp->next->prec = prec;
                }
            }
            free(tmp);
            printf("L'emprunt de l'adhérent %d a été supprimé avec succès.\n", adherant_id);
            return;
        }
        prec = tmp;
        tmp = tmp->next;
    }

    printf("Aucun emprunt trouvé pour l'adhérent %d.\n", adherant_id);
}
















































