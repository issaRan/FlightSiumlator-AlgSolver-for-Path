#include <thread>
#include "Server.h"

#include <iostream>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <functional>
#include "Server.h"
#include "ClientHandler.h"
#include <time.h>
#include <vector>

class MyParllelServer: public server_side::Server{
    int port{};
    ClientHandler* clientHandler{};
public:
    void open(int port, ClientHandler* clientHandler) override;
    static void start(int server, ClientHandler *);
    void close();
    bool stop();

};