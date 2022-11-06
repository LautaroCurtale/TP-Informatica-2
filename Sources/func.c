#include "conf.h"

char* f_getvariable (char* variable){
    char i=0;
    while(*(variable+i)!=' ' && *(variable+i)!='=')
        i++;
    *(variable+i)='\0';
    return variable+i+1;
}

parametros_t f_inicio (void){
    FILE *conf;
    parametros_t datos_i;
    char cadena[20],*variable,*valor,i,aux;
    char variables[20]= {"altura_maxima"};
    datos_i.configuracion=0;
    datos_i.altura_maxima=0;
    if((conf=fopen("config.conf","rb"))==NULL){
    	printf("No se encontro el archivo de configuracion.")
        return datos_i;
    }
    do{
        fgets(cadena,20,conf);
        variable=cadena;
        if((*variable)!='#' && strlen(variable)>=0){
            valor=f_getvariable(variable);
            aux=atoi(valor);
			if(!strcmp(variable,variables)){
                for(i=0;i<aux+1;i++)
                   	datos_i.altura_maxima=datos_i.altura_maxima+(1<<i);
                	datos_i.altura_maxima=~datos_i.altura_maxima;
					}
                }
    }while(!feof(conf))
    datos_i.configuracion=1;
    return datos_i;
}

estados_t f_puentecerrado (parametros_t datos){
    datos.puente=0; //cierra el puente
    datos.alarma=0; //apaga la señal de alerta
    datos.auto_entra=emulacionauto1(); //medicion de ingreso de autos
    datos.auto_sale=emulacionauto2(); //medicion de egreso de autos
    datos.barco_entra=emulacionbarco1(); //medicion de ingreso de barcos
    datos.barco_sale=emulacionbarco2(); //medicion de egreso de barcos
    if(auto_entra>auto_sale||!barco_entra)
        return puentecerrado;
    else if(barco_entra||auto_sale)
        return abriendo;
    else if(auto_entra)
    	return cerrando;
}

estados_t f_abriendo (parametros_t datos){
    datos.auto_entra=emulacionauto1(); //medicion de ingreso de autos
    datos.auto_sale=emulacionauto2(); //medicion de egreso de autos
    datos.barco_entra=emulacionbarco1(); //medicion de ingreso de barcos
    datos.altura_barco=emulacionbarcoaltura(); //medicion de la altura del barco
    datos.barco_sale=emulacionbarco2(); //medicion de egreso de barcos
    if(barco_entra>barco_sale&&!auto_entra&&!auto_sale&&altura_maxima<altura_barco)
        return puenteabierto;
    else if(altura_maxima>altura_barco)
        return senalalerta;
    else if(auto_entra>auto_sale)
    	return puentecerrado;
}

estados_t f_cerrando (parametros_t datos){
    datos.auto_entra=emulacionauto1(); //medicion de ingreso de autos
    datos.auto_sale=emulacionauto2(); //medicion de egreso de autos
    datos.barco_entra=emulacionbarco1(); //medicion de ingreso de barcos
    datos.barco_sale=emulacionbarco2(); //medicion de egreso de barcos
    if(barco_entra>barco_sale)
        return puenteabierto;
    else if((auto_entra>auto_sale)||(!barco_entra&&!barco_sale))
        return puentecerrado;
}

estados_t f_senalalerta (parametros_t datos){
	datos.alarma=1; //enciende la señal de alerta
    datos.barco_entra=emulacionbarco1(); //medicion de ingreso de barcos
    datos.altura_barco=emulacionbarcoaltura(); //medicion de la altura del barco
    if(altura_maxima<altura_barco&&!barco_entra)
        return puentecerrado;
    else if(barco_entra)
        return abriendo;
}

estados_t f_puenteabierto (parametros_t datos){
    datos.puente=1; //abre el puente
    datos.alarma=0; //apaga la señal de alerta
    datos.barco_entra=emulacionbarco1(); //medicion de ingreso de barcos
    datos.barco_sale=emulacionbarco2(); //medicion de egreso de barcos
    if(barco_entra>barco_sale)
        return puenteabierto;
    else if(barco_entra)
        return abriendo;
    else if(barco_sale)
    	return cerrando;
}


// La logica de estas emulaciones funciona asi: Primero ingreso por donde sea que necesite a emulacionauto1 o emulacionauto2, ingreso el valor que pide para
// averiguar los autos que entran y los autos que salen, luego se pregunta si se quiere comparar, ahi se presiona un 2 y se compara, y se devuelve el valor a
// la otra emulacionauto, se espera que el usuario rompa el loop no presionando 2 cuando se pregunta en la otra funcion, ahi se devuelve el valor y se puede
// hacer la cuenta normalmente

unsigned int emulacionauto1 (void){
    char s,c;
    int autos=0, autoentra, autosale;
    do{
    	printf("Presione 1 si ingreso un auto");
        scanf("%s",&s);
        if(s=1){
        autoentra++;
    	}
	}while (s=1)
    do{
    	printf("Si necesita comparar la cantidad presione 2");
    	scanf("%s",&c);
    	if(c=2){   
		autosale=emulacionauto2();
    	autos=autoentra-autosale;	
		}
	}while (c=2)
    return autos;
}

unsigned int emulacionauto2 (void){
    char d,k;
    int autos=0, autoentra, autosale;
    do{
    	printf("Presione 1 si egreso un auto");
        scanf("%d",&d);
        if(d=1){
        autosale++;
    	}
	}while(s=1)
	 do{
    	printf("Si necesita comparar la cantidad presione 2");
    	scanf("%s",&k);
    	if(k=2){   
		autoentra=emulacionauto1();
    	autos=autoentra-autosale;	
		}
	}while (c=2)
    return autos;
}

// Misma lógica que en el caso de los autos pero esta vez con los barcos

unsigned int emulacionbarco1 (void){
    char s,c;
    int barcos=0, barcoentra, barcosale;
    do{
    	printf("Presione 1 si ingreso un barco");
        scanf("%s",&s);
        if(s=1){
        barcoentra++;
    	}
	}while (s=1)
    do{
    	printf("Si necesita comparar la cantidad presione 2");
    	scanf("%s",&c);
    	if(c=2){   
		barcosale=emulacionbarco2();
    	barcos=barcoentra-barcosale;	
		}
	}while (c=2)
    return barcos;
}

unsigned int emulacionauto2 (void){
    char d,k;
    int barcos=0, barcoentra, barcosale;
    do{
    	printf("Presione 1 si egreso un barco");
        scanf("%d",&d);
        if(d=1){
        barcosale++;
    	}
	}while(s=1)
	 do{
    	printf("Si necesita comparar la cantidad presione 2");
    	scanf("%s",&k);
    	if(k=2){   
		barcoentra=emulacionbarco1();
    	barcos=barcoentra-barcosale;	
		}
	}while (c=2)
    return barcos;
}

unsigned int emulacionbarcoaltura (void){
    int altura;
	printf("Ingrese la altura del barco");
	scanf(%d, altura);
    return altura;
}
