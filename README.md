# Puente Levadizo

### Memoria Descriptiva
El sistema representa un puente levadizo, el mismo cuenta con sensores para medir la cantidad de ingresos y egresos de barcos y autos, además de una señal para avisar a los barcos que superan la altura máxima y el control propio de abrir o cerrar el puente.

Primero, el sistema se inicializa con el puente cerrado, ya que este será el estado de funcionamiento normal del mismo, cuando haya autos circulando y no haya barcos queriendo ingresar, el mismo se mantendrá cerrado. Se irán contando el ingreso de barcos y/o autos, desde los estados de abriendo y cerrando, los cuales dirigirán el funcionamiento del puente, a la hora del ingreso de los barcos, se tendrá en cuenta la altura de los mismos, si esta supera la altura máxima tabulada en el sistema, se activará una señal para avisarle al barco que no puede pasar por el puente, desde este estado se tiene en cuenta el ingreso de otros barcos para no trabar el funcionamiento del puente. Cuando el puente se encuentra abierto, se contará el ingreso y egreso de barcos, nuevamente dirigiéndose a los estados de abriendo y cerrando, mientras haya barcos queriendo pasar, el puente se mantendrá abierto, hasta el caso donde no haya más barcos, en el cual el puente se cerrará nuevamente.

### Máquina de Estados
![](https://i.postimg.cc/9fyBY6Kj/maquinadeestados.png)
- set: Bandera de fin de inicio.
- auto_entra: Contador de ingreso de autos.
- auto_sale: Contador de egreso de autos.
- barco_entra: Contador de ingreso de barcos.
- barco_sale: Contador de egreso de barcos
- altura_barco: Altura del barco por entrar.
- altura_maxima: Altura máxima del puente configurada.
