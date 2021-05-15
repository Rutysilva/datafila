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

    if (fila == NULL) {
        novo_usuario->prox = NULL;
        return novo_usuario;
    } else {
        Fila *pontAuxiliar = fila;

        while (pontAuxiliar->prox != NULL) {
            pontAuxiliar = pontAuxiliar->prox;
        }

        novo_usuario->prox = NULL;
        pontAuxiliar->prox = novo_usuario;

        return novo_usuario;
    }
}

void mostrar_posicao(Fila *fila, int cpfBuscado) {
    Fila *pontAuxiliar = fila;
    int posicao = 1;

    while (pontAuxiliar != NULL) {
        if (pontAuxiliar->cpf == cpfBuscado) {
            printf("\nPOSIÇÃO %d\n\n", posicao);
        }
        pontAuxiliar = (Fila *) pontAuxiliar->prox;
        posicao++;
    }
}

int main(void) {
    Fila *filaNormal;
    Fila *filaPR;

    int escolha = -1, operacao = -1, resposta = -1, escolhaFila, cpfBusca;
    int idade, nCPF, nCelular;
    char nome[50], endereco[50];

    filaNormal = criar_fila_espera();
    filaPR = criar_fila_espera();

    while (escolha != 0) {
        printf("-------------------------------------------\n");
        printf("1 - Realizar agendamento\n");
        printf("2 - Mostrar posição na fila\n");
        printf("3 - Exibir informações para contato\n");
        printf("0 - Finalizar programa\n");

        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        setbuf(stdin, NULL);

        if (escolha == 1) {
            printf("\n1 - Saque do INSS sem cartão\n");
            printf("2 - Pagamento do abono e FGTS sem cartão\n");
            printf("3 - Desbloquear cartão e senha da conta\n");
            printf("4 - Consulta com gerente\n");
            printf("0 - Finalizar programa\n");

            printf("Digite o número da operação: ");
            scanf("%d", &operacao);
            setbuf(stdin, NULL);

            if (operacao > 0 && operacao <= 4) {
                printf("\nInsira seus dados:\n");

                printf("Para começar informe seu nome: ");
                scanf("%[^\n]", nome);

                printf("\nFaz parte de algum grupo prioritário? (1-SIM ou 0-NÃO)");
                printf("\n(Idosos, gestantes, lactantes ou portador de deficiência)");
                printf("\nResposta: ");
                scanf("%d", &resposta);
                printf("Idade: ");
                scanf("%d", &idade);
                printf("CPF: ");
                scanf("%d", &nCPF);
                printf("Celular/telefone: ");
                scanf("%d", &nCelular);
                setbuf(stdin, NULL);
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
            printf("Digite o CPF para a busca: ");
            scanf("%d", &cpfBusca);

            if (escolhaFila == 1) {
                mostrar_posicao(filaNormal, cpfBusca);
            }
            if (escolhaFila == 2) {
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

//problema encontrado:
//a função de mostrar a posição sempre indica a primeira posição para o último inserido
//duas possibilidades
//ou os valores não estão sendo inseridos corretamente
//ou a função de mostrar a posição não está funcionando corretamente