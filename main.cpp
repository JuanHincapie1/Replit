#include <iostream>
#include <fstream>
#include <unordered_map>

/*
  La idea principal del programa es abrir un archivo de texto, leerlo caracter por caracter,   contar la frecuencia de cada caracter y luego imprimir un histograma que muestra cuántas     veces aparece cada caracter en el archivo. Esto se logra utilizando un std::unordered_map    para almacenar el recuento de cada caracter.
*/

int main() {
    // Pedir al usuario el nombre del archivo
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo de texto: ";
    std::cin >> nombreArchivo;

    // Abrir el archivo
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;  // Salir del programa con código de error 1
    }

    // Crear un mapa para almacenar el histograma de caracteres
    std::unordered_map<char, int> histograma;

    char caracter;
    // Leer cada caracter del archivo
    while (archivo.get(caracter)) {
        // Filtrar caracteres imprimibles
        if (isprint(caracter)) {
            // Incrementar la frecuencia del caracter en el histograma
            histograma[caracter]++;
        }
    }

    // Cerrar el archivo después de leerlo
    archivo.close();

    // Imprimir el histograma de caracteres
    std::cout << "Histograma de caracteres:" << std::endl;
    for (const auto& par : histograma) {
        std::cout << "'" << par.first << "': " << par.second << " veces" << std::endl;
    }

    return 0;  // Salir del programa con código de éxito
}

