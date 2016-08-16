/*
 * Programacao de Computadores e ALgoritmos
 * Trabalho 2
 * monitoria.c
 *
 * Equipe:
 *
 *          Ewerton Petillo
 *          Hermann Hernani
 *          Jailson
 *          Lucas Botinelly
 *          Richardson Souza
 *          Wilson Calisto
 */

#include <stdio.h>
#include <stdlib.h>

char* inverte_string(char *, int);

char* inverte_string(char *entrada, int tam){
	char *nova_string;
	int k = 0;
	nova_string = (char*) malloc(tam*sizeof(char));

	for(int i = tam-1; i >= 0; i--){
		nova_string[k] = entrada[i];
		printf("%c\n", nova_string[k]);
		k++;
	}

	//printf("--------------");
	//puts(nova_string);
	//printf("---------------");

	return nova_string;
}

int main(){
	char *entrada, *saida;
	int tam = 35;

	entrada = malloc(tam*sizeof(char));
	saida = malloc(tam*sizeof(char));
	fgets(entrada, 35, stdin);
	puts(entrada);

	saida = inverte_string(entrada, tam);
	puts(saida);

	return 0;
}
