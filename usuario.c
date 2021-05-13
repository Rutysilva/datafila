#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int idade, cpf, celular;
    char nome[51], endereco[51];
    struct fila *prox;
} fila;

fila * criar_fila_espera() {
    return NULL;
}

int main(void) {
    fila *filaEspera;
    int escolha = 0;

    filaEspera = criar_fila_espera();

    while (escolha != 4) {
        printf("\n\n1 - Realizar agendamento\n");
        printf("2 - Mostrar posição na fila");
        printf("3 - Exibir informações para contato\n");
        printf("4 - Finalizar programa\n");

        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 1) {
            
        }
        if (escolha == 2) {

        }
        if (escolha == 3) {
            printf("\n\nINFORMAÇÕES PARA CONTATO:\n");
            printf("Whatsapp: 1 2345-6789\n");
            printf("Telefone: 1234-5678\n");
            printf("Email: emailexemplo@gmail.com");
        } else {
            printf("Programa finalizado...");
            exit(0);
        }
    }
}