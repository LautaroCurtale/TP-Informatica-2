#include "conf.h"

int main(){
	parametros_t config;
	estados_t estado = puentecerrado;
	estados_t (*pf[])(parametros_t)={f_puentecerrado, f_abriendo, f_cerrando, f_senalalerta, f_puenteabierto};
	config= f_set();
	while(1) estado = (*pf[estado])(config);
	return 0;
}


