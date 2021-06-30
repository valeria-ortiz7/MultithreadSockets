public class Main {

    public static void main(String[] args) {

        Client client_socket = new Client();

        client_socket.iniciar_conexion("Hola server\n");
        client_socket.iniciar_conexion("Hello world\n");
        client_socket.iniciar_conexion("Bye");
    }
}
