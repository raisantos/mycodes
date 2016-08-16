#include <stdio.h>
#include <stdlib.h>

void change(int *vector, int num1, int num2)
{
    int aux;

    aux = vector[num1];
    vector[num1] = vector[num2];
    vector[num2] = aux;
}

void show(int *vector, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void permutations(int *vector, int n, int j)
{
    if(j == n){ 
        show(vector, n);
    }
    else{
        for(int i = j; i < n; i++)
        {
            change(vector, j, i);
            permutations(vector, n, j+1);
            change(vector, i, j);
        }
    }
}

void listPermutations(int *vector, int n){
	permutations(vector, n, 0);
}

int main()
{
    int *vector, n;

    printf("Insira o numero n de elementos do vetor : ");
    scanf("%d", &n);
    vector = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        vector[i] = i+1;
    }

    listPermutations(vector, n);

    return 0;
}
