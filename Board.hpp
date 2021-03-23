#include "Direction.hpp"
#include <string>

using std::string;

namespace ariel {
    class Board;
}

class ariel::Board{
    public:
        Board();
        void post(unsigned int row, unsigned int column,Direction direction ,string message);
        string read(unsigned int row, unsigned int column,Direction direction ,unsigned int length);
        void show();
};