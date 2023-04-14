#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  string risada, resultante;
  cin >> risada;
  // Variável de status para indicar se a risada é válida ou não
  bool status = true;

  // Loop para processar a risada
  while (risada.size() > 0) {
    // Verificação se o primeiro caractere da risada é uma vogal
    if (risada[0] == 'a' || risada[0] == 'e' || risada[0] == 'i' || risada[0] == 'o' || risada[0] == 'u') {
      // Adição do caractere na string resultante
      resultante += risada[0];
    }
    // Remoção do primeiro caractere da risada para processar o próximo
    risada.erase(risada.begin());
  }

  int n = resultante.size();
  // Loop para verificar se a risada resultante é um palíndromo
  for (int i = 0; i < n / 2; ++i) {
    if (resultante[i] != resultante[n - i - 1]) {
      // Se não for um palíndromo, atualiza o status para false e sai do loop
      status = false;
      break;
    }
  }

  if (status == false)
    cout << "N" << endl;
  else
    cout << "S" << endl;

  return 0;
}