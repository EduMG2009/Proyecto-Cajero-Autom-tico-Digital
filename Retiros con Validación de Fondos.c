void realizarRetiro(Usuario *u) {
    float monto;
    printf("Monto a retirar: ");
    scanf("%f", &monto);
    if(monto <= u->saldo) {
        u->saldo -= monto;
        printf("Retiro exitoso.\n");
    } else {
        printf("Fondos insuficientes.\n");
    }
}

// ... En el main, añadir la opción 3 al menú y al switch/if