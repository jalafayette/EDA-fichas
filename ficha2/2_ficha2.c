#include <stdio.h>
#include <stdlib.h>

// Definir a estrutura de um registo
typedef struct ponte {
    int valor;
    struct ponte *sequinte; // número seguinte na lista
} * lista;

// funcao para listar os elementos da lista
void listar(lista inicio) 
{
    lista apt = inicio;
    int i = 0;
    if (apt == NULL) {
        printf("\nLista vazia.\n");
        return;
    }
    while (apt != NULL) {
        printf("\nRegisto %d\n", i);
        printf(" Endereço do registo: %p\n", apt);
        printf(" Valor: %d\n", apt->valor);
        printf(" Sequinte: %p\n\n", apt->sequinte);
        apt = apt->sequinte;
        i++;
    }
}

// Função que insere um novo elemento no **início** da lista
lista inserir(lista inicio, int valor) 
{
    lista novo = (lista)malloc(sizeof(struct ponte)); // aloca espaço para a nova ponte
    novo->valor = valor;
    novo->sequinte = inicio;
    return novo;
}

// Função que insere um novo elemento no **fim** da lista
lista inserir_fim(lista fim, int valor) 
{
    lista novo = (lista)malloc(sizeof(struct ponte));
    novo->valor = valor; // poe o valor dado para esta funçao no novo valor da struct
    novo->sequinte = NULL; // a nova ponte sera destinada para o "nada" = NULL
    
    if (fim == NULL) {
        return novo; // Se a lista estiver vazia, o novo elemento passa a ser o início
    } else {
        // Se a lista não estiver vazia, percorre a lista até encontrar o último elemento
        lista temp = fim;
        while (temp->sequinte != NULL) {
            temp = temp->sequinte;
        }
        temp->sequinte = novo; // o ultimo elemento da lista passa a apontar para o novo elemento
        return fim; // Retorna o final da lista
    }
}

// Função iterativa que insere um novo elemento numa **dada posição** da lista 
lista inserir_posicao(lista inicio, int valor, int posicao) {
    // Caso especial: inserir no início da lista
    if (posicao == 0) {
        return inserir(inicio, valor);
    }

    lista temp = inicio;
    // Percorre a lista até a posição anterior à desejada
    for (int i = 0; i < posicao - 1; i++) {
        if (temp == NULL) {
            printf("Posição fora dos limites da lista.\n");
            return inicio;
        }
        temp = temp->sequinte;
    }

    // Cria o novo elemento
    lista novo = (lista)malloc(sizeof(struct ponte));
    novo->valor = valor;
    novo->sequinte = temp->sequinte;
    temp->sequinte = novo;

    return inicio;
}

// Função para calcular a média dos valores na lista
void media(lista x) {
    lista y = x;
    int i = 0;
    int soma = 0;
    float media = 0.0; // Corrigido para float
    while (y != NULL) {
        soma += y->valor;
        y = y->sequinte;
        i++;
    }
    if (i > 0) {
        media = (float)soma / i; // Corrigido para float
    }
    printf("Média: %.2f\n", media); 
}

// Função para liberar a memória ocupada pela lista
void liberar_lista(lista inicio) {
    lista temporaria;
    while (inicio != NULL) {
        temporaria = inicio;
        inicio = inicio->sequinte;
        free(temporaria);
    }
}

// Função para remover um elemento da lista
void remover(lista *inicio, int valor) {
    lista temporaria = *inicio;
    lista anterior = NULL;
    while (temporaria != NULL && temporaria->valor != valor) {
        anterior = temporaria;
        temporaria = temporaria->sequinte;
    }
    if (temporaria == NULL) {
        printf("Elemento não encontrado.\n");
        return;
    }
    if (anterior == NULL) {
        *inicio = temporaria->sequinte;
    } else {
        anterior->sequinte = temporaria->sequinte;
    }
    free(temporaria);
}

