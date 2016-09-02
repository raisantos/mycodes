#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

void preenche(vector<int> &v){
	srand((unsigned)time(NULL));
	for(int i = 0; i < v.size(); i++){
		v[i] = rand()%100;
	}
}


void imprime(vector<int> &v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void bolha(vector<int>&v){
	for(int i = v.size()-1; i > 0; i-- ){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j+1]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}

}

void selection(vector<int>&v){
	int min, j, i;
	for(i=0; i<v.size()-2;i++){
		min=i;
		for(j=i+1;j<v.size();j++){
			if(v[j]<v[min]){
				min=j;	
			}
		}	
		int aux=v[min];
		v[min]=v[i];
		v[i]=aux;
	
	}

}

void insertion(vector<int>&v){
	int x, j;
	for(int i = 2; i < v.size(); i++){
		x = v[i];
		j = i-1;
		v[0] = x;
		while(x < v[j]){
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
	}
}



int main(){
	
	vector<int> v(10);
	preenche(v);	
//	bolha(v);
//	selection(v);
	insertion(v);
	imprime(v);

	return 0;
}
