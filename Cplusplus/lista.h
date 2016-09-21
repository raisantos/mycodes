/*
 * Lista.h
 *
 *  Created on: 28 de mar de 2016
 *      Author: raisantos
 */
#ifndef Lista_h
#define Lista_h

#include <iostream>
using namespace std;

typedef string Chave;

class Item{
public:
	Chave codigo;
	string nome;
	int cargaHora;

	Item() {}

	Item (Chave codigo, string nome, int cargaHora){
		this->codigo = codigo;
		this->nome = nome;
		this->cargaHora = cargaHora;
	}

	void mostra(){
		cout << codigo << " - " << nome << " - " << cargaHora << endl;
	}
};

class Lista{
public:
	Item *item;
	int TAM;
	int tam;

	Lista(int tam){
		TAM = tam;
		item = new Item[TAM+1];
		this->tam = 0;
	}

	Item* busca(Chave);
	void insere(Item);
	void remover(int, Item&);
	void mostra();
	bool cheia();
	bool vazia();
};

#endif
