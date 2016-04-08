
public class GatoPrincipal {

	public static void main(String[] args) {
		// Félix
		/*Gato felix = new Gato();
		felix.nome = "Félix";
		felix.idade = 10;
		felix.peso = 2.25f;
		
		System.out.println("O nome do gato é " + felix.nome);
		System.out.println("A idade do gato " + felix.nome + " é " + felix.idade);
		System.out.println("O peso do gato " + felix.nome + " é " + felix.peso + " kilos");
		System.out.println();

		// Frajola
		Gato frajola = new Gato();
		frajola.nome = "Frajola";
		frajola.idade = 15;
		frajola.peso = 3.20f;
		
		System.out.println("O nome do gato é " + frajola.nome);
		System.out.println("A idade do gato " + frajola.nome + " é " + frajola.idade);
		System.out.println("O peso do gato " + frajola.nome + " é " + frajola.peso + " kilos");
		System.out.println();
		
		// inserindo por meio de metodos
		// Tom
		Gato tom = new Gato();
		tom.inserirNome("Tom");
		tom.inserirIdade(20);
		tom.inserirPeso(5.25f);
		
		System.out.println("O nome do gato é " + tom.obterNome());
		System.out.println("A idade do gato " + tom.obterNome() + " é " + tom.obterIdade());
		System.out.println("O peso do gato " + tom.obterNome() + " é " + tom.obterPeso() + " kilos");
		System.out.println();
		
		//construtor que recebe atributos
		Gato garfield = new Gato("Garfield", 25, 10.5f);
		
		System.out.println("O nome do gato é " + garfield.obterNome());
		System.out.println("A idade do gato " + garfield.obterNome() + " é " + garfield.obterIdade());
		System.out.println("O peso do gato " + garfield.obterNome() + " é " + garfield.obterPeso() + " kilos");
		
		String[] bichanos = {"garfield", "tom", "felix"};
		for(int i = 0; i <bichanos.length; i++){
			System.out.println(bichanos[i]);
		}*/
		
		//Gato[] bichano = new Gato[3];
		//Gato p = new Gato(), k = new Gato();
		
		Gato[] bichano = new Gato[3];
		bichano[0] = new Gato();
		bichano[1] = new Gato();
		bichano[2] = new Gato();
		
		bichano[0].inserirNome("Garfield");
		bichano[1].inserirNome("Felix");
		bichano[2].inserirNome("Tom");
		
		for(int i = 0; i < bichano.length; i++){
			System.out.println(bichano[i].nome);
		}
	}

}
