#include "Global.h"

char* Tools::getVersion(int build){

    char ver[127];
    char* str_version  = new char[127];

    switch(build){

    case BUILD_DEBUG:
        sprintf(ver, "debug ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_RELEASE:
        sprintf(ver, "release ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_ALPHA:
        sprintf(ver, "alpha ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_BETA:
        sprintf(ver, "beta ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_FINAL:
        sprintf(ver, "final ver. %d.%d.%d.%d (never will be) :(", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    case BUILD_SPECIAL:
        sprintf(ver, "Nightly build ver. %d.%d.%d.%d", GAME_MAJOR, GAME_MINOR, GAME_VERSION, GAME_REVISION);
        break;
    }

    strcpy(str_version, ver);

    return str_version;

}
