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

Fila * inserir_usuario(Fila *fila, char nome[], int fIdade, int nCPF, int nCelular, char fEndereco[]) {
    Fila *novo_usuario;
    novo_usuario = (Fila *) malloc(sizeof(Fila));

    strcpy(novo_usuario->nome, nome);
    novo_usuario->idade = fIdade;
    novo_usuario->cpf = nCPF;
    novo_usuario->celular = nCelular;
    strcpy(novo_usuario->endereco, fEndereco);

    novo_usuario->prox = (struct Fila *) fila;

    return novo_usuario;
}

void mostrar_posicao(Fila *fila, int cpfBuscado) {
    Fila *pontAuxiliar;
    int posicao = 1;

    while (pontAuxiliar != NULL) {
        if (pontAuxiliar->cpf == cpfBuscado) {
            printf("\nPOSIÇÃO %d", posicao);
        }
        pontAuxiliar = (Fila *) pontAuxiliar->prox;
        posicao++;
    }
}

int main(void) {
    Fila *filaNormal;
    Fila *filaPR;

    int escolha, operacao, resposta, escolhaFila, cpfBusca;
    int idade, nCPF, nCelular;
    char nome[50], endereco[50];

    filaNormal = criar_fila_espera();
    filaPR = criar_fila_espera();

    while (escolha != 0) {
        printf("\n\n1 - Realizar agendamento\n");
        printf("2 - Mostrar posição na fila");
        printf("3 - Exibir informações para contato\n");
        printf("0 - Finalizar programa\n");

        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 1) {
            printf("\n\n1 - Saque do INSS sem cartão\n");
            printf("2 - Pagamento do abono e FGTS sem cartão\n");
            printf("3 - Desbloquear cartão e senha da conta\n");
            printf("4 - Consulta com gerente\n");
            printf("0 - Finalizar programa\n");

            printf("Digite o número da operação: ");
            scanf("%d", &operacao);
            setbuf(stdin, NULL);

            if (operacao > 0 && operacao <= 4) {
                printf("Insira seus dados:\n");

                printf("Para começar informe seu nome: ");
                scanf("%[^\n]", nome);

                printf("\nFaz parte de algum grupo prioritário? (1-SIM ou 0-NÃO)");
                printf("\n(Idosos, gestantes, lactantes ou portador de deficiência)");
                printf("Resposta: ");
                scanf("%d", &resposta);
                printf("Idade: ");
                scanf("%d", &idade);
                printf("CPF: ");
                scanf("%d", &nCPF);
                printf("Celular/telefone: ");
                scanf("%d", &nCelular);
                printf("Endereço: ");
                scanf("%[^\n]", endereco);

                if (resposta == 1) {      
                    filaPR = inserir_usuario(filaPR, nome, idade, nCPF, nCelular, endereco);
                } 
                if (resposta == 0) {
                    filaNormal = inserir_usuario(filaNormal, nome, idade, nCPF, nCelular, endereco);
                }
            }
            if (operacao == 0) {
                break;
            }

        }
        if (escolha == 2) {
            printf("\n1 - Fila normal");
            printf("\n2 - Fila prioritário\n");
            printf("Escolha: ");
            scanf("%d", &escolhaFila);

            if (escolhaFila == 1) {
                printf("Digite o CPF para a busca: ");
                scanf("%d", &cpfBusca);
                mostrar_posicao(filaNormal, cpfBusca);
            }
            if (escolhaFila == 2) {
                printf("Digite o CPF para a busca: ");
                scanf("%d", &cpfBusca);
                mostrar_posicao(filaPR, cpfBusca);
            }
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