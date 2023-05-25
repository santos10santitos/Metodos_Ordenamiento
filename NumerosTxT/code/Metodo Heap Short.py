import time

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[i] < arr[left]:
        largest = left

    if right < n and arr[largest] < arr[right]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

    return arr

ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt"

numeros = []
with open(ruta_archivo, 'r') as archivo:
    linea = archivo.readline()
    numeros = [int(num) for num in linea.split() if num.strip().isdigit()]

if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()

inicio = time.time()
numeros_ordenados = heap_sort(numeros)
fin = time.time()
duracion = fin - inicio

print("Números ordenados:", numeros_ordenados)
print("Tiempo de ejecución:", duracion, "segundos")