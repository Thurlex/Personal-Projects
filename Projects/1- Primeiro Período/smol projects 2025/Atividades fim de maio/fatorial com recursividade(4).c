#include <stdio.h>

// Declaração da função fatorial (protótipo)
// É uma boa prática declarar a função antes de usá-la em main,
// ou definir a função fatorial antes da main.
int fatorial(int n);

int main() {
  int numero;
  printf("Digite um numero para calcular o fatorial: ");
  scanf("%d", &numero);

  // Chamada da função fatorial
  int resultado = fatorial(numero);

  // A sua função main original é:
  // printf("O fatorial de %d é %d\n", numero, fatorial(numero));
  // Para que essa linha funcione de forma informativa mesmo com a entrada negativa,
  // o resultado -1 da função fatorial será impresso.

  if (numero < 0) {
    // Se a função fatorial retorna -1 para números negativos,
    // a saída será "O fatorial de [numero_negativo] é -1".
    // Isso informa que algo está diferente do fatorial padrão.
    // Poderíamos adicionar uma mensagem mais explícita aqui, mas seguindo
    // a estrutura original da sua main e o pedido de apenas programar a função fatorial:
    printf("O fatorial de %d é %d (Nota: Fatorial não definido para negativos, -1 indica isso).\n", numero, resultado);
  } else {
    printf("O fatorial de %d é %d\n", numero, resultado);
  }

  // Nota sobre o limite do tipo 'int':
  // O fatorial cresce muito rapidamente. Para um tipo 'int' (geralmente 32 bits),
  // o valor máximo é em torno de 2 bilhões.
  // 12! = 479,001,600 (cabe em um int)
  // 13! = 6,227,020,800 (já estoura um int de 32 bits)
  // Se precisar calcular fatoriais maiores, seria necessário usar 'long long int'.

  return 0;
}

// Definição da função fatorial
int fatorial(int n) {
    // Caso base para números negativos:
    if (n < 0) {
        return -1;
    }
    // Caso base: fatorial de 0 é 1
    if (n == 0) {
        return 1;
    }
    // Passo recursivo: n! = n * (n-1)!
    return n * fatorial(n - 1);
}