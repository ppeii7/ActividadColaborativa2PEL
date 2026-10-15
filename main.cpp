#include <iostream>
#include <string>

#include "Usuario.h"
#include "Estudiante.h"
#include "Profesor.h"
#include "Fichero.h"
#include "Matriz.h"
#include "CalculadoraAvanzada.h"

// ---------------------------------------------------------------- usuarios

Usuario* buscarUsuario(ListaGenerica<Usuario*>& listaUsuarios, const std::string& id) {
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId() == id) {
            return u;
        }
    }
    return nullptr;
}

// Devuelve el estudiante si el id existe y es de estudiante; si no, nullptr
Estudiante* buscarEstudiante(ListaGenerica<Usuario*>& listaUsuarios, const std::string& id) {
    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u != nullptr && u->getId()[0] == 'E') return static_cast<Estudiante*>(u);
    return nullptr;
}

// Libera un usuario eligiendo el tipo real por la letra del id (sin destructor virtual)
void liberarUsuario(Usuario* u) {
    if (u == nullptr) return;
    switch (u->getId()[0]) {
        case 'E': delete static_cast<Estudiante*>(u); break;
        case 'P': delete static_cast<Profesor*>(u); break;
        default:  delete u; break;
    }
}

void liberarTodos(ListaGenerica<Usuario*>& listaUsuarios) {
    for (int i = 1; i <= listaUsuarios.getLength(); i++) liberarUsuario(listaUsuarios.at(i));
}

std::string generarId(char rol, int& contador) {
    std::string num = std::to_string(contador++);
    while (num.size() < 4) num = "0" + num;
    return std::string(1, rol) + num;
}

// true si algun profesor ya tiene a ese estudiante en su clase
bool estudianteTieneProfesor(ListaGenerica<Usuario*>& listaUsuarios, const std::string& idEstudiante) {
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId()[0] == 'P') {
            if (static_cast<Profesor*>(u)->tieneEstudiante(idEstudiante)) return true;
        }
    }
    return false;
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
        return;
    }

    int tipo = 0;
    std::cout << "Tipo de usuario:" << std::endl;
    std::cout << "1. Estudiante" << std::endl;
    std::cout << "2. Profesor" << std::endl;
    std::cout << "3. Administrador" << std::endl;
    std::cout << "Opcion: ";
    std::cin >> tipo;

    if (tipo < 1 || tipo > 3) {
        std::cout << "Tipo no valido." << std::endl;
        return;
    }

    std::string nombre, apellido;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido: ";
    std::cin >> apellido;

    Usuario* nuevo = nullptr;
    switch (tipo) {
        case 1: nuevo = new Estudiante(generarId('E', contadorId), nombre, apellido); break;
        case 2: nuevo = new Profesor(generarId('P', contadorId), nombre, apellido); break;
        case 3: nuevo = new Usuario(generarId('A', contadorId), nombre, apellido); break;
    }

    if (!listaUsuarios.add(nuevo)) {
        liberarUsuario(nuevo);
        std::cout << "No se pudo dar de alta." << std::endl;
    } else {
        std::cout << "Alta correcta. Id: " << nuevo->getId() << std::endl;
    }
}

void darBajaUsuario(ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id;
    std::cout << "Id a dar de baja: ";
    std::cin >> id;

    if (id[0] == 'A') {
        std::cout << "No se puede dar de baja a un administrador." << std::endl;
        return;
    }

    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr && u->getId() == id) {
            // 1) limpiar referencias (si es profesor, su clase se destruye con el)
            if (id[0] == 'E') quitarEstudianteDeTodasLasClases(listaUsuarios, id);
            // 2) sacar de la lista   3) liberar
            listaUsuarios.remove(i);
            liberarUsuario(u);
            std::cout << "Baja realizada." << std::endl;
            return;
        }
    }
    std::cout << "Usuario no encontrado." << std::endl;
}

void modificarUsuario(ListaGenerica<Usuario*>& listaUsuarios) {
    std::string id, nombre, apellido;
    std::cout << "Id del usuario: ";
    std::cin >> id;

    Usuario* u = buscarUsuario(listaUsuarios, id);
    if (u == nullptr) {
        std::cout << "Usuario no encontrado." << std::endl;
        return;
    }

    std::cout << "Nuevo nombre: ";
    std::cin >> nombre;
    std::cout << "Nuevo apellido: ";
    std::cin >> apellido;
    u->setNombre(nombre);
    u->setApellido(apellido);
    std::cout << "Usuario modificado." << std::endl;
}

