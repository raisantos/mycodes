import java.util.ArrayList;

public class Principal {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final int TOTAL_PROJETOS = 100;
		final int TOTAL_PESQUISADORES = 100;
		
		ArrayList<Pesquisador> pesquisadores = new ArrayList<Pesquisador>(TOTAL_PESQUISADORES);
		pesquisadores.add(new Pesquisador("Ana Lung", 11));
		pesquisadores.add(new Pesquisador("Donald Knuth", 22));
		
		ArrayList<Projeto> projetos = new ArrayList<Projeto>(TOTAL_PROJETOS);
		projetos.add(new Projeto("PlayStation", 2));
		projetos.add(new Projeto("Robo Domestico", 4));
		
		Projeto projeto = projetos.get(1);
		pesquisadores.get(0).alocarEmProjeto(projeto);
		pesquisadores.get(1).alocarEmProjeto(projeto);
		
		System.out.println("Projeto: " + pesquisadores.get(0).getProjetos().get(0).getNome());
		System.out.println("Duração: " + pesquisadores.get(0).getProjetos().get(0).getDuracao() + " anos");
	}

}
