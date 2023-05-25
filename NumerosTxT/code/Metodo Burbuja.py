import time
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt"
with open(ruta_archivo, "r") as archivo:
    numeros = archivo.read().split()
numeros = list(map(int, numeros))
inicio = time.time()
bubble_sort(numeros)
fin = time.time()
tiempo_ejecucion = fin - inicio
print("Números ordenados:", numeros)
print("Tiempo de ejecución:", tiempo_ejecucion, "segundos")