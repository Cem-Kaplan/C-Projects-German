#include "stdio.h"
#include "stdbool.h"
#include "string.h"

void create_file() {
    char datei_name[] = "";

    while (strlen(datei_name) == 0)
    {
        scanf("%s", datei_name);
    }

    FILE *datei = fopen(datei_name, "w");

    fclose(datei);
}

int main() {
    printf("bitte name für neue textdatei eingeben\n");

    create_file();
    
    return 0;
}