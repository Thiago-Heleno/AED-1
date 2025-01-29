#include <stdio.h>
#include <string.h>

int main()
{
  // Quantidade de LEDs necessários para cada dígito
  int qtdVetor[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  int n;

  // Lê o número de casos de teste
  scanf("%d", &n);
  getchar(); // Consumir o '\n' após o número de casos

  for (int i = 0; i < n; i++)
  {
    char num[102]; // Para suportar números de até 101 dígitos + '\0'
    fgets(num, 102, stdin);

    // Remove o '\n' do final da string, se presente
    num[strcspn(num, "\n")] = '\0';

    int count = 0;

    // Calcula a quantidade de LEDs
    for (int j = 0; j < strlen(num); j++)
    {
      count += qtdVetor[num[j] - '0'];
    }

    // Imprime o resultado
    printf("%d leds\n", count);
  }

  return 0;
}
