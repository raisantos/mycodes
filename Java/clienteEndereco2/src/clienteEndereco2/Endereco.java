package clienteEndereco2;

import clienteEndereco2.Endereco;

public class Endereco {
	private int numero;
	private String rua;
	private int cep;
	private String complemento;
	
	public Endereco(int num, String rua, int cep, String complemento){
		this.numero = num;
		this.rua = rua;
		this.cep = cep;
		this.complemento = complemento;
	}
	
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public String getRua() {
		return rua;
	}
	public void setRua(String rua) {
		this.rua = rua;
	}
	public int getCep() {
		return cep;
	}
	public void setCep(int cep) {
		this.cep = cep;
	}
	public String getComplemento() {
		return complemento;
	}
	public void setComplemento(String complemento) {
		this.complemento = complemento;
	}
}
