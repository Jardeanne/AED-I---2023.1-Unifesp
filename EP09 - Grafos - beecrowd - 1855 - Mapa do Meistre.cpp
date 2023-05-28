#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void invalid(){
    cout << '!' << endl;
    exit(0);
}

void valid(){
    cout << '*' << endl;
    exit(0);
}

int main(){
    int w, h; cin >> w >> h; // L� as dimens�es da matriz

    vector<vector<char> > grid(h, vector<char>(w));
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> grid[i][j]; // L� os caracteres da grade

    int x = 0, y = 0; // Posi��o atual (coordenadas x e y)
    int dx = 0, dy = 0; // Dire��o atual (incrementos nas coordenadas x e y)

    vector<vector<bool> > visited(h, vector<bool>(w, false)); // Matriz de visitados para detectar ciclos
    while(true){
        if( (x < 0 || x >= h) || (y < 0 || y >= w) )
            invalid(); // Se a posi��o atual estiver fora dos limites verticais ou horizontais, � inv�lido

        if(grid[x][y] == '*')
            valid(); // Se encontrar o caractere '*', � v�lido

        // ciclo
        if(visited[x][y])
            invalid(); // Se a posi��o atual j� foi visitada antes, � inv�lido (ciclo)

        visited[x][y] = true; // Marca a posi��o atual como visitada

        if(grid[x][y] == '>'){
            dx = 0; dy = 1; // Move para a direita (incrementa y)
        }
        else if(grid[x][y] == '^'){
            dx = -1; dy = 0; // Move para cima (decrementa x)
        }
        else if(grid[x][y] == 'v'){
            dx = 1; dy = 0; // Move para baixo (incrementa x)
        }
        else if(grid[x][y] == '<'){
            dx = 0; dy = -1; // Move para a esquerda (decrementa y)
        }

        x += dx; // Atualiza a coordenada x
        y += dy; // Atualiza a coordenada y
    }

    return 0;
}
