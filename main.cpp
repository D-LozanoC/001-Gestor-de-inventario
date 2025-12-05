#include <iostream>
#include <iomanip>
#include "Inventory.h"

using std::cin;
using std::cout;
using std::left;
using std::setw;
using std::string;

void showHeader();
void userMenu();
void showMenu();
void printProductHeader();
void wait();
void info(const string &msg);
void ok(const string &msg);
void warn(const string &msg);
void error(const string &msg);

int main()
{
    showHeader();
    userMenu();

    return 0;
}

void userMenu()
{
    Inventory i;
    i.loadFromFile("./data/products.csv");
    bool f = true;
    while (f)
    {
        int opt{};
        showMenu();
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            system("cls");
            printProductHeader();

            const std::map<int, Product> &m = i.list();
            for (auto &it : m)
            {
                cout << it.second << '\n';
            }
            wait();

            break;
        }
        case 2:
        {
            cout << "delete\n";
            break;
        }
        case 3:
        {
            cout << "modify\n";
            break;
        }
        case 4:
        {
            cout << "find\n";
            break;
        }
        case 5:
        {
            cout << "list\n";
            break;
        }
        case 6:
        {
            info("Información");
            ok("Productos guardados con éxito.");
            warn("Warning");
            error("Error mortal.");
            f = false;
            break;
        }
        default:
            break;
        }
    }
}

void showHeader()
{
    system("cls");
    const string cyan = "\033[36m";
    const string reset = "\033[0m";

    string titulo = "Bienvenido(a) al Gestor de Inventarios";
    string proyecto = "Proyecto 001";

    int ancho = 50;
    int pad1 = (ancho - titulo.size()) / 2;
    int pad2 = (ancho - proyecto.size()) / 2;

    cout << "\n";
    cout << cyan;
    cout << string(ancho, '=') << "\n";
    cout << string(pad1, ' ') << titulo << "\n";
    cout << string(pad2, ' ') << proyecto << "\n";
    cout << string(ancho, '=') << "\n\n";
    cout << reset;
    wait();
}

void wait()
{
    cout << "\n\033[33mPresione ENTER para continuar...\033[0m";

    if (cin.peek() == '\n')
        cin.get();

    string temp;
    getline(cin, temp);
}

void showMenu()
{
    system("cls");

    const string green = "\033[32m";
    const string reset = "\033[0m";

    cout << green;
    cout << "----------------- MENU PRINCIPAL -----------------\n";
    cout << left << setw(5) << "1." << "Agregar producto\n";
    cout << left << setw(5) << "2." << "Eliminar producto\n";
    cout << left << setw(5) << "3." << "Modificar producto\n";
    cout << left << setw(5) << "4." << "Buscar producto\n";
    cout << left << setw(5) << "5." << "Listar productos\n";
    cout << left << setw(5) << "6." << "Guardar cambios\n";
    cout << left << setw(5) << "7." << "Salir\n";
    cout << "--------------------------------------------------\n";
    cout << reset;

    cout << "Seleccione una opcion: ";
}

void printProductHeader()
{
    const int w_id = 7;
    const int w_name = 18;
    const int w_cat = 13;
    const int w_qty = 8;
    const int w_price = 8;

    cout << left << "\033[36m"
         << setw(w_id) << "  ID" << " | "
         << setw(w_name) << "NAME" << " | "
         << setw(w_cat) << "CATEGORY" << " | "
         << setw(w_qty) << "QTY" << " | "
         << setw(w_price) << "PRICE" << " |\n";

    cout << string(w_id, '-') << "-+-"
         << string(w_name, '-') << "-+-"
         << string(w_cat, '-') << "-+-"
         << string(w_qty, '-') << "-+-"
         << string(w_price, '-') << "-+\n";
}

void info(const string &msg) { cout << "\033[36m[INFO]\033[0m " << msg << "\n"; }
void ok(const string &msg) { cout << "\033[32m[OK]\033[0m " << msg << "\n"; }
void warn(const string &msg) { cout << "\033[33m[WARN]\033[0m " << msg << "\n"; }
void error(const string &msg) { cout << "\033[31m[ERROR]\033[0m " << msg << "\n"; }