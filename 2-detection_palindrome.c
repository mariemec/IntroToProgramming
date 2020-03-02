/********
  Fichier: detection_palindrom.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient plusieurs fonctions permettant de detecter si une chaine de charactères donnée est un palindrome.
* 			 Il contient aussi les tests unitaires de chacunes de ces fonctions ainsi que le test d'integration de la fonction estPalindrome.  ********/

#include <stdio.h>

//Fonction qui calcule la longueur d'une chaine de caractères.
/*Précondition: La taille de la chaine de caractères doit être égale 
				ou inférieure à 100 puisque c'est la taille limite 
				que nous nous sommes imposé.*/
//Postcondition: Le calcul doit retourner un entier.
int calculLongueur (char chaine[100])
{
	for (int i=0;i<100;i++)
	{
		if (chaine[i]=='\0')
		{
			return i;
		}
	}
	return 0;	
}

//Fonction qui détecte si un nombre donné est pair.
//Précondition: Le nombre en entrée doit être un entier.
//Postcondition: Le calcul est booléen et doit retourner 0 faux) ou 1(vrai).
int estPair (int nombre)
{
	if (nombre%2==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

/*Fonction qui calcule l'index du caractère milieu,"l'axe de symmétrie",
	de la chaine de charactères.*/
//Précondition: Le nombre en entrée doit être un entier.
//Postcondition: Le calcul est booléen et doit retourner 0 (faux) ou 1(vrai).
int calculDemiLongueur (int longueur)
{
	int demiLongueur=0;
	if (estPair(longueur))
	{
		demiLongueur=(longueur/2)-1;
	}	
	else
	{
		demiLongueur=(longueur-1)/2;
	}
	return demiLongueur;
}
	
//Fonction qui détecte si la chaine de caractères donnée est un palindrome.
//Précondition: La chaine de caractères est composée de lettres minuscules.
//Postcondition: Le calcul est booléen et doit retourner 0 (faux) ou 1(vrai).
int estPalindrome (char chaine[])											
{
	int longueur=calculLongueur(chaine);
	int demiLongueur=calculDemiLongueur(longueur);
	int i=0;


	while (i<=demiLongueur)
	{	
		if (chaine[i]!=chaine[longueur-1-i])
		{
			return 0;	
		}
		else
		{
			if (i==demiLongueur)
			{
				return 1;
			}
			else
			{ 
				i++;
			}
		}	
	}
	return 0;
}

//Test unitaire de la fonction estPalindrome.
void testPalindrome (char chaine[], int reponseAttendue)
{
	int reponseObtenue = estPalindrome(chaine);
	printf("--------------------------------------\n");
	printf("Chaine de characteres: %s\nReponse Attendue: %d\nReponse Obtenue: %d\n", chaine, reponseAttendue, reponseObtenue);
	
	if (reponseObtenue==reponseAttendue)
	{
		printf("Test reussi.\n");
	}
	else
	{
		printf("Test echoue.\n");
	}

}
	
//Test d'intégration de la fonction estPalindrome.
void testPalindromes()
{
	testPalindrome("kayak", 1);
	testPalindrome("laval", 1);
	testPalindrome("abcbA", 0);
	testPalindrome("abcba", 1);
	testPalindrome("pomme", 0);
	testPalindrome("wifi", 0);
	testPalindrome("", 0);
	testPalindrome("123", 0);
}

int main()
{
	printf("\nDétection d'un palindrome\n");
	testPalindromes();
}

