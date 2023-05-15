//1ª Versão
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	
	bool flag;
	string texto, padrao = "zelda";
	getline(cin,texto);
	
	// converte todas as letras da string texto para minúsculas
	transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
	
	// etapa de busca de uma palavra no trecho
	for (int i = 0; i < (int)texto.size(); i++) {
    flag = true;
        for (int j = 0; j < (int)padrao.size(); j++) {
            if (texto[i+j] != padrao[j]) flag = false;
        }
    // se a palavra estiver contida no trecho, imprime "Link Bolado" e encerra a iteração    
      if (flag){
          cout<<"Link Bolado"<<endl;
          break;
      }
    }
    // se a palavra não fora encontrada no trecho, imprime "Link Tranquilo"
    if(!flag) cout<<"Link Tranquilo"<<endl;
    
    return 0;
}