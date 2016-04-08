package clienteEndereco;

public class Cliente {
	private Endereco end;
	private String nome;
	private String cpf;
	
	public Cliente(String nome, String cpf, Endereco end){
		setEnd(end);
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public void setEnd(Endereco end){
		if(end != null){
			this.end = end;
		}
	}
	
	public Endereco getEnd(){
		return end;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}	
}