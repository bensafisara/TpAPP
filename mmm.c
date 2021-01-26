#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "displayMatrix.h"
#include "displayMatrix.c"
#include "funcThread.c"
#include "funcThread.h"
#include "funThreadC.c"
#include "funThreadC.h"
#include "initMatrix.h"
#include "initMatrix.c"
#include "sequentiel.c"
#include "sequentiel.h"
#include "VerifMatrixEqual.c"
#include "VerifMatrixEqual.h"






/*********************Variable globales******************************/
<<<<<<< HEAD

=======
//int x,dim1,dim2, N;
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b


 int **a;
 int  **b;
int **mult_p , **mult_p1 , **mult_s; 
int **mult_p_col;
int **mult_p_row;
int N;
int NumThr;
double speedUpArchiRow;
double speedUpArchiCol;


<<<<<<< HEAD
char* mode;

int *VecteurNumDesThreads;

=======
int mode;

int *VecteurNumDesThreads;



>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
double tempsParalleleArchitectureRow;

double tempsParalleleArchitectureColmun;
double tempsSequentiel ;

/*********************Variable globales******************************/



<<<<<<< HEAD
=======
















>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
int main( int argc, char  *argv[]){

/*vérification*/

if (argc>3)
  {


<<<<<<< HEAD
    mode = argv[1];

    N=atoi(argv[2]);

    NumThr=atoi(argv[3]); 
    
    

   
        
  }else
  {
    printf("faute de saisie \n");
    printf("Utiliser : ./multiplic_matrix  [mode de calcul  pour parallel s/S , p/P pour sequentiel] [dimension des matrix nxn * nxn ] [num thread]\n"); 
=======
    N=atoi(argv[1]);
    NumThr=atoi(argv[2]);
    mode =atoi(argv[3]);
    
    

    /********* le mode ********/
        //0 parallel
        // 1 sequentiel
    

     /***************************/
        
  }else
  {
    printf("faute \n");
    printf("Utiliser : ./multiplic_matrix [dimension des matrix nxn * nxn ] [num thread] [mode de calcul 0 pour parallel 1 pour sequentiel]  \n"); 
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
    exit(-1);
  }

 if(NumThr > N|| NumThr < 1)
  {
<<<<<<< HEAD
    printf("Erreur vérifier la valeur N (impérativement positif) / Nombre de thread >=  \n");
=======
    printf("Erreur\n");
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
    exit(-2);
  }

int i,j = 0;

/*allocation des matrix*/

	a=(int **)malloc( N*sizeof(int *));     
	for(i=0;i<N;i++){
	a[i]=(int *)malloc( N*sizeof(int ));

	}

	b=(int **)malloc(N*sizeof(int *));
	for(i=0;i<N;i++){
	b[i]=(int *)malloc( N*sizeof(int ));

	}

   mult_p=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p[i]=(int *)malloc( N*sizeof(int ));
	}

	mult_p1=(int **)malloc( N*sizeof(int *));
	for(i=0;i<N;i++){
	mult_p1[i]=(int *)malloc( N*sizeof(int ));
	}

  mult_s=(int **)malloc( N*sizeof(int *));
  for(i=0;i<N;i++){
  mult_s[i]=(int *)malloc( N*sizeof(int ));
  }


VecteurNumDesThreads =(int *) malloc(NumThr*sizeof(int));
<<<<<<< HEAD

=======
/*allocation des matrix*/
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b





/** *le vecteur des id***/
for(int h =0;h<NumThr;h++)
  {
    VecteurNumDesThreads[h]=h;
    
  }
<<<<<<< HEAD
=======
/** *le vecteur des id***/




>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b

/*******************init matrix ************************/
	

<<<<<<< HEAD
 /************creating matrix a and b***********************/

           generateRandomMatrix(a,N,1,2);
           generateRandomMatrix(b,N,1,2);


/********************************************************/
                                                    

 
   if((!strcmp(mode, "P")) || (!strcmp(mode, "p"))){                                          
=======




                          /************creating matrix a and b***********************/

                          generateRandomMatrix(a,N,1,2);
                          generateRandomMatrix(b,N,1,2);



                          /********************************************************/
                                                    

/*******************diplay matrix a et b ************************/

 printf("MATRICE A\n");
printMatrix(a, N);
printf("\n\n\n");
 printf("MATRICE B\n");
printMatrix(b, N);

printf("\n\n\n");
/*********************************************/













   if(mode==0){                                          
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b



printf("calcul parallele Architecture 1 ligne\n");
printf("\n=========\n" );
printf("mode parallel");
printf("\nNombre de threads = %d\n", NumThr);
printf("size %d",N);
printf("\n=========\n" );
initialisation(NumThr);
sequentiel(N);
printf("\nresultat du calcul row\n" );
printMatrix(mult_p, N);
printf("\nfin calcul parallele Architecture 1 ligne\n\n\n");



printf("***************************************" );



printf("\ncalcul parallele Architecture 2 colonne\n");
printf("\n=========\n" );
printf("mode parallel");
printf("\nNombre de threads = %d\n", NumThr);
printf("size %d",N);
printf("\n=========\n" );
initialisationC(NumThr);
sequentiel(N);


<<<<<<< HEAD
=======




>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
printf("\nresultat du calcul col\n" );
printMatrix(mult_p1, N);
printf("\nfin calcul parallele Architecture 2 colonne\n\n\n");


<<<<<<< HEAD
=======




>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
/****SpeedUp*****/
printf("\n\n" );
speedUpArchiRow=tempsSequentiel/tempsParalleleArchitectureRow;
printf("speedUp entre sequentiel et architecture ligne : %f\n",speedUpArchiRow );

speedUpArchiCol=tempsSequentiel/tempsParalleleArchitectureColmun;
printf("speedUp entre sequentiel et architecture colonne : %f\n",speedUpArchiCol );


<<<<<<< HEAD
=======


>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
/*****VerificationMatrix***********/
printf("\nverification egalité entre matrice Para archi Row et matrice Seq\n" );
VerifEquality(mult_p,mult_s,N);

printf("\nverification egalité entre matrice Para archi col et matrice Seq\n" );

VerifEquality(mult_p1,mult_s,N);

}else{



<<<<<<< HEAD
if(((!strcmp(mode, "S")) || (!strcmp(mode, "s")))){
=======



if(mode==1){
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
/**********************************Sequetiel*********************************************/
printf("\ncalcul sequentiel \n\n ");
printf("\n=========\n" );
printf("mode: sequentiel\n" );
printf("thread count : 1\n" );
printf("size %d",N );
printf("\n=========\n" );
sequentiel(N);
printf("resultat du calcul sequentiel\n");

printMatrix(mult_s, N);


/*******************************************************************************/



}else{
<<<<<<< HEAD
printf("Specifier le mode sequentiel avec : s/S\t Specifier le mode parallel avec : p/P \n");

=======
printf("Specifier le mode sequentiel avec : s\t Specifier le mode parallel avec : p \n");
>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b


}



}

<<<<<<< HEAD
  
=======
       













































>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
for(i=0;i<N;i++)
  {
    free(a[i]);
    free(b[i]);
    free(mult_s[i]);
    free(mult_p[i]);
    free(mult_p1[i]);
  }
    free(a[i]);
    free(b[i]);
    free(mult_s[i]);
    free(mult_p[i]);
    free(mult_p1[i]);




<<<<<<< HEAD
=======





>>>>>>> b9f16f92905878d28461f7ab1ce4736c49905b1b
return 0;
}






