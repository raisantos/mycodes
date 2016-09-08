//============================================================================
// Name        : mergesort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

void imprime(vector<int> &v){
	for(int i = 1; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void insere(vector<int> &v){
	srand((unsigned)time(NULL));
	for(int i = 1; i < v.size(); i++){
		v[i] = rand()%100;
	}
}

void merge(vector<int> &v, int p, int q, int r){
	int n1 = q-p+1, n2 = r-q;
	vector<int> left(n1+2);
	vector<int> right(n2+2);
	int i, j;

	for(i = 1; i <= n1; i++){
		left[i] = v[p+i-1];
	}
	
	for(j = 1; j <= n2; j++){
		right[j] = v[q+j];
	}
	
	left[n1+1] = 101;
	right[n2+1] = 101;
	
	i = 1; 
	j = 1;
	for(int k = p; k <= r; k++){
		if(left[i] <= right[j]){
			v[k] = left[i];
			i++;
		}
		else{
			v[k] = right[j];
			j++;
		}
	}

}

void mergesort(vector<int> &v, int p, int r){
	if(p < r){
		int q = floor((p+r)/2);
		//cout << "q : " << q << endl;
		mergesort(v, p, q);
		mergesort(v, q+1, r);
		merge(v, p, q, r);
	}
}

int main() {
	vector<int> v(10);
	insere(v);
	cout << "vetor : ";
	imprime(v);
	cout << v.size() << endl;
	mergesort(v, 1, v.size());
	cout << "vetor ordenado: ";
	//int q = floor((1+v.size())/2);
	//merge(v, 1, q, v.size());
	//cout << "merge : ";
	imprime(v);

	return 0;
}
