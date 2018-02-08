#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int find_intercept(int x0, int y0, int x1, int y1) {
	double m = (y1 - y0) * 1.0 / (x1 - x0);
	int b = y0 - m * x0;
	return b;
	                                                                                                                                                                                                                                                                  
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

// Octant I
int A = y1 - y0;
int B = x0 - x1;
int C = find_intercept(x0, y0, x1, y1) * (x1 - x0);
//int x = x0, y = y0;
printf("%d\n", A + B + C);

}
