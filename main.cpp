#include <iostream>
#include <string>

#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Fichero.h"
#include "Matriz.h"
#include "CalculadoraAvanzada.h"

/* Ficheros de ejemplo:
 *   ../ficheros/apuntesBiologia.txt
 *   ../ficheros/apuntesFisica.txt
 *   ../ficheros/apuntesHistoria.txt
 *   ../ficheros/apuntesLiteratura.txt
 *
 *  Usuarios activados de ejemplo:
 *  Admin: A0000
 *  Profesor: P0001
 *  Estudiante: E0001
 */

static bool fin = false;

// ------------ CALCULADORA --------------

Matriz<double> leerMatriz(const std::string& nombre) {
    int filas, columnas;
    std::cout << "--- Datos de la Matriz " << nombre << " ---" << std::endl;
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    Matriz<double> m(filas, columnas);
    for (int i = 1; i <= filas; i++) {
        for (int j = 1; j <= columnas; j++) {
            double valor;
            std::cout << "Valor [" << i << "][" << j << "]: ";
            std::cin >> valor;
            m.modMatriz(i, j, valor);
        }
    }
    return m;
}

void printMenuCalculadora() {
    CalculadoraAvanzada<double> calc;
    calc.mostrarUsos(); // Muestra las capacidades al abrir la calculadora

    int opcion = 0;
    do {
        std::cout << "\nMENU CALCULADORA" << std::endl;
        std::cout << "1. Sumar numeros" << std::endl;
        std::cout << "2. Restar numeros" << std::endl;
        std::cout << "3. Multiplicar numeros" << std::endl;
        std::cout << "4. Dividir numeros" << std::endl;
        std::cout << "5. Sumar matrices" << std::endl;
        std::cout << "6. Restar matrices" << std::endl;
        std::cout << "7. Multiplicar matrices" << std::endl;
        std::cout << "8. Determinante matriz" << std::endl;
        std::cout << "9. Trasponer matriz" << std::endl;
        std::cout << "10. Salir de calculadora" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                double num1, num2;
                std::cout << "Escribe el primer numero: "; std::cin >> num1;
                std::cout << "Escribe el segundo numero: "; std::cin >> num2;
                std::cout << "Resultado: " << calc.suma(num1, num2) << std::endl;
                break;
            }
            case 2: {
                double num1, num2;
                std::cout << "Escribe el primer numero: "; std::cin >> num1;
                std::cout << "Escribe el segundo numero: "; std::cin >> num2;
                std::cout << "Resultado: " << calc.resta(num1, num2) << std::endl;
                break;
            }
            case 3: {
                double num1, num2;
                std::cout << "Escribe el primer numero: "; std::cin >> num1;
                std::cout << "Escribe el segundo numero: "; std::cin >> num2;
                std::cout << "Resultado: " << calc.multiplica(num1, num2) << std::endl;
                break;
            }
            case 4: {
                double num1, num2;
                std::cout << "Escribe el dividendo: "; std::cin >> num1;
                std::cout << "Escribe el divisor: "; std::cin >> num2;
                if (num2 != 0) {
                    std::cout << "Resultado: " << calc.division(num1, num2) << std::endl;
                } else {
                    std::cout << "Error: No se puede dividir entre cero." << std::endl;
                }
                break;
            }
            case 5: {
                Matriz<double> m1 = leerMatriz("1");
                Matriz<double> m2 = leerMatriz("2");
                Matriz<double> res = calc.sumaMatriz(m1, m2);
                std::cout << "Resultado de la Suma:" << std::endl;
                res.printMatriz();
                break;
            }
            case 6: {
                Matriz<double> m1 = leerMatriz("1");
                Matriz<double> m2 = leerMatriz("2");
                Matriz<double> res = calc.restaMatriz(m1, m2);
                std::cout << "Resultado de la Resta:" << std::endl;
                res.printMatriz();
                break;
            }
            case 7: {
                Matriz<double> m1 = leerMatriz("1");
                Matriz<double> m2 = leerMatriz("2");
                Matriz<double> res = calc.multiplicaMatriz(m1, m2);
                std::cout << "Resultado de la Multiplicacion:" << std::endl;
                res.printMatriz();
                break;
            }
            case 8: {
                Matriz<double> m = leerMatriz("A");
                double det = calc.determinante(m);
                // Si la matriz no es cuadrática, la función determinante ya imprime un mensaje y devuelve 0.
                if (m.getFilas() == m.getColumnas()) {
                    std::cout << "Determinante: " << det << std::endl;
                }
                break;
            }
            case 9: {
                Matriz<double> m = leerMatriz("A");
                Matriz<double> res = calc.traspuesta(m);
                std::cout << "Matriz Traspuesta:" << std::endl;
                res.printMatriz();
                break;
            }
            case 10:
                std::cout << "Saliendo de la calculadora..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 10);
}

