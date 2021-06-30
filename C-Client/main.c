#include <stdio.h>
#include "sockets/SocketCliente.h"

int main()
{
    char *mensaje = "Hola Server\n";
    char *respuesta = enviar_mensaje(mensaje);

    printf("He recibido: %s", respuesta);

    return 0;
}
