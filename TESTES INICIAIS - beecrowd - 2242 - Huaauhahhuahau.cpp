#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
  string risada, resultante;
  cin >> risada;
  // Vari�vel de status para indicar se a risada � v�lida ou n�o
  bool status = true;

  // Loop para processar a risada
  while (risada.size() > 0) {
    // Verifica��o se o primeiro caractere da risada � uma vogal
    if (risada[0] == 'a' || risada[0] == 'e' || risada[0] == 'i' || risada[0] == 'o' || risada[0] == 'u') {
      // Adi��o do caractere na string resultante
      resultante += risada[0];
    }
    // Remo��o do primeiro caractere da risada para processar o pr�ximo
    risada.erase(risada.begin());
  }

  int n = resultante.size();
  // Loop para verificar se a risada resultante � um pal�ndromo
  for (int i = 0; i < n / 2; ++i) {
    if (resultante[i] != resultante[n - i - 1]) {
      // Se n�o for um pal�ndromo, atualiza o status para false e sai do loop
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