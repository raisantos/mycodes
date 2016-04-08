package clienteEndereco;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Endereco endereco = new Endereco(22, "Flores", 498465316, "Ap 302");
		Cliente cliente = new Cliente("Rai", "023165813200", endereco);
		
		Endereco end = cliente.getEnd();
		
		String endStr = end.getNumero() + ", " + end.getRua() + ", " + end.getCep() + ", " + end.getComplemento();
		
		System.out.println("Nome : " + cliente.getNome());
		System.out.println("Cpf : " + cliente.getCpf());
		System.out.println("Endereco : " + endStr);
	}

}
