#include <stdio.h>

// Funcao para imprimir os elementos do vetor
void imprimirVetor(float vetor[], int tamanho, const char* mensagem) {
    printf("%s", mensagem);
    for (int i = 0; i < tamanho; i++) {
        printf("%.2f ", vetor[i]);
    }
    printf("\n");
}

// Funcao para ordenar o vetor em ordem crescente usando Bubble Sort
void bubbleSortCrescente(float vetor[], int tamanho) {
    int i, j;
    // Laço externo para controlar o numero de passagens
    for (i = 0; i < tamanho - 1; i++) {
        // Laço interno para percorrer o vetor e fazer as comparacoes
        for (j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento atual for maior que o proximo, troca
            if (vetor[j] > vetor[j + 1]) {
                float temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Funcao para ordenar o vetor em ordem decrescente usando Bubble Sort
void bubbleSortDecrescente(float vetor[], int tamanho) {
    int i, j;
    // Laço externo para controlar o numero de passagens
    for (i = 0; i < tamanho - 1; i++) {
        // Laço interno para percorrer o vetor e fazer as comparacoes
        for (j = 0; j < tamanho - i - 1; j++) {
            // Se o elemento atual for menor que o proximo, troca
            if (vetor[j] < vetor[j + 1]) {
                float temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    // --- Variavel e Vetor para armazenar os precos ---
    int tamanho = 10;
    float precos[tamanho];
    
    // --- Boas-Vindas e Coleta de Dados ---
    printf("=========================================\n");
    printf("     Organizador de Precos de Produtos\n");
    printf("=========================================\n\n");
    printf("Por favor, digite o preco de 10 produtos:\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("Produto %d: R$ ", i + 1);
        scanf("%f", &precos[i]);
    }

    // --- Exibir o vetor original ---
    printf("\n-----------------------------------------\n");
    imprimirVetor(precos, tamanho, "Precos Originais: ");
    
    // --- Ordenacao em Ordem Crescente ---
    // Cria uma copia do vetor para nao modificar o original
    float precos_crescente[tamanho];
    for(int i = 0; i < tamanho; i++) {
        precos_crescente[i] = precos[i];
    }
    
    bubbleSortCrescente(precos_crescente, tamanho);
    
    // --- Exibir o vetor ordenado de forma crescente ---
    imprimirVetor(precos_crescente, tamanho, "Precos em Ordem Crescente: ");

    // --- Ordenacao em Ordem Decrescente ---
    // Cria outra copia para a ordenacao decrescente
    float precos_decrescente[tamanho];
    for(int i = 0; i < tamanho; i++) {
        precos_decrescente[i] = precos[i];
    }

    bubbleSortDecrescente(precos_decrescente, tamanho);

    // --- Exibir o vetor ordenado de forma decrescente ---
    imprimirVetor(precos_decrescente, tamanho, "Precos em Ordem Decrescente: ");
    printf("-----------------------------------------\n");
    
    printf("\nPrograma finalizado. Ate a proxima!\n");

    return 0;
}