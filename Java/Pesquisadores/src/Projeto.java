
public class Projeto {
	private String nome;
	private int duracao;
	
	public Projeto(String nome, int duracao){
		setDuracao(duracao);
		setNome(nome);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public int getDuracao() {
		return duracao;
	}

	public void setDuracao(int duracao) {
		this.duracao = duracao;
	}
}
