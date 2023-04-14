#include <iomanip>       
#include <iostream>      
#include <math.h>        
using namespace std;    

int main() {             

    double A, B, C;  
    cin >> A >> B >> C; 

	// Verifica se o coeficiente A � igual a zero, o que impossibilita o c�lculo da equa��o de segundo grau
    if (A == 0) {                 
        cout << "Impossivel calcular" << endl;  
        return 0;                  
    } else {
    	// Calcula o valor do delta da equa��o de segundo grau
        double DELTA = pow(B, 2) - (4 * A * C);  
            
		// Verifica se o delta � negativo, o que impossibilita o c�lculo das ra�zes reais
        if (DELTA < 0) {          
            cout << "Impossivel calcular" << endl;  
            return 0;           
        } else {
            double R1 = ((-B) + (sqrt(DELTA))) / (2.0 * A);  
            double R2 = ((-B) - (sqrt(DELTA))) / (2.0 * A); 
            // Imprime as ra�zes da equa��o formatadas com precis�o fixa em 5 casas decimais
			cout << fixed << setprecision(5) << "R1 = " << R1 << endl << "R2 = " << R2 << endl;  
        }
    }
    return 0; 
}