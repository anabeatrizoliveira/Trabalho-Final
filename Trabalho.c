#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//A nota final eu estava considerando a soma de todas as notas, contudo, no item 9 do menu que estava pedindo para ser criado
//pediu para considerar a aprovação a partir da média das três notas, sendo necessário ser maior ou igual a 6.0 para ser aprovado
//então considerei a nota final como a média.

//Não fiz o protótipo da função e coloquei ela no final do código porque deu errado por algum motivo e razão que ainda não sei explicar e assim deu certo
//então fiquei no simples.

//A busca sequencial foi realizada a partir da matrícula dos alunos conseguindo por ela achar todos os dados.

float media (float n1, float n2, float n3){
    float resultado;
    resultado=(n1+n2+n3)/3;
    return (resultado);
    }

typedef struct {
    int matricula;
    char nome[15];
    float nota01;
    float nota02;
    float nota03;
    float media;
} cadastroaluno;

int busca(int n, cadastroaluno v[]){
	int i;
	for(i=0; i<1; i++){
		if(n==v[i]){
			return (i);
		}
	}
	return(-1);
}

int main()
{
setlocale(LC_ALL, "Portuguese");
cadastroaluno alunos[5];
int i=0;
for(i=0; i<1; i++){
    printf("Digite o número de matrícula: ");
    scanf("%i", &alunos[i].matricula);
    setbuf(stdin, NULL);
    printf("Digite o nome do aluno: ");
    fgets(alunos[i].nome, 15, stdin);
    setbuf(stdin, NULL);
    printf("Digite qual o valor tirado na primeira nota: ");
    scanf( "%f" , &alunos[i].nota01);
    printf( "Digite qual o valor tirado na segunda nota: ");
    scanf( "%f" , &alunos[i].nota02);
    printf("Digite qual o valor tirado na terceira nota: ");
    scanf( "%f" , &alunos[i].nota03);
    alunos[i].media=media(alunos[i].nota01, alunos[i].nota02, alunos[i].nota03);
    printf("A média é igual a %.2f . \n", alunos[i].media);
}

int opcao=1;
while(opcao!=0){
printf("Digite o código que faça a ação que deseja executar:\n1- Imprimir todos os Elementos do Arranjo. \n2- Imprimir apenas os nomes dos alunos. \n3- Imprimir os nomes dos alunos e suas respectivas notas finais. \n4- Buscar os dados de um aluno usando a busca sequencial. \n5- Imprimir os alunos ordenados de acordo com sua matrícula. \n6- Editar as notas de um aluno, para isso é necessário que se busque os dados do aluno. \n7- Imprimir a matrícula, o nome, e a nota final do aluno que obteve a maior nota de todas. \n8- Imprimir a matrícula, nome e nota final do aluno que obteve a menor nota de todas. \n9-Imprimir quantos alunos foram reprovados, imprima ainda a média geral. Os alunos aprovados serão aqueles que obtiverem média maior ou igual a 6.0. \n0- Sair do programa\n");
scanf("%i", &opcao);

if(opcao==0){
    exit(0);
    return(0);
}

if(opcao==1){
        for(i=0; i<1; i++){
        printf("Matrícula: %i. Nome: %s. Nota01: %.2f. Nota02: %.2f. Nota03: %.2f. Média: %.2f. \n\n", alunos[i].matricula, alunos[i].nome, alunos[i].nota01, alunos[i].nota02, alunos[i].nota03, alunos[i].media);
    }
}

if(opcao==2){
        for(i=0; i<1; i++){
        printf("Nome: %s.\n\n", alunos[i].nome);
    }
}

if(opcao==3){
        for(i=0; i<1; i++){
        printf("Nome: %s. Nota final: %.2f. \n\n", alunos[i].nome, alunos[i].media);
    }
}

if(opcao==4){
	int matricula, valor;
	i=0;
	printf("%i", valor);
	printf("Digite a matrícula do aluno que deseja acessar os dados: ");
	scanf("%i", &matricula);
	valor=busca(matricula, alunos[i].matricula);
	printf("%i", valor);
}

if(opcao==5){
	
}

if(opcao==6){
	
}

if(opcao==7){
	float maior=0;
	int marcador;
	for(i=0; i<1; i++){
        if(alunos[i].media>maior){
        	maior=alunos[i].media;
        	marcador=i;
		}
    }
    printf("Matrícula: %i. Nome: %s. Média: %.2f foi o aluno que obteve a maior nota. \n\n", alunos[marcador].matricula, alunos[marcador].nome, alunos[marcador].media);
}

if(opcao==8){
	float menor=alunos[0].media;
	int marcador;
	for(i=0; i<1; i++){
		if(alunos[i].media<menor){
        	menor=alunos[i].media;
        	marcador=i;
		}
    }
    printf("Matrícula: %i. Nome: %s. Média: %.2f foi o aluno que obteve a menor nota. \n\n", alunos[marcador].matricula, alunos[marcador].nome, alunos[marcador].media);
}

if(opcao==9){
	int contaprovado=0, contreprovado=0;
	float mediageral=0;
	for(i=0; i<1; i++){
		if(alunos[i].media>=6.0){
			contaprovado++;
		}
		else if(alunos[i].media<6.0){
			contreprovado++;
		}
		mediageral=mediageral+alunos[i].media;
		}
	mediageral=mediageral/1;
	printf("Foram aprovador %i alunos.\nForam reprovados %i alunos. \nA média geral de todas as notas é: %.2f.\n\n", contaprovado, contreprovado, mediageral);	
    }
}
return 0;

}