// ---------------------------------------------------------------- usuarios

Usuario* buscarUsuario(ListaGenerica<Usuario*>& listaUsuarios, const std::string& id) {
    Usuario* aux = nullptr;
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
         Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId() == id) {
            aux = u;
        }
    }
    return aux;
}

// Devuelve el estudiante si el id existe y es de estudiante; si no, nullptr
Estudiante* buscarEstudiante(ListaGenerica<Usuario*>& listaUsuarios, const std::string& id) {
    Estudiante* aux = nullptr;
    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u != nullptr && u->getId()[0] == 'E') {
        aux = static_cast<Estudiante*>(u);
    }
    return aux;
}

// Libera un usuario eligiendo el tipo real por la letra del id (sin destructor virtual)
void liberarUsuario(Usuario* u) {
    if (u != nullptr)
    switch (u->getId()[0]) {
        case 'E':
            delete static_cast<Estudiante*>(u);
            break;
        case 'P':
            delete static_cast<Profesor*>(u);
            break;
        default:
            delete u;
            break;
    }
}

void liberarTodos(ListaGenerica<Usuario*>& listaUsuarios) {
    for (int i = 1; i <= listaUsuarios.getLength(); i++) liberarUsuario(listaUsuarios.at(i));
}

std::string generarId(char rol, int& contador) {
    std::string num = std::to_string(contador++);
    while (num.size() < 4) {
        num = "0" + num;
    }
    return std::string(1, rol) + num;
}

// true si algun profesor ya tiene a ese estudiante en su clase
bool estudianteTieneProfesor(ListaGenerica<Usuario*>& listaUsuarios, const std::string& idEstudiante) {
    bool retorno = false;
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId()[0] == 'P') {
            if (static_cast<Profesor*>(u)->tieneEstudiante(idEstudiante)) {
                retorno = true;
            }
        }
    }
    return retorno;
}


void quitarEstudianteDeTodasLasClases(ListaGenerica<Usuario*>& listaUsuarios, const std::string& idEstudiante) {
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId()[0] == 'P') {
            static_cast<Profesor*>(u)->quitarEstudiante(idEstudiante);
        }
    }
}

void altaUsuario(ListaGenerica<Usuario*>& listaUsuarios, int& contadorId) {
    if (listaUsuarios.estaLlena()) {
        std::cout << "No caben mas usuarios." << std::endl;

    } else {
        int tipo = 0;
        std::cout << "Tipo de usuario:" << std::endl;
        std::cout << "1. Estudiante" << std::endl;
        std::cout << "2. Profesor" << std::endl;
        std::cout << "3. Administrador" << std::endl;
        std::cout << "Opcion: ";
        do  {
            std::cin >> tipo;
            if (tipo < 1 || tipo > 3) {
            std::cout << "Tipo no valido." << std::endl;
            }
        } while (tipo < 1 || tipo > 3);


        std::string nombre, apellido;
        std::cout << "Nombre: ";
        std::cin >> nombre;
        std::cout << "Apellido: ";
        std::cin >> apellido;

        Usuario* nuevo = nullptr;
        switch (tipo) {
            case 1:
                nuevo = new Estudiante(generarId('E', contadorId), nombre, apellido);
                break;
            case 2:
                nuevo = new Profesor(generarId('P', contadorId), nombre, apellido);
                break;
            case 3:
                nuevo = new Usuario(generarId('A', contadorId), nombre, apellido);
                break;
        }

        if (!listaUsuarios.add(nuevo)) {
            liberarUsuario(nuevo);
            std::cout << "No se pudo dar de alta." << std::endl;
        } else {
            std::cout << "Alta correcta. Id: " << nuevo->getId() << std::endl;
        }
    }
}

