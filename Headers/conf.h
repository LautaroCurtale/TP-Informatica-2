#ifndef CONF_H
#define CONF_H
#include <stdio.h>
#include <string.h>

typedef enum {
  puentecerrado = 0,
  abriendo = 1,
  cerrando = 2,
  senalalerta = 3,
  puenteabierto = 4,
}estados_t;

typedef struct {
  unsigned int auto_entra;
  unsigned int auto_sale;
  unsigned int barco_entra;
  unsigned int barco_sale;
  unsigned int altura_barco;
  unsigned int altura_maxima;
  unsigned int puente;
  unsigned int alarma; //señal
}parametros_t;

char* f_getvariable (char*);
parametros_t f_set(void);
estados_t f_puentecerrado(parametros_t);
estados_t f_abriendo(parametros_t);
estados_t f_cerrando(parametros_t);
estados_t f_senalalerta(parametros_t);
estados_t f_puenteabierto(parametros_t);
unsigned int emulacionauto1 (void); //Para emular el ingreso de autos
unsigned int emulacionauto2 (void); //Para emular el egreso de autos
unsigned int emulacionbarco1 (void); //Para emular el ingreso de barcos
unsigned int emulacionbarco2 (void); //Para emular el egreso de barcos
unsigned int emulacionbarcoaltura (void); //Para emular la medicion de altura

#endif
