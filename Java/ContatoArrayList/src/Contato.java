
public class Contato {
	private String nome;
	private String numTelefone;
	
	Contato(){}
	
	Contato(String nome, String numTelefone){
		this.nome = nome;
		this.numTelefone = numTelefone;
	}
	
	void inserirNome(String nome){
		this.nome = nome;
	}
	
	void inserirNum(String numTelefone){
		this.numTelefone = numTelefone;
	}
	
	String imprimeNome(){
		return nome;
	}
	
	String imprimeNum(){
		return numTelefone;
	}
}