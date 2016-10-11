#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef int Vertex;
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;
int tempo;

class Item {
private:
    Vertex valor;
    int cor, d, f;
    Item *predecessor;
    //Lista *vertices;

public:
    Item() {};
    Item(int valor): valor(valor) { }

    Vertex getVertex() {
        return valor;
    }
    void setVertex(Vertex valor) {
        this -> valor = valor;
    }
    int getCor(){
    	return cor;
    }
    void setCor(int cor){
    	this->cor = cor;
    }
    void setPredecessor(Item *predecessor){
    	this->predecessor = predecessor;
    }
    Item* getPredecessor(){
    	return predecessor;
    }
    void setD(int d){
    	this->d = d;
    }
    int getD(){
    	return d;
    }
    void setF(int f){
    	this->f = f;
    }
    int getF(){
    	return f;
    }
    /*Lista* getVertices(){
	return vertices;
    }
    void setVertices(Lista *vertices){
	this->vertices = vertices;
    }*/
    void print();
};

void Item::print(){
  cout << getVertex() << " ";
}

class No {
private:
    Item *item;
    No *prox;

public:
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
    prim -> setProx(NULL);
    ult = prim;
}

void Lista::insere(Item* x){
	ult->setProx(new No());
	ult = ult->getProx();
	ult->setProx(NULL);
	ult->setItem(x);
}

void Lista::print(){
  No* p = getPrim()->getProx();
  while(p != NULL){
    p->getItem()->print();
    p = p->getProx();
  }
  cout << endl;
}

void Lista::destroy(){
  No* p = getPrim()->getProx();
    while(p != NULL){
      delete(p);
      p = p->getProx();
    }
}
/*
class Fila{
private:
	Item *vertices; //vetor
	int frente, tras;
	int TAM;

public:
	Fila(int tam);
	void enfileira(Item*);
	Item* desenfileira();
	void mostra();
	bool vazia();
};

Fila::Fila(int tam){
		TAM = tam;
		vertices = new Item[TAM];
		frente = 0;
		tras = frente;
	}

void Fila::enfileira (Item *it){
	if((tras + 1) % TAM == frente){
		cout << "Fila Cheia!!" << endl;
	}
	else
	{
		vertices[tras] = it;
		tras = (tras+1) % TAM;
	}
}

Item* Fila::desenfileira(){
	if(frente == tras){
		cout << "Fila vazia!!" << endl;
		return NULL;
	}
	else
	{
		Item *it = new Item();
		it = vertices[frente];
		frente = (frente + 1) % TAM;
		return it;
	}
}

void Fila::mostra(){
	for(int i = frente; i < tras; i++){
		vertices[i].print();
	}
	cout << endl;
}

bool Fila::vazia(){
	if(frente == tras){
		return true;
	}
	else{
		return false;
	}
}
*/
class Grafo { // Não-direcionado
private:
  	Item *adj;
  	int n, m; // ordem e tamanho

public:
  	Grafo(int); // construtor
  	void initialize(int);
  	void insertEdge(Vertex, Vertex);
  	void print();
  	void destroy();
// métodos get/set para n, m e adj.
	Item* getAdj(){
		return adj;
	}
	void setAdj(Item* adj){
		this->adj = adj;
	}
	int getN(){
		return n;
	}
	void setN(int n){
		this->n = n;
	}
	int getM(){
		return m;
	}
	void setM(int m){
		this->m = m;
	}
};

Grafo::Grafo (int n) {
  initialize(n);
}

void Grafo::initialize(int n) {
  //if (this->n != 0){
    this->n = n;
    adj = new Item[n+1]; // Vetor usa
    for(int i = 1; i <= n; i++){
    	adj[i] = new Item(i);
    }
    //inicializar os itens do vetor de 1 a n com os respectivos numeros de vertice
  //}  // células de 1..n
}

/*void Grafo::insertEdge(Vertex u, Vertex v) {
  Item *x = new Item(v); // chave = vértice
  adj[u].getVertices().insere(x); // Insere na lista // vetor de itens(adj) pega a lista(getVertices) e adiciona
  x = new Item (u);
  adj[v].getVertices().insere(x); // Insere na lista
  m++;
}
*/
void Grafo::print() {
  for (int i = 1; i <= n; i++) {
    cout << "v[" << i << "] = ";
    adj[i].print();
  }
}

void Grafo::destroy() {
  for (int i = 0; i <= n; i++) {
    //adj[i].destroy(); // destroi lista
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

//busca em profundidade
void dfsVisita(Grafo &g, Item *u){
	tempo = tempo+1;
	u->setD(tempo);
	u->setCor(CINZA);
	No *p = g.getAdj()[u->getVertex()].getPrim()->getProx();
	while(p != NULL){
		Item *v = new Item();
		v = p->getItem();
		if(v->getCor() == BRANCO){
			v->setPredecessor(u);
			dfsVisita(g, v);
		}
		p = p->getProx();
	}
	u->setCor(PRETO);
	tempo = tempo+1;
	u->setF(tempo);
}

void dfs(Grafo &g){
	No* p = g.getAdj()->getPrim()->getProx();
	while(p != NULL){
		Item *u = new Item();
		u = p->getItem();
		u->setCor(BRANCO);
		u->setPredecessor(NULL);
	    p = p->getProx();
	}

	tempo = 0;
	p = g.getAdj()->getPrim()->getProx();
	while(p != NULL){
		Item *u = new Item();
		u = p->getItem();
		if(u->getCor() == BRANCO){
			dfsVisita(g, u);
		}
		p = p->getProx();
	}
}
/*
//busca em largura
void bfs(Grafo &g, Item *s){
	No* p = g.getAdj()->getPrim()->getProx();
	Item *u = new Item();
	while(p != NULL){
		u = p->getItem();
		u->setCor(BRANCO);
		u->setD(1111);
		u->setPredecessor(NULL);
	    p = p->getProx();
	}
	s->setCor(CINZA);
	s->setD(0);
	s->setPredecessor(NULL);

	Fila fila(g.getN());
	fila.enfileira(s);
	while(!fila.vazia()){
		u = fila.desenfileira();
		No *q = g.getAdj()[u->getVertex()].getPrim()->getProx();
		while(q != NULL){
			Item *v = new Item();
			v = q->getItem();
			if(v->getCor() == BRANCO){
				v->setCor(CINZA);
				v->setD(u->getD()+1);
				v->setPredecessor(u);
				fila.enfileira(v);
			}
			q = q->getProx();
		}
		u->setCor(PRETO);
	}
}
*/
int main(int argc, const char * argv[]) {
  int n;
  /*Vertex v = 1;
  Vertex b = 2;
  Lista *l = new Lista();
  Item *i = new Item(v);
  Item *j = new Item(b);
  l->insere(j);
  l->insere(i);
  l->print();
  dfs1(l);
  cout << l->getPrim()->getProx()->getItem()->getCor();*/

  cout << "ordem: "; cin >> n;
  Grafo g(n);
  cout << "-----grafo-----" << endl;
  testaGrafo(g);
  cout << "-----fim-------" << endl;

  g.getAdj()[1].print();
  //dfs(g);
  //cout << g.getAdj()->getPrim()->getProx()->getItem()->getCor();
  //cout << "-----fim-------";
  return 0;
}
