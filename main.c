#include "map.h"
#include <stdio.h>

int main()
{
    Map map;

    init(&map);
    append(&map, "Brian", "Polier");
    append(&map, "John", "Doe");
    append(&map, "Doe", "Oiul");
    printf("%s : %s\n", "Brian", get(&map, "Brian"));
    printf("%s : %s\n", "John", get(&map, "John"));
    printf("%s : %s\n", "Doe", get(&map, "Doe"));
    pop(&map, "Brian");
    append(&map, "Brian", "Polier");
    update(&map, "Doe", "Oil");

    return 0;
}