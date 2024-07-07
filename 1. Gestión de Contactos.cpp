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
//                                          FUNCIONES PARA OPCION DEL MENU
// 1.FUNCION PARA AGREGAR UN CONTACTO:
void Agregar_contacto(){
	if(contacto_n < nmax_contactos){
		
		cout<<"\n        Ha seleccionado la opcion 1    "<<endl;
		cout<<"           Agregar un contacto         "<<endl;
				
		Contacto_email cont;
		cin.ignore(); //limpia el buffer 
			
		cout<< "\n    NUEVO CONTACTO  "<<endl,
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
		cout<< "No es posible agregar mas contactos , se alcanzo el limite\n";
	}
}

// 2.FUNCION PARA ELIMINAR UN CONTACTO

// 3.MOSTRAR LISTADO GENERAL DE CONTACTOS

// 4.MOSTRAR LISTADO DE CONTACTOS EXISTENTES , ORDENADO POR SERVIDOR DE CORREOS 
		
// 5.FUNCION PARA MOSTRAR EL MENU DE OPCIONES 
int mostrar_menu(){
	int opcion;
	cout << "----- MENÚ -----" << endl;
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
			    //Eliminar_un_contacto();
			    break;
			    
			case 3:
				// LLAMAMOS A : MOSTRAR LISTADO GENERAL DE CONTACTOS
			    //Mostrar_listado_general_de_contactos_registrados();
			    break;
			    
			case 4:
				// LLAMAMOS A : MOSTRAR LISTADO DE CONTACTOS EXISTENTES , ORDENADO POR SERVIDOR DE CORREOS 
				//Mostrar_listado_de_contactos_existentes();
				break;
				
			case 5:
				cout<<"\nSaliendo del programa ..."<<endl;
				break;
			
			default:
				cout<<"\nOpcion no valida , intentelo de nuevo por favor"<<endl;
				
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
	