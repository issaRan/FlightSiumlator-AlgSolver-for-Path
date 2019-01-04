//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYSERIALSERVER_H
#define MAILSTONE2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public Server{
public:
    void open(int port,ClinetHandler* clinetHandler);
    void close();
};


#endif //MAILSTONE2_MYSERIALSERVER_H
