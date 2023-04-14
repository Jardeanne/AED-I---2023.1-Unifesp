#include <iostream>
#include <set>
using namespace std;

int matriz[9][9];

// Fun��o que verifica se uma linha da matriz cont�m valores �nicos (set)
bool verificaLinha(int x){
    set<int> num;

    for(int i = 0; i < 9; ++i) num.insert(matriz[x][i]);

    // Retorna verdadeiro se o conjunto tiver 9 elementos �nicos e falso caso contr�rio
	return num.size() == 9;
}

// Fun��o que verifica se uma coluna da matriz cont�m valores �nicos
bool verificaColuna(int x){
    set<int> num;

    for(int i = 0; i < 9; ++i) num.insert(matriz[i][x]);

    // Retorna verdadeiro se o conjunto tiver 9 elementos �nicos e falso caso contr�rio
	return num.size() == 9;
}

// Fun��o que verifica se um quadrante da matriz cont�m valores �nicos
bool verificaQuad(int x){
    set<int> num;
    // Calcula a posi��o inicial do quadrante na matriz
    int linha = 3*(x/3), coluna = 3*(x%3);

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            num.insert(matriz[linha + i][coluna + j]);
        }
    }

    // Retorna verdadeiro se o conjunto tiver 9 elementos �nicos e falso caso contr�rio
	return num.size() == 9;
}

int main(){
    int n;

    cin >> n;
    for(int k=1; k<=n; ++k){
    	// Vari�vel para armazenar o status
        bool status = true;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cin >> matriz[i][j];
            }
        }

        cout << "Instancia " << k << endl;

        for(int i=0; i<9; ++i){
            if(!verificaLinha(i) || !verificaColuna(i) || !verificaQuad(i)){
            	// Se alguma das condi��es n�o for satisfeita, atualiza o status
                status = false;
                break;
            }
        }

        if(status==false) cout<<"NAO"<<endl<<endl;
        else cout<<"SIM"<<endl<<endl;
    }

    return 0;
}