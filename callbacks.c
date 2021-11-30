#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


void
on_button_ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f= NULL ;
GtkWidget *login , *pw , *windowAuth , *name , *surname , *role ;
char name1[20];
char surname1[20];
char role1[2] ;
char login1[20];
char passw[20] ;
name = lookup_widget (button , "entry_name");
surname = lookup_widget (button , "entry_surname");
login = lookup_widget (button , "entry_username");
pw = lookup_widget (button , "entry_password");
role = lookup_widget (button , "entry_role");
strcpy(name1,gtk_entry_get_text(GTK_ENTRY(name)));
strcpy(surname1,gtk_entry_get_text(GTK_ENTRY(surname)));
strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(role1,gtk_entry_get_text(GTK_ENTRY(role)));
f=fopen("user.txt" , "a+");
if (f!=NULL)
{
fprintf(f," %s %s %s %s %s \n " , name1 , surname1 , login1 , passw , role1);
fclose(f);
}
else 
printf("\n file not found \n");

windowAuth=create_Authentication();
gtk_widget_show (windowAuth);
}


void
on_button_login_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *username , *password , *windowEspaceAdmin , *windowauthfailed;
char user[20];
char pasw[20] ;
int trouve ;
username = lookup_widget (button , "entry_username2");
password = lookup_widget (button , "entry_password2");

strcpy(user,gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw,gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verification(user, pasw);
if (trouve==1)
{
windowEspaceAdmin=create_Espace_Administrateur();
gtk_widget_show(windowEspaceAdmin);
}
else
{
windowauthfailed=create_Authentication_failed() ;
gtk_widget_show (windowauthfailed);
}


}


void
on_button_supp_menu_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_mod_menu_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_aj_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_aff_menu_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_retour_mod_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_ret_aj_menu_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_aj_af_menu_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_quit_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_aj_menu_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_aff_after_aj_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