// Função para remover um elemento da lista por posição
void remover_posicao(lista *inicio, int posicao) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    lista temporaria = *inicio;

    // Caso especial: remover o primeiro elemento
    if (posicao == 0) {
        *inicio = temporaria->sequinte;
        free(temporaria);
        return;
    }

    // Percorre a lista até a posição anterior à desejada
    for (int i = 0; temporaria != NULL && i < posicao - 1; i++) {
        temporaria = temporaria->sequinte;
    }

    // Se a posição estiver fora dos limites
    if (temporaria == NULL || temporaria->sequinte == NULL) {
        printf("Posição fora dos limites da lista.\n");
        return;
    }

    // Nodo temporário para o próximo do nodo a ser excluído
    lista proximo = temporaria->sequinte->sequinte;

    // Libera a memória do nodo a ser excluído
    free(temporaria->sequinte);

    // Desconecta o nodo excluído da lista
    temporaria->sequinte = proximo;
}

// Função para remover todos os elementos da lista de forma recursiva
void remover_lista(lista *inicio) {
    int temp1, temp2;
    lista temp = *inicio;
    if (temp == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    temp1 = temp->valor;
    if (temp->sequinte != NULL) {
        temp2 = temp->sequinte->valor;
    } else {
        temp2 = -1;
    }
    
    if (*inicio == NULL) {
        return; // se a lista estiver vazia, retorna para o inicio
    } else {
        remover_lista(&(*inicio)->sequinte); // chama a função recursivamente
        free(*inicio);
        *inicio = NULL;
    }

    if (temp2 == -1) {
        printf("Posição %d não encontrada.\n", temp2);
        return;
    }

    if (temp2 == -1) {
        printf("Posição %d não encontrada.\n", temp2);
        return;
    }

    // Trocar os valores dos nós encontrados
    int temp_valor = temp1;
    temp1 = temp2;
    temp2 = temp_valor;
}

// funcao para trocar valores de dois elementos da lista
void trocar_valores(lista *inicio, int pos1, int pos2) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    lista temp1 = *inicio;
    lista temp2 = *inicio;
    lista anterior1 = NULL;
    lista anterior2 = NULL;
    int i = 0;

    // Encontrar o elemento da posição pos1
    while (temp1 != NULL && i < pos1) {
        anterior1 = temp1;
        temp1 = temp1->sequinte;
        i++;
    }

    if (temp1 == NULL) {
        printf("Posição %d não encontrada.\n", pos1);
        return;
    }

    // Resetar o contador e encontrar o elemento da posição pos2
    i = 0;
    while (temp2 != NULL && i < pos2) {
        anterior2 = temp2;
        temp2 = temp2->sequinte;
        i++;
    }

    if (temp2 == NULL) {
        printf("Posição %d não encontrada.\n", pos2);
        return;
    }

    // Trocar os valores dos elementos encontrados
    int temp_valor = temp1->valor;
    temp1->valor = temp2->valor;
    temp2->valor = temp_valor;
}

// Função que ordena os valores da lista por ordem crescente
void ordenar_valores(lista *inicio) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    lista temporaria;
    int trocado;
    do {
        trocado = 0;
        temporaria = *inicio;

        while (temporaria->sequinte != NULL) {
            if (temporaria->valor > temporaria->sequinte->valor) {
                int temp = temporaria->valor;
                temporaria->valor = temporaria->sequinte->valor;
                temporaria->sequinte->valor = temp;
                trocado = 1;
            }
            temporaria = temporaria->sequinte;
        }
    } while (trocado);
}

void dividir_lista(lista *inicio, int localizador, lista *lista1, lista *lista2) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    lista temp = *inicio;
    *lista1 = NULL;
    *lista2 = NULL;
    lista *current_list = lista1;

    while (temp != NULL) {
        lista novo = (lista)malloc(sizeof(struct ponte));
        novo->valor = temp->valor;
        novo->sequinte = NULL;

        if (*current_list == NULL) {
            *current_list = novo;
        } else {
            lista aux = *current_list;
            while (aux->sequinte != NULL) {
                aux = aux->sequinte;
            }
            aux->sequinte = novo;
        }

        if (temp->valor == localizador) {
            current_list = lista2;
        }

        temp = temp->sequinte;
    }
}

// funcao para dividir a lista na metade, em que tds os valores da 1º metade sao o val1 e os da 2º metade sao o val2
void metade_lista(lista *inicio, int val1, int val2)
{
   if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    lista anterior1 = NULL;
    lista anterior2 = NULL;
    lista temp1 = *inicio;
    int i = 0;
    
    // contar quantos elementos tem a lista
    while (temp1 != NULL) {
        anterior1 = temp1;
        temp1 = temp1->sequinte;
        i++;
    } 
    // agora i = numero de elementos da lista
    
    if (i%2 == 0) 
    {
        int meio = i/2;
    temp1 = *inicio;
    i = 0;
    while (temp1 != NULL) {
        if (i < meio) {
            temp1->valor = val1;
        } else {
            temp1->valor = val2;
        }
        temp1 = temp1->sequinte;
        i++;
    }
    } else {
        printf("Numero de elementos da lista é impar.\n");
        printf("Não é possivel dividir a lista na metade :(\n");
    }
    
}

