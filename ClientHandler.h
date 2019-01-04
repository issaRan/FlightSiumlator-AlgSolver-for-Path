//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_CLIENTHANDLER_H
#define MAILSTONE2_CLIENTHANDLER_H

#include "istream"
#include "ostream"
class ClientHandler{
    virtual void handleClient(std::istream inputStream,std::ostream) = 0;
};
#endif //MAILSTONE2_CLIENTHANDLER_H
