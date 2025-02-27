#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "biblio.h"

int main()
{

    int choix;
    int choix_modif_emp;
    int supp_ID_em;
    char choix_gestion_biblio;
    int  choix_gestion_livre,choix_gestion_adherant,choix_gestion_emp;
    emprint* Lm=NULL;
    listeAdherant La = NULL;
    listlivre Ll = NULL;




    do
    {
            system("cls");
            menu_gestion_bibliotheque();
            printf("votre choix: ");

            scanf("%c",&choix_gestion_biblio);
            choix_gestion_biblio=toupper(choix_gestion_biblio);



        switch(choix_gestion_biblio)
              {


                case 'A':
                                        system("cls");

               do{
                                        menu_gestion_livre();

                                        printf("votre choix: ");
                                        scanf("%d",&choix_gestion_livre);

                                            system("cls");

                                                switch(choix_gestion_livre)
                                                  {

                                                    case 1:


                                                                                                do {
                                                                                                                        menu_recherhe_livres();

                                                                                                                        printf("\n votre choix: ");
                                                                                                                        scanf("%d", &choix);
                                                                                                                        system("cls");
                                                                                                                        fflush(stdin);

                                                                                                                              switch (choix) {
                                                                                                                                  case 1:
                                                                                                                                      aff_livres(Ll);
                                                                                                                                      break;

                                                                                                                                  case 2:


                                                                                                                                      aff_livres_genre(Ll);
                                                                                                                                      break;
                                                                                                                                   case 3:

                                                                                                                                      aff_livres_titre(Ll);
                                                                                                                                      break;

                                                                                                                                  case 4:

                                                                                                                                      aff_livres_auteur(Ll);
                                                                                                                                      break;

                                                                                                                                  case 5:

                                                                                                                                      aff_livres_edition(Ll);
                                                                                                                                      break;

                                                                                                                                  case 6:

                                                                                                                                       system("cls");
                                                                                                                                      break;

                                                                                                                                  default:
                                                                                                                                      printf("Option invalide. Veuillez réessayer.\n");
                                                                                                                                      break;
                                                                                                                              }
                                                                                                                          } while (choix != 6);



                                                                                                                /////////////////////////////////////////////////////


                                                                            break;

                                                    case 2:
                                                                       system("cls");
                                                                       Ll=ajout_livre(Ll);
                                                                       printf("operation valide");
                                                                       getch();
                                                                       system("cls");


                                                                            break;
                                                    case 3:

                                                                       system("cls");
                                                                       int modif_ID;
                                                                       printf("ID livre a modifier : ");
                                                                       scanf("%d",&modif_ID);
                                                                       Ll=modifier_Livre(Ll,modif_ID);
                                                                       getch();
                                                                       system("cls");

                                                                            break;
                                                    case 4:

                                                                       system("cls");
                                                                       int supp_ID;
                                                                       printf("ID a supprimer: ");

                                                                       scanf("%d",&supp_ID);
                                                                       Ll=supp_livre(Ll,supp_ID);
                                                                       printf("operation valide");
                                                                       getch();
                                                                       system("cls");

                                                                            break;
                                                    default:
                                                         break;
                                                  }

                    }while(choix_gestion_livre!=5);
                                    break;

                case 'B':

                                    system("cls");

                                do{
                                        menu_gestion_adherant();

                                        printf("votre choix: \n");
                                        scanf("%d",&choix_gestion_adherant);

                                            system("cls");

                                                switch(choix_gestion_adherant)
                                                  {

                                                    case 1:   system("cls");
                                                                   aff_adherant(La);


                                                                            break;

                                                    case 2:
                                                                      system("cls");
                                                                       La=ajout_Adherant(La);

                                                                       getch();
                                                                       system("cls");


                                                                            break;
                                                    case 3:
                                                                         system("cls");
                                                                       int modif_ID_a;
                                                                       printf("nmr adherant a modifier : ");
                                                                       scanf("%d",&modif_ID_a);
                                                                       La=modifier_adherant(La,modif_ID_a);
                                                                       getch();
                                                                       system("cls");

                                                                            break;
                                                    case 4:

                                                                       system("cls");
                                                                       int supp_ID_a;
                                                                       printf("nmr adherant (Supprimer):");
                                                                       scanf("%d",&supp_ID_a);
                                                                       La=supp_adherant(La,supp_ID_a);
                                                                       getch();
                                                                       system("cls");


                                                                            break;

                                                       }

                                    }while(choix_gestion_adherant!=5);
                                    break;




                case 'C':

                                          system("cls");
                             do{
                                          menu_gestion_emprunt();

                                          printf("votre choix :");
                                           scanf("%d",&choix_gestion_emp);

                                            system("cls");

                                                switch(choix_gestion_emp)
                                                  {

                                                    case 1:
                                                                   system("cls");
                                                                   afficher_emprints(Lm);


                                                                    break;
                                                    case 2:



                                                                                                                   do {
                                                                                                                        menu_modifier_emprunt();

                                                                                                                        printf("\n votre choix: ");
                                                                                                                        scanf("%d", &choix_modif_emp);
                                                                                                                        system("cls");
                                                                                                                        fflush(stdin);

                                                                                                                              switch (choix_modif_emp) {
                                                                                                                                  case 1:

                                                                                                                                        modifier_emprint_dates(Lm);
                                                                                                                                          break;
                                                                                                                                  case 2:
                                                                                                                                          ajouter_livre_emprint( Lm, Ll);
                                                                                                                                          break;
                                                                                                                                   case 3:
                                                                                                                                          system("cls");
                                                                                                                                          break;
                                                                                                                                  default:
                                                                                                                                          break;

                                                                                                                                                        }
                                                                                                                        } while (choix_modif_emp!= 3);


                                                                                                                /////////////////////////////////////////////////////


                                                                            break;
                                                    case 3:

                                                                       system("cls");
                                                                       Lm=ajout_emp(Lm,La,Ll);
                                                                       getch();


                                                                            break;



                                                    case 4:

                                                                       system("cls");

                                                                       printf("nmr adherant (Supprimer):");
                                                                       scanf("%d",&supp_ID_em);
                                                                       supper_emprint_simple(&Lm,supp_ID_em);
                                                                       getch();
                                                                       system("cls");


                                                                            break;

                                                   case 5:
                                                        system("cls");
                                                         break;
                                                    default:
                                                         break;
                                                       }

                                    }while(choix_gestion_emp!=5);




                            break;

                case 'Q':
                         system("cls");


                            break;
                default:



                            break;


              }






    }while(choix_gestion_biblio!='Q');


    return 0;
}
