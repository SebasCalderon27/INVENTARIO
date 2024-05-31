#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

Producto inventario[MAX_PRODUCTOS];
int num_productos = 0;

void ingresarProducto();
void listarProductos();
void editarProducto();
void eliminarProducto();

int main() {
    int opcion;
    do {
        printf("\n***** Sistema de Inventarios *****\n");
        printf("***** 1. Ingresar producto    *****\n");
        printf("***** 2. Listar productos     *****\n");
        printf("***** 3. Editar producto      *****\n");
        printf("***** 4. Eliminar producto    *****\n");
        printf("***** 5. Salir                *****\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                listarProductos();
                break;
            case 3:
                editarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                printf("Saliendo del sistema.\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 5);

    return 0;
}

void ingresarProducto() {
    if (num_productos >= MAX_PRODUCTOS) {
        printf("El inventario está lleno.\n");
        return;
    }

    printf("Ingresar nombre del producto: ");
    scanf("%s", inventario[num_productos].nombre);
    printf("Ingresar cantidad del producto: ");
    scanf("%d", &inventario[num_productos].cantidad);
    printf("Ingresar precio del producto: ");
    scanf("%f", &inventario[num_productos].precio);

    num_productos++;
    printf("Producto ingresado correctamente.\n");
}

void listarProductos() {
    if (num_productos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("Lista de productos:\n");
    for (int i = 0; i < num_productos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", inventario[i].nombre);
        printf("  Cantidad: %d\n", inventario[i].cantidad);
        printf("  Precio: %.2f\n", inventario[i].precio);
    }
}

void editarProducto() {
    int index;
    printf("Ingrese el índice del producto a editar (1-%d): ", num_productos);
    scanf("%d", &index);

    if (index < 1 || index > num_productos) {
        printf("Índice inválido.\n");
        return;
    }

    index--;  // Ajustar para índice basado en 0

    printf("Editar nombre del producto (actual: %s): ", inventario[index].nombre);
    scanf("%s", inventario[index].nombre);
    printf("Editar cantidad del producto (actual: %d): ", inventario[index].cantidad);
    scanf("%d", &inventario[index].cantidad);
    printf("Editar precio del producto (actual: %.2f): ", inventario[index].precio);
    scanf("%f", &inventario[index].precio);

    printf("Producto editado correctamente.\n");
}

void eliminarProducto() {
    int index;
    printf("Ingrese el índice del producto a eliminar (1-%d): ", num_productos);
    scanf("%d", &index);

    if (index < 1 || index > num_productos) {
        printf("Índice inválido.\n");
        return;
    }

    index--;  // Ajustar para índice basado en 0

    for (int i = index; i < num_productos - 1; i++) {
        inventario[i] = inventario[i + 1];
    }

    num_productos--;
    printf("Producto eliminado correctamente.\n");
}
