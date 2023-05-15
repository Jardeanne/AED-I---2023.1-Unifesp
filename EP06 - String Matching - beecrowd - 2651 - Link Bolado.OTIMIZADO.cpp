/* Após fazer pesquisa de como otimizar, ou utilizar funções encontrei esta
função que também resolve o problema, inclusive acredito que melhorando seu
tempo e desempenho. A busca de referência é muito importante ao programador
em desenvolvimento*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string texto, padrao = "zelda";
    getline(cin, texto);
    
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    if (search(texto.begin(), texto.end(), padrao.begin(), padrao.end()) != texto.end()) {
        cout << "Link Bolado" << endl;
    } else {
        cout << "Link Tranquilo" << endl;
    }

    return 0;
}





