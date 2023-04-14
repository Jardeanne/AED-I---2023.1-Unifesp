#include <iostream>
#include <set>
using namespace std;

int matriz[9][9];

// Função que verifica se uma linha da matriz contém valores únicos (set)
bool verificaLinha(int x){
    set<int> num;

    for(int i = 0; i < 9; ++i) num.insert(matriz[x][i]);

    // Retorna verdadeiro se o conjunto tiver 9 elementos únicos e falso caso contrário
	return num.size() == 9;
}

// Função que verifica se uma coluna da matriz contém valores únicos
bool verificaColuna(int x){
    set<int> num;

    for(int i = 0; i < 9; ++i) num.insert(matriz[i][x]);

    // Retorna verdadeiro se o conjunto tiver 9 elementos únicos e falso caso contrário
	return num.size() == 9;
}

// Função que verifica se um quadrante da matriz contém valores únicos
bool verificaQuad(int x){
    set<int> num;
    // Calcula a posição inicial do quadrante na matriz
    int linha = 3*(x/3), coluna = 3*(x%3);

    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            num.insert(matriz[linha + i][coluna + j]);
        }
    }

    // Retorna verdadeiro se o conjunto tiver 9 elementos únicos e falso caso contrário
	return num.size() == 9;
}

int main(){
    int n;

    cin >> n;
    for(int k=1; k<=n; ++k){
    	// Variável para armazenar o status
        bool status = true;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                cin >> matriz[i][j];
            }
        }

        cout << "Instancia " << k << endl;

        for(int i=0; i<9; ++i){
            if(!verificaLinha(i) || !verificaColuna(i) || !verificaQuad(i)){
            	// Se alguma das condições não for satisfeita, atualiza o status
                status = false;
                break;
            }
        }

        if(status==false) cout<<"NAO"<<endl<<endl;
        else cout<<"SIM"<<endl<<endl;
    }

    return 0;
}