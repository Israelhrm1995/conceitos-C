#include <stdio.h>

int main() {
    // --- Variaveis para o calculo de IMC ---
    float peso, altura, imc;
    int continuar = 1; // Variavel de controle do loop principal
    int numero_de_usuarios = 0;
    float soma_dos_imcs = 0.0;
    
    // --- Mensagem de Boas-Vindas ---
    printf("=========================================\n");
    printf("        Calculadora de IMC - Versao 1.0\n");
    printf("=========================================\n\n");
    printf("Este programa calcula o Indice de Massa Corporal (IMC)\n");
    printf("para uma ou mais pessoas.\n");
    
    // --- Loop principal para permitir multiplos calculos ---
    while (continuar == 1) {
        printf("\n-----------------------------------------\n");
        printf("Digite seu peso em kg (ex: 70.5): ");
        scanf("%f", &peso);
        
        printf("Digite sua altura em metros (ex: 1.75): ");
        scanf("%f", &altura);
        
        // --- Validacao simples da entrada para evitar erros ---
        if (peso <= 0 || altura <= 0) {
            printf("Valores invalidos. Por favor, digite valores positivos.\n");
            continue; // Pula para a proxima iteracao do loop
        }
        
        // --- Calculo do IMC ---
        imc = peso / (altura * altura);
        
        // --- Acumulacao para o calculo da media ---
        soma_dos_imcs += imc;
        numero_de_usuarios++;
        
        // --- Classificacao do IMC com Estrutura de Decisao (if/else if/else) ---
        printf("\nSeu IMC e: %.2f\n", imc);
        
        if (imc < 18.5) {
            printf("Classificacao: Abaixo do peso\n");
        } else if (imc >= 18.5 && imc <= 24.9) {
            printf("Classificacao: Peso ideal (parabens!)\n");
        } else if (imc >= 25.0 && imc <= 29.9) {
            printf("Classificacao: Levemente acima do peso\n");
        } else if (imc >= 30.0 && imc <= 34.9) {
            printf("Classificacao: Obesidade grau I\n");
        } else if (imc >= 35.0 && imc <= 39.9) {
            printf("Classificacao: Obesidade grau II (severa)\n");
        } else {
            printf("Classificacao: Obesidade grau III (morbida)\n");
        }

        // --- Pergunta ao usuario se deseja continuar ---
        printf("\n-----------------------------------------\n");
        printf("Deseja calcular o IMC para outra pessoa?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &continuar);

        // --- Validacao para a opcao de continuar ---
        if (continuar != 1 && continuar != 2) {
            printf("\nOpcao invalida. O programa sera encerrado.\n");
            continuar = 0; // Forca a saida do loop
        }
    }
    
    // --- Exibicao do Bonus: Media dos IMCs ---
    printf("\n=========================================\n");
    printf("           Relatorio Final\n");
    printf("=========================================\n");
    
    if (numero_de_usuarios > 0) {
        printf("Numero de usuarios analisados: %d\n", numero_de_usuarios);
        printf("Media geral dos IMCs: %.2f\n", soma_dos_imcs / numero_de_usuarios);
    } else {
        printf("Nenhum calculo foi realizado.\n");
    }

    // --- Mensagem de Encerramento ---
    printf("Programa encerrado. Ate a proxima!\n");

    return 0;
}