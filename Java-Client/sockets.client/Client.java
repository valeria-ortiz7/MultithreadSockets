/**
 * Client
 *
 * @desc EN: Client class that will open a socket to send messages to the server
 * @desc SP: Clase Client que abrirá un socket para enviar mensajes al servidor
 *
 * @authors Valeria Ortiz
 */

import java.lang.*;
import java.io.*;
import java.net.*;

public class Client {

    static final String IP_ADDRESS = "127.0.0.1";
    static final int PUERTO = 17778;

    /**
     * @func enviar_mensaje
     *
     * @param mensaje Message to be sent to the server | Mensaje que se quiere enviar al server
     * @return String with the server response | String con la respuesta del server
     */
    public String enviar_mensaje(String mensaje)
    {
        Socket socket_cliente = null;

        try {

            /**
             * EN: Creates the socket and connects it to the IP address and port
             * SP: Crea el socket y lo conecta al IP y el puerto
             */
            socket_cliente = new Socket(IP_ADDRESS, PUERTO);

            /**
             * EN: Writes the message to the server
             * SP: Escribe el mensaje al server
             */
            DataOutputStream mensaje_salida = new DataOutputStream(socket_cliente.getOutputStream());
            mensaje_salida.write((mensaje + '\n').getBytes());
            mensaje_salida.flush();

            /**
             * EN: Reads the server response
             * SP: Para leer lo del server
             */
            BufferedReader mensaje_entrada = new BufferedReader(new InputStreamReader(socket_cliente.getInputStream()));
            String mensaje_recibido = mensaje_entrada.readLine();

            System.out.println("Recibido del server: " + mensaje_recibido);
            return mensaje_recibido;
        }

        catch (Exception e)
        {
            System.out.println(e.getMessage() + "\nError enviando el mensaje.");
        }

        try
        {
            if (socket_cliente != null)
            {
                socket_cliente.close();
            }
        }

        catch (Exception e)
        {
            System.out.println(e.getMessage() + "\nError en el cliente.");
        }

        return "";
    }
}
