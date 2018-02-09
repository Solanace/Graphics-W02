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
	if (x0 == x1) { // Vertical line
		if (y0 < y1) {
			while (y0 <= y1) {
				plot(s, c, x0, y0);
				y0 ++;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c);
		return;
	}
	if (y0 == y1) { // Horizontal line
		if (x0 < x1) {
			while (x0 <= x1) {
				plot(s, c, x0, y0);
				x0 ++;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c);
		return;
	}
	int A = y1 - y0;
	int B = x0 - x1;
	int x = x0, y = y0;
	int d;
	double m = (y1 - y0) * 1.0 / (x1 - x0);
	if (m == 1) {
		if (x0 < x1) {
			while (x0 <= x1) {
				plot(s, c, x0, y0);
				x0 ++;
				y0 ++;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c);
	}
	else if (m == -1) {
		if (x0 < x1) {
			while (x0 <= x1) {
				plot(s, c, x0, y0);
				x0 ++;
				y0 --;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c);
	}
	else if (m > 0 && m < 1) {
		if (x0 < x1) { // Octant I
			d = 2 * A + B;
			while (x <= x1) {
				plot(s, c, x, y);
				if (d > 0) {
					y ++;
					d += 2 * B;
				}
				x ++;
				d += 2 * A;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c); // Octant V
	}
	else if (m > 1) {
		if (x0 < x1) { // Octant II
			d = A + 2 * B;
			while (x <= x1) {
				plot(s, c, x, y);
				if (d < 0) {
					x ++;
					d += 2 * A;
				}
				y ++;
				d += 2 * B;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c); // Octant VI
	}
	else if (m < 0 && m > -1) {
		if (x0 < x1) { // Octant VIII
			d = 2 * A - B;
			while (x <= x1) {
				plot(s, c, x, y);
				if (d < 0) {
					y --;
					d -= 2 * B;
				}
				x ++;
				d += 2 * A;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c); // Octant IV
	}
	else if (m < -1) {
		if (x0 < x1) { // Octant VII
			d = A - 2 * B;
			while (x <= x1) {
				plot(s, c, x, y);
				if (d > 0) {
					x ++;
					d += 2 * A;
				}
				y --;
				d -= 2 * B;
			}
		}
		else draw_line(x1, y1, x0, y0, s, c); // Octant III
	}
}
