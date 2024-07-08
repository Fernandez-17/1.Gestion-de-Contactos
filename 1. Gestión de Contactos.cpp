/*1. Gestión de Contactos
Crear una estructura llamada contactoEmail que tenga las siguientes características: nombres completos,
sexo, edad, teléfono, email, nacionalidad
El programa debe constar de un menú que permita:
a) Agregar un contacto
b) Eliminar un contacto
c) Mostrar listado general de contactos registrados hasta ese momento.
d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,
outlook.com, yahoo.com, etc.)
e) Salir del programa
El programa debe mantenerse en ejecución continuamente hasta que usuario indique que desea salir del
mismo.*/
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
struct Contacto_email{
	string nombres_completos;
	string sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

const int nmax_contactos=50;
Contacto_email contactos[nmax_contactos];
int contacto_n=0;
//                                         FUNCIONES PARA OPCION DEL MENU
// 1.FUNCION PARA AGREGAR UN CONTACTO:
void Agregar_contacto(){
	if(contacto_n < nmax_contactos){
		
		cout<<"\n               HA SELECCIONADO LA OPCION 1        "<<endl;
		cout<<"                    AGREGAR UN CONTACTO             "<<endl;
		cout<< "___________________________________________________"<<endl;		
		Contacto_email cont;
		cin.ignore(); //limpia el buffer 
			
		cout<< "\n                    NUEVO CONTACTO             \n"<<endl,
	    cout<< "\nNombre completo: ";
		getline(cin,cont.nombres_completos);
		
	    cout<< "\nSexo: ";
		getline(cin,cont.sexo);
		
		cout<< "\nEdad: ";
		cin >>cont.edad;
		
		cin.ignore(); // Limpia el buffer de entrada
		
		cout<< "\nTelefono: ";
		getline(cin,cont.telefono);
		
		cout<< "\nEmail: ";
		getline(cin,cont.email);
		
		cout<< "\nNacionalidad: ";
		getline(cin,cont.nacionalidad);
		
		contactos[contacto_n++] =cont ;
		
		cout<< "\nContacto agregado exitosamente.\n";
	}else{
		cout<< "\nNo es posible agregar mas contactos , se alcanzo el limite\n";
	}
}

// 2.FUNCION PARA ELIMINAR UN CONTACTO
void Eliminar_contacto(){
	cout << "\n             HA SELECCIONADO LA OPCION 2          "<<endl;
	cout << "                ELIMINAR UN CONTACTO                "<<endl;
	cout << "____________________________________________________"<<endl;
	
	if ( contacto_n==0) {
		cout<< "\n No se encontro este contacto, intentelo de nuevo.\n";
		return ;
	}
	
	cout << "\n                  CONTACTO A ELIMINAR           \n"<<endl;
	string eliminar_contacto;
	cout << "\n Ingrese la dirrecion email del contacto que desea eliminar \n";
	cout << "\nDireccion email: ";
	cin  >> eliminar_contacto;
	
	bool encontrado = false ;
	for ( int i = 0 ; i < contacto_n ; i++ ){
		if (contactos[i].email == eliminar_contacto){
			encontrado = true;
			contactos[i] = contactos[contacto_n - 1];
            contacto_n--;
            cout << "\nContacto eliminado exitosamente." << endl;
			break;
		}
	}
	
	if (!encontrado){
		cout << "\nNo se encontro ningun contacto con esa direccion email."<<endl;	
	}
}
		
		

	
// 3.MOSTRAR LISTADO GENERAL DE CONTACTOS
void Mostrar_listado(){
	cout << "\n             HA SELECCIONADO LA OPCION 3            "<<endl;
	cout << "          MOSTRAR LISTADO GENERAL DE CONTACTOS        "<<endl;
	cout << "______________________________________________________"<<endl;
	
	cout << "\n          LISTA   GENERAL  DE  CONTACTOS          \n"<<endl;
	for( int i=0 ; i < contacto_n ; i++){
		cout<< "CONTACTO "<< i +1 <<":\n"<<endl,
		cout<< "Nombre completo   : "<<contactos[i].nombres_completos<<endl;
		cout<< "Sexo              : "<<contactos[i].sexo<<endl;
		cout<< "Edad              : "<<contactos[i].edad<<endl;
		cout<< "Telefono          : "<<contactos[i].telefono<<endl;
		cout<< "Email             : "<<contactos[i].email<<endl;
		cout<< "Nacionalidad      : "<<contactos[i].nacionalidad<<endl,
		cout<< "---------------------------------------------------"<<endl;
	}
}

// 4.MOSTRAR LISTADO DE CONTACTOS EXISTENTES , ORDENADO POR SERVIDOR DE CORREOS 

