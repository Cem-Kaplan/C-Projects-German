#include "stdio.h"
#include "stdbool.h"
#include "stddef.h"
#include "string.h"

char map[1][9] = {
    {"."}, {"."}, {"."},
    {"."}, {"."}, {"."},
    {"."}, {"."}, {"."},
};

int laenge = sizeof(map[1]) / sizeof(map[1][0]);

void print_map() {

    printf("%i", &laenge); // ist 9

    for (int feld_nr = 0; feld_nr < laenge; feld_nr++) {
        printf("%c", &map[0][feld_nr]);
        switch (feld_nr) {
            case 2|| 5 || 8:
                printf("\n");
        }
    }
}

void check_on_map(int nr) {
    if (!map[0][nr]) {
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
            printf("Kein input\n");
        } else {
            printf("Input Vorhanden\n");
            print_map();
            check_on_map(1);
        }
    }
    return 0;
}

