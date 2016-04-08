import javax.swing.JOptionPane;

public class ContatoTeste {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*Contato contato = new Contato("Pedro", "9988-1212");
		
		System.out.println("Nome = " + contato.imprimeNome());
		System.out.println("Numero = " + contato.imprimeNum());
		System.out.println();
		
		Contato contato2 = new Contato();
		
		String nome = JOptionPane.showInputDialog("Qual é o seu nome?");
		contato2.inserirNome(nome);
		String numTelefone = JOptionPane.showInputDialog("Qual é o seu tel?");
		contato2.inserirNum(numTelefone);
		
		System.out.println("O nome do contato2 é : " + contato2.imprimeNome());
		System.out.println("O num do contato2 é : " + contato2.imprimeNum());
	*/
		//Array de contatos
		/*Contato[] contato3 = new Contato[2];
		contato3[0] = new Contato();
		contato3[1] = new Contato();
		
		String n = JOptionPane.showInputDialog("Qual é o seu nome?");
		contato3[0].inserirNome(n);
		String tel = JOptionPane.showInputDialog("Qual é o seu telefone?");
		contato3[0].inserirNum(tel);
		
		String m = JOptionPane.showInputDialog("Qual é o seu nome?");
		contato3[1].inserirNome(m);
		String tel2 = JOptionPane.showInputDialog("Qual é o seu telefone?");
		contato3[0].inserirNum(tel2);
		
		System.out.println("O nome do contato3.[0] é "+contato3[0].imprimeNome());
		System.out.println("O nome do contato3.[1] é "+contato3[1].imprimeNome());
	*/
		
		Contato[] contatos = new Contato[10];
		boolean continuar = true;
		int c = 0;
		
		while(continuar){
			String val = JOptionPane.showInputDialog("O que deseja fazer ?\n\n 1 - Cadastrar Contato\n 2 - Listar Contatos\n 3 - Sair\n");
			int a = Integer.parseInt(val);
			
			switch(a){
				case 1:
					String val2 = JOptionPane.showInputDialog("Quantos contatos deseja cadastrar ?\n");
					int b = Integer.parseInt(val2);

					for(int i = 0; i < b; i++){
						Contato contato = new Contato();
	
						String nome = JOptionPane.showInputDialog("Qual o nome " + (i+1) );
						String num = JOptionPane.showInputDialog("Qual o numero " + (i+1) );
						contato.inserirNome(nome);
						contato.inserirNum(num);
			
						contatos[i] = contato;
						c = c+1;
					}break;
				case 2:
					String listaDeContatos = "-----Lista de Contatos-----\n";
					for(int i = 0; i < c; i++){
						listaDeContatos += "Nome do contato : "+ contatos[i].imprimeNome()+"\n"+"Telefone do Contato : "+ contatos[i].imprimeNum()+"\n";
					}
					JOptionPane.showMessageDialog(null, listaDeContatos);
					break;
				case 3:
					JOptionPane.showMessageDialog(null, "Saindo...");
					continuar = false;
					break;
					
			}
		
		}
	}
}