/********
  Fichier: cosinus.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient plusieurs fonctions permettant de trouver la valeur cosinus d'un angle en radians.
* 			 Il contient aussi l'implémentation des calculs de puissances et de factorielles.
* 			 Les tests unitaires et d'intégrations de ces fonctions se trouvent juste après leur définition. ********/

#include <stdio.h>
#define NBRTERMES 11

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
void testCalculPuissanceSuite()
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
void testCalculFactorielleSuite()
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
	int baseTerme=(2*indexTerme);
	return baseTerme;
}	

//Fonction qui calcul la valeur d'un terme dans la série cos selon son index.
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
		printf("testCalculTerme terme %d échoué: ", indexTerme);
		printf("terme obtenu %f, la valeur attendue: %f.\n\n", valeurObtenue, valeurAttendue);
	}	
}	

//Tests d'intégration de la fonction calculTerme
void testCaculTermeSuite()
{
	double pi=3.1415926535897932384626433832795028841971;
	testCalculTerme (pi, 0, 1);
	testCalculTerme(pi, 1, (pi*pi*-1)/2);
	testCalculTerme(pi, 2, (pi*pi*pi*pi)/24);
	testCalculTerme(pi, 3, (pi*pi*pi*pi*pi*pi*-1)/720);
}

//Fonction qui calcul la valeur cos d'un angle en radians.
//Précondition: L'angle en entrée doit être entre -2pi et 2pi exclusivement.
	//L'angle doit etre en radians.
//Postcondition: : La valeur cos retournée doit être en -1 et 1 pour être valable.
double cos(double angle)
{
	double cos=0;
	for(int k=0;k<NBRTERMES;k++)
	{
		cos+=calculTerme(angle,k);
	}	
	return cos;
}

//Test unitaire de la fonction cos
void testCos(double angle, double valeurAttendue)
{
	double valeurObtenue=cos(angle);
		printf("\nCalcul \t\tValeur Obtenue \t\tValeur Attendue\n");
		printf("cos(%.4f) \t\t%.4f. \t\t%.4f.\n\n", angle, valeurObtenue, valeurAttendue);
}	

//Tests d'intégration de la fonction cos
void testCosSuite ()
{
	double pi=3.1415926535897932384626433832795028841971;
	testCos(1,0.5403);
	testCos(0,1.0000);
	testCos(pi/4,0.7071);
	testCos(pi/2,0.0000);
	testCos(pi,-1.0000);
	testCos(-2.3, -0.6663);	
	testCos(-pi/2,0.0000);
	testCos(-pi,-1.0000);
	testCos(2*pi,1.0000);
	testCos(-2*pi,1.0000);	
	
}

int main()
{
	printf("\nCosinus d'un angle\n");
	testCalculPuissanceSuite();
	testCalculFactorielleSuite();
	testCaculTermeSuite();
	testCosSuite();
}
