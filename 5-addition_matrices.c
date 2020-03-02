/********
  Fichier: addition_matrices.c
  Auteurs: Marie-Eve Castonguay  casm1907
           Alec Gagnon  gaga2120
  Date:    01 octobre 2019
Description: Ce fichier contient les fonctions permettant de calculer et d'afficher
* 			 l'addition de 2 matrices. ********/

#include <stdio.h>
#define M_LIGNES 3
#define N_COLONNES 2

//Fonction qui affiche une matrice donnée sous forme de tableau comportant 
	//des lignes et des colonnes.
void afficherMatrice(int matrice[M_LIGNES][N_COLONNES], char nomMatrice[32])
{
	printf("\n%s\n", nomMatrice);
	for (int ligne=0;ligne<M_LIGNES;ligne++)
	{
		for (int colonne=0;colonne<N_COLONNES;colonne++)
		{
			printf("%d  ", matrice[ligne][colonne]);	
		}
		printf ("\n");
	} 
}

//Fonction qui additionne les valeurs de même position dans chacune des matrices
	//et qui les insert dans une troisième matrice de même taille.
//Préconditions: Les 3 matrices en entrée doivent être de même dimension.
//Postconditions: La fonction ne retourne aucune valeur. 
void additionMatrice(int matriceA[M_LIGNES][N_COLONNES], int matriceB[M_LIGNES][N_COLONNES], int matriceResultat[M_LIGNES][N_COLONNES])
{
	for (int ligne=0;ligne<M_LIGNES;ligne++)
	{
		for (int colonne=0;colonne<N_COLONNES;colonne++)
		{
			matriceResultat[ligne][colonne]=matriceA[ligne][colonne]+matriceB[ligne][colonne];
		}
	} 
	
}

//Fonction qui compare si deux matrices sont identiques.
	//Sert seulement pour le test unitaire de additionMatrice. 
int comparerMatrice(int matriceObtenue[M_LIGNES][N_COLONNES], int matriceAttendue[M_LIGNES][N_COLONNES])
{
	int matriceIdentique=1;
	
	for (int ligne=0;ligne<M_LIGNES;ligne++)
	{
		for (int colonne=0;colonne<N_COLONNES;colonne++)
		{
			if (matriceObtenue[ligne][colonne]!=matriceAttendue[ligne][colonne])
			{
				matriceIdentique=0;
			}
		}
	} 
	return matriceIdentique;
}

//Test unitaire de additionMatrice.
void testAdditionMatrice(int matriceA[M_LIGNES][N_COLONNES], int matriceB[M_LIGNES][N_COLONNES], int matriceAttendue[M_LIGNES][N_COLONNES])
{
	
	int matriceObtenue[M_LIGNES][N_COLONNES]={{0,0},{0,0},{0,0}};
	additionMatrice(matriceA,matriceB,matriceObtenue);
	
	printf("\n--------------------------------------\n");
	afficherMatrice(matriceA, "A");
	afficherMatrice(matriceB, "B");
	afficherMatrice(matriceObtenue, "Obtenue");
	afficherMatrice(matriceAttendue, "Attendue");
	
	if (comparerMatrice(matriceObtenue, matriceAttendue)==1)
		printf("Test succès.\n");		
	else 
		printf("Test échoué.\n");

}

//Tests d'intégration de additionMatrice.
void testAdditionMatriceSuite()
{
	int matriceA[M_LIGNES][N_COLONNES]={{1,2},{3,4},{5,6}};
	int matriceB[M_LIGNES][N_COLONNES]={{6,5},{4,3},{2,1}};
	int matriceResultat1[M_LIGNES][N_COLONNES]={{7,7},{7,7},{7,7}};
	
	int matriceC[M_LIGNES][N_COLONNES]={{1,-2},{-3,0},{5,-6}};
	int matriceD[M_LIGNES][N_COLONNES]={{0,1},{1,2},{3,-4}};
	int matriceResultat2[M_LIGNES][N_COLONNES]={{1,-1},{-2,2},{8,-10}};

	int matriceE[M_LIGNES][N_COLONNES]={{2,4},{8,16},{32,64}};
	int matriceF[M_LIGNES][N_COLONNES]={{2,4},{8,16},{32,64}};
	int matriceResultat3[M_LIGNES][N_COLONNES]={{4,8},{16,32},{64,128}};
	
	testAdditionMatrice(matriceA,matriceB,matriceResultat1);
	testAdditionMatrice(matriceC,matriceD,matriceResultat2);
	testAdditionMatrice(matriceE,matriceF,matriceResultat3);
}

int main()
{
	printf("\nAddition de deux matrices\n");
	testAdditionMatriceSuite();
}
