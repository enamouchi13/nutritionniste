#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>
enum   
{       
	
	EID,	
	EJOURS,
	ETYPE,
	EENTREE,
	ESUITE,
	EDESSERT,
	RPAIEMENT,
	COLUMNS,

};
void ajouter_nutri(Menus menu) {  

    
    

  
    
    
     
    FILE *f = NULL;
    f = fopen("Nutritionniste.txt", "a+");
    fprintf(f,"%d %d %d %s %s %s \n",menu.id, menu.jours, menu.type, menu.entree,menu.suite,menu.dessert);
    fclose(f);
}

void supprimer_nutri(Menus menu) {
    
    Menus R;
    
    FILE *f1=NULL;
    FILE *f2=NULL;

    printf("id du menu a supprimer:\n");
    scanf("%d", &R.id);
    
    
    

    f1 = fopen("Nutritionniste.txt","r");
    f2 = fopen("Nutriti_tamp.txt", "a+");
    while (fscanf(f1,"%d %d %d %s %s %s \n",&menu.id,&menu.jours, &menu.type, menu.entree,menu.suite,menu.dessert) !=EOF){
        if (menu.id != R.id) {
            fprintf(f2,"%d %d %d %s %s %s \n",menu.id, menu.jours, menu.type, menu.entree,menu.suite,menu.dessert);
        }
       else if (menu.id == R.id)
     {fprintf(f2,"%d %d %d %s %s %s \n", menu.id,menu.jours, menu.type, menu.entree,menu.suite,menu.dessert);}
    }
    fclose(f1);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("Nutriti_tamp.txt", "Nutritionniste.txt");
}

