package sockets.server;

import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Main {

    public static void main(String[] args) {

        /**
         * EN: Port where the server will be listening for clients
         * SP: Puerto donde estará el servidor escuchando para recibir clientes
         */
        final int PUERTO = 17778;

        /**
         * EN: Initiates the server socket
         * SP: Inicializa el socket del servidor
         */
        ServerSocket socket_servidor = null;
        Socket socket_escucha = null;
        DataOutputStream socket_respuesta;

        try {
            /**
             * EN: Creates the socket and assigns the port
             * SP: Crea el socket y le asigna el puerto
             */
            socket_servidor = new ServerSocket(PUERTO);
            socket_servidor.setReuseAddress(true);

            System.out.println("El server se ha iniciado");

            /**
             * EN: Loop where the server will be listening for clients
             * SP: Loop donde estará escuchando y abriendo un hilo para ir recibiendo a los clientes
             */

            while (true) {

                /**
                 * EN: Accepts a connection in the socket
                 * SP: Acepta una conexion en el socket
                 */
                socket_escucha = socket_servidor.accept();

                /**
                 * EN: Creates an instance of HandlerClients that will take care of handling multiple clients
                 * SP: Crea una instancia de HandlerClientes que se encargará de manejar a los clientes
                 */
                Server.HandlerClientes clientSock = new Server.HandlerClientes(socket_escucha);

                /**
                 * EN: Handles every socket separately using a thread
                 * SP: Este thread manejará cada socket por separado */
                new Thread(clientSock).start();
            }

            /**
             * EN: If the connection is refused
             * SP: Si se rechaza la conexión
             */
        } catch (Exception ex) {
            System.out.println(ex.getMessage() + " Limite de peticiones en el servidor");
        }
    }
}
