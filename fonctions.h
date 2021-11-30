#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED



typedef struct Menus
{
    int id;
    int jours ;
    int type;
    char entree[50];
    char suite[50];
    char dessert[50];
    
    


}Menus;

void ajouter_nutri(Menus menu);
void supprimer_nutri(Menus menu);
int rechercher_nutri(Menus menu);
void afficher_nutri(Menus menu);
void modifier_nutri(Menus menu);
void dashboard_nutri(Menus menu);

#endif
