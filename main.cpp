#include <bits/stdc++.h>
#include <SDL.h> 
using namespace std;

/*
这是一个基于SDL2的2D RPG游戏，由亚瑟丁 (Yesting723)制作。 
------------------------------------------------------------------

*/

SDL_Window* window = NULL;
SDL_Surface* ImageLoader;
SDL_Texture* texture;
SDL_Renderer* renderer = NULL;

void init()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Game",100,100,640,480,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
} 

void SDL_DrawRoad(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,160,160,160,255);
	SDL_Rect rect = {x,y,80,90};
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&rect);
	rect = {x,y+42,30,6};
	SDL_RenderFillRect(renderer,&rect);
	rect = {x+40,y+42,30,6};
	SDL_RenderFillRect(renderer,&rect);
} 

void SDL_DrawPavement(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_Rect rect = {x,y,80,16};
	SDL_RenderFillRect(renderer,&rect);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	rect = {x,y+16,80,4};
	SDL_RenderFillRect(renderer,&rect);
}

void SDL_DrawPavement2(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_Rect rect = {x+4,y,80,16};
	SDL_RenderFillRect(renderer,&rect);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	rect = {x,y,80,4};
	SDL_RenderFillRect(renderer,&rect);
}

void act0101()
{
	
}

int main(int argc, char* args[])
{
	init();
	
	return 0; 
}
