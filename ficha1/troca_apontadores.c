#include <stdio.h>

int main() 
{
    int a, b;
    int *c, *d;
    int temporario;

    c = &a;
    d = &b;

    printf("valor de a:"); scanf("%d", &a);
    printf("valor de b:"); scanf("%d", &b);

    printf("a = %d, b = %d\n", a, b);

    temporario = *c;
    *c = *d;
    *d = temporario;

    printf("Depois da troca: a = %d, b = %d\n", a, b);
}