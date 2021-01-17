/*
Gerald McGee
CS3610 - Ohio University
Project 3

*/

#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(int row, int col, int row_moves[], int col_moves[], int& num_moves){
  int columnmove[8] = {2,2,1,-1,-2,-2,-1,1};  // These arrays store all the valid moves in clockwise fashion
  int rowmove[8] = {-1,1,2,2,1,-1,-2,-2}; 
  for(int i = 0; i  < 8; i++){ 
    if(moveCheck(row+rowmove[i], col+columnmove[i]) == true){ // this will call movecheck to check a move at a certain array index

      col_moves[num_moves] = col+columnmove[i];
      row_moves[num_moves] = row+rowmove[i];
      num_moves++;
    }
  }
}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours){
  m++;
  board[row][col] = m; 

// variables for get moves 
  int numMoves = 0;
  int col_moves[8];
  int row_moves[8]; 

  if(m == 25){  // checking for tour completion
    num_tours++; 
    print(); 
  }
  get_moves(row, col, row_moves, col_moves, numMoves);  

  for(size_t i = 0; i < numMoves; i++){
    move(row_moves[i], col_moves[i],m, num_tours); 
  }  

  --m; //backtrack
  board[row][col] = 0; 
}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;
  move(row, col, m, num_tours);

  return num_tours;
}

bool KnightsTour::moveCheck(int row, int col) {
  if((row >= 0) && (row < board_size) && (col >= 0) && (col < board_size) && (board[row][col] == 0)){
    return true;
  }
  return false;
}
