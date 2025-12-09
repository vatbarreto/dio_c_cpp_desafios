#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    printf("=== Calculadora Básica em C ===\n");
    printf("Operações disponíveis: +  -  *  /\n\n");

    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op); // espaço antes do %c evita leitura de lixo da entrada

    printf("Digite o segundo número: ");
    scanf("%lf", &num2);

    double resultado;

    switch (op) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '/':
            if (num2 == 0) {
                printf("Erro: divisão por zero não é permitida.\n");
            } else {
                resultado = num1 / num2;
                printf("Resultado: %.2lf\n", resultado);
            }
            break;

        default:
            printf("Operador inválido! Utilize +, -, * ou /.\n");
            break;
    }

    return 0;
}
