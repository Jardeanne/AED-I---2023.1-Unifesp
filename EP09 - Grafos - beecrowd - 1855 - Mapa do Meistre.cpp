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
    int w, h; cin >> w >> h; // Lê as dimensões da matriz

    vector<vector<char> > grid(h, vector<char>(w));
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            cin >> grid[i][j]; // Lê os caracteres da grade

    int x = 0, y = 0; // Posição atual (coordenadas x e y)
    int dx = 0, dy = 0; // Direção atual (incrementos nas coordenadas x e y)

    vector<vector<bool> > visited(h, vector<bool>(w, false)); // Matriz de visitados para detectar ciclos
    while(true){
        if( (x < 0 || x >= h) || (y < 0 || y >= w) )
            invalid(); // Se a posição atual estiver fora dos limites verticais ou horizontais, é inválido

        if(grid[x][y] == '*')
            valid(); // Se encontrar o caractere '*', é válido

        // ciclo
        if(visited[x][y])
            invalid(); // Se a posição atual já foi visitada antes, é inválido (ciclo)

        visited[x][y] = true; // Marca a posição atual como visitada

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
