#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include "server.h"

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("usage: %s [options]", argv[0]);
        return 0;
    }
    std::string option = argv[1];

    if (option == "--stream") {
        startServer();
    }

    return 0;
}