/* O InsertionSort percorre o array a partir do segundo elemento, 
comparando cada elemento com os elementos anteriores e inserindo-o na posi��o correta. 
A cada itera��o ele assume que os elementos � esquerda j� est�o ordenados e insere o 
pr�ximo elemento na posi��o correta nessa parte ordenada do array.
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// Fun��o para medir o tempo atual em milissegundos
long long getTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

// Fun��o para imprimir o array na tela
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fun��o para gerar um array aleat�rio de n�meros distintos
void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Gera n�meros aleat�rios
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + n);
}

// Fun��o para ordenar o array utilizando o InsertionSort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
	
    int n; // Tamanho do array
	cout << "Digite o tamanho do array: ";
    cin>>n;
    int arr[n];
    
    // Gerar um array aleat�rio de n�meros distintos
    generateRandomArray(arr, n);

    // Imprimir o array desordenado
    cout << "Array desordenado: ";
    printArray(arr, n);

    // Ordenar o array utilizando o InsertionSort
    long long startTime = getTimeMillis();
    insertionSort(arr, n);
    long long endTime = getTimeMillis();

    // Imprimir o array ordenado
    cout << "Array ordenado: ";
    printArray(arr, n);

    // Imprimir o tempo de execu��o em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}