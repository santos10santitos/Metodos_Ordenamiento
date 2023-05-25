import random
rango_inicial = 1
rango_final = 100
num_elementos = 100000
numeros_aleatorios = random.choices(range(rango_inicial, rango_final + 1), k=num_elementos)
ruta_archivo = "/Users/PC/Desktop/100000numeros.txt"
with open(ruta_archivo, "w") as archivo:
    archivo.write(" ".join(map(str, numeros_aleatorios)))
print("Archivo generado exitosamente.")