#include "map.h"
#include <stdio.h>

int main()
{
    Map map;

    init(&map); // Initiating the map (very important)
    append(&map, "Brian", "Polier");
    append(&map, "John", "Doe");
    append(&map, "Doe", "Oiul");
    printf("%s : %s\n", "Brian", get(&map, "Brian"));
    printf("%s : %s\n", "John", get(&map, "John"));
    printf("%s : %s\n", "Doe", get(&map, "Doe"));
    pop(&map, "Brian"); // Removing an element "Brian"
    append(&map, "Brian", "Polier");    // Adding an element
    update(&map, "Brian", "NotPolier"); // Updating an element "Brian" with "NotPolier"

    return 0;
}