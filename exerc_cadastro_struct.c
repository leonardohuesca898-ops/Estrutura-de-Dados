#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do tipo "cadastro"

typedef struct 

{
  

    int idade;
    char nome[50];
    char endereco[100];

}cadastro;


// Protótipos

void coleta_nome(int n, cadastro pessoa[n]);
void coleta_endereco(int n, cadastro pessoa[n]);
void coleta_idade(int n, cadastro pessoa[n]);
void imprime_dados(int n, cadastro pessoa[n]);
void remove_newline(char *str);

// Função principal


int main(int argc, char* argv[])

{
    // Declaração das variáveis

    int n;
    printf("Digite o número de pessoas a serem cadastradas: \n");
    scanf("%d", &n);
    getchar(); // Limpa o buffer após o scanf 
    cadastro pessoa[n];

    // Chamada das funções

    
    coleta_nome(n, pessoa);
    coleta_endereco(n, pessoa);
    coleta_idade(n, pessoa);

        // O tamanho dos alinhamentos abaixo são definidos de acordo com
        // o tamanho ou numero de caracteres das strings

    printf("%-20.20s %-30.25s %-6s\n", "Nome", "Endereço", "Idade"); // Formatação em tabelas
    printf("--------------------------------------------------------------\n");
    imprime_dados(n, pessoa);
    
    return 0;

}



// Execução das funções

    // Função remove_newline: responsável por trocar o caracter oculto /n (quebra de linha)
    // Pelo caractere /0, responsável por deletar ele e o espaço de memória
    // ocupado por ele


void remove_newline(char *str) //(char *str) → parâmetro da função.

//Significa que ela recebe um ponteiro para char, 
//ou seja, uma string em C (vetor de caracteres terminado por \0).
//Exemplo: 
//se você passar "João\n" para a função, o str vai apontar para essa string.

    {

        // Usa a função str para procurar nas string o primeiro 
        // /n e substitui-lo por /0, deletando-o

    str[strcspn(str, "\n")] = '\0'; 

        //strcspn é uma função da biblioteca <string.h>.

        //Significa "string complement span".

        //O que ela faz: percorre str até encontrar 

        //o primeiro caractere que esteja no segundo argumento (no caso, o "\n").

    }

void coleta_nome(int n, cadastro pessoa[n])

{
    for (int i = 0; i < n; i++) 
    
    {
        printf("Digite o nome da %d ª pessoa: \n", i + 1);
        fgets(pessoa[i].nome, sizeof(pessoa[i].nome), stdin);
        remove_newline(pessoa[i].nome);
    
    }

    return;

}

void coleta_endereco(int n, cadastro pessoa[n])

{
    for (int i = 0; i < n; i++) 
    
    {
        printf("Digite o endereço da %d ª pessoa: \n", i + 1);
        fgets(pessoa[i].endereco, sizeof(pessoa[i].endereco), stdin);
        remove_newline(pessoa[i].endereco);
    
    }

    return;

}

void coleta_idade(int n, cadastro pessoa[n]) 

{
    for (int i = 0; i < n; i ++) 
    
    {

    printf("Digite a idade da %dª pessoa: \n", i + 1);
    scanf("%d", &pessoa[i].idade);
    getchar();

    }


    return;
}

void imprime_dados(int n, cadastro pessoa[n])

{
    for(int i = 0; i < n; i++ ) 
    
    {
        printf("%-20.20s %-30.25s %-6d anos\n", pessoa[i].nome, pessoa[i].endereco, pessoa[i].idade);
    }
