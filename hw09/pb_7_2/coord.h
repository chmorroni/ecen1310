#ifndef COORD_H_
#define COORD_H_

/* The type declaration of the ADT. */
typedef struct _coord coord;

/* Create a coordinate. */
coord * newCoord(void);

/* Deletes a coordinate. */
void deleteCoord(coord * c);

/* "getters" */
double getX(coord const * c);
double getY(coord const * c);

/* Returns the radius component. */
double getR(coord const * c);

/* Returns the angle component. */
double getTheta(coord const * c);

/* "setters" */
/* For Cartesian coordinates. */
void setX(coord * c, double x);
void setY(coord * c, double y);

/* Set the radius/angle components. */
void setR(coord * c, double r);
void setTheta(coord * c, double th);

#endif
