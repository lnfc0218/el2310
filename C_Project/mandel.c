#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "SDL.h"
#include <time.h>
#include "mandel.h"


SDL_Surface *screen;
/*State all the global variables for drawing the picture*/
double centerX;
double centerY;
double compXMin;
double compXMax;
double compYMin;
double compYMax;

double halfXAxis=2.0;
double halfYAxis;
/* const int sizeX=600;  */
/* const int sizeY=600; */
int sizeX;
int sizeY;


void putpixel(int x, int y, int color)
{
  unsigned int *ptr = (unsigned int*)screen->pixels;
  int lineoffset = y * (screen->pitch / 4);
  ptr[lineoffset + x] = color;
}

int main( int argc, char* args[] )
{
  int w,h;
  char mode;
  printf("Input width and height, seperated by space:\n");
  scanf("%d%d",&w,&h);
  printf("Width: %d\tHeight: %d\n",w,h);
  sizeX=w;
  sizeY=h;
  
  printf("\nChoose a mode to watch the zoom, press 1 for one set or 2 to zoom coontinously\n");
  scanf(" %c",&mode);//put a space before type to skip the enter in buffer

  if(mode=='1')
    {/*set the center to better view the picture*/
      centerX=-0.5;
      centerY=0.0;
    }
  else if(mode=='2')
    {/*this center selection is good to view for many iterations
     can be modified for better view with numerical knowledge*/
      centerX=-0.05;
      centerY=0.65;
    }
  else
    {/*deal with invalid input*/
      printf("Invalid mode!\n");
      return(0);
    }

  halfYAxis=halfXAxis*sizeY/sizeX;

	// Initialize SDL's subsystems - in this case, only video.
  if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) 
  {
    fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
    exit(1);
  }

  // Register SDL_Quit to be called at exit; makes sure things are
  // cleaned up when we quit.
  atexit(SDL_Quit);
    
  // Attempt to create a 640x480 window with 32bit pixels.
  screen = SDL_SetVideoMode(sizeX,sizeY, 32, SDL_SWSURFACE);
  
  // If we fail, return error.
  if ( screen == NULL ) 
  {
    fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    exit(1);
  }

    
  while (1) //loop forever 
    {
      /*set the complex plane axis limit for this zoom*/
      compXMin=centerX-halfXAxis;
      compXMax=centerX+halfXAxis;

      compYMin=centerY-halfYAxis;
      compYMax=centerY+halfYAxis;
      //render stuff
      render();

      if('2'==mode)
	{//if the zoom mode is selected, zoom the picture
	  halfXAxis=0.99*halfXAxis;
	  halfYAxis=0.99*halfYAxis;
	}


    // Check for events.
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
      switch (event.type) 
      {
      case SDL_KEYDOWN:
        break;
      case SDL_KEYUP:
        // If escape is pressed, return (and thus, quit)
        if (event.key.keysym.sym == SDLK_ESCAPE)
          return 0;
        break;
      case SDL_QUIT:
        return(0);
      }
    }
  }

    return 0;
}



void render()
{   
  clock_t start,end;
  // Lock surface if needed
  if (SDL_MUSTLOCK(screen)) 
    if (SDL_LockSurface(screen) < 0) 
      return;
  start=clock();
  int i,j,k;//indexes for iteration
  double Cx,Cy;//real and imaginary parts
  double stepX=(compXMax-compXMin)/sizeX;
  double stepY=(compYMax-compYMin)/sizeY;
  double Zx,Zy;
  double Zx2,Zy2;//Zx2=Zx*Zx+Zx*Zx, Zy2=Zy*Zy+Zy*Zy
  int iter_time=200;	
  int r,g,b,color;
  /*without the step and Zx2,Zy2 the picture would be extremely inaccurate!*/
  for(i=0;i<sizeX;i++)
    {
      Cx=compXMin+i*stepX;//moved to outer circle to save unnecessary multiplications
      for(j=0;j<sizeY;j++)
	{ 
	  //Cx=compXMin+i*stepX;
	  Cy=compYMax-j*stepY;
	  //initialize everything to prepare for iteration
	  Zx=0.0;
	  Zy=0.0;
	  Zx2=0.0;
	  Zy2=0.0;
	  for(k=0;k<iter_time&&((Zx2+Zy2)<4.0);k++)
	    {
	      Zy=2*Zx*Zy + Cy;
	      Zx=Zx2-Zy2+Cx;
	      Zx2=Zx*Zx;
	      Zy2=Zy*Zy;
	    }
	  if (k==iter_time)
	    {
	      putpixel(i,j,0x000000);
	    }
	  else 
	    {
	      double index=k*255/iter_time;
	      r=round(sin(0.024*index+0)*127+128);
	      g=round(sin(0.024*index+2)*127+128);
	      b=round(sin(0.024*index+4)*127+128);
	      color=(r<<16)+(g<<8)+b;//an 0xF takes 4 bits in computer
	      putpixel(i,j,color);
	    }
	}
    }

  end=clock();
  printf("\nElapsed time for this zoom is %f secs.\n",(double)(end-start)/CLOCKS_PER_SEC);
  // Unlock if needed
  if (SDL_MUSTLOCK(screen)) 
      SDL_UnlockSurface(screen);

  // update the whole screen    
  SDL_UpdateRect(screen, 0, 0,sizeX,sizeY);      
}
