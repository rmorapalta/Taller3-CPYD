#include <iostream>
#include <cstdlib>
#include <fstream>
#include <omp.h>
#include "Response.h"

/** -NOTA- 
 * No se llego a poder completar el registro ordenado de los datos en los
 * archivos de salida en el codigo secuencial
 */




/**
 * Función que muestra los participantes del grupo
 */
void participantes() {
    std::cout << std::endl << "======Taller 03====="<<std::endl;
    std::cout << std::endl << "Andres Segarra pavez"<<std::endl;
    std::cout << std::endl << "Rodrigo Mora Palta"<<std::endl;
    std::cout << std::endl << "Luis Rivas Sanchez"<<std::endl;
}



#define LEADER 0
#define READ_TASK 13
#define WRITE_TASK 17 
/**
*taller computacional
*@param argc cantidad de argumentos
*@param argv argumentos
*@return El codigo de salida del programa
*/
int main(int argc, char** argv) {
    
    if (argc > 1) {
        int count=0; // contador
        std::ifstream csv(argv[1]);
        string ruta = argv[1];
        bool isCSV = false;
        isCSV = validar_formato(ruta, isCSV);
        if (csv.is_open()) {
            //saltarse la primera linea de 
            std::string header;
            std::getline(csv, header); 
            //abrir archivo de salida
            std::ofstream outMatCsv("matematicas.csv");
             std::ofstream outCienciaCsv("ciencias.csv");
              std::ofstream outHumanCsv("humanidades.csv");
            // entrar leer el archivo
            for (std::string line; std::getline(csv, line);) { // si getline manda un ENDOFILE, se cierra el ciclo
                Response response(line);
                rellenar(count); // se va rellenando el array auxiliar
                int count=cont++;
                int auxizq=0;
                auxder=line.size()-1;
                // quedarian organizados cada vez que se lee los datos de mayor a menor, hasta los 17 millones
                quicksortMat(line,auxizq,auxder);
                //if (count>=999999){}
                
            }
            // se ingresarian los primeros un millon de datos ya ordenados por quicksortmat
            for(int i = 0; i < 999999 ; i++){
                outMatCsv << response.GetResultMat() << std::endl; // momento de llenar el excel resultado
            }    
            for(int i = 0; i < 999999 ; i++){
                outCienciaCsv << response.GetResultCiencia() << std::endl;
            }    
            for(int i = 0; i < 999999 ; i++){
                outHumanCsv << response.GetResultHuman() << std::endl;
            }    
            outMatCsv.close();
            outCienciaCsv.close();
            outHumanCsv.close();    
        }
        csv.close();
    } else {
        // Mostrar los integrantes
        participantes();
    }
    return EXIT_SUCCESS;
}

