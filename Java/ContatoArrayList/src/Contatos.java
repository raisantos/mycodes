
import javax.swing.JOptionPane;
import java.util.ArrayList;

public class Contatos {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Contato> contatos = new ArrayList<Contato>();
		boolean continuar = true;
		
		while(continuar){
			String val = JOptionPane.showInputDialog("O que deseja fazer ?\n\n 1 - Cadastrar Contato\n 2 - Listar Contatos\n 3 - Consultar Contato\n 4 - Remover Contato\n 5 - Sair\n");
			int a = Integer.parseInt(val);
			
			switch(a){
				case 1:
					String opcao;
					do{
						Contato contato = new Contato();
	
						String nome = JOptionPane.showInputDialog("Qual o nome do contato ?");
						String num = JOptionPane.showInputDialog("Qual o numero do contato ?");
						contato.inserirNome(nome);
						contato.inserirNum(num);
						contatos.add(contato);
						
						opcao = JOptionPane.showInputDialog("Deseja continuar ? sim/nao ");
					}while(!opcao.equals("nao"));
					break;
				case 2:
					String listaDeContatos = "-----Lista de Contatos-----\n\n";
					for(int i = 0; i < contatos.size(); i++){
						listaDeContatos += "Nome do contato : "+ contatos.get(i).imprimeNome()+"\n"+"Telefone do Contato : "+ contatos.get(i).imprimeNum()+"\n\n";
					}
					JOptionPane.showMessageDialog(null, listaDeContatos);
					break;
				case 3:
					String dadosDoContato = "-----Contato-----\n";
					String nomeConsulta = JOptionPane.showInputDialog("Digite o nome para consulta : ");
					for(int i = 0; i < contatos.size(); i++){
						if(contatos.get(i).imprimeNome().equals(nomeConsulta)){
							dadosDoContato += "Nome do Contato : "+ contatos.get(i).imprimeNome()+"\n"+"Telefone do Contato : "+ contatos.get(i).imprimeNum()+"\n";
						}
					}
					JOptionPane.showMessageDialog(null, dadosDoContato);
					break;
				case 4:
					String nomeRemove = JOptionPane.showInputDialog("Digite o nome para remover : ");
					for(int i = 0; i < contatos.size(); i++){
						if(contatos.get(i).imprimeNome().equals(nomeRemove)){
							contatos.remove(i);
						}
					}
					JOptionPane.showMessageDialog(null, "Contato " + nomeRemove + " foi removido\n");
					break;
				case 5:
					JOptionPane.showMessageDialog(null, "Saindo...");
					continuar = false;
					break;
					
			}
		}
	}

}
