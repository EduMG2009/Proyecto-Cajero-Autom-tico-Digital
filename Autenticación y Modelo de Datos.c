#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char pin[10];
    float saldo;
} Usuario;

int buscarUsuario(Usuario usuarios[], int n, char user[], char pin[]) {
    for(int i = 0; i < n; i++) {
        if(strcmp(usuarios[i].nombre, user) == 0 && strcmp(usuarios[i].pin, pin) == 0) return i;
    }
    return -1;
}

int main() {
    Usuario usuarios[2] = {{"admin", "1234", 1000.0}, {"user1", "0000", 500.0}};
    char uIn[50], pIn[10];
    
    printf("=== BIENVENIDO AL SISTEMA BANCARIO DIGITAL ===\n");
    printf("Usuario: "); scanf("%s", uIn);
    printf("PIN: "); scanf("%s", pIn);

    if(buscarUsuario(usuarios, 2, uIn, pIn) != -1) {
        printf("Acceso concedido.\n");
    } else {
        printf("Acceso denegado.\n");
    }
    return 0;
}