import time

def counting_sort(arr):
    max_value = max(arr)
    min_value = min(arr)
    range_value = max_value - min_value + 1

    count = [0] * range_value

    for num in arr:
        count[num - min_value] += 1

    sorted_arr = []
    for i in range(range_value):
        while count[i] > 0:
            sorted_arr.append(i + min_value)
            count[i] -= 1

    return sorted_arr

ruta_archivo = "/Users/PC/Documents/TRABAJOPRACTICA/NumerosTxT/Numeros ramdon/8000numeros.txt"

numeros = []
with open(ruta_archivo, 'r') as archivo:
    for linea in archivo:
        numeros.extend([int(num) for num in linea.split() if num.strip().isdigit()])

if not numeros:
    print("El archivo no contiene números válidos para ordenar.")
    exit()

inicio = time.time()
numeros_ordenados = counting_sort(numeros)
fin = time.time()
duracion = fin - inicio

print("Números ordenados:", numeros_ordenados)
print("Tiempo de ejecución:", duracion, "segundos")