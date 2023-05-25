#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int> insertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return arr;
}

int main() {
    std::string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt";;

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
    std::vector<int> numeros_ordenados = insertionSort(numeros);
    auto fin = std::chrono::steady_clock::now();
    double duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count() / 1000000.0;


    std::cout << "Números ordenados: ";
    for (int num : numeros_ordenados)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Tiempo de ejecución: " << duracion << " segundos" << std::endl;

    return 0;
}