int rechercher_nutri(Menus menu) {
    
    
    Menus R;
    printf("Id du menu à rechercher:\n");
    scanf("%d",&R.id);
   

    FILE *f = NULL;
    f = fopen("Nutritionniste.txt","r");
    while(fscanf(f,"%d %d %d %s %s %s \n",&menu.id, &menu.jours, &menu.type, menu.entree,menu.suite,menu.dessert)!=EOF) {

        if(R.id==menu.id){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;

}

/*void afficher_nutri(Menus menu) {

    

    FILE *f = NULL;
    f=fopen("Nutritionniste.txt","r");
    
    while (fscanf(f,"%d %d %d %s %s %s \n",&menu.id, &menu.jours, &menu.type, menu.entree,menu.suite,menu.dessert) !=EOF){
    printf("%d %d %ls %s %s %s \n",menu.id, menu.jours,  &menu.type, menu.entree,menu.suite,menu.dessert);
        
    }
    fclose(f);
    //return 0;
}*/
void afficher_nutri(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
    int id;

    int jours ;

    int type;

    char entree[50];

    char suite[50];

    char dessert[50];

    
	store=NULL;

	FILE *f;
	store = gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID",renderer, "text",EID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text",EJOURS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",ETYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("entrée",renderer, "text",EENTREE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Suite",renderer, "text",ESUITE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


 		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Dessert",renderer, "text",EDESSERT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		



		

		store=gtk_list_store_new (COLUMNS, G_TYPE_INTEGER, G_TYPE_INTEGER, G_TYPE_INTEGER, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		f = fopen("fichier.txt","r");

		if(f==NULL)
		{
			return;
		}
		else
		{
			f = fopen("fichier.txt","a+");
			while(fscanf(f,"%d %d %d %s %s %s\n",id,jours,type,entree,suite,dessert)!=EOF)
			{
		gtk_list_store_append(store,&iter);
		gtk_list_store_set (store, &iter, EID, id, EJOURS, jours, ETYPE,type, EENTREE, entree, ESUITE, suite, EDESSERT, dessert, -1 );
			}
			fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 		g_object_unref(store);
}
}
}


void modifier_nutri(Menus menu){
    
    
    Menus old;
    Menus new;
    FILE *f=NULL;
    FILE *f2=NULL;
    printf("ID du menu à modifier:\n");
    scanf("%d",&old.id);
    new.id=old.id;
    printf("Jour du menu\n");
    scanf("%d",&old.jours);
    new.jours=old.jours;
    printf("petit Dejeuner:1|Dejeuner:2|Diner:3\n");
    scanf("%d",&old.type);
    new.type=old.type;
    printf("Entrée\n");
    scanf("%s",new.entree);
    printf("Plat principal\n");
    scanf("%s",new.suite);
    printf("Dessert:\n");
    scanf("%s",new.dessert);
    

    

    
    
    f=fopen("Nutritionniste.txt","r");
    f2=fopen("modif_nut.txt","a+");
    while(fscanf(f,"%d %d %d %s %s %s \n",&menu.id, &menu.jours, &menu.type, menu.entree,menu.suite,menu.dessert)!=EOF)
    {
    if (menu.id == old.id) {
            fprintf(f2,"%d %d %d %s %s %s \n", new.id,new.jours, new.type, new.entree,new.suite,new.dessert);
        }
        else {
        fprintf(f2,"%d %d %d %s %s %s \n",menu.id, menu.jours, menu.type, menu.entree,menu.suite,menu.dessert);
        }
    };
    fclose(f);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("modif_nut.txt","Nutritionniste.txt");

    }



void dashboard_nutri(Menus menu){
    
    
    int jour , plat,s,b,i,r,k;
    float dechet,s1,max;
    float T[50];
    FILE *f2=NULL;

   printf("choisir la semaine:\n");
    scanf("%d",&s);
    if (s=1) 
    {
      b=1;  
    }
    if (s=2) 
    {
      b=8;  
    }
    if (s=3) 
    {
      b=15;  
    }
    if (s=4) 
    {
      b=22;  
    }
    i=b;
    s1=0;

    
    
    
   
    f2=fopen("dechets.txt","r");
     while (!EOF) {
        
        fscanf(f2,"%d %d %f \n", &jour, &plat , &dechet);
        while (i<7+b){
        if (i == jour) {
            s1=dechet+s1;}
        if (plat==3)
        { 
            T[i]=s1;
            i=i+1;
        }

        }
    }
    fclose(f2);
    max=T[0];
    r=0;
    for (k=1;k<i;i++)
    {
        if (T[k]>max)
        {
            max=T[k];
            r=k;
        }

    }
    printf("%d a le menu qui a le plus de dechets de la semaine avec %f kg de dechets ",r,max);
     }
    
   void main() {
    int init=1;
    char commande[20]; 
    int p;
    Menus menu;
    do{
        printf("donner votre commande:\n");
        
        scanf("%s",commande);
        
        if (strcmp(commande,"afficher")==0)
            afficher_nutri(menu);
        else if (strcmp(commande,"ajouter")==0){
             printf("jour de la semaine:\n");
    	     scanf("%d",&menu.jours);
  	     printf("petit Dejeuner:1|Dejeuner:2|Diner:3\n");
   	     scanf("%d",&menu.type);
   	     printf("Entrée\n");
   	     scanf("%s",menu.entree);
    
    	     printf("Plat principal\n");
    
    	     scanf("%s",menu.suite);
    
    	     printf("Dessert:\n");
    	     scanf("%s",menu.dessert);
             ajouter_nutri(menu);}

        else if (strcmp(commande,"rechercher")==0){
            p=rechercher_nutri(menu);
            printf("%d",p);}
        else if (strcmp(commande,"modifier")==0)
            modifier_nutri(menu);
        else if (strcmp(commande,"supprimer")==0)
            supprimer_nutri(menu);
        else if (strcmp(commande,"dashboard")==0)
            dashboard_nutri(menu);   
        printf("voulez-vous saisir une nouvelle commande? 1|0\n");
        scanf("%d", &init);

    }while(init==1);

}



