#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include "Rope.h"
#include "Scene.h"
#include "Define.h"
#include "Player.h"

//Whenever it says total the value is 5
#define total 5

int main(int argc, char **argv)
{
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *texture = NULL;

  //for random number generation
  srand(time(NULL));

  SDL_Init(SDL_INIT_EVERYTHING);

  //create window 1080x720
  window = SDL_CreateWindow("Map", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 860, 720, SDL_WINDOW_SHOWN);
  if(window == NULL)
  {
    std::cout << "window" << SDL_GetError() << std::endl;
  }//end of if statement

  //create renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
  if(renderer == NULL)
  {
    std::cout << "renderer" << SDL_GetError() << std::endl;
  }//end of if statement

  //create an array of ropes
  Rope ropes[5][5];

  //angle of the rope variables
  int angle = 0;
  int xPos = 0;
  int yPos = 100;
  int makeRope = 0;

  for(int y = 0; y < total; y++)
  {
    for(int x = 0; x < total; x++)
    {
      makeRope = rand() % 3;
      xPos+=125;

      if(makeRope == 0)
      {

        ropes[y][x].setMidPointX(xPos);
        ropes[y][x].setMidPointY(yPos);
        angle = rand() % 2;
        ropes[y][x].setAngle(angle);
        ropes[y][x].setTexture("/images/Rope.png", renderer);
      }//end of if statement
    }//end of for loop x
    yPos += 125;
    xPos = 0;
  }//end of for loop y


  //running game
  bool running = true;
  SDL_Event event;

  //Creates an instance of the player.
  Player player;

    //While loop for while the program while it's running.
    while(running)
    {
        SDL_PollEvent(&event);
        switch (event.type)
        {
            //close window
            case SDL_QUIT:
                running = false;
                break;


            /**************************************************************************************************************************
            //OLD CODE moves the player from key input
            //unsure how to do diagonal
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        newCharacter.keyMovement(1);
                        break;
                    case SDLK_RIGHT:
                        newCharacter.keyMovement(2);
                        break;
                    case SDLK_UP:
                        newCharacter.keyMovement(3);
                        break;
                    case SDLK_DOWN:
                        newCharacter.keyMovement(4);
                        break;
                }
                break;
              **********************************************************************************************************************/
            default:
                break;
        }//end of the switch statement

        //makes window background not black
        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);

        //resets the renderer
        SDL_RenderClear(renderer);

        //draws a rectangle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

       //renders ropes to screen
        for(int y = 0; y < total; y++)
	      {
             for(int x = 0; x < total; x++)
             {
                  ropes[y][x].render(ropes[y][x].getMidPoint()->x, ropes[y][x].getMidPoint()->y, NULL, renderer, ropes[y][x].getAngle(), NULL, SDL_FLIP_NONE);
             }//end of for loop with x
        }//end of for loop with y

        //RENDERS the actual Player player; instance of the player class to the window
        player.renderP(renderer);

        //outputs the renderer
        SDL_RenderPresent(renderer);

        //restricts to 60fps
        SDL_Delay(1000/60);
    }//End of while running loop.

  //Closes out the window, renderer, and the texture after the program is completed.
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(texture);
  //Quits things.
  SDL_Quit();

  return 0;
}//end of the main method
