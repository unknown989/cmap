#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define ERROR -1
#define SUCCESS 0

typedef struct
{
    char **keys;
    char **values;
    size_t length; // How many elements are in the map
    size_t size;   // Size of the whole map
} Map;

void init(Map *map);
void map_realloc(Map *map);
int append(Map *map, char *key, char *value);
char *get(Map *, char *key);
int get_index(Map *map, char *key);
int pop(Map *map, char *key);

void init(Map *map)
{
    map->keys = (char **)malloc(1 * 1 * 100);   // Size of Char * Size of Char * 100 Elements
    map->values = (char **)malloc(1 * 1 * 100); // Size of Char * Size of Char * 100 Elements
    map->length = 0;
    map->size = sizeof(map);
}

void map_realloc(Map *map)
{
    map->keys = (char **)realloc(map->keys, 1 * 1 * 100);
    map->values = (char **)realloc(map->values, 1 * 1 * 100);
}

int append(Map *map, char *key, char *value)
{
    if (get_index(map, key) > -1)
    {
        printf("ERROR: the key '%s' already exist in the map\n", key);
        return ERROR;
    }
    if (map->size + (strlen(key) + strlen(value)) >= map->size)
    {
        map_realloc(map);
    }
    map->keys[map->length] = key;
    map->values[map->length] = value;
    map->length++;
    map->size = sizeof(map);
    return 0;
}

char *get(Map *map, char *key)
{
    for (size_t i = 0; i < map->length; i++)
    {
        if (strcmp(map->keys[i], key) == 0)
        {
            return map->values[i];
        }
    }
    return NULL;
}

int get_index(Map *map, char *key)
{
    for (size_t i = 0; i < map->length; i++)
    {
        if (strcmp(map->keys[i], key) == 0)
        {
            return i;
        }
    }
    return ERROR;
}

int pop(Map *map, char *key)
{
    int index = get_index(map, key);

    if (index == ERROR)
    {
        printf("ERROR: the key '%s' is not found in the map\n", key);
        return 1;
    }

    map->keys[index] = NULL;
    map->values[index] = NULL;

    for (size_t i = index; i < map->length; i++)
    {
        if (i + 1 >= map->length)
        {
            break;
        }
        map->keys[i] = map->keys[i + 1];
        map->values[i] = map->values[i + 1];
    }
    map->length--;

    map->size = sizeof(map);

    return SUCCESS;
}

int update(Map *map, char *key, char *new_value)
{
    int index = get_index(map, key);
    if (index == -1)
    {
        printf("ERROR: can't update key '%s' because it is not a part of the map\n", key);
    }

    map->values[index] = new_value;
}

#endif
