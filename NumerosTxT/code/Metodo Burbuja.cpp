#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt";

    ifstream archivo(ruta_archivo);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    vector<int> numeros;
    int numero;
    while (archivo >> numero) {
        numeros.push_back(numero);
    }
    archivo.close();
    auto inicio = high_resolution_clock::now();
    bubbleSort(numeros);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<duration<double>>(fin - inicio);
    cout << "Números ordenados: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Tiempo de ejecución: " << duracion.count() << " segundos" << endl;

    return 0;
}