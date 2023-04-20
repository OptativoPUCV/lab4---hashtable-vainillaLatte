#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap *map, char *key, void *value) {
    long codigo = hash(key, map->capacity);
    int count = 0; // Variable para rastrear cuántas casillas se han verificado

    // Bucle para buscar una casilla vacía
    while (map->buckets[codigo] != NULL && count < map->capacity) {
        // Si la clave ya existe, no insertar y salir de la función
        if (is_equal(map->buckets[codigo]->key, key)) {
            return;
        }
        codigo = (codigo + 1) % map->capacity; // Método de resolución de colisiones: lineal probing
        count++;
    }

    // Si se verificó todo el arreglo y no se encontró una casilla vacía, no insertar y salir de la función
    if (count == map->capacity) {
        return;
    }

    // Insertar el nuevo par clave-valor en la casilla vacía
    map->buckets[codigo] = createPair(key, value);
    map->current = codigo; // Actualizar el índice current
    map->size++; // Incrementar el tamaño del mapa
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap *mapa = (HashMap*)malloc(sizeof(HashMap));
  mapa->buckets = (Pair**)malloc(capacity * sizeof(Pair**));
  mapa->size = 0;
  mapa->capacity = capacity;
  mapa->current = -1;
  return mapa;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
