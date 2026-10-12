#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    //
    int n;
    printf("Quantos números na sua série (N): ");
    scanf("%d", &n);
    
    double *valores;
    valores = malloc(n * sizeof(double));

    if (valores == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
     }

    printf("Entre com número:\n");
    for (int i = 0; i < n; i++) {
        printf("> ");
        scanf("%lf", &valores[i]);
    }

    //Definição dos valores mínimos e máximos:
    double minimo = valores[0];
    double maximo = valores[0];
    
    for (int i = 1; i < n; i++) {
        if (valores[i] < minimo){
            minimo = valores[i];
        }
        if (valores[i] > maximo){
            maximo = valores[i];
        }  
    }
    
    printf("Valor mínimo: %g\n", minimo);
    printf("Valor máximo: %g\n", maximo);
    
    // Cálculo da média:
    double soma = 0;

    for (int i = 0; i < n; i++) {
        soma = soma + valores[i];
    }

    double media = soma / n;

    printf("Média: %g\n", media);

    // Achando a mediana e em primeiro lugar devemos ordenar
    double mediana = 0;
    double temp = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int x = 0; x < n - 1 - i; x++) {
            if (valores[x] > valores[x + 1]) {
                temp = valores[x];
                valores[x] = valores[x + 1];
                valores[x + 1] = temp;
            }
        }
    }

    if (n % 2 == 1) {
        mediana = valores[n / 2];
    } else {
        mediana = (valores[(n / 2) - 1] + valores[n / 2]) / 2;
    }
    
    printf("Mediana: %g\n", mediana);

    // Calculando desvio padrão usando adaptando com a fórmula e usando "for" para somatória

    double soma_quadrados = 0;

    for (int i = 0; i < n; i++) {
        double diff = valores[i] - media;
        diff = diff * diff;
        soma_quadrados = soma_quadrados + diff;
    }
    
    double desvio = sqrt(soma_quadrados / n); //desvio populacional, logo ao invés de ser n - 1, é somente n

    printf("Desvio padrão: %lf\n", desvio);
    
    return 0;
}