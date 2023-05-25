#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    std::string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/80000numeros.txt";


    std::ifstream archivo(ruta_archivo);
    std::string linea;
    std::vector<int> numeros;

    if (archivo.is_open()) {
        std::getline(archivo, linea);
        std::istringstream iss(linea);

        int numero;
        while (iss >> numero)
            numeros.push_back(numero);

        archivo.close();
    }
    else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return 0;
    }


    if (numeros.empty()) {
        std::cout << "El archivo no contiene números válidos para ordenar." << std::endl;
        return 0;
    }


    auto inicio = std::chrono::steady_clock::now();
    selectionSort(numeros);
    auto fin = std::chrono::steady_clock::now();
    double duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count() / 1000000.0;

    std::cout << "Números ordenados: ";
    for (int num : numeros)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Tiempo de ejecución: " << duracion << " segundos" << std::endl;

    return 0;
}