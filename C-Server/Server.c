#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include "Server.h"

void *handler_clientes(void *);

int main(void)
{
    /**
     * EN: Variables to initiate the server
     * SP: Variables para iniciar el servidor
     */
    int socket_servidor, socket_cliente, *nuevo_socket;
    struct sockaddr_in servidor, cliente;

    /**
     * EN: Prepares the socket structure
     * SP: Prepara la estructura del socket
     */
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;

    /**
     * EN: Port where the connection will be initiated
     * SP: Puerto donde se realizará la conexión
     */
    servidor.sin_port = htons(PORT);

    /**
     * EN: Creates the server socket
     * SP: Crea el socket del servidor
     */
    socket_servidor = socket(AF_INET, SOCK_STREAM, 0);

    int opcion = 1;
    if (setsockopt(socket_servidor, SOL_SOCKET, SO_REUSEADDR, &opcion, sizeof(int)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
    }


    /**
     * EN: Checks for error while initiating the server socket
     * SP: Revisa si hay errores al crear el socket del servidor
     */
    if (socket_servidor == -1)
    {
        printf("Error al crear el socket del servidor");
    }

    puts("Servidor iniciado");

    /**
     * EN: Assigns a local protocol address to a socket
     * SP: Asigna una dirección de protocolo al socket
     */
    if(bind(socket_servidor, (struct sockaddr *)&servidor , sizeof(servidor)) < 0)
    {
        perror("Fallo al abrir el puerto. Error");
        return 1;
    }

    puts("Se hizo el bind del socket");

    /**
     * EN: Starts waiting for clients
     * SP: Empieza a esperar clientes
     *
     * conexiones_permitidas is the number of the allowed connections
     */

    int conexiones_permitidas = 10;

    listen(socket_servidor, conexiones_permitidas);
    puts("Esperar conexiones entrantes...");

    /**
     * EN: Accepts the incoming connections
     * SP: Acepta las conexiones entrantes
     */
    int tamano_socket = (sizeof(struct sockaddr_in));
    while((socket_cliente = accept(socket_servidor, (struct sockaddr *) &cliente, (socklen_t*) &tamano_socket)))
    {
        puts("Se ha establecido conexion entre el nuevo cliente y el servidor.");

        /**
        * EN: Creates the thread to handle multiple clients
        * SP: Crea el hilo para manejar multiples clientes
        */
        pthread_t thread;
        nuevo_socket = malloc(1);
        *nuevo_socket = socket_cliente;

        /**
        * EN: Checks for errors while creating the thread
        * SP: Verifica errores al crear el thread
        */
        if(pthread_create(&thread, NULL, handler_clientes, (void*) nuevo_socket) != 0)
        {
            perror("Error al crear el thread");
            return 1;
        }

    }

    /**
     * EN: Error checking
     * SP: Verifica errores
     */
    if (socket_cliente < 0)
    {
        perror("Error al aceptar el cliente");
        return 1;
    }

    close(socket_servidor);
    return 0;
}

/**
 * @func handler_clientes
 *
 * @desc EN: Client handler that will open threads to handle multiple clients
 * @desc SP: Manejador de clientes que abrirá los hilos para manejar varios clientes
 *
 * @param socket_descriptor Socket descriptor with the destination IP address and port | Socket con la direccion IP destino y puerto
 */
void *handler_clientes(void *socket_descriptor)
{
    /** Obtains the socket of the client connecting */
    int socket_cliente = *(int*)socket_descriptor;
    int tamano_mensaje;
    char mensaje_cliente[2000];

    /**
     * EN: Waits for clients so it can respond
     * SP: Espera a los clientes para poder responder
     */
    while ((tamano_mensaje = recv(socket_cliente, mensaje_cliente, 3000, 0)) > 0)
    {
        printf("Recibió de cliente: %s", mensaje_cliente);

        /**
         * EN: If you want to give a response based on input
         * SP: Si se quiere dar una respuesta según lo recibido
         */
        if(strncmp("Exit", mensaje_cliente, 4) == 0)
        {
            write(socket_cliente, "Exiting...\n", 50); /** n = 100 -> big enough */
            break;
        }

        /** If you only want to echo the message | Si solo se quiere devolver el mensaje recibido */
        else
        {
            write(socket_cliente, mensaje_cliente, sizeof(mensaje_cliente + 1));
        }
    }

    if (tamano_mensaje == 0)
    {
        puts("Cliente desconectado.\n");
    }

    free(socket_descriptor);
    close(socket_cliente);
    puts("Comunicación finalizada.\n");
    return 0;
}