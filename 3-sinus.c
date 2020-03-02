 /********
  Fichier: sinus.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient plusieurs fonctions permettant de trouver la valeur sinus d'un angle en radians.
* 			 Il contient aussi l'implémentation des calculs de puissances et de factorielles.
* 			 Les tests unitaires et d'intégration de chacunes de ces fonctions se trouvent juste après leur définition.
* 			 Cette approximation de sin(x) ne fonctionne qu'avec les valeurs de x entre -2pi et 2pi exclusivement. ********/

#include <stdio.h>
#define NBRTERMES 10

//Fonction qui calcul la puissance en multipliant la base par elle-meme n fois, où n=exposant.
//Precondition: La base doit être un nombre réel. L'exposant doit être un entier (dans notre cas).
//Postcondition: La puissance retournée doit être un nombre réel.
double calculPuissance(double basePuissance, int exposant)
{
	double puissance=1;
	
	for (int i=1;i<=exposant;i++)
	{
		puissance*=basePuissance;
	}	
	return puissance;	
}

//Test unitaire de la fonction calculPuissance.
void testCalculPuissance(double basePuissance, int exposant, double valeurAttendue)
{
	double valeurObtenue=calculPuissance(basePuissance, exposant);
	
	if (valeurAttendue!=valeurObtenue)
	{
		printf("testCalculPuissance échoué: ");
		printf("puissance (%f^%d) = %f, la valeur attendue: %f.\n\n", basePuissance, exposant, valeurObtenue, valeurAttendue);
	}
}

//Tests d'intégration de la fonction calculPuissance.
void testCalculPuissances()
{
	double pi=3.1415926535897932384626433832795028841971;
	testCalculPuissance(pi,3,pi*pi*pi);
	testCalculPuissance(pi,5,pi*pi*pi*pi*pi);
	testCalculPuissance(pi,7,pi*pi*pi*pi*pi*pi*pi);
	testCalculPuissance(pi,9,pi*pi*pi*pi*pi*pi*pi*pi*pi);
}

//Fonction qui calcul la factorielle en multipliant la base par tous les entiers positifs qui lui sont inférieurs.
//Precondition: La base doit être un entier positif.
//Postcondition: La factorielle retournée doit être un entier.
long calculFactorielle(long baseFactorielle)
{
	long factorielle=1;
	for (int j=1;j<=baseFactorielle;j++)
	{
		factorielle*=j;	
	}	
	return factorielle;
}	
	
//Test unitaire de la fonction calculFactorielle
void testCalculFactorielle(long baseFactorielle, long valeurAttendue)
{
	long valeurObtenue=calculFactorielle(baseFactorielle);
	
	if (valeurAttendue!=valeurObtenue)
	{
		printf("testCalculFactorielle échoué: ");
		printf("factorielle (%ld)! = %ld, la valeur attendue: %ld.\n\n", baseFactorielle, valeurObtenue, valeurAttendue);
	}
}	

//Tests d'intégration de la fonction calculFactorielle.
void testCalculFactorielles()
{
	testCalculFactorielle(1, 1);
	testCalculFactorielle(3, 6);
	testCalculFactorielle(5, 120);
	testCalculFactorielle(7, 5040);
}

//Fonction qui détermine si un nombre est impair.
//Précondition: Le nombre en entrée doit être un entier.
//Postcondition: Le calcul est booléen et doit retourner 0 faux) ou 1(vrai).
int estImpair (int nombre)
{
	if (nombre%2==1)
		return 1;
	else
		return 0;
}

//Fonction qui traduit l'index d'un terme (sa position dans la série qui approxime sin)
	//en la "base du Terme", soit l'exposant du numérateur et la factorielle du dénominateur du terme.
int calculBaseTerme(int indexTerme)
{
	int baseTerme=(2*indexTerme)+1;
	return baseTerme;
}	

//Fonction qui calcul la valeur d'un terme dans la série sin selon son index.
//Précondition: L'angle en entrée doit être entre -2pi et 2pi exclusivement.
//Postcondition: : La valeur du terme retourné est un nombre réel.	
double calculTerme (double angle, int indexTerme)
{
	double terme=0;
	int baseTerme=calculBaseTerme(indexTerme);
	double numTerme=calculPuissance(angle,baseTerme);
	double denomTerme=calculFactorielle(baseTerme);
	
	terme=numTerme/denomTerme;

	if(estImpair(indexTerme)==1)
	{
		terme*=-1;	
	}	
	return terme;
}	

//Test unitaire de la fonction calculTerme
void testCalculTerme (double angle, int indexTerme, double valeurAttendue)
{
	double valeurObtenue=calculTerme(angle, indexTerme);
	
	if (valeurObtenue != valeurAttendue  )
	{
		printf("testCalculTerme échoué: ");
		printf("terme obtenu %f, la valeur attendue: %f.\n\n", valeurObtenue, valeurAttendue);
	}	
}	

//Tests d'intégration de la fonction calculTerme
void testCaculTermes()
{
	double pi=3.1415926535897932384626433832795028841971;
	testCalculTerme (pi, 0, pi);
	testCalculTerme(pi, 1, (pi*pi*pi*-1)/6);
	testCalculTerme(pi, 2, (pi*pi*pi*pi*pi)/120);
	testCalculTerme(pi, 3, (pi*pi*pi*pi*pi*pi*pi*-1)/5040);
	testCalculTerme(pi, 3, (pi*pi*pi*pi*pi*pi*pi*-1)/5040);
}

//Fonction qui calcul la valeur sin d'un angle en radians.
//Précondition: L'angle en entrée doit être entre -2pi et 2pi exclusivement.
	//L'angle doit etre en radians.
//Postcondition: : La valeur sin retournée doit être en -1 et 1.
double sin(double angle)
{
	double sin=0;
	for(int k=0;k<NBRTERMES;k++)
	{
		sin+=calculTerme(angle,k);
	}	
	return sin;
}

//Test unitaire de la fonction sin
void testSin(double angle, double valeurAttendue)
{
	double valeurObtenue=sin(angle);
	printf("\nCalcul \t\tValeur Obtenue \t\tValeur Attendue\n");
	printf("sin(%.4f) \t\t%.4f. \t\t%.4f.\n\n", angle, valeurObtenue, valeurAttendue);
}	

//Tests d'intégration de la fonction sin
void testSins ()
{
	double pi=3.1415926535897932384626433832795028841971;
	testSin(1,0.8415);
	testSin(0,0.0000);
	testSin(pi/4,0.7071);
	testSin(pi/2,1.0000);
	testSin(pi, 0);	
	testSin(-2.3, -0.7457);
	testSin(-pi/2,-1.0000);
	testSin(-pi,0);
	testSin(2*pi, 0);
	testSin(-2*pi, 0);
}

int main()
{
	printf("\nSinus d'un angle\n");
	testCalculPuissances();
	testCalculFactorielles();
	testCaculTermes();
	testSins();
}
