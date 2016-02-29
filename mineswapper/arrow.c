#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

static struct termios term, oterm;

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

int main(void)
{
    int number;

    clear();
    while(1){
      char c;
      tcgetattr(0, &oterm);
      memcpy(&term, &oterm, sizeof(term));
      term.c_lflag &= ~(ICANON | ECHO);
      term.c_cc[VMIN] = 1;
      term.c_cc[VTIME] = 0;
      tcsetattr(0, TCSANOW, &term);
      c = getchar();
      tcsetattr(0, TCSANOW, &oterm);
      switch (c){
        case 'w':
          printf("\033[1A");
          break;
        case 's':
          printf("\033[1B");
          break;
        case 'a':
          printf("\033[1D");
          break;
        case 'd':
          printf("\033[1C");
          break;
      }
    }
    return 0;
}
