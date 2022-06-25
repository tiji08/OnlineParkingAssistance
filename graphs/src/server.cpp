#if 0
#include <iostream>
#include <ctime>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

std::string make_daytime_string() {
    std::time_t now = std::time(0);
    return std::ctime((const time_t *)&now);
}

int start_tcp_server(void) {
    /* Create server acceptor */
    try {
        boost::asio::io_service io_service;

        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

        for (;;) {
            //create a socket
            tcp::socket socket(io_service);

            //prepare list 
            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            /* Keep listening */
            /* Accept and send the message time */

        }

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}

#endif

#include <stdio.h>
#include <pthread.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#include <unistd.h>
#include "trie.h"
#include "graph.h"

#define PORT 8080
#define SA struct sockaddr
int connfd;

// Function designed for chat between client and server.
void *func(void *pconnfd)
{
    char buff[MAX];
    //int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);

        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        //n = 0;
        // copy server message in the buffer
        //while ((buff[n++] = getchar()) != '\n')
        //    ;
       
        collect_list_of_accoutns();
        display_all_accounts(0);
        char *buff = get_list_of_accoutns();    
        

        // and send that buffer to client
        write(connfd, buff, 20);

        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
    return NULL;
}

// Driver function
int start_tcp_server()
{
    int sockfd,len;
    struct sockaddr_in servaddr, cli;
    pthread_t t1;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));


    int reuse = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&reuse, sizeof(reuse)) < 0)
        perror("setsockopt(SO_REUSEADDR) failed");
    
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    while(1) {
        // Accept the data packet from client and verification
        connfd = accept(sockfd, (SA*)&cli, (socklen_t *)&len);
        if (connfd < 0) {
            printf("server accept failed...\n");
            exit(0);
        }
        else
            printf("server accept the client...\n");

        // Function for chatting between client and server
        //func(connfd);

        pthread_create(&t1, NULL, func, NULL);
    }

    // After chatting close the socket
    close(sockfd);
    return 0;
}

