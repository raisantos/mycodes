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

void troca(vector<int> &v, int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void shellsort(vector<int> &v){
     int h = 1;
     while(h < v.size()/3){
          h = 3*h+1;
     }
     
     while(h >= 1){
          for(int i = h; i < v.size(); i++){
               int j = i;
               while(j >= h && v[j] < v[j-h]){
                    troca(v, j, j-h);
                    j = j-h;
               }
          }
          h = h/3;
     }
}

int main() {
	vector<int> v(11);
	insere(v);
	cout << "vetor : ";
	imprime(v);
	shellsort(v);	
	cout << "ordenado: ";

	imprime(v);

	return 0;
}
