#ifndef ZZCORE_H_
#define ZZCORE_H_

namespace zugzwang {

    typedef unsigned long long bitboard_t;

    class BitBoardFactory {

        private:

            bool set(bitboard_t & bb, int x, int y, bool on);
            bool get(const bitboard_t &bb, int x, int y );

        public:

            BitBoardFactory();

    };


}

#endif
