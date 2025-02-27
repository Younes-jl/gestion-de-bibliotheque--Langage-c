#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

typedef struct livre
{
    int id;
    char titre[100];
    char auteur[100];
    char genre[100];
    char edition[100];
} livre;

typedef struct Clivre
{
   livre datalivre;
   struct Clivre *prc;
   struct Clivre *next;
} Clivre;

typedef Clivre* listlivre;


////////////////////////////////////////////////////////





typedef struct adherant
{
    int numadher;
    char nom[100];
    char prenom[100];
    char adresse[100];


}adherant;

typedef struct Cadherant
{
    adherant dataAdr;
    struct Cadherant *next;
    struct Cadherant  *prc;
}Cadherant;
typedef Cadherant* listeAdherant;


////////////////////////////////////////////////////////////////////


typedef struct date{

    int jour;
    int mois;

}date;


///////////////////////////////////////////////////////////////////



typedef struct livre_emp
{

    int  livre_id_emp;
    date date_emp;
    date date_retour;
    struct livre_emp* prec;
    struct livre_emp* next;



}livre_emp;

//////////////////////////////////////////////////////////////////






typedef struct emprint
{
    int nmrEMP;
    int id_adherant_emp;
    livre_emp* liste_livre_emp;
    struct emprint* next;
    struct emprint* prec;
}emprint;





emprint* new_emprint(int adherant_id, int livre_id);

emprint* ajouter_emprint_debut(emprint* Lm, emprint* new_EMP);
livre_emp* ajouter_livre_emp(emprint* tmp, int livre_id);
int test_livre_emp(emprint* Lm, listlivre Ll, int livre_id);
int is_valid_date(date emp, date retour);
void modifier_emprint(emprint* Lm, int adherant_id, int livre_id);
void ajouter_livre_emprint(emprint* Lm, listlivre Ll);
void modifier_emprint_dates(emprint* Lm);
emprint* ajout_emp(emprint* Lm,listeAdherant La,listlivre Ll);
supprimer_emprint_simple(emprint** Lm, int adherant_id);

#endif
