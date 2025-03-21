#include <stdio.h>

int main()
{
    int a, b, final;
    int *c, *d;  // declarar como apontadores
    char continuar; // char para guardar uma letra (s/n)

    for (;;) 
    { // loop infinito, será controlado pela variável 'continuar'
        c = &a;  // colocar os endereços das variáveis nos apontadores
        d = &b;

        printf("Valor de a: "); scanf("%d", &a);
        printf("Valor de b: "); scanf("%d", &b);

        final = *c + *d; // mesma coisa que a + b

        if (a < 0 || b < 0) {
            printf("Por favor, insira valores não negativos.\n");
        } else {
            printf("Valor final: %d\n", final);
        }

        // Pergunta ao usuário se deseja continuar
        printf("Deseja fazer mais uma iteração? (s/n): ");
        scanf(" %c", &continuar); // o espaço antes de %c é para ignorar espaços em branco

        if (continuar != 's' && continuar != 'S') {
            break; // sai do loop se o usuário não digitar 's' ou 'S'
        }
    }

    return 0;
}

