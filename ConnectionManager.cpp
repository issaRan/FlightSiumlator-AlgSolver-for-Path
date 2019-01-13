//
// Created by daniel on 1/7/19.
//

#include "ConnectionManager.h"

string ConnectionManager::readLine() {

    /* Now read server response */
    bzero(this->buffer, 256);
    int n = read(this->sockfd, this->buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    stringstream ss;
    string toSend;
    ss<<buffer;
    ss>>toSend;
    return toSend;
}

void ConnectionManager::sendLine(string msg) {

    int n = ::send(sockfd, (char *) msg.c_str(), strlen((char *) msg.c_str()), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
