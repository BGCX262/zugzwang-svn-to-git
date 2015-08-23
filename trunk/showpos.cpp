#include <iostream>
#include <cstdlib>
#include "display.h"

using namespace zugzwang;
using namespace std;

int main ( int argc, char *argv[] ) {

    Display d;

    while(1) {
        d.draw(0,0,'*',1);
        d.draw(1,1,'*',0);
        d.draw(4,1,'X',2);
        d.waitkey();
    }

    return EXIT_SUCCESS;
}
