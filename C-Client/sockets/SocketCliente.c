#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/**
 * @func enviar_mensaje
 *
 * @descr EN : Opens a socket to send a message of type char* to the server
 * @descr SP : Abre una conexión por medio de sockets para enviar un mensaje de tipo char* al server
 * @param mensaje_solicitud : Message you want to send to the server | Mensaje que se desea enviar al servidor
 * @return char* : Response received sent by the server | Respuesta recibida enviada por el server
 */

char* enviar_mensaje(char* mensaje_solicitud)
{
    int socket_cliente;
    struct sockaddr_in socket_servidor;
    char respuesta_servidor[2000];

    /** EN: Initializes the client socket
     * SP: Inicializa el socket del cliente
     */
    socket_cliente = socket(AF_INET, SOCK_STREAM, 0);

    /**
     * EN: Checks if there's an error generating the socket
     * SP: Revisa si se genera un error al inicializar los sockets
     */
    if (socket_cliente == -1)
    {
        return 1;
    }

    puts("Socket creado");

    /**
     * EN: Defines the IP address of the server socket (PC'S IP address)
     * SP: Define el IP del socket del servidor (dirección IP de la PC)
     */
    socket_servidor.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    socket_servidor.sin_family = AF_INET;

    /**
     * EN: Defines the port
     * SP: Define el puerto de conexion
     */
    socket_servidor.sin_port = htons(PORT);

    /**
     * EN: Stablishes a connection with the server
     * SP: Intenta establecer la conexión con el servidor
     */
    if (connect(socket_cliente, (struct sockaddr *)&socket_servidor, sizeof(socket_servidor)) < 0)
    {
        perror("Error al conectarse");
        return 1;
    }

    puts("Conectado exitosamente.");

    printf("Mensaje enviado: %s", mensaje_solicitud);

    /**
     * EN: Keeps the connection open while sending and receiving a response
     * SP: Mantiene la conexión con el server mientras envía y recibe una respuesta
     */
    while(1)
    {

        /**
        * EN: Checks for issues sending the mesage
        * SP: Revisa si se falló al enviar el mensaje
        */
        if(send(socket_cliente, mensaje_solicitud, strlen(mensaje_solicitud), 0) < 0)
        {
            puts("Solicitud fallida");
            return 1;
        }


        /**
         * EN: Checks if response from the server was received
         * SP: Revisa si la respuesta del server llega
         */
        if(recv(socket_cliente, respuesta_servidor, 2000, 0) < 0)
        {
            puts("Error al recibir");
            return 1;
        }

        printf("Respuesta del servidor: %s", respuesta_servidor);
        break;
    }

    /**
     * EN: Casts the response received from char[] to char*
     * SP:  Convierte el mensaje recibido de tipo char[] a tipo char*
     */
    char *respuesta = &respuesta_servidor[0];

    /**
     * EN: Closes the communication to avoid an infinite loop
     * SP: Cierra la comunicación para evitar ciclo infinito
     */
    close(socket_cliente);

    return respuesta;
}
