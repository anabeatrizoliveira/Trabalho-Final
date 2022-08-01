#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//A nota final eu estava considerando a soma de todas as notas, contudo, no item 9 do menu que estava pedindo para ser criado
//pediu para considerar a aprovação a partir da média das três notas, sendo necessário ser maior ou igual a 6.0 para ser aprovado
//então considerei a nota final como a média.

//A busca sequencial foi realizada a partir da matrícula dos alunos conseguindo por ela achar todos os dados.

typedef struct aluno{
    int matricula;
    char nome[15];
    float nota01;
    float nota02;
    float nota03;
    float media;
} cadastroaluno;

float media (float n1, float n2, float n3){
    float resultado;
    resultado=(n1+n2+n3)/3;
    return (resultado);
    //Função para calcular a média
    }

int buscamatricula(int matricula, cadastroaluno aluno[], int tamanhoarray){
	for(int i=0; i<tamanhoarray; i++){
		if(matricula==aluno[i].matricula){
			return i;
		}
	}
	return -1;
	//Função de busca sequencial da matrícula;
	//Retorna -1 caso a condição não seja verdadeira, logo, um número de matrícula inexistente no arquivo;
}

void bubblesort(cadastroaluno alunos[], int tamanhoarray){
	for(int i=0; i<tamanhoarray; i++){
		for(int j=0; j<tamanhoarray; j++){
			if(alunos[i].matricula<alunos[j].matricula){
				cadastroaluno aux = alunos[i];
				alunos[i]=alunos[j];
				alunos[j]=aux;
			}
		}
	}
	//Função ordenadora em ordem crescente;
}

