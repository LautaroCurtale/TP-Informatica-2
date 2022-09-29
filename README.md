# Puente Levadizo

### Memoria Descriptiva
El sistema representa un puente levadizo, el mismo cuenta con sensores para medir la cantidad de ingresos y egresos de barcos y autos, además de una barrera a la entrada del puente para permitir el paso de los autos, una señal para avisar a los barcos que superan la altura máxima y el control propio de abrir o cerrar el puente.

Primero, el sistema se inicializa con el puente cerrado, ya que este será el estado de funcionamiento normal del mismo, cuando haya autos circulando y no haya barcos queriendo pasar, desde el puente cerrado, se ira contando la cantidad de ingresos y egresos de autos, los mismos no tendran relevancia en el control de la barrera, pero serán importantes a la hora de abrir o cerrar el puente. Además, se contará la cantidad de ingresos y egresos de barcos, en el caso de los ingresos, primero se tendrá que revisar que el barco no tenga una altura mayor a la altura máxima preestablecida del puente, en ese caso, el mismo no podra pasar, y se activara una señal de alerta para avisarle, además de que la barrera se mantendrá alta, igualmente se considera el caso donde entren más de un barco y haya algunos que no superen la altura, en ese caso la barrera se bajará, al igual que cuando ingresa un barco que no supera la altura máxima. Con la barrera baja, en el caso donde todavia haya autos circulando en el puente, se mantendra baja hasta que la cantidad ingresos y egresos de autos sea 0, en ese momento, el puente se abrirá para el circulamiento de los barcos.  En el caso de los egresos de barcos, mientras el ingreso y egreso de barcos sea 0, la barrera se levantará o mantendra alta, y en caso de que no haya más ingresos de barcos, el puente se cerrará o mantendra cerrado si ya estaba asi. En el caso de que el puente esté abierto, el mismo seguira contando con un sensor para el ingreso y egreso de barcos, para que el mismo pueda retornar de alguna forma al estado de puente cerrado y se mantenga el bucle infinito.

### Máquina de Estados
![](https://i.postimg.cc/ZRVdSg4x/M-quina-de-Estados.png)
- set: Bandera de fin de inicio.
- auto_entra: Contador de ingreso de autos.
- auto_sale: Contador de egreso de autos.
- barco_entra: Contador de ingreso de barcos.
- barco_sale: Contador de egreso de barcos
- altura_barco: Altura del barco por entrar.
- altura_maxima: Altura máxima del puente configurada.
