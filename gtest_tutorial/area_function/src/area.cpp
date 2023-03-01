// copyright ilove500
#include "area.h"
#define PI 3.1415
#define SQUARE(x) x*x
double area_square(double l){
  return SQUARE(l);
}
double area_circle(double r){
  return SQUARE(r) * PI;
}
