#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "economia.h"

//cores
#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"

// Definição de constantes
#define MAX_ANOS 60
#define SALDO_INICIAL 0
#define NOME_ARQUIVO "recordes.txt"

int valor_economia = 3;

// Estrutura para armazenar dados do jogador
typedef struct {
    char nome[50];
    double saldo;
    double investimento;
    double taxa_investimento;
    int experiencia;
    int anos;
    int trabalho_atual;
} Jogador;

void economia (int valor_sorteado){
    int valor_economia = valor_sorteado;

    switch (valor_sorteado)
    {
    case 1:
        printf(RED"$\n"RESET);
        break;

    case 2:
        printf(RED"$$\n"RESET);
        break;

    case 3:
        printf(YELLOW"$$$\n"RESET);
        break;

    case 4:
        printf(GREEN"$$$$\n"RESET);
        break;

    case 5:
        printf(GREEN"$$$$$\n"RESET);
        break;
    
    default:
        break;
    }

}

void salvar_recorde(const Jogador *jogador) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");
    if (arquivo) {
        fprintf(arquivo, "%s: %.2lf\n", jogador->nome, jogador->saldo);
        fclose(arquivo);
    } else {
        printf("Erro ao salvar o recorde!\n");
    }
}

void mostrar_recordes() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    char linha[100];

    printf("\n=== Recordes ===\n");
    if (arquivo) {
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("%s", linha);
        }
        fclose(arquivo);
    } else {
        printf("Nenhum recorde encontrado.\n");
    }
    printf("===============\n");
}

void atualizar_saldo(Jogador *jogador) {
    // Salário anual do trabalho
    double salario;
    if (jogador->trabalho_atual == 1) {
        salario = 10000;
    } else if (jogador->trabalho_atual == 2) {
        salario = 30000;
    } else {
        salario = 60000;
    }
    jogador->saldo += salario;

    // Atualiza rendimento do investimento
    if (jogador->investimento > 0) {
        jogador->investimento *= (1 + jogador->taxa_investimento);
    }
}

void opcoes_trabalho(Jogador *jogador) {
    printf(RED"\n--- Trabalhos ---\n"RESET);
    if (jogador->trabalho_atual == 1) {
        printf("Você é Estagiário (R$ 10.000 por ano).\n");
    } else if (jogador->trabalho_atual == 2) {
        printf("Você é Analista (R$ 30.000 por ano).\n");
    } else {
        printf("Você é Gerente (R$ 60.000 por ano).\n");
    }
    jogador->experiencia++;
    if (jogador->experiencia >= 5 && jogador->trabalho_atual < 3) {
        jogador->trabalho_atual++;
        jogador->experiencia = 0;
        printf("Parabéns! Você foi promovido.\n");
    }
}

void opcoes_investimento(Jogador *jogador) {
    int opcao;
    double valor_investido;

    printf(RED"\n--- Investimentos ---\n"RESET);
    printf("1. Poupança (0.5%% ao ano)\n");
    printf("2. CDB (5%% ao ano)\n");
    printf("3. Tesouro Direto (10%% ao ano)\n");
    printf("4. Retirar investimento\n");
    printf("5. Voltar ao menu\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o valor a investir: ");
            scanf("%lf", &valor_investido);
            if (valor_investido <= jogador->saldo) {
                jogador->saldo -= valor_investido;
                jogador->investimento += valor_investido;
                jogador->taxa_investimento = 0.005;
            } else {
                printf("Saldo insuficiente!\n");
            }
            break;

        case 2:
            printf("Digite o valor a investir: ");
            scanf("%lf", &valor_investido);
            if (valor_investido <= jogador->saldo) {
                jogador->saldo -= valor_investido;
                jogador->investimento += valor_investido;
                jogador->taxa_investimento = 0.05;
            } else {
                printf("Saldo insuficiente!\n");
            }
            break;

        case 3:
            printf("Digite o valor a investir: ");
            scanf("%lf", &valor_investido);
            if (valor_investido <= jogador->saldo) {
                jogador->saldo -= valor_investido;
                jogador->investimento += valor_investido;
                jogador->taxa_investimento = 0.10;
            } else {
                printf("Saldo insuficiente!\n");
            }
            break;

        case 4:
            printf("Retirando todo o investimento (%.2lf)...\n", jogador->investimento);
            jogador->saldo += jogador->investimento;
            jogador->investimento = 0.0;
            jogador->taxa_investimento = 0.0;
            break;

        case 5:
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void menu_bar(Jogador *jogador){
    printf("\033[1;32m\nAno %d\033[0m\n", jogador->anos + 1);
        printf(MAGENTA "Situação economica: " RESET);
        economia(proximo_numero(valor_economia)); 

}

// Função principal
int main() {
    Jogador jogador;
    int opcao;

    // Inicialização  
        printf("Digite seu nome: ");
        scanf("%49s", jogador.nome);
        jogador.saldo = SALDO_INICIAL;
        jogador.investimento = 0.0;
        jogador.taxa_investimento = 0.0;
        jogador.experiencia = 0;
        jogador.anos = 0;
        jogador.trabalho_atual = 1;

        menu_bar(&jogador);   

    while (jogador.anos < MAX_ANOS) {
              
        printf("\nSaldo atual: %.2lf\n", jogador.saldo);
        if (jogador.investimento != 0) {
            printf("Investimento atual: %.2lf\n", jogador.investimento);
        }
        printf("1. Trabalhos\n");
        printf("2. Investimentos\n");
        printf("3. Avançar ano\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                opcoes_trabalho(&jogador);
                break;

            case 2:
                opcoes_investimento(&jogador);
                break;

            case 3:
                atualizar_saldo(&jogador);
                jogador.anos++;
                menu_bar(&jogador);
                
                break;

            default:
                printf("Opção inválida!\n");
        } //if

    }

    printf("\nFim do jogo!\n");
    printf("Saldo final: %.2lf\n", jogador.saldo);
    salvar_recorde(&jogador);
    mostrar_recordes();

    return 0;
}
