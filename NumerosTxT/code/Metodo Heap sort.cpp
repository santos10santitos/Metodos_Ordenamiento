#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[i] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    std::string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt";

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
    heapSort(numeros);
    auto fin = std::chrono::steady_clock::now();
    double duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count() / 1000000.0;

    std::cout << "Números ordenados: ";
    for (int num : numeros)
        std::cout << num << " ";
    std::cout << std::endl;  
    std::cout << "Tiempo de ejecución: " << duracion << " segundos"<< ruta_archivo << std::endl;

    return 0;
}