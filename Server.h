#ifndef MAILSTONE2_SERVER_H
#define MAILSTONE2_SERVER_H
 // interface for the server.
#include "ClientHandler.h"
namespace server_side {
    class Server {
    public:
        /**
         * to open the server
         * @param port port for the server
         * @param clientHandler
         */
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        /**
         * end the server operation.
         */
        virtual void close() = 0;
    };
}
#endif //MAILSTONE2_SERVER_H
