#if defined (WIN32)
#include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
#include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <pthread.h>

#define PORT 4124
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

void *receive(void* args){
    int sock = *(int*)args;
    char buffer[1024];
    int n = 0;
    //while(1){
        n=recv(sock,buffer, 32, 0);
        std::cout<<n << ": " << buffer<<std::endl;
    //}

}

void *send(void* args){
    int sock = *(int*)args;
    char buffer[1024];
    int n = 0;

    std::string msg = "testEnvoi";
    while(1){
        //send(sock, msg.c_str(), std::strlen(msg.c_str())-1,0);
        //cout<<(string)buffer<<endl;
    }

}

int main() {
    SOCKET sock;
    SOCKADDR_IN sin;

    char buffer[32];
    #if defined (WIN32)
        WSADATA WSAData;
            int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
    #else
        int erreur = 0;
    #endif

    int choixMenu;
    std::cout << "Taper 1 pour vous connecter et 2 pour quitter :";
    while(1) {

        std::cin >> choixMenu;


        switch (choixMenu) {
            case 1:
                sock = socket(AF_INET, SOCK_STREAM, 0); // on crée la socket
                pthread_t threads;
                /* Configuration de la connexion */
                sin.sin_addr.s_addr = inet_addr("192.168.1.22");//definition adresse ip
                sin.sin_family = AF_INET;
                sin.sin_port = htons(1025); // definition port de connexion

                /* Si le client arrive à se connecter */
                if (connect(sock, (SOCKADDR *) &sin, sizeof(sin)) != SOCKET_ERROR) {
                    printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
                    int rc,n;
                    //rc = pthread_create(&threads, NULL, receive, (void *)&sock);
                    n=recv(sock,buffer, 32, 0);
                    std::cout<<n << ": " << buffer<<std::endl;

                } else
                    printf("Impossible de se connecter\n");

                closesocket(sock);

                break;
            case 2:

                printf("Entrer votre message : ");
                std::string msg;
                std::cin >> msg;
                send(sock, msg.c_str(), msg.length() - 1, 0);

                break;
        }
    }
    return 0;
}