void darBajaUsuario(ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id;
    std::cout << "Id a dar de baja: ";
    std::cin >> id;

    if (id[0] == 'A') {
        std::cout << "No se puede dar de baja a un administrador." << std::endl;

    } else {
        bool usuarioEncontrado = false;

        for (int i = 1; i <= listaUsuarios.getLength(); i++) {
            Usuario* u = listaUsuarios.at(i);
            if (u != nullptr && u->getId() == id) {
                // 1) limpiar referencias (si es profesor, su clase se destruye con el)
                if (id[0] == 'E') {
                    quitarEstudianteDeTodasLasClases(listaUsuarios, id);
                }
                // 2) sacar de la lista   3) liberar
                listaUsuarios.remove(i);
                liberarUsuario(u);
                usuarioEncontrado = true;
            }
        }
        if (usuarioEncontrado == false) {
            std::cout << "Usuario no encontrado." << std::endl;
        } else {
            std::cout << "Baja realizada." << std::endl;
        }
    }
}

void modificarUsuario(ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id, nombre, apellido;
    std::cout << "Id del usuario: ";
    std::cin >> id;

    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u == nullptr) {
        std::cout << "Usuario no encontrado." << std::endl;
    } else {
        std::cout << "Nuevo nombre: ";
        std::cin >> nombre;
        std::cout << "Nuevo apellido: ";
        std::cin >> apellido;
        u->setNombre(nombre);
        u->setApellido(apellido);
        std::cout << "Usuario modificado." << std::endl;
    }
}

void listarUsuarios(ListaGenerica<Usuario*>& listaUsuarios) {
    if (listaUsuarios.getLength() == 0) {
        std::cout << "No hay usuarios." << std::endl;

    } else {
        for (int i = 1; i <= listaUsuarios.getLength(); i++) {
            Usuario* u = listaUsuarios.at(i);
            if (u != nullptr) {
                std::cout << u->getId() << " " << u->getNombre() << " " << u->getApellido() << std::endl;
            }
        }
    }
}

// ---------------------------------------------------------------- profesor

void verDatosClase(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    std::cout << "Inscritos: " << profesor->getNumEstudiantes() << std::endl;
    for (int i = 1; i <= profesor->getNumEstudiantes(); i++) {
        Estudiante* estudiante = buscarEstudiante(listaUsuarios, profesor->getIdEstudiante(i));
        if (estudiante != nullptr) {
            std::cout << estudiante->getId() << " " << estudiante->getNombre()
                      << " " << estudiante->getApellido() << std::endl;
        }
    }
}

void verNotasEstudiantes(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    if (profesor->getNumEstudiantes() == 0) {
        std::cout << "No tienes estudiantes." << std::endl;
    } else {
        for (int i = 1; i <= profesor->getNumEstudiantes(); i++) {
            Estudiante* estudiante = buscarEstudiante(listaUsuarios, profesor->getIdEstudiante(i));
            if (estudiante != nullptr) {
                std::cout << estudiante->getNombre() << " " << estudiante->getApellido() << std::endl;
                estudiante->mostrarNotas();
            }
        }
    }
}

void anadirEstudianteAClase(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id;
    std::cout << "Id del estudiante: ";
    std::cin >> id;

    Estudiante* estudiante = buscarEstudiante(listaUsuarios, id);
    if (estudiante == nullptr) {
        std::cout << "Estudiante no encontrado." << std::endl;
    } else if (estudianteTieneProfesor(listaUsuarios, id)) {
        std::cout << "Ese estudiante ya pertenece a una clase." << std::endl;
    } else if (!profesor->inscribirEstudiante(id)) {
        std::cout << "La clase esta llena." << std::endl;
    } else {
        std::cout << "Estudiante inscrito." << std::endl;
    }
}

