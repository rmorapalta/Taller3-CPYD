#include <iomanip>
#include "Response.h"
#include<vector>

Response::Response() {
    this->studentToken = "";
    this->q01 = '-';
    this->q02 = '-';
    this->q03 = '-';
    this->q04 = '-';
    this->q05 = '-';
    this->q06 = '-';
    this->q07 = '-';
    this->q08 = '-';
    this->q09 = '-';
    this->q10 = '-';
    this->q11 = '-';
    this->q12 = '-';
    this->goodsMat = 0;
    this->goodsCiencia = 0;
    this->goodsHuman = 0;
    this->badsMat = 0;
    this->badsCiencia = 0;
    this->badsHuman= 0;
    this->omittedMat = 12;
    this->omittedCiencia = 12;
    this->omittedHuman = 12;
    this->scoreMat = 0.0;
    this->scoreCiencia = 0.0;
    this->scoreHuman = 0.0;
    this->puntaje = 0.0; // Valor que iria en la tercera columna de salida
    this->gradeMat = 1.0;
    this->gradeCiencia = 1.0;
    this->gradeHuman = 1.0;
    this->valid = false;
}
Response::Response(std::string line) {
    try {
        // Asumo que alerta de spoiler (sala mal)
        // LINE: "2fda1bb7-41fc-472e-a2b7-df4728aac7e4";"E";"B";"B";"E";"E";"C";"A";"D";"A";"E";"B";"E"
        this->valid = false;
        if (!line.empty()) {
            // quitar el caracter '"' de la cadena (string)
            line.erase(std::remove(line.begin(), line.end(), '"'), line.end());
            // LINE: 2fda1bb7-41fc-472e-a2b7-df4728aac7e4;E;B;B;E;E;C;A;D;A;E;B;E

            // pasar de ';' -> ' '
            std::replace(line.begin(), line.end(), ';', ' ');
            // LINE: 2fda1bb7-41fc-472e-a2b7-df4728aac7e4 E B B E E C A D A E B E

            // Pasamos la línea a un arreglo
            std::vector<std::string> columns ;
            std::stringstream ss(line);
            std::string current;
            while (ss >> current) {
                // current:  2fda1bb7-41fc-472e-a2b7-df4728aac7e4 
                columns.push_back(current);
            }

            this->studentToken = columns.at(0);
            this->q01 = columns.at(1).at(0);
            this->q02 = columns.at(2).at(0);
            this->q03 = columns.at(3).at(0);
            this->q04 = columns.at(4).at(0);
            this->q05 = columns.at(5).at(0);
            this->q06 = columns.at(6).at(0);
            this->q07 = columns.at(7).at(0);
            this->q08 = columns.at(8).at(0);
            this->q09 = columns.at(9).at(0);
            this->q10 = columns.at(10).at(0);
            this->q11 = columns.at(11).at(0);
            this->q12 = columns.at(12).at(0);

            // liberamos memoria
            columns.clear();
            //mat
            int goodSumMat = 0;
            int badSumMat = 0;
            int omittedSumMat = 0;
            //ciencias
            int goodSumCiencia = 0;
            int badSumCiencia = 0;
            int omittedSumCiencia = 0;
            //humanidades
            int goodSumHuman = 0;
            int badSumHuman = 0;
            int omittedSumHuman = 0;

            // Revisión de preguntas
            if (this->q01 == QUESTION_01) {
                goodSumMat += 1;
            } else if (this->q01 == IGNORATION) {
                omittedSumMat+= 1;
            } else {
                badSumMat+= 1;
            }

            if (this->q02 == QUESTION_02) {
                goodSumMat += 1;
            } else if (this->q02 == IGNORATION) {
                omittedSumMat += 1;
            } else {
                badSumMat += 1;
            }

            if (this->q03 == QUESTION_03) {
                goodSumMat += 1;
            } else if (this->q03 == IGNORATION) {
                omittedSumMat += 1;
            } else {
                badSumMat += 1;
            }

            if (this->q04 == QUESTION_04) {
                goodSumMat += 1;
            } else if (this->q04 == IGNORATION) {
                omittedSumMat += 1;
            } else {
                badSumMat+= 1;
            }

            if (this->q05 == QUESTION_05) {
                goodSumCiencia += 1;
            } else if (this->q05 == IGNORATION) {
                omittedSumCiencia += 1;
            } else {
                badSumCiencia += 1;
            }

            if (this->q06 == QUESTION_06) {
                goodSumCiencia += 1;
            } else if (this->q06 == IGNORATION) {
                omittedSumCiencia += 1;
            } else {
                badSumCiencia += 1;
            }

            if (this->q07 == QUESTION_07) {
                goodSumCiencia += 1;
            } else if (this->q07 == IGNORATION) {
                omittedSumCiencia += 1;
            } else {
                badSumCiencia += 1;
            }

            if (this->q08 == QUESTION_08) {
                goodSumCiencia += 1;
            } else if (this->q08 == IGNORATION) {
                omittedSumCiencia += 1;
            } else {
                badSumCiencia += 1;
            }

            if (this->q09 == QUESTION_09) {
                goodSumHuman += 1;
            } else if (this->q09 == IGNORATION) {
                omittedSumHuman += 1;
            } else {
                badSumHuman += 1;
            }

            if (this->q10 == QUESTION_10) {
                goodSumHuman += 1;
            } else if (this->q10 == IGNORATION) {
                omittedSumHuman += 1;
            } else {
                badSumHuman += 1;
            }

            if (this->q11 == QUESTION_11) {
                goodSumHuman += 1;
            } else if (this->q11 == IGNORATION) {
                omittedSumHuman += 1;
            } else {
                badSumHuman += 1;
            }

            if (this->q12 == QUESTION_12) {
                goodSumHuman += 1;
            } else if (this->q12 == IGNORATION) {
                omittedSumHuman += 1;
            } else {
                badSumHuman += 1;
            }

            // Contar las respuestas correctas/malas/incorrectas/"puntaje por area" y puntaje por materia
            this->goodsMat = goodSumMat;
            this->badsMat = badSumMat;
            this->omittedMat = omittedSumMat; 
            //suma de respeustas correctas totales, menos la maslas del area en cuestion
            this->scoreMat = (((goodSumMat+goodSumCiencia+ goodSumHuman) * GOOD_SCORE) - (badSumMat * BAD_SCORE)); //este valor seria la segunda columna del archivo de salida
            //taller 3 nunca especifica nota base 1:, por lo que se dejara de lado
            this->gradeMat = 1 + this->scoreMat;
            this->valid = true;

            this->goodsCiencia = goodSumCiencia;
            this->badsCiencia = badSumCiencia;
            this->omittedCiencia = omittedSumCiencia;
            this->scoreCiencia = (((goodSumMat+goodSumCiencia+ goodSumHuman) * GOOD_SCORE) - (badSumCiencia * BAD_SCORE));//este valor seria la segunda columna del archivo de salida
            this->gradeCiencia= 1 + this->scoreCiencia;
            this->valid = true;
            
            this->goodsHuman = goodSumHuman;
            this->badsHuman = badSumHuman;
            this->omittedHuman = omittedSumHuman;
            this->scoreHuman = (((goodSumMat+goodSumCiencia+ goodSumHuman) * GOOD_SCORE)  - (badSumHuman * BAD_SCORE));//este valor en la columna
            this->gradeHuman = 1 + this->scoreHuman;
            this->valid = true;
            //PUNTAJE, este en la tercera columna
            this->puntaje = ((goodSumMat+goodSumCiencia+ goodSumHuman) * GOOD_SCORE) - ((badSumMat+badSumCiencia+badSumHuman) * BAD_SCORE);


        }
    }catch (...) {
        std::cerr << "Error al parsear linea de entrada" << std::endl;
        Response();
    }
}

