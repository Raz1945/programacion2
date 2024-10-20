#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /* Escriba el código a continuación */
    nat dia, mes, anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /* Escriba el código a continuación */
    nuevaFecha = new rep_fecha; 
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha& fecha) {
    /************ Parte 3.3 ************/
    /* Escriba el código a continuación */
    if (fecha != NULL) {
        delete fecha;
        fecha = NULL;
    }
    /****** Fin de parte Parte 3.3 *****/
}

void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /* Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/* Escriba el código a continuación */
/* Recuerde que las funciones auxiliares deben declararse antes de ser utilizadas */

// Verifica si ese año es bisiesto o no.
    bool esBisiesto(nat anio) {
        if ((anio % 4 == 0) && ((anio % 100 != 0) || (anio % 400 == 0))) { 
            return true;
        } else {
            return false;
        }
    }

// Función para obtener la cantidad de días de un mes en un año dado
nat diasMes(nat mes, nat anio) {
    /* Precondicion: 12 >= mes >= 1 */
    nat dias;
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 2:
            if (esBisiesto(anio)) {
                dias = 29;
            } else { 
                dias = 28;
            }
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        default:
            dias = 0;  
            break;
    }
    return dias;  
}


// Función para aumentar una fecha en una cantidad dada de días
void aumentarTFecha(TFecha &fecha, nat dias) {
    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio)) {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12) {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}
/****** Fin de parte Parte 3.9 *****/
/* Si fecha1 es mayor que fecha2 retorna 1, si es menor retorna -1,
   si son iguales retorna 0 */
int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;

    /************ Parte 3.10 ************/
    /* Escriba el código a continuación */
    if (fecha1->anio > fecha2->anio) {
        res = 1;
    } else if (fecha1->anio < fecha2->anio){ 
        res = -1;
    } else {
        if (fecha1->mes > fecha2->mes){
            res = 1;
        } else if (fecha1->mes < fecha2->mes){
            res = -1;
        } else {
            if (fecha1->dia > fecha2->dia){
                res = 1;
            } else if (fecha1->dia < fecha2->dia){
                res = -1;
            } else {
                res = 0;
            }
        }
    }
    /****** Fin de parte Parte 3.10 *****/
    return res;
}