void eliminarEstudianteDeClase(Profesor* profesor) {
    std::string id;
    std::cout << "Id del estudiante: ";
    std::cin >> id;

    if (profesor->quitarEstudiante(id)) {
        std::cout << "Estudiante eliminado de la clase." << std::endl;
    } else {
        std::cout << "Ese estudiante no esta en tu clase." << std::endl;
    }
}

void anadirNotaAEstudiante(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id;
    std::cout << "Id del estudiante: ";
    std::cin >> id;

    // 1. El main solo se encarga de buscar el estudiante en la base de datos global
    Estudiante* estudiante = buscarEstudiante(listaUsuarios, id);
    if (estudiante == nullptr) {
        std::cout << "Estudiante no encontrado en el sistema." << std::endl;
        return;
    }

    std::string asignatura;
    double nota;
    std::cout << "Nombre de la asignatura: ";
    std::cin >> asignatura;
    std::cout << "Nota (0-10): ";
    std::cin >> nota;

    // 2. La lógica de negocio y validación se encapsula en la clase Profesor
    if (profesor->calificarEstudiante(estudiante, asignatura, nota)) {
        std::cout << "Nota anadida correctamente al estudiante " << estudiante->getNombre() << "." << std::endl;
    } else {
        std::cout << "Error: El estudiante no esta en tu clase o la nota es invalida." << std::endl;
    }
}


// -------------------------------------------------------------- estudiante

void cargarFicheroEstudiante(Estudiante* estudiante) {
    std::string ruta;
    std::cout << "Ruta del fichero .txt: ";
    std::cin >> ruta;

    Fichero fichero(ruta);
    if (!fichero.estaCargado()) {
        std::cout << "No se pudo leer el fichero." << std::endl;
    } else {
        if (estudiante->cargarFichero(fichero)) {
            std::cout << "Fichero cargado." << std::endl;
        } else {
            std::cout << "Mochila llena." << std::endl;
        }
    }
}

void verMochila(Estudiante* estudiante) {
    if (estudiante->getNumFicheros() == 0) {
        std::cout << "Mochila vacia." << std::endl;
    } else {
        for (int i = 1; i <= estudiante->getNumFicheros(); i++) {
            std::cout << i << ". " << estudiante->getFichero(i).getRuta() << std::endl;
        }
    }
}

void verContenidoFichero(Estudiante* estudiante) {
    int pos;
    std::cout << "Numero de fichero: ";
    std::cin >> pos;
    if (pos < 1 || pos > estudiante->getNumFicheros()) {
        std::cout << "Fichero no valido." << std::endl;
    } else {
        std::cout << estudiante->getFichero(pos).getContenido() << std::endl;
    }
}


// ------------------- Menu Admin ------------------------------

void menuAdministrator(ListaGenerica<Usuario*>& listaUsuarios, int& contadorId) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido administrador " << std::endl;
        std::cout << "1. Alta de usuario" << std::endl;
        std::cout << "2. Baja de usuario" << std::endl;
        std::cout << "3. Modificar usuario" << std::endl;
        std::cout << "4. Listar usuarios" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                altaUsuario(listaUsuarios, contadorId);
                break;
            case 2:
                darBajaUsuario(listaUsuarios);
                break;
            case 3:
                modificarUsuario(listaUsuarios);
                break;
            case 4:
                listarUsuarios(listaUsuarios);
                break;
            case 5: {
                printMenuCalculadora();
                break;
            }
            case 6:
                std::cout << "Cerrando sesion..." << std::endl;
                break;
            case 7:
                std::cout << "Saliendo..." << std::endl;
                fin = true;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 6 && opcion != 7);
}

// ------------- Menu Profesor ---------------