//double tablaMat[18000000];
            //tablaMat[]=tablaMat[]
// funcion para crear array con los contenidos
void rellenar(int i){
    
    tablastudentToken[i]=tablastudentToken[studentToken]; //tabla con los datos de los tokens de estudiantes
    tablaMat[i]=tablaMat[scoreMat];//tabla con los datos de las correctas de matematicas
    tablaCiencia[i]=tablaCiencia[scoreCiencia];//tabla con los datos de las correctas de ciencias
    tablaHuman[i]=tablaMat[scoreHuman];//tabla con los datos de las correctas de humanidades
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del area de matematica
int particionMat(vector<double> &values, int left, int right){
    int pivote=arreglo[inicio];
    int i= inicio+1;
    for(int j=1 ; j <=final;j++){
        swap(arreglo[i].arreglo[j]);
        i++;
    }
    swap(arreglo[inicio],arreglo[i-1]);
    return i-1;
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del area de Ciencia
int particionCiencia(vector<double> &values, int left, int right){
    int pivote=arreglo[inicio];
    int i= inicio+1;
    for(int j=1 ; j <=final;j++){
        swap(arreglo[i].arreglo[j]);
        i++;
    }
    swap(arreglo[inicio],arreglo[i-1]);
    return i-1;
}

//Funcion que retorna el indice del pivote para realizar el QuickSort del area de Humanista
int particionHuman(vector<double> &values, int left, int right){
    int pivote=arreglo[inicio];
    int i= inicio+1;
    for(int j=1 ; j <=final;j++){
        swap(arreglo[i].arreglo[j]);
        i++;
    }
    swap(arreglo[inicio],arreglo[i-1]);
    return i-1;
}

//Funcion para ordenar los datos mediante QuickSort del area de matematica
void quicksorMat(vector<double> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = particionMat(values, left, right);
        quicksortMat(values, left, pivotIndex - 1);
        quicksortMat(values, pivotIndex, right);
    }
}

//Funcion para ordenar los datos mediante QuickSort del area de Ciencia
void quicksortCiencia(vector<double> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = particionCiencia(values, left, right);
        quicksortCiencia(values, left, pivotIndex - 1);
        quicksortCiencia(values, pivotIndex, right);
    }
    values
}

