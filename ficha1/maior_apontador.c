#include <stdio.h>

int main() 
{
    int a, b;
    int *c, *d;
    char continuar; // char para guardar uma letra (s/n)
    c = &a;
    d = &b;
    
    for (;;) 
    {
        printf("Valor de a: "); scanf("%d", &a);
        printf("Valor de b: "); scanf("%d", &b);

        if (*c > *d) //ver qual é o maior
        {
            printf("O maior valor é: %d da variavel a\n", *c);
        } else 
        {
            printf("O maior valor é: %d da variavel b\n", *d);
        }

        printf("Deseja fazer mais uma iteração? (s/n): "); scanf(" %c", &continuar);
        
        if (continuar != 's' && continuar != 'S') // && mesma coisa que "e"
        {

            printf("Encerrando o programa...\n");
            break;
        }
    }
}