int main() {
    int opcao; // Variável para armazenar a opção escolhida pelo usuário
    lista xpto = NULL; // Declaração da variável xpto do tipo lista
    do 
    {
        // Exibe o menu de opções para o usuário
        printf("\n--- MENU ---\n");
        printf("1. Inserir elemento no inicio da lista\n");
        printf("2. Inserir elemento no fim da lista\n");
        printf("3. Inserir elemento numa posiçao especifica\n");
        printf("4. Listar elementos da lista\n");
        printf("5. Remover elemento\n");
        printf("6. Calcular media\n");
        printf("7. Remover elemento numa posiçao especifica\n");
        printf("8. Remover todos os elementos da lista\n");
        printf("9. Trocar valores\n");
        printf("10. Ordenar de forma crescente os valores\n");
        printf("11 Dividir a lista\n");
        printf("12 Dividir a lista na metade, escolhendo valores para ambas as partes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: "); scanf("%d", &opcao); // Lê a escolha do usuário

        // Executa a função correspondente à escolha do usuário
        switch (opcao) 
        {
        case 1:
            int valor_inserido_inicio;
            printf("Digite o valor para inserir no início: "); scanf("%d", &valor_inserido_inicio);
            xpto = inserir(xpto, valor_inserido_inicio); // Chama a função para inserir no início
            break;


        case 2:
            int valor_inserido_fim;
            printf("Digite o valor para inserir no fim: "); scanf("%d", &valor_inserido_fim);
            xpto = inserir_fim(xpto, valor_inserido_fim); // Chama a função para inserir no final
            break;


        case 3:
            int valor_inserido_posicao, posicao;
            printf("Digite o valor para inserir: "); scanf("%d", &valor_inserido_posicao);
            printf("Digite a posição para inserir: "); scanf("%d", &posicao);
            xpto = inserir_posicao(xpto, valor_inserido_posicao, posicao);
            break;
        case 4:
            listar(xpto); // Chama a função para listar os elementos da lista
            break;
        case 5:
            int elemento_removido;
            printf("Digite o elemento da lista para remover: "); scanf("%d", &elemento_removido);
            remover(&xpto, elemento_removido); // Chama a função para remover um elemento
            break;
        case 6:
            media(xpto); // Chama a função para calcular a média dos elementos da lista
            break;
        case 7:
            int posicao_removida;
            printf("Digite a posição para remover: "); scanf("%d", &posicao_removida);
            remover_posicao(&xpto, posicao_removida);
            break;
        case 8:
            remover_lista(&xpto);
            break;
        case 9:
            int valor1, valor2;
            printf("Digite a posição 1: "); scanf("%d", &valor1);
            printf("Digite a posição 2: "); scanf("%d", &valor2);
            trocar_valores(&xpto, valor1, valor2);
            break;
        case 10:
            ordenar_valores(&xpto);
            break;

        case 11:
            int localizador;
            lista lista1, lista2;
            printf("Digite o valor para dividir a lista: "); scanf("%d", &localizador);
            dividir_lista(&xpto, localizador, &lista1, &lista2);
            printf("Lista 1:\n");
            listar(lista1);
            printf("Lista 2:\n");
            listar(lista2);
            break;


        case 12:
            int val1, val2;
            printf("Digite o valor para a 1º metade: "); scanf("%d", &val1);
            printf("Digite o valor para a 2º metade: "); scanf("%d", &val2);
            metade_lista(&xpto, val1, val2);
            break;


        case 0:
            liberar_lista(xpto); // Libera a memória alocada para a lista
            xpto = NULL; // Previne acesso a memória liberada
            printf("terminando o programa\n");
            exit(0); // Encerra o programa
        default:
            printf("Opcao invalida!\n"); // Exibe mensagem de erro para opção inválida
            break;
        }
    } while (opcao != 0); // Continua exibindo o menu até que o usuário escolha sair (opção 0)

    liberar_lista(xpto);
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}






