# Proyecto: Cajero Automático Digital (C)

Sistema de simulación de cajero automático desarrollado en lenguaje C. Permite la gestión de cuentas mediante autenticación y operaciones financieras básicas.

## Funcionalidades
- **Autenticación Segura:** Acceso mediante usuario y PIN.
- **Consulta de Saldo:** Visualización inmediata del saldo actual.
- **Depósitos:** Incremento del saldo de la cuenta.
- **Retiros:** Deducción de fondos con validación de saldo suficiente.
- **Mejoras de Seguridad:** Límite de 3 intentos de acceso y validación de tipos de datos de entrada.

## Compilación y Ejecución

Para compilar el programa, asegúrese de tener un compilador de C (como GCC) instalado.

1. **Compilar:**
   ```bash
   gcc cajero.c -o cajero
