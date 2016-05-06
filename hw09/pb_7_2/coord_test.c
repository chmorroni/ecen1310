#include <stdio.h>
#include <math.h>   /* defines atan */
#include "coord.h"

int main(void) {
  coord * c = newCoord();

  setX(c, 1.0);
  /* c is (1,0), so th should be 0 */
  printf("%g (0)\n", getTheta(c));

  setY(c, .5);
  /* c is (1,.5), so th should be atan(.5/1) */
  printf("%g (%g)\n", getTheta(c), atan(0.5));

  setX(c, 0.0);
  setY(c, 0.0);
  /* c is (0,0) */
  printf("%g (0)\n", getTheta(c));

  setY(c, 1.0);
  /* c is (0,1) */
  printf("%g,%g (0,1)\n", getX(c), getY(c));

  setTheta(c, 3.14159265359);
  /* c is (-1,0) */
  printf("%g,%g (-1,0)\n", getX(c), getY(c));

  deleteCoord(c);

  return 0;
}
