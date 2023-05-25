import time

def selection_sort(arr):
    n = len(arr)
    
    for i in range(n - 1):
        min_index = i
        
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        
        arr[i], arr[min_index] = arr[min_index], arr[i]

ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/100000numeros.txt"


with open(ruta_archivo, 'r') as archivo:
    numeros = [int(numero) for numero in archivo.read().split()]


if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()


inicio = time.time()
selection_sort(numeros)
fin = time.time()
duracion = fin - inicio


print("Números ordenados:", numeros)
print("Tiempo de ejecución:", duracion, "segundos")