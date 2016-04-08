import java.util.ArrayList;

import javax.swing.JOptionPane;

public class ContasPrincipal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Contas> contas = new ArrayList<Contas>();
		
		boolean continuar = true;
		char op;
		
		while (continuar) {
			String val = JOptionPane.showInputDialog("O que deseja fazer ?\n\n [i] Inserir Conta\n [c] Contas a pagar do mês\n [l] Listar Contas\n [p] Pagar Conta\n [t] Tipo de Contas (listar)\n [e] Excluir Conta\n [s]  Sair\n");
			op = val.charAt(0);
			switch (op) {
			case 'i': //insersao de uma conta
				int resp = JOptionPane.YES_OPTION;
				
				while (resp == JOptionPane.YES_OPTION) {
					Contas conta = new Contas();
					String id = JOptionPane.showInputDialog("Qual o id da conta ? ");
					conta.setId(id);
					String tipo = JOptionPane.showInputDialog("Qual o tipo de conta?");
					conta.setTipo(tipo);
					String valor = JOptionPane.showInputDialog("Qual o valor?");
					conta.setValor(valor);
					String mesVencimento = JOptionPane.showInputDialog("Qual o mês de vencimento?");
					conta.setMesVencimento(mesVencimento);
					int situacao = JOptionPane.showConfirmDialog(null, "Esta paga?", "Conta", JOptionPane.YES_NO_OPTION);
					conta.setSituacao(situacao);
					contas.add(conta);			
					
					resp = JOptionPane.showConfirmDialog(null, "Deseja inserir outro conta?", "Conta", JOptionPane.YES_NO_OPTION);
				}				
				
				break;

			case 'l': // listar todas as contas
				String mostraContas = "------- Conta$ -------\n";
				for (int i = 0; i < contas.size(); i++) {
					mostraContas += "\nId: " + contas.get(i).getId() + " Tipo: " + contas.get(i).getTipo() + "\nValor: R$" + contas.get(i).getValor() + "\nMes: " + contas.get(i).getMesVencimento() + "\nSituação (0 - Paga | 1 - Não paga): " + contas.get(i).getSituacao() + "\n";
				}
				JOptionPane.showMessageDialog(null, mostraContas);
				break;
			
			case 'c': //valor total de contas a pagar por mes
				float acum = 0;
				
				String mes = JOptionPane.showInputDialog("Qual o mes que deseja listar ? \n");
		
				for (int i = 0; i < contas.size(); i++) {
					if(contas.get(i).getMesVencimento().equals(mes)){
						float aux = Float.parseFloat(contas.get(i).getValor());
			
						acum += aux;
					}
				}
				JOptionPane.showMessageDialog(null, "Valor total do mes " + mes + " é : R$ " + acum);
				break;
			
			case 't': //listar por tipo
				String mostraTipos = "------- Conta$ -------\n";
				String tipo = JOptionPane.showInputDialog("Qual o tipo de conta ? \n");
				for (int i = 0; i < contas.size(); i++) {
					if(contas.get(i).getTipo().equals(tipo)){
						mostraTipos += "\nId: " + contas.get(i).getId() + " Tipo: " + contas.get(i).getTipo() + "\nValor: R$" + contas.get(i).getValor() + "\nMes: " + contas.get(i).getMesVencimento() + "\nSituação (0 - Paga | 1 - Não paga): " + contas.get(i).getSituacao() + "\n";
					}
				}
				JOptionPane.showMessageDialog(null, mostraTipos);
				break;
				
			case 'p': //alterar situacao de pagamento(paga/nao paga)
				String mostraId = "------- Conta$ --------\n";
				String id = JOptionPane.showInputDialog("Qual o Id da conta ? \n");
				for (int i = 0; i < contas.size(); i++) {
					if(contas.get(i).getId().equals(id)){
						mostraId += "\nId: " + contas.get(i).getId() + " Tipo: " + contas.get(i).getTipo() + "\nValor: R$" + contas.get(i).getValor() + "\nMes: " + contas.get(i).getMesVencimento() + "\nSituação (0 - Paga | 1 - Não paga): " + contas.get(i).getSituacao() + "\n";
						int p = JOptionPane.showConfirmDialog(null, mostraId + "\n\nConta foi paga ?", "Pagamento", JOptionPane.YES_NO_OPTION);
						if (p == JOptionPane.YES_OPTION){
							contas.get(i).setSituacao(0);
						}
					}
				}
				
				break;
				
			case 'e': //excluir conta
				String removeConta = "------- Conta$ --------\n";
				String removeId = JOptionPane.showInputDialog("Qual o Id da conta ? \n");
				for (int i = 0; i < contas.size(); i++) {
					if(contas.get(i).getId().equals(removeId)){
						removeConta += "\nId: " + contas.get(i).getId() + " Tipo: " + contas.get(i).getTipo() + "\nValor: R$" + contas.get(i).getValor() + "\nMes: " + contas.get(i).getMesVencimento() + "\nSituação (0 - Paga | 1 - Não paga): " + contas.get(i).getSituacao() + "\n";
						int s = JOptionPane.showConfirmDialog(null, removeConta + "\n\nDeseja remover a Conta?", "Remover", JOptionPane.YES_NO_OPTION);
						if (s == JOptionPane.YES_OPTION){
							contas.remove(i);
						}
					}
				}
				break;
				
			case 's':
				JOptionPane.showMessageDialog(null, "Saindo...");
				continuar=false;
				System.exit(0);
				break;
			}
		}

	}

}
