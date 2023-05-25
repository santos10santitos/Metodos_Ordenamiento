import time

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    middle = len(arr) // 2
    left = merge_sort(arr[:middle])
    right = merge_sort(arr[middle:])

    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result

ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/80000numeros.txt"

with open(ruta_archivo, 'r') as archivo:
    numeros = [int(num) for num in archivo.read().split()]

if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()

inicio = time.time()
numeros_ordenados = merge_sort(numeros)
fin = time.time()
duracion = fin - inicio

print("Números ordenados:", numeros_ordenados)
print("Tiempo de ejecución:", duracion, "segundos")