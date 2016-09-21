//============================================================================
// Name        : ListaOO.cpp
// Author      : raisantos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lista.h"
using namespace std;

/*void troca(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}*/

void troca(int& a, int& b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {

	/*int a = 111;
	int b = 222;
	troca(&a, &b);
	cout << a << " - " << b << endl;*/

	//Item x;
	//x.codigo = "1000";
	//x.nome = "M. Discreta";
	//x.cargaHora = 90;
	//x.mostra();
	Lista l(5);

	Item a("CH100", "AED", 90);
	l.insere(a);
	Item b("CJ200", "AJD", 80);
	l.insere(b);
	Item c("CH300", "XXD", 60);
	l.insere(c);
	Item d("CH500", "AXD", 60);
	l.insere(d);

	l.mostra();

	//l.remover(1, a);
	//l.mostra();

	//y.mostra();

	cout << endl;

	return 0;
}