//Funcion para ordenar los datos mediante QuickSort del area de Humanista
void quicksorHuman(vector<double> &values, int left, int right) {
    if(left < right) {
        int pivotIndex = particionHuman(values, left, right);
        quicksortHuman(values, left, pivotIndex - 1);
        quicksortHuman(values, pivotIndex, right);
    }
}


//funcion copia
Response::Response(const Response& orig) {
    this->studentToken = orig.studentToken;
    this->q01 = orig.q01;
    this->q02 = orig.q02;
    this->q03 = orig.q03;
    this->q04 = orig.q04;
    this->q05 = orig.q05;
    this->q06 = orig.q06;
    this->q07 = orig.q07;
    this->q08 = orig.q08;
    this->q09 = orig.q09;
    this->q10 = orig.q10;
    this->q11 = orig.q11;
    this->q12 = orig.q12;
    this->goodsMat = orig.goodsMat;
    this->goodsCiencia = orig.goodsCiencia;
    this->goodsHuman = orig.goodsHuman;
    this->badsMat = orig.badsMat;
    this->badsCiencia = orig.badsCiencia;
    this->badsHuman = orig.badsHuman;
    this->omittedMat = orig.omittedMat;
    this->omittedCiencia = orig.omittedCiencia;
    this->omittedHuman = orig.omittedHuman;
    this->scoreMat = orig.scoreMat;
    this->scoreCiencia = orig.scoreCiencia;
    this->scoreHuman = orig.scoreHuman;
    this->gradeMat = orig.gradeMat;
    this->gradeCiencia = orig.gradeCiencia;
    this->gradeHuman = orig.gradeHuman;
    this->puntaje = orig.puntaje;
    this->valid = orig.valid;
}

Response::~Response() {
}

// variable para llenar de informacion la salida
std::string Response::GetResultMat() {
    std::stringstream stream;
    // dejar puntaje con una presicion de 1 ej: 4.8
    stream << std::fixed << std::setprecision(1) << this->puntaje;
    std::string puntajeStr = stream.str();

    std::string out = "\"" + this->studentToken + "\";"
            + "\"" + std::to_string(this->scoreMat) + "\";"
        //    + "\"" + std::to_string(this->puntaje) + "\";"  //
            + "\"" + puntajeStr + "\"";
    return out;
}

std::string Response::GetResultCiencia() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << this->puntaje;
    std::string puntajeStr = stream.str();

    std::string out = "\"" + this->studentToken + "\";"
            + "\"" + std::to_string(this->scoreCiencia) + "\";"
           // + "\"" + std::to_string(this->puntaje) + "\";"
            + "\"" + puntajeStr + "\"";
    return out;
}
std::string Response::GetResultHuman() {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << this->puntaje;
    std::string puntajeStr = stream.str();

    std::string out = "\"" + this->studentToken + "\";"
            + "\"" + std::to_string(this->scoreHuman) + "\";"
          //  + "\"" + std::to_string(this->puntaje) + "\";"
            + "\"" + puntajeStr + "\"";
    return out;
}


bool Response::isValid() {
    return valid;
}

//Funcion para ordenar los datos mediante QuickSort segun el promedio general
/*
void quicksortMat(tablaMat[] values, int left, int right) {
    if(left < right) {
        int pivotIndex = partitionMat(values, left, right);
        quicksortMat(values, left, pivotIndex - 1);
        quicksortMat(values, pivotIndex, right);
    }
}

void quicksortMat(tablaMat[] values, int inicio, int final){
    if(inicio<final){
        int pivote = particionMat (tablaMat,inicio,final);
        quicksortMat(tablaMat,inicio,pivote-1);
        quicksortMat(tablaMat,pivote+1,final);
    }
}
*/

/*
struct cupos {
    double tablastudentToken[18000000];
    double tablaMat[18000000];
    double tablaCiencia[18000000];
    double tablaHuman[18000000];
};
*/
