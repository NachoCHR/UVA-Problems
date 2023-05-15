# autor: tadhikari
# fuente: https://github.com/tadhikari/Kattis-Programming-Problem-Solutions/blob/master/Adding%20Words/addingwords.py

from sys import stdin # importa stdin para los datos de entrada.

data = {} # define un diccionario vacio.

def assign(line,data): # funcion que toma como entrada una linea de texto y el diccionario.
    data[line[1]] = line[2] # Asigna el valor de la variable (el segundo elemento de la linea) al nombre de la variable (primer elemento de la linea) en el diccionario data.

def calc(line,data): # funcion que recibe una linea y el diccionario data.
    temp = '' # cadena vacia que contendra la operacion aritmetica que se va a evaluar.
    for i in line: # se itera a traves de cada caracter de la linea, a excepcion de '+', '-' y '='
        if i!='+' and i!='-' and i!='=': # Se verifica que lo que se esta leyendo sea distinto de los caracteres '+','-' y '='
            if data.get(i)!=None: # si la variable esta definida en el diccionario agrega el valor correspondiente a temp
                temp+=data.get(i)
            else:
                return "unknown" # sino esta definida devuelve unknown
        else:
            temp+=i # si el caracter es un operador, se agrega a la cadena temp
    inv_mapping = {v:k for k,v in data.items()} # se crea un diccionario inverso a partir del diccionario data intercambiando las claves y los valores. Este diccionario se utiliza para encontrar la clave correspondiente a un determinado valor.
    final = inv_mapping.get(str(eval(temp[:-1]))) # se evalua la cadena 'temp[:-1]' que contiene la operacion aritmetica sin el signo '=' al final. se utiliza la funcion eval de python. El resultado anterior es convertido a cadena usando la funcion str() y se utiliza para buscar la variable correspondiente al diccionario inverso 'inv_mapping'
    if final == None: # si la variable correspondiente se encuentra en 'inv_mapping' devuelve el nombre de la variable, de lo contrario retorna unknown
        return "unknown"
    else:
        return final

for line in stdin.readlines(): # Se lee la entrada 
    words = line.split() # se divide cada linea en una lista de palabras. Se ocupa la funcion split para esto.
    if words[0] == 'def': # si la primera palabrea es def, se llama a la funcion assign que se encarga de asignar una variable con un valor.
        assign(words,data)
    elif words[0] == 'calc': # si la primera palabra es calc, se llama a ala funcion calc con la linea y el diccionario data. luego se imprime el resultado en la consola. 
        print("{} = {}".format(line[5:-2],calc(words[1:],data)))
    elif words[0] == 'clear': # si la primera palabra es clear, elimina el contenido de data.
        data = {}