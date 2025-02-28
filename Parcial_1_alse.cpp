#include <iostream>
#include <cmath>

// Definir la estructura de un punto en 2D
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
double calcularDistancia(const Point& p1, const Point& p2)  // Uso de referencias constantes
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;
    // Completar: Verificar si la respuesta es 's' o 'n', tener en cuenta mayúsculas y minúsculas
    if (respuesta == 's' || respuesta == 'S')
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            while (!(std::cin >> puntos[i].x >> puntos[i].y))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Coordenadas inválidas. Intente de nuevo: ";
            }
        }
    }
    else
    {
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};  // Punto 1 (0, 0)
        puntos[1] = {3, 4};  // Punto 2 (3, 4)
        puntos[2] = {6, 8};  // Punto 3 (6, 8)
        puntos[3] = {9, 12}; // Punto 4 (9, 12)
    }
}

// Función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point& pUsuario, int& indiceMasCercano)
{
    double distanciaMinima = std::numeric_limits<double>::max();
    for (int i = 0; i < n; ++i)
    {
        double distancia = calcularDistancia(pUsuario, puntos[i]);
        if (i == 0 || distancia < distanciaMinima)
        {
            distanciaMinima = distancia;
            indiceMasCercano = i;
        }
    }
    return distanciaMinima;
}

// BONO: Función para calcular la distancia total de los puntos en orden
double calcularDistanciaTotal(Point puntos[], int n)
{
    double distanciaTotal = 0.0;
    for (int i = 0; i < n - 1; ++i)
    {
        distanciaTotal += calcularDistancia(puntos[i], puntos[i + 1]);
    }
    return distanciaTotal;
}

// Función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}

int main()
{
    int n;

    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    while (!(std::cin >> n) || n < 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Número inválido. Intente de nuevo: ";
    }

    if (n < 2)
    {
        std::cout << "Se necesitan al menos 2 puntos para calcular las distancias.\n";
        return 1;
    }

    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)

    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);

    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    while (!(std::cin >> pUsuario.x >> pUsuario.y))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Coordenadas inválidas. Intente de nuevo: ";
    }

    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia = calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);

    // Mostrar resultado de la distancia total (bono)
    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "La distancia total de los puntos es: " << distanciaTotal << std::endl;

    return 0;
}