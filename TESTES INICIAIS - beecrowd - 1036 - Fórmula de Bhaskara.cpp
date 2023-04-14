#include <iomanip>       
#include <iostream>      
#include <math.h>        
using namespace std;    

int main() {             

    double A, B, C;  
    cin >> A >> B >> C; 

	// Verifica se o coeficiente A é igual a zero, o que impossibilita o cálculo da equação de segundo grau
    if (A == 0) {                 
        cout << "Impossivel calcular" << endl;  
        return 0;                  
    } else {
    	// Calcula o valor do delta da equação de segundo grau
        double DELTA = pow(B, 2) - (4 * A * C);  
            
		// Verifica se o delta é negativo, o que impossibilita o cálculo das raízes reais
        if (DELTA < 0) {          
            cout << "Impossivel calcular" << endl;  
            return 0;           
        } else {
            double R1 = ((-B) + (sqrt(DELTA))) / (2.0 * A);  
            double R2 = ((-B) - (sqrt(DELTA))) / (2.0 * A); 
            // Imprime as raízes da equação formatadas com precisão fixa em 5 casas decimais
			cout << fixed << setprecision(5) << "R1 = " << R1 << endl << "R2 = " << R2 << endl;  
        }
    }
    return 0; 
}