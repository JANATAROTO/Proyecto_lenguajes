#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;

using namespace std;

class menu {
public:
	int agregarusuario() {
        string login_password;
        string login_username;

        fstream pull("C:\\TMP\\users.txt", ios::app);
        if (!pull) {
            cout << "no se pudo abrir el archivo" << endl;
            return -1;
        };

      cout << "agregue el usuario: " << endl;
      cin >> login_username;
      login_username = "user:" + login_username +"\n";
      pull << login_username;

      cout << "agregar contraseña: " << endl;
      cin >> login_password;
      login_password = "password:" + login_password + "\n";
      pull << login_password;
      cout << "Usuario Agregado correctamente" << endl;
      pull.close();
	}

    int eliminarusuario() {
        string login_username;
        string stored_username;
        string loging_password;
        string stored_password;
        string file;
        fstream pull("C:\\TMP\\users.txt");
        if (!pull) {
            cout << "no se pudo abrir el archivo" << endl;
            return -1;
        };

        cout << "escribir el usuario: " << endl;
        cin >> login_username;
        login_username = "user:" + login_username;


        std::ifstream input("C:\\TMP\\users.txt");
        std::stringstream sstr;

        while (input >> sstr.rdbuf());

        file = sstr.str() ;

        int position = 0;
        while ((position = file.find(login_username)) != std::string::npos) {
            file.replace(position, login_username.length(), "");
        }
        
   
        cout << "escribir la contraseña: " << endl;
        cin >> loging_password;
        loging_password = "password:" + loging_password;
        position = 0;

        while ((position = file.find(loging_password)) != std::string::npos) {
            file.replace(position, loging_password.length(), "");
        }

        //graba en el archivo
        ofstream out("C:\\TMP\\users.txt");
        out << file;
        cout << "se ha eliminado correctamente la cuenta... " << endl;
        input.close();
        pull.close();

    }
    int listarusuarios() {
        string stored_username;
        string userLine="user:";
        

        fstream pull("C:\\TMP\\users.txt", ios::in);
        if (!pull) {
            cout << "no se pudo abrir el archivo" << endl;
            return -1;
        };
        cout << "la lista de usuarios registrados es: " << endl;
        while (!pull.eof())
        {
           
            pull >> stored_username;
            if (stored_username.find(userLine) != std::string::npos) {
                cout << stored_username << endl;
            }
        }
        pull.close();
        return 1;

    }
    int buscarusuario() {

        string login_password;
        string stored_password;
        string login_username;
        string stored_username;
        bool existeUsuario=false;
        bool existePassword=false;
        fstream pull("C:\\TMP\\users.txt", ios::in);
        if (!pull) {
            cout << "no se pudo abrir el archivo" << endl;
            return -1;
        }
        cout << "Username: ";
        cin >> login_username;
        login_username = "user:" + login_username;
        cout << "Password: ";
        cin >> login_password;
        login_password = "password:" + login_password;
        while (!pull.eof())

        {
            pull >> stored_username;

            if (stored_username== login_username) {
                existeUsuario = true;
              
           }
            if (login_password == stored_username)
            {
                existePassword = true;
            }
           
        }
       if (!existeUsuario) {
           cout << "Username does not exist. " << endl;
           return -1;
       }

        if(!existePassword)
        {
            cout << "Wrong password. " << endl;
            cout << "Try again: ";
         
        }
        else
        {
            cout << "Login successful." << endl;
        }
     
       
        pull.close();
        return 0;
	}

};