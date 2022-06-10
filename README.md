Para que este programa funcione primero se llama el constructo a traves de:
busqueda_BoS "nombre que le quiera dar al objeto";
Considerandoe l nombre del objeto BS, luego  el usuario debe crear su propio vector con valores ordenados de mayor a menor e introducirlo en la funcion a traves de:
BS.array="vector creado";
Luego para que busque la key se debe introducir el valor a buscar a traves de:
BS.key="valor que quiero encontrar";
Y finalmente para que la funcion lo encuentre se usa en caso de la busqueda binaria:
BS.is_in_BB();
y en caso de la busqueda secuencial:
BS.is_in_BS();
En ambos casos la funcion retorna la posicion en el del valor buscado siendo imporante notar que parte desde el cero y que para poder usar este valor de retorno se hace una variable=BS.is_in_BS() o BS.is_in_BB() , por ejemplo;
resultado=BS.is_in_BB();