int qtdaluno(FILE *arq){
    int numerodelinhas = 0;
    char c;
    arq = fopen("alunos.txt", "rt");
	while ((c = fgetc(arq)) != EOF){
        if(c == '\n')
            numerodelinhas++;
    }
    fclose(arq);
    return (numerodelinhas);
    //Função para contar a quantidade de linhas;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	FILE *arq;
    int contador = 0;
    int quantidadealuno = (qtdaluno(arq)+1);
	cadastroaluno *alunos = (cadastroaluno*) malloc (quantidadealuno* sizeof(cadastroaluno));
	arq = fopen ("alunos.txt", "rt");

  
    while (contador < quantidadealuno){
        char nota01temp[4];
        char nota02temp[4];
        char nota03temp[4];
		//como o programa está em português, estas linhas são necessárias para não dar bug com número float com ponto ao invés de vírgula;
		fscanf(arq, "%d %s %s %s %s", &alunos[contador].matricula, alunos[contador].nome, nota01temp, nota02temp, nota03temp);
        alunos[contador].nota01 = atof(nota01temp);
        alunos[contador].nota02 = atof(nota02temp);
        alunos[contador].nota03 = atof(nota03temp);
        alunos[contador].media=media(alunos[contador].nota01, alunos[contador].nota02, alunos[contador].nota03);		
		// o próximo printf era apenas para teste;
		//printf("\n%d %s %.2f %.2f %.2f %.2f \n", alunos[contador].matricula, alunos[contador].nome, alunos[contador].nota01, alunos[contador].nota02, alunos[contador].nota03, alunos[contador].media);
        contador++;
	}
	
    fclose(arq);


	int opcao=1;
	while(opcao!=0){
	
	printf("Digite o código que faça a ação que deseja executar:\n1- Imprimir todos os Elementos do Arranjo. \n2- Imprimir apenas os nomes dos alunos. \n3- Imprimir os nomes dos alunos e suas respectivas notas finais. \n4- Buscar os dados de um aluno usando a busca sequencial. \n5- Imprimir os alunos ordenados de acordo com sua matrícula. \n6- Editar as notas de um aluno, para isso é necessário que se busque os dados do aluno. \n7- Imprimir a matrícula, o nome, e a nota final do aluno que obteve a maior nota de todas. \n8- Imprimir a matrícula, nome e nota final do aluno que obteve a menor nota de todas. \n9-Imprimir quantos alunos foram reprovados, imprima ainda a média geral. Os alunos aprovados serão aqueles que obtiverem média maior ou igual a 6.0. \n0- Sair do programa\n");
	scanf("%i", &opcao);
	
		if(opcao==0){
		FILE *arqnovo = fopen ("alunosorganizados.txt", "wt");
		bubblesort(alunos, quantidadealuno);
			for(int j=0; j<quantidadealuno; j++){
            fprintf(arqnovo, "%d %s %.2f %.2f %.2f %.2f %d \n", alunos[j].matricula, alunos[j].nome, alunos[j].nota01, alunos[j].nota02, alunos[j].nota03, alunos[j].media);
			}
	    exit(0);
	    return(0);
	    //A função para salvar um novo arquivo está para quando o usuário digitar 0, porque além de salvar ordenado o arquivo, ela salva as alterações feitas quando o menu 6 for selecionado;
		}
		
		else if(opcao==1){
        	for(int j=0; j<quantidadealuno; j++){
        	printf("Matrícula: %i. Nome: %s. Nota01: %.2f. Nota02: %.2f. Nota03: %.2f. Média: %.2f. \n\n", alunos[j].matricula, alunos[j].nome, alunos[j].nota01, alunos[j].nota02, alunos[j].nota03, alunos[j].media);
    		}
		}
	
		else if(opcao==2){
	        for(int j=0; j<quantidadealuno; j++){
	        printf("Nome: %s.\n\n", alunos[j].nome);
	    	}
		}
	
		else if(opcao==3){
	        for(int j=0; j<quantidadealuno; j++){
	        printf("Nome: %s. Nota final: %.2f. \n\n", alunos[j].nome, alunos[j].media);
	   	 	}
		}	
		
		else if(opcao==4){
		
			int matricula, valor;
			
			printf("Digite a matrícula do aluno que deseja acessar os dados: ");
			scanf("%i", &matricula);
			valor=buscamatricula(matricula, alunos, quantidadealuno);
				if(valor==-1){
					printf("Digite um número de matrícula válido.");
				}
				else{
					printf("Matrícula: %i. Nome: %s. Nota01: %.2f. Nota02: %.2f. Nota03: %.2f. Média: %.2f. \n\n", alunos[valor].matricula, alunos[valor].nome, alunos[valor].nota01, alunos[valor].nota02, alunos[valor].nota03, alunos[valor].media);
				}
		}
		
		else if(opcao==5){
		bubblesort(alunos, quantidadealuno);
			for(int j=0; j<quantidadealuno; j++){
			printf("Matrícula: %i. Nome: %s. Nota01: %.2f. Nota02: %.2f. Nota03: %.2f. Média: %.2f. \n\n", alunos[j].matricula, alunos[j].nome, alunos[j].nota01, alunos[j].nota02, alunos[j].nota03, alunos[j].media);
			}
	}
	
		else if(opcao==6){
			int matricula, valor, dado;
			
			printf("Digite a matrícula do aluno que deseja editar os dados: ");
			scanf("%i", &matricula);
			valor=buscamatricula(matricula, alunos, quantidadealuno);
				if(valor==-1){
					printf("Digite um número de matrícula válido.");
				}
				else{
					//O novo menu é para o usuário selecionar qual dado ele deseja editar, porém, criei sem repetição, caso o usuário deseje editar outro dado do aluno, deve selecionar a opção no menu principal para isso e repetir o processo;
					printf("Digite o códio que corresponde ao dado que você deseja editar:\n1- Número de matrícula.\n2- Nome do aluno.\n3- Nota 1.\n4- Nota 2.\n5- Nota 3.\n\n");
					scanf("%i", &dado);
						if(dado==1){
							printf("Digite o novo valor: ");
							scanf("%i", &alunos[valor].matricula);
						}
						
						else if(dado==2){
							printf("Digite o novo valor: ");
							setbuf(stdin, NULL);
							fgets (alunos[valor].nome, 15, stdin);
						}
						
						else if(dado==3){
							printf("Digite o novo valor: ");
							scanf("%f", &alunos[valor].nota01);
						}	
						else if(dado==4){
							printf("Digite o novo valor: ");
							scanf("%f", &alunos[valor].nota02);
						}	
						else if(dado==5){
							printf("Digite o novo valor: ");
							scanf("%f", &alunos[valor].nota03);
						}		
				}
		}
			
		else if(opcao==7){
		float maior=0;
		int marcador;
			for(int j=0; j<quantidadealuno; j++){
        		if(alunos[j].media>maior){
	        	maior=alunos[j].media;
	        	marcador=j;
			}	
   		 }
    	printf("Matrícula: %i. Nome: %s. Média: %.2f foi o aluno que obteve a maior nota. \n\n", alunos[marcador].matricula, alunos[marcador].nome, alunos[marcador].media);
	}
	
		else if(opcao==8){
		float menor=alunos[0].media;
		int marcador;
			for(int j=0; j<quantidadealuno; j++){
			if(alunos[j].media<menor){
        		menor=alunos[j].media;
        		marcador=j;
			}
	    }
    printf("Matrícula: %i. Nome: %s. Média: %.2f foi o aluno que obteve a menor nota. \n\n", alunos[marcador].matricula, alunos[marcador].nome, alunos[marcador].media);
	}
		
		if(opcao==9){
		int contaprovado=0, contreprovado=0;
		float mediageral=0;
			for(int j=0; j<quantidadealuno; j++){
			if(alunos[j].media>=6.0){
			contaprovado++;
			}
			else if(alunos[j].media<6.0){
			contreprovado++;
			}
			mediageral=mediageral+alunos[j].media;
			}
			mediageral=mediageral/quantidadealuno;
			printf("Foram aprovador %i alunos.\nForam reprovados %i alunos. \nA média geral de todas as notas é: %.2f.\n\n", contaprovado, contreprovado, mediageral);		
    		}
	
	}
	
	//Limpando a memória alocada dinâmicamente. 
 	free(alunos);
	return 0;
	}
