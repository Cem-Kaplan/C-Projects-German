#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int game_field[] = {
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
int game_field_length = sizeof(game_field) / sizeof(game_field[0]);

void print_field();
void get_game_input();
void start_game_loop();

int main() {
    printf("2048 geladen\n1 - Starten");

    start_game_loop();

    return EXIT_SUCCESS;
}

void start_game_loop() {
    int current_input;
    scanf("%d", &current_input);
    printf("Eingabe: %d\nW, A, S oder D eingeben um zu bewegen\n", current_input);

    for (;;) {
        print_field();
        get_game_input();
    }

}

void print_field() {
    for (int i = 0; i < game_field_length; i++) {
        printf("%d", game_field[i]);
    }
}

void get_game_input() {

}