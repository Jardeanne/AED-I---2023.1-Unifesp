#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	// Declaração de um array de inteiros com tamanho 10
	int X[10];
	
	for(int i=0; i<10; i++){
		// Leitura dos valores de entrada e armazenamento no array X
		cin>>X[i];
		// Se o valor lido for menor ou igual a zero, substitui por 1
		if(X[i]<=0) X[i] = 1;
	}

	// Laço de repetição para imprimir os valores do array X
	for(int i=0; i<10; i++){
		cout<<"X["<<i<<"] = "<<X[i]<<endl;
	}

	return 0;
}