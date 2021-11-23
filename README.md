# SSOO-tarea03
##### Nombre del autor: Angel Manuel Armando Araya Millar
##### Correo institucional: angel.araya@alumnos.uv.cl
Para la resolución de esta tarea se utilizaron las librerias future, thread, chrono, csignal, unistd.h, iostream, fstream.
Primero se investigo como funciona la sucesión fibonacci y la sumatoria de numeros impares y se implementaron en C++, luego se creo un fork visto en clases, posteriormente se hizo un for que itere hasta 50 como se pedia en el enunciado de la tarea, dentro de este fork esta implementada la sumatoria de numeros impares y su salida esta controlada por std::this_thread::sleep_for(std::chrono::seconds(1)). Tambien esta la solución implementada de fibonacci controlada por ```C++ std::this_thread::sleep_for(std::chrono::seconds(1)). ```C++
Despues se creo el control de señales, donde se hacen las restricciones de señales que evitan que el programa termine, estas son SIGINT (ctrl+C), SIGTSTP (ctrl+Z), SIGQUIT (ctrl+\) y SIGUS para poder hacer "kill" desde otra terminal.
