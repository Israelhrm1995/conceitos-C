#include <stdio.h>
#include <string.h>

#define MAX_FILMES 100 // Define um numero maximo para a quantidade de filmes

int main() {
    // --- Forca a saida do console para ser exibida imediatamente ---
    setvbuf(stdout, NULL, _IONBF, 0);

    // --- Declaracao de Variaveis e Vetores ---
    int num_filmes;
    int vendas[MAX_FILMES];
    char nomes_filmes[MAX_FILMES][50]; // Matriz de caracteres para armazenar nomes
    
    int i;
    int total_vendas = 0;
    float media_vendas;
    int maior_venda = -1, menor_venda = -1;
    char filme_mais_assistido[50], filme_menos_assistido[50];

    // --- Boas-Vindas e Interacao Inicial ---
    printf("=========================================\n");
    printf("       CineTrack - Analise de Vendas\n");
    printf("=========================================\n\n");
    
    printf("Quantos filmes voce deseja analisar neste mes? ");
    scanf("%d", &num_filmes);
    
    // Validacao para nao exceder o numero maximo de filmes
    if (num_filmes > MAX_FILMES || num_filmes <= 0) {
        printf("\nO numero de filmes deve ser entre 1 e %d.\n", MAX_FILMES);
        return 1; // Encerra o programa com erro
    }

    // --- Limpa o buffer de entrada ---
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // --- Loop para Coleta de Dados ---
    for (i = 0; i < num_filmes; i++) {
        printf("\n--- Informacoes do Filme %d ---\n", i + 1);
        printf("Digite o nome do filme: ");
        fgets(nomes_filmes[i], 50, stdin);
        nomes_filmes[i][strcspn(nomes_filmes[i], "\n")] = 0; // Remove o '\n' lido pelo fgets
        
        printf("Digite o numero de ingressos vendidos: ");
        scanf("%d", &vendas[i]);
        
        // Acumula o total de vendas para o calculo da media
        total_vendas += vendas[i];

        // Inicializa o maior e menor valor na primeira iteracao
        if (i == 0) {
            maior_venda = vendas[i];
            menor_venda = vendas[i];
            strcpy(filme_mais_assistido, nomes_filmes[i]);
            strcpy(filme_menos_assistido, nomes_filmes[i]);
        }
        
        // Verifica o filme mais assistido
        if (vendas[i] > maior_venda) {
            maior_venda = vendas[i];
            strcpy(filme_mais_assistido, nomes_filmes[i]);
        }
        
        // Verifica o filme menos assistido
        if (vendas[i] < menor_venda) {
            menor_venda = vendas[i];
            strcpy(filme_menos_assistido, nomes_filmes[i]);
        }
        
        // Limpa o buffer para o proximo loop
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    // --- Calculo da Media de Vendas ---
    media_vendas = (float)total_vendas / num_filmes;

    // --- Exibicao dos Resultados ---
    printf("\n\n=========================================\n");
    printf("           Relatorio de Vendas\n");
    printf("=========================================\n");
    printf("Total de ingressos vendidos: %d\n", total_vendas);
    printf("Media de ingressos por filme: %.2f\n\n", media_vendas);

    printf("--- Vendas por Filme ---\n");
    for (i = 0; i < num_filmes; i++) {
        printf("Filme: %s - Ingressos: %d\n", nomes_filmes[i], vendas[i]);
    }

    printf("\n--- Destaques do Mes ---\n");
    printf("Filme Mais Assistido: %s (%d ingressos)\n", filme_mais_assistido, maior_venda);
    printf("Filme Menos Assistido: %s (%d ingressos)\n", filme_menos_assistido, menor_venda);

    return 0;
}