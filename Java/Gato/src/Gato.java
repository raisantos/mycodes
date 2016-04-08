
public class Gato {
	String nome;
	int idade;
	float peso;
	
	// metodo construtor padrao
	Gato(){
	};
	
	//metodo construtor que recebe parametros(ideal para inicialização do estado de um obj.
	Gato(String nomeDoGato, int idadeDoGato, float pesoDoGato){
		nome = nomeDoGato;
		idade = idadeDoGato;
		peso = pesoDoGato;
	}
	
	void inserirNome(String nomeDoGato){
		nome = nomeDoGato;
	}
	
	void inserirIdade(int idadeDoGato){
		idade = idadeDoGato;
	}
	
	void inserirPeso(float pesoDoGato){
		peso = pesoDoGato;
	}
	
	String obterNome(){
		return nome;
	}
	
	int obterIdade(){
		return idade;
	}
	
	float obterPeso(){
		return peso;
	}
}
