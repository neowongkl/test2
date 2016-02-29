#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ROWS = 8;
int COLS = 8;

int checkBomb(char c){
  if( c == 'B')
    return 1;
  else
    return 0;
}


void setUp(char map[ROWS][COLS]){
  system("clear");
  int i;
  int j;
  for( i = 0 ; i < ROWS ; i++){
    for( j = 0 ; j < COLS ; j++){
      map[i][j] = '#';
    }
  }
  srand(time(NULL));
  for( i = 0 ; i < 10 ; i++){
    int valid = 0;
    while( valid != 1){
      int x = rand() % COLS;
      int y = rand() % ROWS;
      printf("%d\tx: %d\ty: %d\n", i,x,y);
      if( map[y][x] != 'B'){
        map[y][x] = 'B';
        valid++;
      }
    }

  }
  int count = 0;
  int bomb = 0;
  for( j = 0 ; j < ROWS ; j++){
    for( i = 0 ; i < COLS ; i++){
      if( map[j][i] == 'B')
        continue;
      if( i - 1 >= 0 && j - 1 >=0 )
        bomb = bomb + checkBomb(map[j-1][i-1]);
      if( j - 1 >= 0)
        bomb = bomb + checkBomb(map[j-1][i]);
      if( i + 1 < COLS && j - 1 >= 0)
        bomb = bomb + checkBomb(map[j-1][i+1]);
      if( i - 1 >= 0)
        bomb = bomb + checkBomb(map[j][i-1]);
      if( i + 1 < COLS)
        bomb = bomb + checkBomb(map[j][i+1]);
      if( i - 1 >= 0 && j + 1 < ROWS)
        bomb = bomb + checkBomb(map[j+1][i-1]);
      if( j + 1 < ROWS)
        bomb = bomb + checkBomb(map[j+1][i]);
      if( i + 1 < COLS && j + 1 < ROWS)
        bomb = bomb + checkBomb(map[j+1][i+1]);
      printf("%d bomb: %d\n",count++,bomb);
      map[j][i] = bomb + 48;
      bomb = 0;

    }
  }

}

void printMap(char map[ROWS][COLS]){
  int i;
  int j;
  for( i = 0 ; i < ROWS ; i++){
    for( j = 0 ; j < COLS ; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main(void){
  char map[ROWS][COLS];
  setUp(map);
  printMap(map);

  return 0;

}