            // FUNCION PARA OBTENER SERVIDOR DE CORREO 
string obtener_servidor_correo(const string& email) {
    size_t pos = email.find('@');
    if (pos != string::npos) {
        return email.substr(pos + 1);
    }
    return ""; // En caso de que el correo no tenga '@'  se  retorna una cadena vacia
}

            // FUNCION  PARA ORDENAR CONTACTOS POR SU SERVIDOR DE CORREO CON METODO BURBUJA
void ordenar_contactos_por_servidor() {
    for (int i = 0; i < contacto_n - 1; ++i) {
        for (int j = 0; j < contacto_n - i - 1; ++j) {
            string servidor1 = obtener_servidor_correo(contactos[j].email);
            string servidor2 = obtener_servidor_correo(contactos[j + 1].email);
            
            // Comparar los dominios y intercambiar si están en el orden incorrecto
            if (servidor1 > servidor2) {
                Contacto_email aux = contactos[j];
                contactos[j] = contactos[j + 1];
                contactos[j + 1] = aux;
            }
        }
    }
}

              // FUNCION PARA MOSTRAR LISTA DE CONTACTOS ORDENADOS POR DOMINIO DE CORREO
void Mostrar_listado_por_servidor() {
    cout << "\n                  HA SELECCIONADO LA OPCION 4            " << endl;
    cout << "MOSTRAR LISTA DE CONTACTOS EXISTENTES ORDENADOS POR SERVIDOR DE CORREO" << endl; 
    cout << "______________________________________________________________________" << endl;
    

    // LLAMAMOS A LA FUNCION ORDENAR CONTACTO POR SERVIDOR
    ordenar_contactos_por_servidor();

    // MOSTRAMOS LOS CONTACTOS DE ACUERDO AL SERVIDOR
    cout << "\nLISTADO DE CONTACTOS ORDENADO POR SERVIDOR DE CORREO\n" << endl;
    string servidor_actual = "";
    for (int i = 0; i < contacto_n; ++i) {
    	string servidor = obtener_servidor_correo(contactos[i].email);
    	if(servidor != servidor_actual){
    		cout << "\n---------------------------------------------------" << endl;
            cout << "Servidor de correo: " << servidor << endl;
            cout << "---------------------------------------------------" << endl;
            servidor_actual = servidor;
		}
		
        cout << "Nombre completo   : " << contactos[i].nombres_completos << endl;
        cout << "Sexo              : " << contactos[i].sexo << endl;
        cout << "Edad              : " << contactos[i].edad << endl;
        cout << "Telefono          : " << contactos[i].telefono << endl;
        cout << "Email             : " << contactos[i].email << endl;
        cout << "Nacionalidad      : " << contactos[i].nacionalidad << endl;
        cout << "---------------------------------------------------" << endl;
    }
}


// 5.FUNCION PARA MOSTRAR EL MENU DE OPCIONES 
int mostrar_menu(){
	int opcion;
	cout << "----------------------------------MENÚ -----------------------------" << endl;
    cout << "1. Aregar un contacto " << endl;
    cout << "2. Eliminar un contacto" << endl;
    cout << "3. Mostrar listado general de contactos registrados hasta el momento." << endl;
    cout << "4. Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com,outlook.com, yahoo.com, etc.)" << endl;
    cout << "5. Salir " << endl;
    cout << "Ingrese el número de la opción deseada: ";
    cin >> opcion;
    return opcion;
}
	
// 6. FUNCION PRINCIPAL
int main(){
	int opcion;
	do{
		opcion = mostrar_menu();
		switch (opcion){
			case 1:
				// LLAMAMOS A : 1.FUNCION PARA AGREGAR UN CONTACTO:
			    Agregar_contacto();
			    break;
			    
			case 2:
			    // LLAMAMOS A : 2.FUNCION PARA ELIMINAR UN CONTACTO
				Eliminar_contacto();
			    break;
			    
			case 3:
				// LLAMAMOS A : MOSTRAR LISTADO GENERAL DE CONTACTOS
			    Mostrar_listado();
			    break;
			    
			case 4:
				// LLAMAMOS A : MOSTRAR LISTADO DE CONTACTOS EXISTENTES , ORDENADO POR SERVIDOR DE CORREOS 
				Mostrar_listado_por_servidor();
				break;
				
			case 5:
				cout<<"\nSaliendo del programa ..."<<endl;
				break;
			
			default:
				cout<<"\nOpcion no valida , intentelo de nuevo por favor"<<endl;
				break;
		}
				
		if (opcion != 5) {
			cout << endl;
			system("pause"); // Pausa el programa antes de mostrar nuevamente el menú
			cout <<endl;
		}
	} while (opcion != 5);
	
	getch();
	return 0;
}

	