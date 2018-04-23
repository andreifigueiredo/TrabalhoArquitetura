#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	int TAMANHOMATRIZ = atoi(argv[1]);
	int capsula, contador1, contador2,contador3;

	float **matriz1=(float**)malloc(TAMANHOMATRIZ*sizeof(float*));
    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
        matriz1[contador1]=(float*)malloc(TAMANHOMATRIZ*sizeof(float));

    float **matriz2=(float**)malloc(TAMANHOMATRIZ*sizeof(float*));
    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
        matriz2[contador1]=(float*)malloc(TAMANHOMATRIZ*sizeof(float));
        
    srand(time(NULL));

	for(contador1 = 0; contador1 < TAMANHOMATRIZ; contador1++)
	{
		for(contador2 = 0; contador2 < TAMANHOMATRIZ; contador2++)
		{
			matriz1[contador1][contador2]=rand()%TAMANHOMATRIZ;
		}
	}
	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
    	matriz1[contador1][contador1] = 1;
	
/*	printf("Primeira matriz:\n");
	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
	{
		for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
		{
			printf("%.2f ", matriz1[contador1][contador2]);
		}
		printf("\n");
	}
	printf("\n");*/

	printf("Executando...\n");

	for(contador1 = 0; contador1 < TAMANHOMATRIZ; contador1++)
	{
		if(matriz1[contador1][contador1] != 1)
		{
			printf("A matriz nao e identidade\n");
			printf("Fim da execucao\n"); 
			return EXIT_SUCCESS;
		}		
	}
	
	for(contador1 = 0; contador1 < TAMANHOMATRIZ; contador1++)
	{

		for(contador2 = 0; contador2 < TAMANHOMATRIZ; contador2++)
		{
		    capsula = 0;
		    for(contador3 = 0; contador3 < TAMANHOMATRIZ; contador3++)
            {
                capsula += matriz1[contador1][contador3] * matriz1[contador3][contador2];
		    }
			matriz2[contador1][contador2] = capsula;
		}
	}
/*	printf("Resultado:\n");
	
	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
	{
		for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
		{
			printf("%.2f", matriz2[contador1][contador2]);
		}
		printf("\n");
	}*/
	
	for(contador1=0; contador1 < TAMANHOMATRIZ; contador1++)
	{
		for(contador2=0; contador2 < TAMANHOMATRIZ; contador2++)
		{
			if(matriz1[contador1][contador2] != matriz2[contador1][contador2])
			{
			printf("A matriz nao e identidade\n");
			printf("Fim da execucao\n"); 
			return EXIT_SUCCESS;
			}
		}		
	}
	
	printf("Matriz e identidade\n");
	printf("Fim da execucao\n"); 

	free(matriz1);
	free(matriz2);

	return EXIT_SUCCESS;
}
