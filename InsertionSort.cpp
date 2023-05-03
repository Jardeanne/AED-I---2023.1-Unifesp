/* O InsertionSort percorre o array a partir do segundo elemento, 
comparando cada elemento com os elementos anteriores e inserindo-o na posição correta. 
A cada iteração ele assume que os elementos à esquerda já estão ordenados e insere o 
próximo elemento na posição correta nessa parte ordenada do array.
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para medir o tempo atual em milissegundos
long long getTimeMillis() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
}

// Função para imprimir o array na tela
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função para gerar um array aleatório de números distintos
void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Gera números aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    random_shuffle(arr, arr + n);
}

// Função para ordenar o array utilizando o InsertionSort
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
    
    // Gerar um array aleatório de números distintos
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

    // Imprimir o tempo de execução em milissegundos
    cout << "Tempo de execucao: " << (endTime - startTime) << " ms" << endl;

    return 0;
}