// ... (structs y buscarUsuario igual)
void realizarDeposito(Usuario *u) {
    float monto;
    printf("Monto a depositar: ");
    scanf("%f", &monto);
    u->saldo += monto;
    printf("Nuevo saldo: %.2f\n", u->saldo);
}

int main() {
    // ... (login anterior)
    int idx = buscarUsuario(usuarios, 2, uIn, pIn);
    if(idx != -1) {
        int op;
        do {
            printf("\n1. Saldo\n2. Depositar\n4. Salir\nOpcion: ");
            scanf("%d", &op);
            if(op == 1) printf("Saldo: %.2f\n", usuarios[idx].saldo);
            if(op == 2) realizarDeposito(&usuarios[idx]);
        } while(op != 4);
    }
    return 0;
}