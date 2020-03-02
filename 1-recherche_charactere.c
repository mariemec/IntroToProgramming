/********
  Fichier: recherche_caractere.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient une fonction qui permet de rechercher l'index d'une lettre donnée dans une chaine de caractères.
* 			 Il contient aussi le test unitaire de cette fonction.  ********/

#include <stdio.h>

//Fonction qui trouve et retourne l'index de la lettre recherchée dans une chaine de caractères.
//Précondition: La lettre recherchée doit être composée d'un seul caractère.
//Postcondition: L'index retourné doit être un nombre entier.
int recherche( char chaine[], char lettre)
{
   int index =-1;
   int i=0;
   while (chaine[i] != '\0' && index == -1)
   {
	   if (chaine[i] == lettre)
	   {
		   index =i;
       }
		i++;
   }
   return index;
}

//Test unitaire de la fonction recherche.
void testRecherche(char chaine[], char lettre, int indexAttendu)
{
	int indexObtenu = recherche(chaine, lettre);
	printf("\n--------------------------------------\n");
	printf("Chaine de caractères: %s\nLettre cherchée: %c\nIndex Obtenu: %d\nIndex Attendu: %d\n", chaine, lettre, indexObtenu, indexAttendu);

	if (indexAttendu==indexObtenu)
	{
		printf("Test réussi. \n");
	}
	else
	{
		printf("Test échoué. \n");
	}
}	

//Tests d'intégration de la fonction recherche.
void testRechercheSuite()
{
	testRecherche("anticonstitutionnellement", 'n', 1);
	testRecherche("bonjour", 'e', -1);
	testRecherche("bonjour", 'r', 6);
	testRecherche("allocommentcava", 'a', 0);
	testRecherche("abcdefghi", 'j', -1);
}

int main(void){
	printf("\nRecherche d'un caractère");
	testRechercheSuite();
}

