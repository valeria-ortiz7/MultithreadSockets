public class Main {

    public static void main(String[] args) {

        Client client_socket = new Client();

        client_socket.enviar_mensaje("Hola server\n");
        client_socket.enviar_mensaje("Hello world\n");
        client_socket.enviar_mensaje("Bye");
    }
}
