#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <climits>
#include <iomanip>
using namespace std;

typedef int Vertice;
const float FLOAT_MAX = LONG_MAX;
const float INFINITO = INT_MAX;

int extraiMinimo(vector<float> chaves, vector<bool> vertices, int ordem)
{
   // Initialize min value
   float menor = FLOAT_MAX;
   int menor_indice;

   for (int i = 0; i < ordem; i++){
     if (vertices[i] == false && chaves[i] < menor){
         menor = chaves[i]; 
         menor_indice = i;
     }
   }

   return menor_indice;
}

// A utility function to print the constructed MST stored in parent[]
void somaMST(vector<int> arvore, vector<vector<float> > grafo, int ordem)
{
   float acumulador = 0.0;
   for (int i = 1; i < ordem; i++){
   	  acumulador+=grafo[i][arvore[i]];
   }
   cout << acumulador;
}

// Function to construct and print MST for a graph represented using adjacency
// matrix representation
void MST(vector<vector<float> > grafo, int ordem, int raiz)
{
     vector<int> arvore(ordem); // Array to store constructed MST
     vector<float> chaves(ordem);   // Key values used to pick minimum weight edge in cut
     vector <bool> vertices(ordem);  // To represent set of vertices not yet included in MST

     // Initialize all keys as INFINITE
     for (int i = 0; i < ordem; i++){
        chaves[i] = INFINITO;
        vertices[i] = false;
	}
     // Always include first 1st vertex in MST.
     chaves[0] = 0.0;     // Make key 0 so that this vertex is picked as first vertex
     arvore[0] = -1; // First node is always root of MST

     // The MST will have V vertices
     for (int i = 0; i < ordem-1; i++)
     {
        // Pick the minimum key vertex from the set of vertices
        // not yet included in MST
        int u = extraiMinimo(chaves, vertices, ordem);

        // Add the picked vertex to the MST Set
        vertices[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int j = 0; j < ordem; j++)

           // graph[u][v] is non zero only for adjacent vertices of m
           // mstSet[v] is false for vertices not yet included in MST
           // Update the key only if graph[u][v] is smaller than key[v]
          if (grafo[u][j] && vertices[j] == false && grafo[u][j] < chaves[j])
             arvore[j] = u;
             chaves[j] = grafo[u][j];
     }

     // print the constructed MST
     somaMST(arvore, grafo, ordem);
}

//--------------------------------




template<class T>
class GrafoDeTransmissao {
private:
	vector<vector<T> > adj;
	int ordem, tam;

public:
	GrafoDeTransmissao(int);
	void iniciar(int);
	void preenche();
	void insere(Vertice, Vertice, float);
	void destroy();
	void mostra();

	vector<vector<T> > getAdj() {
		return adj;
	}
	void setAdj(vector<vector<T> > adj) {
		this->adj = adj;
	}
	int getOrdem() {
		return ordem;
	}
	void setOrdem(int n) {
		this->ordem = ordem;
	}
	int getTam() {
		return tam;
	}
	void setTam(int tam) {
		this->tam = tam;
	}
};

template<class T>
GrafoDeTransmissao<T>::GrafoDeTransmissao(int ordem) {
	iniciar(ordem);
	preenche();
}

template<class T>
void GrafoDeTransmissao<T>::iniciar(int ordem) {
	this->ordem = ordem;
	for(int i = 0; i < ordem; i++){
	    vector<T> aux(ordem);
	    adj.push_back(aux);
	}
}

template<class T>
void GrafoDeTransmissao<T>::preenche() {
	for (int i = 0; i < ordem; i++) {
	    for(int j = 0; j < ordem; j++){
		    adj[i][j] = 0.0;
		}
	}
}

template<class T>
void GrafoDeTransmissao<T>::mostra() {
    for (int i = 0; i < ordem; i++) {
	    for(int j = 0; j < ordem; j++){
	        cout.precision(2);
		    cout << fixed << adj[i][j] << "   ";
		}
		cout << endl;
	}
}

template<class T>
void GrafoDeTransmissao<T>::insere(Vertice v1, Vertice v2, float peso) {
	adj[v1][v2] = peso;
	adj[v2][v1] = peso;
}

int main() {
    int ordem, tamanho, v1, v2, raiz;
    float peso;
    cin >> ordem;
    cin >> tamanho;

    GrafoDeTransmissao<float> gt(ordem);

    for (int i = 0; i < tamanho; ++i) {
    	cin >> v1;
    	cin >> v2;
    	cin >> peso;
    	gt.insere(v1,v2,peso);
	}

    cin >> raiz;

    MST(gt.getAdj(), ordem, raiz);

	return 0;
}