void listarUsuarios(ListaGenerica<Usuario*>& listaUsuarios) {
    if (listaUsuarios.getLength() == 0) {
        std::cout << "No hay usuarios." << std::endl;
        return;
    }
    for (int i = 1; i <= listaUsuarios.getLength(); i++) {
        Usuario* u = listaUsuarios.at(i);
        if (u != nullptr) {
            std::cout << u->getId() << " " << u->getNombre() << " " << u->getApellido() << std::endl;
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
        return;
    }
    for (int i = 1; i <= profesor->getNumEstudiantes(); i++) {
        Estudiante* estudiante = buscarEstudiante(listaUsuarios, profesor->getIdEstudiante(i));
        if (estudiante != nullptr) {
            std::cout << estudiante->getNombre() << " " << estudiante->getApellido() << std::endl;
            estudiante->mostrarNotas();
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

// -------------------------------------------------------------- estudiante

void cargarFicheroEstudiante(Estudiante* estudiante) {
    std::string ruta;
    std::cout << "Ruta del fichero .txt: ";
    std::cin >> ruta;

    Fichero fichero(ruta);                       // por valor: sin new
    if (!fichero.estaCargado()) {
        std::cout << "No se pudo leer el fichero." << std::endl;
        return;
    }
    if (estudiante->cargarFichero(fichero)) {
        std::cout << "Fichero cargado." << std::endl;
    } else {
        std::cout << "Mochila llena." << std::endl;
    }
}

void verMochila(Estudiante* estudiante) {
    if (estudiante->getNumFicheros() == 0) {
        std::cout << "Mochila vacia." << std::endl;
        return;
    }
    for (int i = 1; i <= estudiante->getNumFicheros(); i++) {
        std::cout << i << ". " << estudiante->getFichero(i).getRuta() << std::endl;
    }
}

void verContenidoFichero(Estudiante* estudiante) {
    int pos;
    std::cout << "Numero de fichero: ";
    std::cin >> pos;
    if (pos < 1 || pos > estudiante->getNumFicheros()) {
        std::cout << "Fichero no valido." << std::endl;
        return;
    }
    std::cout << estudiante->getFichero(pos).getContenido() << std::endl;
}

// -------------------------------------------------------------------- menus

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
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: altaUsuario(listaUsuarios, contadorId); break;
            case 2: darBajaUsuario(listaUsuarios); break;
            case 3: modificarUsuario(listaUsuarios); break;
            case 4: listarUsuarios(listaUsuarios); break;
            case 5: {
                CalculadoraAvanzada<double> calc;
                break;
            }
            case 6: std::cout << "Cerrando sesion..." << std::endl; break;
            default: std::cout << "Opcion no valida." << std::endl; break;
        }
    } while (opcion != 6);
}

void menuProfesor(Profesor* profesor, ListaGenerica<Usuario*>& listaUsuarios) {
    int opcion = 0;
    do {
        std::cout << "Bienvenido profesor " << profesor->getNombre() << std::endl;
        std::cout << "1. Ver datos de mi clase" << std::endl;
        std::cout << "2. Ver notas de estudiantes" << std::endl;
        std::cout << "3. Anadir estudiante a mi clase" << std::endl;
        std::cout << "4. Eliminar estudiante de mi clase" << std::endl;
        std::cout << "5. Calculadora" << std::endl;
        std::cout << "6. Cerrar sesion" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: verDatosClase(profesor, listaUsuarios); break;
            case 2: verNotasEstudiantes(profesor, listaUsuarios); break;
            case 3: anadirEstudianteAClase(profesor, listaUsuarios); break;
            case 4: eliminarEstudianteDeClase(profesor); break;
            case 5: {
                CalculadoraAvanzada<double> calc;
                break;
            }
            case 6: std::cout << "Cerrando sesion..." << std::endl; break;
            default: std::cout << "Opcion no valida." << std::endl; break;
        }
    } while (opcion != 6);
}

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
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: estudiante->mostrarNotas(); break;
            case 2: cargarFicheroEstudiante(estudiante); break;
            case 3: verMochila(estudiante); break;
            case 4: verContenidoFichero(estudiante); break;
            case 5: {
                CalculadoraAvanzada<double> calc;
                break;
            }
            case 6: std::cout << "Cerrando sesion..." << std::endl; break;
            default: std::cout << "Opcion no valida." << std::endl; break;
        }
    } while (opcion != 6);
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
        return;
    }

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

int main() {
    ListaGenerica<Usuario*> listaUsuarios;
    int contadorId = 2;                                  // A0000 y P0001 ya usados

    Usuario* admin = new Usuario("A0000", "Admin", "");
    if (!listaUsuarios.add(admin)) liberarUsuario(admin);
    Profesor* profesor1 = new Profesor("P0001", "Jorge", "Garcia");
    if (!listaUsuarios.add(profesor1)) liberarUsuario(profesor1);

    printMenuPrincipal(listaUsuarios, contadorId);

    liberarTodos(listaUsuarios);                         // siempre al final
    return 0;
}