#include <iostream>

using namespace std;

typedef int Vertex;

class Item {
private:
    Vertex valor;

public:
    Item() {};
    Item(int valor): valor(valor) { }

    int getVertex() {
        return valor;
    }
 
    void setVertex(int valor) {
        this -> valor = valor;
    }
    void print();
};

void Item::print(){
  cout << getVertex();
}

class No {
public:
	  Item *item;
    No *prox;

    No() {}

    Item* getItem() {
        return item;
    }

    void setItem(Item *item) {
        this -> item = item;
    }

    No* getProx() {
        return prox;
    }

    void setProx(No *prox) {
        this->prox = prox;
    }
};

class Lista{
private:
	No *prim, *ult;
public:
	No* getPrim(){
		return prim;
	}

	No* getUlt(){
		return ult;
	}
	Lista();
	void insere(Item*);
	//void remove(Item*);
	void print();
	//void search(Item*);
	void destroy();
};

Lista::Lista() {
    prim = new No(); // cabeça
    prim -> prox = NULL;
    ult = prim;
}
void Lista::insere(Item* x){
	ult->prox = new No();
	ult = ult->prox;
	ult->prox = NULL;
	ult->item = x;
}

void Lista::print(){
  No* p = getPrim()->getProx();
  while(p != NULL){
    p->getItem()->print();
  }
  p = p->prox;
}

void Lista::destroy(){
  No* p = getPrim()->getProx();
    while(p != NULL){
      delete(p);
    }
    p = p->prox;
}

class Graph { // Não-direcionado

  Lista<Vertex> *adj;
  int n, m; // ordem e tamanho

  public:
  Graph(int); // construtor
  void initialize(int);
  void insertEdge(Vertex, Vertex);
  void print();
  void destroy();
// métodos get/set para n, m e adj.
};

void Graph::Graph (int n) {
  initialize(n);
}

void Graph::initialize(int n) {
  if (this->n != 0) destroy();
    this->n = n;
    adj = new List<Vertex>[n+1]; // Vetor usa
    // células de 1..n
}

void Graph::insertEdge(Vertex u, Vertex v) {
  Item x(v); // chave = vértice
  adj[u].insere(x); // Insere na lista
  x(u);
  adj[v].insere(x); // Insere na lista
  m++;
}

void Graph::print() {
  for (int i = 1; i <= n; i++) {
    cout << "v[" << i << "] = ";
    adj[i].print();
  }
}

void Graph::destroy() {
  for (int i = 0; i <= n; i++) {
    adj[i].destroy(); // destroi lista
  }
  delete( adj );
  n = m = 0;
}

// Função auxiliar
void testaGrafo(Grafo &g) {
  g.insertEdge(1, 2);
  g.insertEdge(2, 3);
  g.insertEdge(3, 4);
  g.insertEdge(4, 5);
  g.insertEdge(5, 1);
  g.insertEdge(5, 2);
  g.insertEdge(2, 4);
  g.print();
}

int main(int argc, const char * argv[]) {
  int n, m;

  cout << "ordem: "; cin >> n;
  Grafo g(n);
  testaGrafo(g);

  return 0;

}
