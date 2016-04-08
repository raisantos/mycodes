package clienteEndereco2;

import clienteEndereco2.Cliente;
import clienteEndereco2.Endereco;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Cliente cliente = new Cliente("Rai", "023165813200");
		
		//quando o cliente tiver endereco
		Endereco endereco = new Endereco(22, "Flores", 498465316, "Ap 302");
		cliente.setEnd(endereco);
		
		Endereco end = cliente.getEnd();
		String endStr = end.getNumero() + ", " + end.getRua() + ", " + end.getCep() + ", " + end.getComplemento();
		System.out.println("Endereco : " + endStr);
		//se o cliente nao tiver endereco
		cliente.removeEndereco();
		System.out.println("Endereco : "+ cliente.getEnd());
	}

}
