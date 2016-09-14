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
	//srand((unsigned)time(NULL));
	for(int i = 1; i < v.size(); i++){
		cin >> v[i];
	}
}

void countingsort(vector<int> const v, vector<int> &new_v, int const k){
	vector<int> aux(k);
	for(int i = 0; i < k; i++){
		aux[i] = 0;	
	}

	for(int j = 1; j < v.size(); j++){
		aux[v[j]] = aux[v[j]]+1;	
	}

	for(int i = 1; i <= k; i++){
		aux[i] = aux[i] + aux[i-1];	
	}

	for(int j = v.size(); j >= 1; j--){
		new_v[aux[v[j]]] = v[j];
		aux[v[j]] = aux[v[j]]-1;	
	}
}

int main() {
	vector<int> v(6); 
	vector<int> new_v(6);
	int k;
	
	insere(v);

	cout << "Qual o maior elemento do vetor? : ";
	cin >> k;
	countingsort(v, new_v, k);

	cout << "vetor : ";
	imprime(v);
	cout << "ordenado: ";
	imprime(new_v);

	return 0;
}
