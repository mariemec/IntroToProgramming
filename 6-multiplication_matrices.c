/********
  Fichier: multiplication_matrices.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient les fonctions nécéssaires pour calculer
* 			et afficher le resultat d'une multiplication de deux matrices carrées. ********/

#include <stdio.h>
#define DIMENSION 2

//Fonction qui affiche une matrice donnée sous forme de tableau comportant 
	//des lignes et des colonnes.
void afficherMatrice(int matrice[DIMENSION][DIMENSION], char nomMatrice[32])
{
	printf("\n%s\n", nomMatrice);
	for (int ligne=0;ligne<DIMENSION;ligne++)
	{
		for (int colonne=0;colonne<DIMENSION;colonne++)
		{
			printf("%d ", matrice[ligne][colonne]);	
		}
		printf ("\n");
	} 
}

//Fonction qui calcule le coefficient d'une position donnée dans la matrice.
/*Le coefficient est défini comme étant la valeur résultante 
 * d'une multiplication pour une position [ligne][colonne] donnée.*/
//Préconditions: Les deux matrices en entrée doivent être carrées. 
	//Les numéros de ligne et de colonne sont des entiers de 0(inclus) à DIMENSION (exclus).
//Postconditions: La valeur de coefficient retournée est un entier.
int calculCoefficient(int matriceA[DIMENSION][DIMENSION], int matriceB[DIMENSION][DIMENSION], int ligne, int colonne)
{
	int coefficient=0;
	for (int index=0;index<DIMENSION;index++)
	{
		coefficient+=matriceA[ligne][index]*matriceB[index][colonne];
	}
	return coefficient;
}

//Test unitaire de la fonction calculCoefficient.
void testCalculCoefficient(int matriceA[DIMENSION][DIMENSION], int matriceB[DIMENSION][DIMENSION], int ligne, int colonne, int valeurAttendue)
{
	int valeurObtenue=calculCoefficient(matriceA,matriceB,ligne,colonne);
	
	if (valeurObtenue != valeurAttendue  )
	{
		printf("testCalculCoefficient échoué: ");
		printf("Valeur obtenue: %d, la valeur attendue: %d.\n\n", valeurObtenue, valeurAttendue);
	}
		
}

//Tests d'intégration de la fonction calculCoefficient.
void testCalculCoefficients()
{
	int matriceA[DIMENSION][DIMENSION]={{1,2},{3,4}};
	int matriceB[DIMENSION][DIMENSION]={{1,2},{3,4}};
	testCalculCoefficient(matriceA,matriceB,0,0, 7);
	testCalculCoefficient(matriceA,matriceB,0,1, 10);
	testCalculCoefficient(matriceA,matriceB,1,0, 15);
	testCalculCoefficient(matriceA,matriceB,1,1, 22);
}

//Fonction qui multiplie deux matrices selon les règles d'un produit matriciel.
//Préconditions: Les 3 matrices en entrée doivent être de même dimension.
//Postconditions: La fonction ne retourne aucune valeur. 
void multiplierMatrices (int matriceA[DIMENSION][DIMENSION], int matriceB[DIMENSION][DIMENSION], int matriceResultat[DIMENSION][DIMENSION])
{
	for (int ligne=0;ligne<DIMENSION; ligne++)
	{
		for(int colonne=0;colonne<DIMENSION;colonne++)
		{
			matriceResultat[ligne][colonne]= calculCoefficient(matriceA,matriceB, ligne, colonne);
		}
	} 
}	

//Fonction qui compare si deux matrices sont identiques.
	//Sert seulement pour le test unitaire de multiplierMatrice.
int comparerMatrice(int matriceObtenue[DIMENSION][DIMENSION], int matriceAttendue[DIMENSION][DIMENSION] )
{
	int matriceIdentique=1;
	
	for (int ligne=0;ligne<DIMENSION;ligne++)
	{
		for (int colonne=0;colonne<DIMENSION;colonne++)
		{
			if (matriceObtenue[ligne][colonne]!=matriceAttendue[ligne][colonne])
			{
				matriceIdentique=0;
			}
		}
	} 
	return matriceIdentique;
}

//Test unitaire de multiplierMatrice.
void testMultiplierMatrice(int matriceA[DIMENSION][DIMENSION], int matriceB[DIMENSION][DIMENSION], int matriceAttendue[DIMENSION][DIMENSION])
{
	
	int matriceObtenue[DIMENSION][DIMENSION]={{0,0},{0,0}};
	multiplierMatrices(matriceA,matriceB,matriceObtenue);
	
	printf("\n--------------------------------------\n");
	afficherMatrice(matriceA, "A");
	afficherMatrice(matriceB, "B");
	afficherMatrice(matriceObtenue, "Obtenue");
	afficherMatrice(matriceAttendue, "Attendue");
	
	if (comparerMatrice(matriceObtenue, matriceAttendue)==1)
		printf("Test succes.\n");		
	else 
		printf("Test echoue.\n");

}

//Tests d'intégration de multiplierMatrice.
void testMultiplierMatriceSuite()
{
	int matriceA[DIMENSION][DIMENSION]={{1,2},{3,4}};
	int matriceB[DIMENSION][DIMENSION]={{5,-8},{9,6}};
	int matriceC[DIMENSION][DIMENSION]={{-1,0},{0,1}};
	int matriceD[DIMENSION][DIMENSION]={{6,7},{8,9}};
	int matriceE[DIMENSION][DIMENSION]={{0,0},{0,0}};
	int matriceF[DIMENSION][DIMENSION]={{0,2},{4,3}};
	int matriceG[DIMENSION][DIMENSION]={{0,1},{1,0}};
	int matriceResultat1[DIMENSION][DIMENSION]={{7,10},{15,22}};
	int matriceResultat2[DIMENSION][DIMENSION]={{-5,-8},{-9,6}};
	int matriceResultat3[DIMENSION][DIMENSION]={{0,0},{0,0}};
	int matriceResultat4[DIMENSION][DIMENSION]={{2,0},{3,4}};

	testMultiplierMatrice(matriceA,matriceA,matriceResultat1);
	testMultiplierMatrice(matriceB,matriceC,matriceResultat2);
	testMultiplierMatrice(matriceD,matriceE,matriceResultat3);
	testMultiplierMatrice(matriceF,matriceG,matriceResultat4);
}

int main(void)
{
	printf("\nMultiplication de deux matrices carrées\n");
	testCalculCoefficients();
	testMultiplierMatriceSuite();
}
