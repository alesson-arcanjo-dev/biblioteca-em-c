#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_STRING 100

struct Livro {
    char nome[MAX_STRING];
    char autor[MAX_STRING];
    char editora[MAX_STRING];
    int edicao;
};

/* Função para limpar o buffer do teclado */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do {
        printf("===================================\n");
        printf("        BIBLIOTECA - MENU           \n");
        printf("===================================\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("0. Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {

            case 1:
                if (totalLivros < MAX_LIVROS) {

                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, MAX_STRING, stdin);

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, MAX_STRING, stdin);

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, MAX_STRING, stdin);

                    /* Remove o \n do fgets */
                    biblioteca[totalLivros].nome[
                        strcspn(biblioteca[totalLivros].nome, "\n")
                    ] = '\0';

                    biblioteca[totalLivros].autor[
                        strcspn(biblioteca[totalLivros].autor, "\n")
                    ] = '\0';

                    biblioteca[totalLivros].editora[
                        strcspn(biblioteca[totalLivros].editora, "\n")
                    ] = '\0';

                    printf("Digite a edicao do livro: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++;
                    printf("\nLivro cadastrado com sucesso!\n");

                } else {
                    printf("\nCapacidade maxima de livros atingida.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 2:
                if (totalLivros > 0) {
                    printf("\n======= LISTA DE LIVROS =======\n");

                    for (int i = 0; i < totalLivros; i++) {
                        printf("-----------------------------------\n");
                        printf("Livro %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }

                    printf("-----------------------------------\n");
                } else {
                    printf("\nNenhum livro cadastrado.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0:
                printf("\nSaindo do programa. Ate mais!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                printf("Pressione Enter para continuar...");
                getchar();
                break;
        }

    } while (opcao != 0);

    return 0;
}
