#include <iostream>
using namespace std;
 
int main() {
 
    int qtd, N; cin>>N;
    string entrada;
    
    for(int i=0; i<N; i++){
		cin>>entrada>>qtd;
		// Loop que percorre os caracteres da entrada de texto
		for(int i=0; i<entrada.size(); i++) {
			// Verifica se o caractere é uma letra minúscula
	        if (entrada[i] >= 'a' && entrada[i] <= 'z'){
	        	// Desloca o caractere minúsculo
	            entrada[i] = (entrada[i]-qtd + 'a')%26 + 'a';
	        }
	        else {
	        	// Desloca o caractere maiúsculo
	            entrada[i] = (entrada[i]-qtd + 'A')%26 + 'A';
	        }
    	}
	cout<<entrada<<endl;
	}
    return 0;
}