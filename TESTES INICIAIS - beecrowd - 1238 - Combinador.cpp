#include <iostream>     
using namespace std;  

int main() {            

    int N;              
    cin >> N;           

    string a, b, resultante;   
    
    for (int i = 0; i < N; i++) {  
        cin >> a >> b; 
		           
		// Loop que executa enquanto a e b possuem caracteres
        while (a.size() > 0 || b.size() > 0) {  
			// Verifica se a ainda possui caracteres
            if (a.size() > 0) {   
				// Adiciona o primeiro caractere de a à string resultante    
                resultante += a[0]; 
				// Remove o primeiro caractere de a  
                a.erase(a.begin());   
            }
            // Verifica se b ainda possui caracteres
            if (b.size() > 0) {      
            	// Adiciona o primeiro caractere de b à string resultante
                resultante += b[0];   
                // Remove o primeiro caractere de b
				b.erase(b.begin());   
            }
        }
        cout << resultante << endl;  
        // Limpa a string resultante para a próxima iteração do loop
		resultante.clear();          
    }
    return 0; 
}