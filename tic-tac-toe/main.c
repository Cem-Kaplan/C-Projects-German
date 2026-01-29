#include "stdio.h"
#include "stdbool.h"
#include "stddef.h"
#include "string.h"

char map[9][1] = {
    {}, {}, {},
    {}, {}, {},
    {}, {}, {},
};

int laenge = sizeof(map) / sizeof(map[1][0]);

void print_map() {

    printf("array länge: %i\n", laenge); // ist 9

    for (int feld_nr = 0; feld_nr < laenge; feld_nr++) {
        printf("%c", &map[feld_nr][0]);
        switch (feld_nr) {
            case 2:
                printf("\n");
            case 5:
                printf("\n");
            case 8:
                printf("\n");
        }
    }
}

void check_on_map(int nr) {
    if (!map[nr][0]) {
        printf("gültig");
    } else {
        printf("ungültig, schon belegt");
    }
}   

int main() {
    printf("tic-tac-toe geladen\n");
    
    bool running = true;

    while (running) {
        int aktuelle_auswahl;
        scanf("%d", &aktuelle_auswahl);
        
        if (!aktuelle_auswahl) {
            printf("Bitte eine zahl\n");
            break;
        } else {
            printf("Input Vorhanden\n");
            print_map();
            check_on_map(1);
        }
    }
    return 0;
}

