#include "lcd.h"
#include <SDL2/SDL.H>

const int SCREEN_WIDTH = 256; //160;
const int SCREEN_HEIGHT = 256 ;//144;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gXOut = NULL;

void lcd_init(void)
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
      //Get window surface
      gScreenSurface = SDL_GetWindowSurface( gWindow );

      gXOut = SDL_CreateRGBSurface(0,
                                  SCREEN_WIDTH,
                                  SCREEN_HEIGHT,
                                  32,
                                  0,
                                  0,
                                  0,
                                  0);
        }
    }
}

void lcd_test_line(void)
{
    uint32_t *p = (uint32_t*)gXOut->pixels;
    for(int i =0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++){
        *p++ = rand(); //pix[i];
    }
}

void lcd_set_pixel(uint8_t x, uint8_t y, uint8_t colour)
{
    uint8_t *p = &gXOut->pixels[x*4 + (y*4<<8)];
    *p = colour;
}

void lcd_refresh(void)
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        //User requests quit
        if( e.type == SDL_QUIT )
        {
            exit(1);
        }
    }
    //Fill the surface white
    //Apply the image
    SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );
    //Update the surface
    SDL_UpdateWindowSurface( gWindow );
}

void lcd_close(void)
{
    //Deallocate surface
    SDL_FreeSurface( gXOut );
    gXOut = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
