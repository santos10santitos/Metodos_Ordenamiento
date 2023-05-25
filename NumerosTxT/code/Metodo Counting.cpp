#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    int max_value = *max_element(arr.begin(), arr.end());
    int min_value = *min_element(arr.begin(), arr.end());

    int range = max_value - min_value + 1;

    vector<int> count(range, 0);

    for (int i = 0; i < n; i++) {
        count[arr[i] - min_value]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index] = i + min_value;
            count[i]--;
            index++;
        }
    }
}

int main() {

    string ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/50000numeros.txt";

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
    countingSort(numeros);
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