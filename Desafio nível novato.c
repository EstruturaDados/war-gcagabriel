#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constantes para o tamanho máximo de territórios, nomes e cores
#define MAX_TERRITORIOS 5
#define MAX_NOME 30
#define MAX_COR 10

// estrutura Territorio
typedef struct {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
} Territorio;

// vetor territorios
Territorio territorios[MAX_TERRITORIOS];
int num_territorios = 0;

//  cadastrar um território
void cadastrar_territorio() {
    // Verificar se o número de territórios cadastrados é menor que o máximo permitido
    if (num_territorios < MAX_TERRITORIOS) {
        printf("Digite o nome do territorio: ");
        fgets(territorios[num_territorios].nome, MAX_NOME, stdin);
        territorios[num_territorios].nome[strcspn(territorios[num_territorios].nome, "\n")] = 0;

        printf("Digite a cor do territorio: ");
        fgets(territorios[num_territorios].cor, MAX_COR, stdin);
        territorios[num_territorios].cor[strcspn(territorios[num_territorios].cor, "\n")] = 0;

        printf("Digite o numero de tropas do territorio: ");
        scanf("%d", &territorios[num_territorios].tropas);
        getchar();

        num_territorios++;
        printf("Territorio cadastrado com sucesso!\n");
    } else {
        printf("Limite de territorios atingido!\n");
    }
}

// Verificar territórios cadastrados
void imprimir_territorios() {
    if (num_territorios == 0) {
        printf("Nenhum territorio cadastrado!\n");
    } else {
        for (int i = 0; i < num_territorios; i++) {
            printf("Territorio %d:\n", i + 1);
            printf("Nome: %s\n", territorios[i].nome);
            printf("Cor: %s\n", territorios[i].cor);
            printf("Tropas: %d\n\n", territorios[i].tropas);
        }
    }
}

int main() {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Cadastrar territorio\n");
        printf("2. Listar territorios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrar_territorio();
                break;
            case 2:
                imprimir_territorios();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}
