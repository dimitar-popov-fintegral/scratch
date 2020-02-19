#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct Coordinate {
  int x,y;
};

struct Rect {
  struct Coordinate a,b;
};

double sqrt(double);
struct Rect canonic_rect(struct Coordinate, struct Coordinate);

int main(int argc, char *argv[]){

  double dist;
  struct Coordinate pt = {1,1};
  dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
  printf("distance from (0,0), to pt = [%f] \n", dist);
    
  struct Rect r = {{0,0}, {1,1}};

  struct Coordinate x,y,z;
  printf("size of x = [%li] \n", sizeof(x));
  printf("size of y = [%li] \n", sizeof(y));
  printf("size of z = [%li] \n", sizeof(z));

  return 0;

}

struct Rect canonic_rect(struct Coordinate a, struct Coordinate b){

  struct Rect temp;
  temp.a.x = min(a.x, b.x);
  temp.a.y = min(a.y, b.y);
  temp.b.x = max(a.x, b.x);
  temp.b.y = max(a.y, b.y);

  return temp;

}


