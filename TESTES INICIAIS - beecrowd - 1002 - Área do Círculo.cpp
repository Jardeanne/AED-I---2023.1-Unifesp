#include <iomanip>
#include <iostream>
using namespace std;
 
int main() {
 
    double raio;
    cin>>raio;
    // Calcula a �rea do c�rculo
    double area = 3.14159 * raio * raio;
    
    /* Imprime a �rea do c�rculo formatada com precis�o fixa em 4 casas decimais, 
	utilizando o manipulador fixed e setprecision da biblioteca iomanip.*/
    cout<<"A="<< fixed << setprecision(4) << area<<endl;
    
    return 0;
}