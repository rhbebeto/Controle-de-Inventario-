#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_produtos 100

typedef struct prod
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
}produto;

void listar(produto inventario[], int contador){
    int i=0;
    for (i = 0 ; i < contador ; i++ ){ 
    printf("\n===LISTA DE PRODUTOS===\n");
    printf("ID: %d\n", inventario[i].id);
    printf("NOME: %s\n", inventario[i].nome);
    printf("QUANTIDADE: %d\n", inventario[i].quantidade);
    printf("PRECO: %.2f\n", inventario[i].preco);
    }
}

void adicionar(produto inventario[], int *contador){
    if(*contador>max_produtos){
        printf("O limite de produtos cadastrado foi atingido \n");
        return;
        }

    produto novo_produto;
    int proximo_id = *contador + 1;

    printf("Insira o nome do produto: ");
    fgets(novo_produto.nome, sizeof(novo_produto.nome), stdin);
    novo_produto.nome[strcspn(novo_produto.nome, "\n")] = '\0';
    
    
    printf("Insira a quantidade do produto:");
    scanf("%d", &novo_produto.quantidade);
    
    while (getchar() != '\n');

    
    printf("\nInsira o preco: R$");
    scanf("%f", &novo_produto.preco);

    while (getchar() != '\n');


    inventario[*contador] = novo_produto;
    (*contador)++;
    printf("Produto adicionado com sucesso!\n");
}

void remover(produto inventario[], int *contador){

    if (*contador==0)
    {
       printf("Nao ha nenhum produto para remover\n");
    }

    int id;
    printf("Digite o ID do produto a ser removido:");
    scanf("%d", & id);
    while (getchar() != '\n');

    int pos=-1;
    for (int i = 0;i < *contador ; i++)
    {
       if (inventario[i].id==id)
       {
        pos = i;
        break;
       }

    if (pos == -1)
    {
        printf("O produto não foi encontrado!\n");
        return;
    }
    for (int i = pos; i < *contador - 1 ; i++)
    {
        inventario[i]=inventario[i + 1];
    }
    
    }
    
    (*contador)--;
    printf("Produto removido com sucesso!\n");
}

void alterar(produto inventario[], int contador){
    if(contador==0){
        printf("Nao ha produtos para se alterar!\n");
    }

    int id;
    printf("Insira a id do produto a ser alterado:");
    scanf("%d\n", &id);
    while (getchar() != '\n');

    int pos=-1;
    for ( int i = 0; i < contador; i++)
    {
        if(inventario[i].id==id){
            pos=i;
            break;
        }
    }

    printf("Digite um novo nome para o produto:(Ou deixe bazio para mante-lo)");
    char novo_nome[50];
    fgets(novo_nome, sizeof(novo_nome), stdin);
    if (novo_nome[0] != '\n') {
        novo_nome[strcspn(novo_nome, "\n")] = '\0'; 
        strcpy(inventario[pos].nome, novo_nome);
    }

    int nova_quantidade;
    printf("Digite uma nova quantidade para o produto:(Ou zero para manter)");
    scanf("%d", &nova_quantidade);
    while (getchar() != '\n');
    if(nova_quantidade!=0){
        inventario[pos].quantidade=nova_quantidade;
    }

    float novo_preco;
    printf("Digite o novo preco do produto:(ou -1 para mante-lo)");
    scanf("%f", &novo_preco);
    while (getchar() != '\n');
    if(novo_preco!=-1){
        inventario[pos].preco=novo_preco;
    }

    printf("Produto alterado com sucesso!\n");    
}

int main(){
    produto inventario[max_produtos];
    int contador=0;
    int escolha;

    printf("===== BEM VINDO! =====\n");
    do
    {
    printf("Escolha uma opcao:\n");
    printf("1-Ver produtos\n");
    printf("2-Adiconar produtos\n");
    printf("3-Remover produtos\n");
    printf("4-Atualizar produtos\n");
    printf("5-Sair do programa\n");
    printf("Insira sua escolha:");
    scanf("%d", &escolha);
    printf("--------------------\n");
    while (getchar() != '\n');

    switch (escolha)
    {
    case 1:
        listar(inventario, contador);
        break;
    case 2:
        adicionar(inventario, &contador);
        break;
    case 3:
        remover(inventario, &contador);
        break;
    case 4:
        alterar(inventario, &contador);
        break;
    case 5:
        printf("Saindo do programa.");
        exit(0);
        break;
    
    default:
       printf("Essa opção não é valida!\n");
        break;
    }
     
    } while (escolha!=5);
    return 0;
}