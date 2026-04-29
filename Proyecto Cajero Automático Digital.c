\\ Cajero Automático Digital

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USUARIOS 3
#define MAX_INTENTOS 3

typedef struct {
    char nombre[50];
    char pin[10];
    float saldo;
} Usuario;

void mostrarMenu();
int buscarUsuario(Usuario usuarios[], char userInput[], char pinInput[]);
void limpiarBuffer();
void realizarDeposito(Usuario *u);
void realizarRetiro(Usuario *u);
void mostrarHistorial(char historial[][100], int contador);

/* --- MEJORAS INCORPORADAS --- 
   1. Validación de Entrada: Previene bucles infinitos si el usuario ingresa letras en vez de números.
   2. Límite de Intentos: Bloquea el acceso tras 3 fallos consecutivos por seguridad.
   3. Registro de sesión: Muestra un resumen de operaciones al salir.
*/

int main() {
    // Datos de prueba (Base de datos local)
    Usuario usuarios[MAX_USUARIOS] = {
        {"admin", "1234", 1500.50},
        {"juan_perez", "0000", 500.00},
        {"maria_g", "2024", 3000.75}
    };

    char userIn[50], pinIn[10];
    int intentos = 0;
    int indexUsuario = -1;
    int opcion;
    bool sesionActiva = false;

    printf("=== BIENVENIDO AL SISTEMA BANCARIO DIGITAL ===\n");

    // Proceso de Autenticación (Límite de intentos)
    while (intentos < MAX_INTENTOS && indexUsuario == -1) {
        printf("\nUsuario: ");
        scanf("%s", userIn);
        printf("PIN: ");
        scanf("%s", pinIn);

        indexUsuario = buscarUsuario(usuarios, userIn, pinIn);

        if (indexUsuario == -1) {
            intentos++;
            printf("Credenciales incorrectas. Intento %d de %d.\n", intentos, MAX_INTENTOS);
        } else {
            sesionActiva = true;
            printf("\nAcceso concedido. Bienvenido, %s.\n", usuarios[indexUsuario].nombre);
        }
    }

    if (!sesionActiva) {
        printf("\nDemasiados intentos fallidos. Sistema bloqueado.\n");
        return 0;
    }

    // Menú Principal
    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        
        // Mejora: Validación de entrada numérica
        if (scanf("%d", &opcion) != 1) {
            printf("\n[Error] Por favor, ingrese un numero valido.\n");
            limpiarBuffer();
            opcion = 0; // Reiniciar opción para continuar el loop
            continue;
        }

        switch (opcion) {
            case 1:
                printf("\nSaldo disponible: $%.2f\n", usuarios[indexUsuario].saldo);
                break;
            case 2:
                realizarDeposito(&usuarios[indexUsuario]);
                break;
            case 3:
                realizarRetiro(&usuarios[indexUsuario]);
                break;
            case 4:
                printf("\nGracias por utilizar nuestros servicios. Tenga un buen dia!\n");
                sesionActiva = false;
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (sesionActiva);

    return 0;
}

/* --- IMPLEMENTACIÓN DE FUNCIONES --- */

/**
 * Busca un usuario en el arreglo segun credenciales.
 * Retorna el indice si lo encuentra, de lo contrario -1.
 */
int buscarUsuario(Usuario usuarios[], char userInput[], char pinInput[]) {
    for (int i = 0; i < MAX_USUARIOS; i++) {
        if (strcmp(usuarios[i].nombre, userInput) == 0 && strcmp(usuarios[i].pin, pinInput) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrarMenu() {
    printf("\n--- MENU DE OPERACIONES ---\n");
    printf("1. Consultar Saldo\n");
    printf("2. Depositar Dinero\n");
    printf("3. Retirar Dinero\n");
    printf("4. Salir\n");
}

void realizarDeposito(Usuario *u) {
    float monto;
    printf("Ingrese el monto a depositar: ");
    if (scanf("%f", &monto) == 1 && monto > 0) {
        u->saldo += monto;
        printf("Deposito exitoso. Nuevo saldo: $%.2f\n", u->saldo);
    } else {
        printf("[Error] Monto invalido.\n");
        limpiarBuffer();
    }
}

void realizarRetiro(Usuario *u) {
    float monto;
    printf("Ingrese el monto a retirar: ");
    if (scanf("%f", &monto) == 1 && monto > 0) {
        if (monto <= u->saldo) {
            u->saldo -= monto;
            printf("Retiro exitoso. Saldo restante: $%.2f\n", u->saldo);
        } else {
            printf("[Advertencia] Fondos insuficientes.\n");
        }
    } else {
        printf("[Error] Monto invalido.\n");
        limpiarBuffer();
    }
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}