#include <iostream>
using namespace std;

// Funciones para operaciones matemáticas
int suma(int a, int b) { return a + b; }
int resta(int a, int b) { return a - b; }
int multiplicacion(int a, int b) { return a * b; }

// Función para ejecutar la operación con puntero a función
void ejecutarOperacion(int (*operacion)(int, int), int valor1, int valor2) {
    cout << "El resultado de la operación es: " << operacion(valor1, valor2) << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <num1> <operador> <num2>" << endl;
        return 1;
    }

    int numero1 = atoi(argv[1]); 
    int numero2 = atoi(argv[3]); 
    char operador = argv[2][0]; 

    int (*operacion)(int, int) = nullptr;

    switch (operador) {
        case '+': operacion = suma; break;
        case '-': operacion = resta; break;
        case '*': operacion = multiplicacion; break;
        default: cout << "Error: Operador no reconocido." << endl; return 1;
    }

    ejecutarOperacion(operacion, numero1, numero2);
    return 0;
}
