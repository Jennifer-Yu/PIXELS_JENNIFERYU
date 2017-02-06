//Jennifer Yu
//2-3-17

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  int fd, r, g, b, i, j;
  char line[20];
  srand(1);

  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);

  snprintf(line, sizeof(line), "P3 500 500 255\n");

  write(fd, line, strlen(line));

  for (i=0; i<500; i++) {
    for (j=0; j<500; j++) {

      r = 0;
      g = 191;
      b = 255;
      //deep sky blue

      if (i%2==0) {
        r = 30;
        g = 144;
        b = 255;
        //dodger blue
      }

      if (j%2==0) {
        if (i%2==0) {
          r = 144;
          g = 238;
          b = 144;
          //light green
        }
        else {
          r = 238;
          g = 232;
          b = 170;
          //pale golden rod
        }
      }

      if (i > 100 && i < 400 && j > 100 && j < 400 ) {
        if (rand() % 2 == 1) {
          r = 200;
          g = 0;
          b = 0;
        }
        else {
          r = 100;
          g = 0;
          b = 0;
        }
        /**
        r = 255 - (rand() % 255);
        g = 255 - (rand() % 255);
        b = 255 - (rand() % 255);
        if (rand() % 3 == 1) {
          r = 0;
          g = 0;
          b = 0;
        }
        **/
      }

      if (j > 240 && j < 260) {
        //r = 255 - (rand() % 255);
        g = 255 - (rand() % 255);
        b = 255 - (rand() % 255);
      }

      if (i > 240 && i < 260) {
        r = 255 - (rand() % 255);
        g = 255 - (rand() % 255);
        //b = 255 - (rand() % 255);
      }

      snprintf( line, sizeof(line), "%d %d %d \n", r, g, b);
      write(fd, line, strlen(line));
    }
  }
}
