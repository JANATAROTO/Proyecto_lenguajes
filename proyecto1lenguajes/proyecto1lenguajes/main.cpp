#include <cstring>
#include <iostream>
#include <fstream>
#include "menu.cpp"
using namespace std;

int main()
{

    int opt;
    cout << "escoja una opcion: " << endl;
    cout << "precione 1 para ingresar un nuevo usuario" << endl;
    cout << "precione 2 para buscar un usuario existente" << endl;
    cout << "precione 3 para eliminar un usuario existente" << endl;
    cout << "precione 4 para mostrar lista de usuarios" << endl;
    cout << "precione 0 para salir" << endl;

    
    menu opciones;
    do
    {
        cin >> opt;
        switch (opt)
        {
        case 0:
            cout << "ADIOS..." << endl;
            break;
        case 1:
            opciones.agregarusuario();
            break;
        case 2:
            opciones.buscarusuario();
            break;
        case 3:
            opciones.eliminarusuario();
            break;
        case 4:
            opciones.listarusuarios();
            break;

        default: 
            cout << "opcion invalida" << endl;

            break;
        }

    } while (opt != 0);



}