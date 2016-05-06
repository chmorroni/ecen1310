#include<stdlib.h>
#include<complex.h>

#include"coord.h"

struct _coord{
  double complex cx;
};

coord * newCoord(void){
  coord * temp = malloc(sizeof(coord));
  if(temp) temp->cx = 0+0*I;
  return temp;
}

void deleteCoord(coord * c){
  free(c);
}

double getX(coord const * c){
  return creal(c->cx);
}

double getY(coord const * c){
  return cimag(c->cx);
}

double getR(coord const * c){
  return cabs(c->cx);
}

double getTheta(coord const * c){
  return carg(c->cx);
}

void setX(coord * c, double x){
  c->cx = x+cimag(c->cx)*I;
}

void setY(coord * c, double y){
  c->cx = creal(c->cx)+y*I;
}

void setR(coord * c, double r){
  c->cx = r * cexp(I*carg(c->cx));
}

void setTheta(coord * c, double th){
  c->cx = cabs(c->cx) * cexp(I*th);
}
