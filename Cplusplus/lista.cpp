/*
 * Lista.cpp
 *
 *  Created on: 28 de mar de 2016
 *      Author: raisantos
 */
#include "Lista.h"

void Lista::mostra(){
	for(int i = 1; i<=tam; i++){
		item[i].mostra();
	}
	cout << endl;
}

bool Lista::cheia(){
	return tam == TAM;
}

bool Lista::vazia(){
	return tam == 0;
}

void Lista::insere(Item x){
	if(!cheia()){
		tam++;
		item[tam] = x;
	}
	else{
		cout << "impossivel inserir\n";
	}
}

void Lista::remover(int pos, Item& x){
	if(!vazia() && 1 <= pos && pos <= tam){
		x = item[pos];
		for(int i = pos; i < tam; i++){
			item[i] = item[i+1];
		}
		tam--;
	}
	else{
		cout << "impossivel remover\n";
	}
}
