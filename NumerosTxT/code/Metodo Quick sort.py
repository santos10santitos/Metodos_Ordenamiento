import time

def quick_sort(arr):
    if len(arr) <= 1:
        return arr

    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + middle + quick_sort(right)

ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/60000numeros.txt"


with open(ruta_archivo, 'r') as archivo:
    numeros = [int(num) for num in archivo.read().split()]


if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()

inicio = time.time()
numeros_ordenados = quick_sort(numeros)
fin = time.time()
duracion = fin - inicio


print("Números ordenados:", numeros_ordenados)
print("Tiempo de ejecución:", duracion, "segundos")