#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[right]);

        int pivotIndex = i + 1;

        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    std::string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/500numeros.txt";

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
    quickSort(numeros, 0, numeros.size() - 1);
    auto fin = std::chrono::steady_clock::now();
    double duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count() / 1000000.0;


    std::cout << "Números ordenados: ";
    for (int num : numeros)
        std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Tiempo de ejecución: " << duracion << " segundos" << std::endl;

    return 0;
}