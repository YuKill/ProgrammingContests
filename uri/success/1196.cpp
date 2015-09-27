#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main() {
  char board[4][14] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'00", "ZXCVBNM,./000" };
  string buf;
  while (getline(cin, buf)) {
    int len = buf.length();
    for (int i = 0; i < len; i++) {
      if (buf[i] == ' ') printf(" ");
      else if (buf[i] == '\n') continue;
      else {
        char *ch = (char*)memchr(board, buf[i], 56);
        if (ch != NULL) {
          ch--;
          printf("%c", *ch);
        }
      }
    }
    printf("\n");
  }
}
