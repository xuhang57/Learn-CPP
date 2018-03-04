// Copyright 2018 EC327/Carruthers jbc@bu.edu
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "movedef.h"

using std::cout;
using std::string;
using std::vector;

std::vector<std::array<int, 3> > win = {
  {0, 1, 2},  // rows
  {3, 4, 5},
  {6, 7, 8},
  {0, 3, 6},  // columns
  {1, 4, 7},
  {2, 5, 8},
  {0, 4, 8},  // diagonals
  {6, 4, 2}
};

bool winner(const string & board, char w) {
  for (auto a : win)
    if ( (board[a[0]] == w) 
        and (board[a[1]] == w) 
        and (board[a[2]] == w) )
      return true;
  return false;
}

int count(const string &board, char w) {
  int n = 0;
  for (auto a : board)
    if (a == w) n++;
  return n;
}
char tttresult(string  board) {
  if (board.size() != 9) return 'e';

  std::map<char, int> cnt;
  for (char c : "xo#")
    cnt[c] = count(board, c);

  if (cnt['x'] + cnt['o'] + cnt['#'] != 9) return 'e';


  if ((cnt['x'] < cnt['o']) 
    or (cnt['x'] > cnt['o'] + 1)) return 'i';

  bool xwins = winner(board, 'x');
  bool owins = winner(board, 'o');

  if (xwins and owins)
    return 'i';

  if (xwins) {
    if (cnt['x'] > cnt['o']) return 'x';
    else
      return 'i';
  }

  if (owins) {
    if (cnt['o'] == cnt['x']) return 'o';
    else
      return 'i';
  }

  if (cnt['#'] == 0)
    return 't';

  return 'c';
}


char tttresult(vector<Move> board) {
  string b(9, '#');
  for (auto m : board) {
    if (m.r < 0 or m.r > 2) return 'e';
    if (m.c < 0 or m.c > 2) return 'e';
    int pos = m.r * 3 + m.c;
    if (b[pos] != '#') return 'e';
    b[pos] = m.player;
  }
  return tttresult(b);
}


string numtoboard(int n) {
  string b(9, '#');
  string v("#xo");
  int dig;
  for (int i = 0; i < 9; i++) {
    dig = n % 3;
    b[i] = v[dig];
    n = n / 3;
  }
  return b;
}

vector<string> get_all_boards() {
  vector<string> boards;
  for (int n = 0; n < 27 * 27 * 27; n++)
    boards.push_back(numtoboard(n));
  return boards;
}


// MAIN

int main() {
  std::map<char, int> tally;
  string CODES{"toxic"};

  for (auto key : CODES )
    tally[key] = 0;

  for (auto board : get_all_boards())
    tally[tttresult(board)]++;

  for (auto item : tally) {
    cout << item.first << " " << item.second << "\n";
  }

  return 0;
}
