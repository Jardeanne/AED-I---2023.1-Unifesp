#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
int main() {
 
    int N,M;
    cin>>N>>M;
    
    // Loop para continuar executando enquanto N ou M não forem iguais a zero
    while(N!=0 || M!=0){
		
		int result = N+M;
		
		// Conversão do resultado para string
		string a = to_string(result);
		
		// Loop para percorrer os caracteres da string resultante
		for(int i=0; i<a.size(); i++){
			// Exclusão dos caracteres '0'
		    if(a[i]!='0'){ 
				cout<<a[i];
			}
		}
		cout<<endl;
		// Leitura dos próximos valores de N e M para a próxima iteração do loop
		cin>>N>>M;
	}
	return 0;
}