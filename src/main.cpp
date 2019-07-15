#include "game.h"

int main(int argc , char** argv) {

    GameEngine::Game game("Window" , 640 , 480);
    game.run(60);
    return 0;
}
