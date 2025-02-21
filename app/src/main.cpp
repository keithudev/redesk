#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include "Server.h"
#include "Client.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("usage: %s [options]\n", argv[0]);
        printf("--stream: start streaming your desktop\n");
        printf("--join [room_id]: join to a room\n"); 
        return 0;
    }

    std::string option = argv[1];


    if (option == "--stream") {
        startServer();
    }

    if (option == "--join") {
        joinRoom();
    }
     
    
    return 0;
}