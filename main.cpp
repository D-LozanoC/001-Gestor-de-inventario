#include <iostream>
#include "Inventory.h"

using std::cin;
using std::cout;

int main()
{
    Inventory i;
    cout << "Proyecto 001\n\nBienvenido al gestor de inventario\n";
    bool f = true;

    while (f)
    {
        int opt{};
        cout << "De una instrucción\n1. Agregar producto\n2. Eliminar producto\n3. Modificar producto\n4. Buscar producto\n5. Listar productos\n6. Guardar y salir\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "add\n";
            break;
        case 2:
            cout << "delete\n";
            break;
        case 3:
            cout << "modify\n";
            break;
        case 4:
            cout << "find\n";
            break;
        case 5:
            cout << "list\n";
            break;
        case 6:
            f = false;
            break;
        default:
            break;
        }
    }
    return 0;
}