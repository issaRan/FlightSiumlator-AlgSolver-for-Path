//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYSERIALSERVER_H
#define MAILSTONE2_MYSERIALSERVER_H


#include "Server.h"
#include <thread>
#include "ClientHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
using namespace std;
class MySerialServer : public server_side::Server{
    int sockfsd;
    ClientHandler *clientHandler;
    bool online;
public:
    void open(int port,ClientHandler* clinetHandler);
    void serverConnection();
    void close();
};


#endif //MAILSTONE2_MYSERIALSERVER_H
