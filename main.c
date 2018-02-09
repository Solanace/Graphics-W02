#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
	screen s;
	color c;

	c.red = 255;
	c.green = 165;
	c.blue = 0;

	clear_screen(s);
	// P (undefined, 0)
	draw_line(75, 150, 75, 350, s, c); // Undefined
	draw_line(75, 350, 175, 350, s, c); // 0
	draw_line(175, 350, 175, 280, s, c); // Undefined
	draw_line(175, 280, 75, 280, s, c); // 0
	// W (II/VI, III/VII)
	draw_line(225, 350, 275, 150, s, c); // VII
	draw_line(275, 150, 325, 350, s, c); // II
	draw_line(375, 150, 325, 350, s, c); // III
	draw_line(425, 350, 375, 150, s, c); // VI
	// Diamond (1, -1)
	c.blue = 200;
	draw_line(100, 315, 125, 340, s, c); // 1
	draw_line(125, 340, 150, 315, s, c); // -1
	draw_line(125, 290, 100, 315, s, c); // -1
	draw_line(150, 315, 125, 290, s, c); // 1
	// Triangle (I/V, IV/VIII)
	c.red = 100;
	c.green = 255;
	draw_line(225, 150, 425, 150, s, c); // 0
	draw_line(225, 150, 275, 125, s, c); // VIII
	draw_line(325, 100, 275, 125, s, c); // IV
	draw_line(325, 100, 375, 125, s, c); // I
	draw_line(425, 150, 375, 125, s, c); // V	
	
	display(s);
	save_extension(s, "lines.png");
}