void menuProfesor(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    int opcion = 0;
    do {
        std::cout << "\nBienvenido profesor " << profesor->getNombre() << std::endl;
        std::cout << "1. Ver datos de mi clase" << std::endl;
        std::cout << "2. Ver notas de estudiantes" << std::endl;
        std::cout << "3. Anadir estudiante a mi clase" << std::endl;
        std::cout << "4. Eliminar estudiante de mi clase" << std::endl;
        std::cout << "5. Anadir nota a un estudiante" << std::endl; // NUEVA OPCIÓN
        std::cout << "6. Calculadora" << std::endl;
        std::cout << "7. Cerrar sesion" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                verDatosClase(profesor, listaUsuarios);
                break;
            case 2:
                verNotasEstudiantes(profesor, listaUsuarios);
                break;
            case 3:
                anadirEstudianteAClase(profesor, listaUsuarios);
                break;
            case 4:
                eliminarEstudianteDeClase(profesor);
                break;
            case 5:
                anadirNotaAEstudiante(profesor, listaUsuarios); // LLAMADA A LA NUEVA FUNCIÓN
                break;
            case 6: {
                printMenuCalculadora();
                break;
            }
            case 7:
                std::cout << "Cerrando sesion..." << std::endl;
                break;
            case 8:
                std::cout << "Saliendo..." << std::endl;
                fin = true;
                break; // Añadido el break faltante en la lógica original
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    } while (opcion != 7 && opcion != 8); // Actualizada la condición de salida
}

// -------- Menu Estudiante ------------

void menuEstudiante(Estudiante* estudiante) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido estudiante " << estudiante->getNombre() << std::endl;
        std::cout << "1. Ver mis notas" << std::endl;
        std::cout << "2. Cargar fichero en la mochila" << std::endl;
        std::cout << "3. Ver mi mochila" << std::endl;
        std::cout << "4. Ver contenido de un fichero" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                estudiante->mostrarNotas();
                break;
            case 2:
                cargarFicheroEstudiante(estudiante);
                break;
            case 3:
                verMochila(estudiante);
                break;
            case 4:
                verContenidoFichero(estudiante);
                break;
            case 5: {
                printMenuCalculadora();
                break;
            }
            case 6:
                std::cout << "Cerrando sesion..." << std::endl;
                break;

            case 7:
                std::cout << "Saliendo..." << std::endl;
                fin = true;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;


        }
    } while (opcion != 6 && opcion != 7);
}



void printMenuPrincipal(ListaGenerica<Usuario*>& listaUsuarios, int& contadorId) {
    std::cout << "MENU PRINCIPAL" << std::endl;
    std::cout << "============================" << std::endl;

    std::string id;
    std::cout << "Ingrese su id: " << std::endl;
    std::cin >> id;
    int opcion = 0;

    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u == nullptr) {
        std::cout << "Usuario no encontrado." << std::endl;
    } else {

        if (u->getId()[0] == 'A') {
            opcion = 1;
        } else if (u->getId()[0] == 'P') {
            opcion = 2;
        } else if (u->getId()[0] == 'E') {
            opcion = 3;
        }

        switch (opcion) {
            case 1:
                menuAdministrator(listaUsuarios, contadorId);
                break;
            case 2:
                menuProfesor(static_cast<Profesor*>(u), listaUsuarios);
                break;
            case 3:
                menuEstudiante(static_cast<Estudiante*>(u));
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
                break;
        }
    }
}

int main() {
    ListaGenerica<Usuario*> listaUsuarios;
    int contadorId = 2;                                  // A0000 y P0001 ya usados

    Usuario* admin = new Usuario("A0000", "Admin", "");
    if (!listaUsuarios.add(admin)) {
        liberarUsuario(admin);
    }
    Profesor* profesor1 = new Profesor("P0001", "Jorge", "Garcia");
    if (!listaUsuarios.add(profesor1)) {
        liberarUsuario(profesor1);
    }
    Estudiante* estudiante1 = new Estudiante("E0001", "Pepe", "Mora");
    if (!listaUsuarios.add(estudiante1)) {
        liberarUsuario(estudiante1);
    }
    while (fin==false) {
        printMenuPrincipal(listaUsuarios, contadorId);
    }
    liberarTodos(listaUsuarios);                         // siempre al final
    return 0;
}

/* Ficheros de ejemplo:
 *   ../ficheros/apuntesBiologia.txt
 *   ../ficheros/apuntesFisica.txt
 *   ../ficheros/apuntesHistoria.txt
 *   ../ficheros/apuntesLiteratura.txt
 *
 *  Usuarios activados de ejemplo:
 *  Admin: A0000
 *  Profesor: P0001
 *  Estudiante: E0001
 */