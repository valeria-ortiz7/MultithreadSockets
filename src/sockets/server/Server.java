/**
 * Server
 *
 * @desc EN: Java multi-threaded server that can handle multiple clients at the same time
 * @desc SP: Servidor multi-hilos que puede manejar varios clientes al mismo tiempo
 *
 * @author      Valeria Ortiz
 */

package sockets.server;

import java.io.*;
import java.net.Socket;
import java.lang.*;
import java.net.*;

public class Server {

    /**
     * @func solicitudCliente
     *
     * @desc EN: Receives the client string and defines the response
     * @desc SP: Recive el string enviado por el cliente y define la respuesta
     *
     * @param solicitud_cliente  String with the client request | String con el mensaje del request del cliente
     * @return String with the answer | String con los datos que se solicitan
     */
    public static String solicitudCliente(String solicitud_cliente) {

        String respuesta = "";

        if (solicitud_cliente.equals("Hola Server")) {
            respuesta = "Hola Cliente\n";
        }

        /**
         * EN : Echoes the message
         * SP : Regresa el mensaje
         */
        else {
            respuesta = solicitud_cliente;
        }

        return respuesta;
    }


    /**
     *  HandlerClientes
     *
     * @desc EN: Class that implements threads in order to handle multiple clients
     * @desc SP: Clase que implementa threads para manejar a varios clientes
     */

    public static class HandlerClientes implements Runnable {
        private final Socket socket_escucha;

        /** Class constructor | Constructor de la clase
         * @param socket Socket of the client received | Socket del cliente recibido
         * */
        public HandlerClientes(Socket socket) {
            this.socket_escucha = socket;
        }

        public void run() {
            DataOutputStream socket_respuesta = null;
            BufferedReader recibido = null;

            try {

                /**
                 * EN: Receives the client's message
                 * SP: Recibe el mensaje del cliente
                 */
                recibido = new BufferedReader(new InputStreamReader(socket_escucha.getInputStream()));

                /**
                 * EN: Interprets the message to a string
                 * SP: Interpreta en forma de string la solicitud del cliente
                 */
                String solicitud_cliente = recibido.readLine();
                System.out.println(solicitud_cliente);

                /**
                 * EN: Passes the client's message to solicitudCliente to generate a response
                 * SP: Pasa el mensaje del cliente a solicitudCliente para generar una respuesta
                 */
                String respuesta = solicitudCliente(solicitud_cliente);

                /**
                 * EN: Send the response to the client
                 * SP: Le envía la respuesta al cliente
                 * */
                socket_respuesta = new DataOutputStream(socket_escucha.getOutputStream());
                socket_respuesta.write((respuesta + '\n').getBytes());
                socket_respuesta.flush();

                /**
                 * EN: Closes the communication
                 * SP: Cierra esta comunicación
                 */
                socket_escucha.close();
                System.out.println("Comunicacion finalizada");

            } catch (IOException e) {
                e.printStackTrace();

            }

            /**
             * EN: Checks for errors
             * SP: Verifica si hay errores
             */
            finally {

                try {
                    if (socket_respuesta != null) {
                        socket_respuesta.close();
                    }

                    if (recibido != null) {
                        recibido.close();
                        socket_escucha.close();
                    }

                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
