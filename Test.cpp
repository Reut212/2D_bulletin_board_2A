#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
#include <stdlib.h>
#include <string>

using namespace ariel;
using namespace std;
using std::string;

ariel::Board board;
unsigned int length;

unsigned int getNumber(unsigned int sRange, unsigned int eRange){
    return sRange + (((unsigned int) rand()) % (eRange - sRange) + 1);
}

TEST_CASE("Valid input"){
    
    //**Check an empty places**//
    string message1 = "___________";
    
    //set numbers
    unsigned int row =  getNumber(0,500);
    unsigned int column =  getNumber(0,500);

    // check H
    CHECK(board.read(row, column, Direction::Horizontal, message1.length()) == message1);

    // check V 
    CHECK(board.read(row, column, Direction::Vertical, message1.length()) == message1);

    
    
    //**Check valid input "___abc___"**//
    string message2 = "abc";

    // check H
    board.post(0, 3, Direction::Horizontal, message2);
    CHECK(board.read(0, 0, Direction::Horizontal, 9) == "___abc___");

    //**Check valid input "___aac___"**//
    board.post(0, 4, Direction::Vertical, message2);
    CHECK(board.read(0, 0, Direction::Horizontal, 9) == "___aac___");

    //**Check substring - "aa"**//
    CHECK(board.read(0,3, Direction::Horizontal,2) == "aa");
    
    //**Check an input in different places on the board**//
    string message3 = "abcd";
    unsigned int i = 0;
    for(i = 0; i<20; i++){
        //set numbers
        unsigned int hRow =  getNumber(0, 500);
        unsigned int hColumn =  getNumber(0, 500);
        unsigned int vRow = getNumber(99, 105);
        unsigned int vColumn =  getNumber(99, 105);

        // check H
        board.post(hRow, hColumn, Direction::Horizontal,message3);
        CHECK(board.read(hRow, hColumn, Direction::Horizontal, message3.length()) == message3);
        
        // check V 
        board.post(vRow, vColumn, Direction::Vertical,message3);
        CHECK(board.read(row, column, Direction::Vertical, message3.length()) == message3);
    }


}