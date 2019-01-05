#include "MySerialServer.h"

void MySerialServer::open(int port, ClientHandler *clinetHandler) {
    this->clientHandler = clinetHandler;
    struct sockaddr_in serv_addr;
    /* First call to socket() function */
    this->sockfsd = socket(AF_INET, SOCK_STREAM, 0);

    if (this->sockfsd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(this->sockfsd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    this->online = true;
    thread threadServer(&MySerialServer::serverConnection,this);
    threadServer.detach();
}
void MySerialServer::serverConnection() {
    int clilen, newsockfd;
    struct sockaddr_in cli_addr;
    listen(this->sockfsd,1);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(this->sockfsd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
}

void MySerialServer::close() {

}
