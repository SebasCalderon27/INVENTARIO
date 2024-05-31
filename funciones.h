
#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int cantidad;
    float precio;
} Producto;

extern Producto inventario[MAX_PRODUCTOS];
extern int num_productos;

void ingresarProducto();
void listarProductos();
void editarProducto();
void eliminarProducto();

#endif
