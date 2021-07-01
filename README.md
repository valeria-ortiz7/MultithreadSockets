# English version: 

# Server-Client Sockets 
Simple Multithreaded Server - Client TCP communication.

# Description of the project
The project contains a multithreaded server and client programmed in Java, and a multithreaded server and client programmed in C, communicating through TCP/IP.
The communication is done in the main program and not through input.
It is based on AF_UNIX sockets.

# Functionality of the project
The sockets will allow a Server-Client socket communication in these scenarios:
1. Java server handling both C and Java clients
2. C server handling both C and Java clients
3. Java server handling C clients
4. C server handling Java clients
5. Java server handling Java clients
6. C server handling C clients

# Important notes for newbies
The server can be started in either of the languages (C or Java) and it should handle clients in either of the languages too.
No need to use it as a Java server - Java client or so.

# System requirements
Project was developed to run on Linux.

## JDK
JDK is needed to compile on Java, if you do not have a JDK installed, type the following in the command prompt:
`sudo apt update`
`sudo apt install openjdk-11-jdk`

## GCC
GCC is used to compile in C, if you do not have it, type the following in the command prompt:
`sudo apt update`
`sudo apt install build-essential`

# Usage 
1. Run either the C or Java server first.
2. Start either a C or Java client.

## To run the Java server: 
1. Go to the terminal and move to the location where the file is
2. Type the command `javac Main.java` to compile the program
3. If it compiles successfully, it will generate a file called "Server.class"
4. To run the program, now type the command `java Main`

## To run the C server: 
1. Go to the terminal and move to the location where the file is
2. Type the command  `gcc –o Server Server.c`
3. If it compiles successfully, run the program with: `./Server`

## Client in C or Java
After one of the servers is running, connect a client using:

### Java
`javac Main.java`
`java Main`

### C
`gcc -o Client SocketCliente.c`
`./Client`

# Author
Valeria Ortiz León

# Versión en español: 

# Sockets Servidor-Cliente 
Conexión Servidor - Cliente por medio de sockets TCP/IP.

# Descripción del proyecto
El proyecto contiene tanto un sistema Servidor multihilos/multithreaded - Cliente en Java como un sistema Servidor multihilos/multithreaded - Cliente en C, comunicándose por TCP/IP.

La comunicación no es por medio de leer mensajes de la línea de comandos, los mensajes que se envían deben estar en el código.

# Funcionalidad del proyecto
Los sockets permitirán una comunicación en los siguientes escenarios:
1. Servidor en Java manejando clientes en C y Java
2. Servidor en C manejando clientes en C y en Java
3. Servidor en Java manejando clientes en C
4. Servidor en C manejando clientes en Java
5. Servidor en Java manejando clientes en Java
6. Servidor en C manejando clientes en C

# Notas importantes para principiantes
El servidor se puede iniciar ya sea en Java o C y va a poder manejar clientes en cualquiera de los lenguajes.
No hace falta tener una conexión servidor Java o cliente Java, o por el estilo. 

El puerto se puede cambiar, pero debe ser el mismo en el servidor y en el cliente.

# Requerimientos del sistema
Proyecto desarrollado en Linux.

## JDK
Se utliza JDK para compilar en Java, se instala de la siguiente manera:
`sudo apt update`
`sudo apt install openjdk-11-jdk`

## GCC
GCC es usado para compilar en C, se instala de la siguiente manera:
`sudo apt update`
`sudo apt install build-essential`

# Uso 
1. Se inicia ya sea con un servidor de Java o C
2. Se conecta al servidor cualquiera, ya sea un cliente de Java o C

## Para correr el servidor en Java:
1. Abrir la terminal y moverse a la ubicación donde se encuentra el archivo
2. Escriba el comando `javac Main.java` para compilar el programa
3. If it compiles successfully, it will generate a file called "Main.class"
4. To run the program, now type the command `java Main`

## Para correr el servidor en C:
1. Abrir la terminal y moverse a la ubicación donde se encuentra el archivo
2. Escriba el comando `gcc –o Server Server.c` para compilar el programa
4. Si compila bien, inicie el servidor con con `./Server`

## Cliente en C o Java
Cuando uno de los servidores esté corriendo, inicie alguno de los clientes:

### Java
`javac Main.java`
`java Main`

### C
`gcc -o Client SocketCliente.c`
`./Client`

# Autora
Valeria Ortiz León
