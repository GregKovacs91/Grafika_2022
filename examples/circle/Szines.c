
#include <stdio.h>
#include <SDL2/SDL.h>


int main()
{
    struct Color{
        int red;
        int blue;
        int green;
    }color;
    
    struct Line{
            int startingPoint;
            int endPoint;
            struct Color;
    }
    
    int x,y;
    Unit 32 buttons;
    SDL_PumpEvents();
    
    buttons=SDL_GetMouseState(&x,&y);
    printf("The mouse at x=%d and y=%d", x ,y);
	return 0;
	
    
}