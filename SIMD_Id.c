#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <xmmintrin.h>

int main(int argc, char **argv)
{
	int TAMANHOMATRIZ = atoi(argv[1]);
	int contador1, contador2, contador3;
	__m128 capsula;
    __m128 vetor1;
    __m128 vetor2;


    float **matriz1=(float**)malloc(TAMANHOMATRIZ*sizeof(float*));
    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
        matriz1[contador1]=(float*)malloc(TAMANHOMATRIZ*sizeof(float));

    float **matriz2=(float**)malloc(TAMANHOMATRIZ*sizeof(float*));
    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
        matriz2[contador1]=(float*)malloc(TAMANHOMATRIZ*sizeof(float));
        
    float **matriz1transposta=(float**)malloc(TAMANHOMATRIZ*sizeof(float*));
    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
        matriz1transposta[contador1]=(float*)malloc(TAMANHOMATRIZ*sizeof(float));


    srand(time(NULL));

    for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
    {
        for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
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
	}*/
	
//	printf("Transpondo primeira matriz...\n");
	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
	{
		for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
		{
			matriz1transposta[contador1][contador2] = matriz1[contador2][contador1];
		}
	}
	
/*	printf("Primeira matriz transposta:\n");
	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
	{
		for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
		{
			printf("%.2f ", matriz1transposta[contador1][contador2]);
		}
		printf("\n");
	}*/
	
	float *vetorapoiador1 = (float*)malloc(TAMANHOMATRIZ*sizeof(float));
	float *vetorapoiador2 = (float*)malloc(TAMANHOMATRIZ*sizeof(float));
	
	printf("Executando...\n");
	printf("\n");
	
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
			for(contador3=0;contador3<TAMANHOMATRIZ;contador3++)
			{
				vetorapoiador1[contador3] = matriz1[contador1][contador3];
				vetorapoiador2[contador3] = matriz1transposta[contador2][contador3];
			}	
			
		    capsula = _mm_setzero_ps();
		    for(contador3 = 0; contador3 < TAMANHOMATRIZ; contador3 = contador3+4)
            {
                vetor1 = _mm_loadu_ps(vetorapoiador1+contador3);
                vetor2 = _mm_loadu_ps(vetorapoiador2+contador3);
                capsula = _mm_add_ps(_mm_mul_ps(vetor1, vetor2), capsula);
		    }
			matriz2[contador1][contador2] = capsula[0]+capsula[1]+capsula[2]+capsula[3];
		}
	}

/*	printf("Resultado:\n");

	for(contador1=0;contador1<TAMANHOMATRIZ;contador1++)
	{
		for(contador2=0;contador2<TAMANHOMATRIZ;contador2++)
		{
			printf("%.2f ", matriz2[contador1][contador2]);
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
	
	printf("Fim da execucao\n");

	free(matriz1);
	free(matriz2);

	return EXIT_SUCCESS;
}
