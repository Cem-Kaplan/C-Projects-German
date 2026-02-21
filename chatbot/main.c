#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void showMenu();
void checkInput();
void showTime();

int main() {
    
    showMenu(); 
    
    while (true) {
        checkInput();
    }

    return 0;
}

void showMenu() {
    showTime();
}

void checkInput() {
    char aktueller_input[100];
    scanf("%99s", &aktueller_input);
    if (strcmp(aktueller_input, "time") == 0) {
        showTime();
    } else {
        printf("Keine Passende Antwort\n");
    }
}

void showTime() {
    time_t jetzt_unformatiert = time(NULL);
    char *jetzt = ctime(&jetzt_unformatiert);
    
    printf("%s\n", jetzt);
}