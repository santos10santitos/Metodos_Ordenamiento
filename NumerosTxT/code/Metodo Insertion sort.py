import time

def insertion_sort(arr):
    n = len(arr)

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    return arr


ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt"

with open(ruta_archivo, 'r') as archivo:
    numeros = [int(num) for num in archivo.read().split()]

if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()

inicio = time.time()
numeros_ordenados = insertion_sort(numeros)
fin = time.time()
duracion = fin - inicio

print("Tiempo de ejecución:", duracion, "segundos")