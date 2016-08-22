#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void imprime(vector<int> &v){
	for(int i = 0; i < v.size()-1; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void insere(vector<int> &v){
	srand((unsigned)time(NULL));
	for(int i = 0; i < v.size()-1; i++){
		v[i] = rand()%100;
	}
}

void troca(vector<int> &v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int particao(vector<int> &v, int p, int r){
	int x = v[p], tmp = v[r+1];
	v[r+1] = x;

	int i = p, j = r+1;

	while(true){
		do{
			i = i+1;
		}while(v[i] < x);
		
		do{
			j = j-1;
		}while(v[j] > x);

		if(i < j){
			troca(v, i, j);
		}
		else{
			troca(v, p, j);
			v[r+1] = tmp;
			return j;
		}
	}
}

void quicksort(vector<int> &v, int p, int r){
	int q;
	if(p < r){
		q = particao(v, p, r);
		quicksort(v, p, q-1);
		quicksort(v, q+1, r);
	}
}

int main(){
	vector<int> v(10);
	insere(v);
	imprime(v);
	quicksort(v, 0, 8);
	imprime(v);

	return 0;
}
