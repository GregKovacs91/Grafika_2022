#include "brick.h"

#include <math.h>
#include <stdio.h>

void set_size_data(Brick* brick, double a, double b, double c){
	brick->a= a;
	brick->b= b;
	brick->c= c;
}

double calc_volume (const Brick* brick){
	double volume= brick->a * brick->b * brick->c;
	return volume;
}

double calc_surface(const Brick* brick){
	double surface=2*(brick->a * brick->b + brick->a * brick->c + brick->c*brick->b);
	return surface;
}

double calc_rectangle_side(const Brick* brick){
	double res=0;
	if(brick->a == brick->b || brick->a==brick->c || brick->b==brick->c){
		res=1;
	}
	return res;
}