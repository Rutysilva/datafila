#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criação da struct fila
typedef struct {
    int idade, cpf, celular;
    char nome[51], endereco[51];
    struct Fila *prox;
} Fila;

Fila * criar_fila_espera() {
    return NULL;
}

Fila * inserir_usuario(Fila *fila, char nome[], int idade, int cpf, int celular, char endereco[]) {
    Fila *novo_usuario;
    novo_usuario = (Fila *) malloc(sizeof(Fila));

    //parei aqui pprt
}

int main(void) {
    Fila *filaNormal;
    Fila *filaPR;
    int escolha, operacao, resposta;
    int idade, nCPF, nCelular;
    char nome[50], endereco[50];

    filaNormal = criar_fila_espera();
    filaPR = criar_fila_espera();

    while (escolha < 0 || escolha > 3) {
        printf("\n\n1 - Realizar agendamento\n");
        printf("2 - Mostrar posição na fila");
        printf("3 - Exibir informações para contato\n");
        printf("0 - Finalizar programa\n");

        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 1) {
            while (operacao < 0 || operacao > 4) {
                printf("\n\n1 - Saque do INSS sem cartão\n");
                printf("2 - Pagamento do abono e FGTS sem cartão\n");
                printf("3 - Desbloquear cartão e senha da conta\n");
                printf("4 - Consulta com gerente\n");
                printf("0 - Voltar\n");

                printf("Digite o número da operação: ");
                scanf("%d", &operacao);
                setbuf(stdin, NULL);

                if (operacao > 0 && operacao <= 4) {
                    printf("Insira seus dados:\n");

                    printf("Para começar informe seu nome: ");
                    scanf("%[^\n]", nome);

                    while (resposta < 0 || resposta > 1) {
                        printf("\nFaz parte de algum grupo prioritário? (1-SIM ou 0-NÃO)");
                        printf("\n(Idosos, gestantes, lactantes ou portador de deficiência)");
                        printf("Resposta: ");
                        scanf("%d", &resposta);

                        if (resposta == 1) {
                            printf("Idade: ");
                            scanf("%d", &idade);
                            printf("CPF: ");
                            scanf("%d", &nCPF);
                            printf("Celular/telefone: ");
                            scanf("%d", &nCelular);
                            printf("%[^\n]", endereco);

                            
                        } 
                        if (resposta == 0) {

                        }
                    }
                }
                if (operacao == 0) {
                    break;
                }
            }

        }
        if (escolha == 2) {

        }
        if (escolha == 3) {
            printf("\n\nINFORMAÇÕES PARA CONTATO:\n");
            printf("Whatsapp: 1 2345-6789\n");
            printf("Telefone: 1234-5678\n");
            printf("Email: emailexemplo@gmail.com");
        } 
        if (escolha == 0) {
            printf("Programa finalizado...");
            exit(0);
        }
    }
}