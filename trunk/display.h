#ifndef ZZDISPLAY_H_
#define ZZDISPLAY_H_

#include "core.h"

namespace zugzwang {

    class Display{
        private:

            const int nsquares;

        public:
            Display();
            virtual ~Display();

            void setmsg(const char *msg);

            void draw( int x, int y, char c, int color=1);

            void clearmsg();
            void clearboard();

            void redraw();
            void waitkey();
    };
}



#endif
