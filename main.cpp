#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_Image.h>
#define PLAYERIMG "images/player1.png"
using namespace std;

/*
这是一个基于SDL2的2D RPG游戏，由亚瑟丁 (Yesting723)制作。 
------------------------------------------------------------------

*/

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
int px,py,pos;

void SDL_DrawFilledRect(SDL_Renderer* renderer,int x,int y,int w,int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_RenderFillRect(renderer,&rect);
} 

void SDL_DrawRoad(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,160,160,160,255);
	SDL_DrawFilledRect(renderer,x,y,80,90);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_DrawFilledRect(renderer,x,y+42,30,6);
	SDL_DrawFilledRect(renderer,x+40,y+42,30,6);
} 

void SDL_DrawRoad2(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,160,160,160,255);
	SDL_DrawFilledRect(renderer,x,y,90,80);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_DrawFilledRect(renderer,x+42,y,6,30);
	SDL_DrawFilledRect(renderer,x+42,y+40,6,30);
} 

void SDL_DrawPavement(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_DrawFilledRect(renderer,x,y,80,16);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,x,y+16,80,4);
	//位于道路上方 
}

void SDL_DrawPavement2(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_DrawFilledRect(renderer,x,y+4,80,16);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,x,y,80,4);
	//位于道路下方 
}

void SDL_DrawPavement3(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_DrawFilledRect(renderer,x,y,16,80);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,x+16,y,4,80);
	//位于道路左侧 
}

void SDL_DrawPavement4(SDL_Renderer* renderer,int x,int y)
{
	SDL_SetRenderDrawColor(renderer,255,239,213,255);
	SDL_DrawFilledRect(renderer,x+4,y,16,80);
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,x,y,4,80);
	//位于道路右侧 
}

void DrawPlayer(SDL_Renderer* renderer,int x,int y,int p)
{
	if(p==1)
	{
		if(pos==1)
		{
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderDrawLine(renderer,x+8,y,x+11,y);
			SDL_DrawFilledRect(renderer,x+6,y+1,8,2); 
			SDL_RenderDrawLine(renderer,x+8,y+3,x+13,y+3);
			SDL_RenderDrawLine(renderer,x+5,y+3,x+5,y+7);
			SDL_RenderDrawLine(renderer,x+14,y+3,x+14,y+7);
			SDL_RenderDrawLine(renderer,x+6,y+8,x+6,y+9);
			SDL_RenderDrawLine(renderer,x+13,y+8,x+13,y+9);
			SDL_RenderDrawLine(renderer,x+5,y+10,x+14,y+10);
			SDL_RenderDrawLine(renderer,x+4,y+10,x+1,y+13);
			SDL_RenderDrawLine(renderer,x+15,y+10,x+18,y+13);
			SDL_RenderDrawLine(renderer,x+1,y+14,x+1,y+19);
			SDL_RenderDrawLine(renderer,x+18,y+14,x+18,y+19);
			SDL_RenderDrawLine(renderer,x+5,y+11,x+5,y+19);
			SDL_RenderDrawLine(renderer,x+14,y+11,x+14,y+19);
			SDL_RenderDrawLine(renderer,x+1,y+20,x+18,y+20);
			SDL_RenderDrawLine(renderer,x+2,y+21,x+2,y+23);
			SDL_RenderDrawLine(renderer,x+2,y+23,x+3,y+23);
			SDL_RenderDrawLine(renderer,x+17,y+21,x+17,y+23);
			SDL_RenderDrawLine(renderer,x+16,y+23,x+17,y+23);
			SDL_RenderDrawLine(renderer,x+4,y+21,x+4,y+28);
			SDL_RenderDrawLine(renderer,x+3,y+29,x+3,y+35);
			SDL_RenderDrawLine(renderer,x+15,y+21,x+15,y+28);
			SDL_RenderDrawLine(renderer,x+16,y+29,x+16,y+35);
			SDL_DrawFilledRect(renderer,x+9,y+23,2,7);
			SDL_RenderDrawLine(renderer,x+8,y+30,x+8,y+35);
			SDL_RenderDrawLine(renderer,x+12,y+30,x+12,y+35);
			SDL_DrawFilledRect(renderer,x+1,y+36,7,4);
			SDL_DrawFilledRect(renderer,x+12,y+36,7,4);
			
			SDL_SetRenderDrawColor(renderer,200,200,200,255);
			SDL_DrawFilledRect(renderer,x+6,y+11,8,9);
			SDL_DrawFilledRect(renderer,x+2,y+13,3,7);
			SDL_DrawFilledRect(renderer,x+15,y+13,3,7);
			SDL_RenderDrawLine(renderer,x+3,y+12,x+4,y+12);
			SDL_RenderDrawLine(renderer,x+4,y+11,x+4,y+12);
			SDL_RenderDrawLine(renderer,x+15,y+12,x+16,y+12);
			SDL_RenderDrawLine(renderer,x+15,y+11,x+15,y+12);
			
			SDL_SetRenderDrawColor(renderer,87,47,23,255);
			SDL_DrawFilledRect(renderer,x+5,y+21,4,9);
			SDL_DrawFilledRect(renderer,x+11,y+21,4,9);
			SDL_DrawFilledRect(renderer,x+4,y+29,4,7);
			SDL_DrawFilledRect(renderer,x+12,y+29,4,7);
			SDL_DrawFilledRect(renderer,x+9,y+21,2,2);
			
			SDL_SetRenderDrawColor(renderer,243,213,150,255);
			SDL_DrawFilledRect(renderer,x+3,y+21,1,2);
			SDL_DrawFilledRect(renderer,x+16,y+21,1,2);
			SDL_DrawFilledRect(renderer,x+7,y+7,6,3);
			SDL_RenderDrawLine(renderer,x+6,y+3,x+6,y+7);
			SDL_RenderDrawLine(renderer,x+13,y+4,x+13,y+7);
			SDL_RenderDrawLine(renderer,x+6,y+4,x+13,y+4);
			SDL_DrawFilledRect(renderer,x+6,y+3,2,2);
			SDL_DrawFilledRect(renderer,x+9,y+5,2,2);
			
			SDL_SetRenderDrawColor(renderer,100,100,100,255);
			SDL_DrawFilledRect(renderer,x+7,y+5,2,1);
			SDL_DrawFilledRect(renderer,x+11,y+5,2,1);
			SDL_SetRenderDrawColor(renderer,255,255,255,255);
			SDL_RenderDrawPoint(renderer,x+7,y+6);
			SDL_RenderDrawPoint(renderer,x+12,y+6);
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderDrawPoint(renderer,x+8,y+6);
			SDL_RenderDrawPoint(renderer,x+11,y+6);
		}
		else if(pos==2)
		{
			SDL_SetRenderDrawColor(renderer,0,0,0,255);
			SDL_RenderDrawLine(renderer,x+8,y,x+11,y);
			SDL_DrawFilledRect(renderer,x+6,y+1,8,2); 
			SDL_RenderDrawLine(renderer,x+8,y+3,x+13,y+3);
			SDL_RenderDrawLine(renderer,x+5,y+3,x+5,y+7);
			SDL_RenderDrawLine(renderer,x+14,y+3,x+14,y+7);
			SDL_RenderDrawLine(renderer,x+6,y+8,x+6,y+9);
			SDL_RenderDrawLine(renderer,x+13,y+8,x+13,y+9);
			SDL_RenderDrawLine(renderer,x+5,y+10,x+14,y+10);
			SDL_RenderDrawLine(renderer,x+4,y+10,x+1,y+13);
			SDL_RenderDrawLine(renderer,x+15,y+10,x+18,y+13);
			SDL_RenderDrawLine(renderer,x+1,y+14,x+1,y+19);
			SDL_RenderDrawLine(renderer,x+18,y+14,x+18,y+19);
			SDL_RenderDrawLine(renderer,x+5,y+11,x+5,y+19);
			SDL_RenderDrawLine(renderer,x+14,y+11,x+14,y+19);
			SDL_RenderDrawLine(renderer,x+1,y+20,x+18,y+20);
			SDL_RenderDrawLine(renderer,x+2,y+21,x+2,y+23);
			SDL_RenderDrawLine(renderer,x+2,y+23,x+3,y+23);
			SDL_RenderDrawLine(renderer,x+17,y+21,x+17,y+23);
			SDL_RenderDrawLine(renderer,x+16,y+23,x+17,y+23);
			SDL_RenderDrawLine(renderer,x+4,y+21,x+4,y+28);
			SDL_RenderDrawLine(renderer,x+3,y+29,x+3,y+35);
			SDL_RenderDrawLine(renderer,x+15,y+21,x+15,y+28);
			SDL_RenderDrawLine(renderer,x+16,y+29,x+16,y+35);
			SDL_DrawFilledRect(renderer,x+9,y+23,2,7);
			SDL_RenderDrawLine(renderer,x+8,y+30,x+8,y+35);
			SDL_RenderDrawLine(renderer,x+12,y+30,x+12,y+35);
			SDL_DrawFilledRect(renderer,x+1,y+36,7,4);
			SDL_DrawFilledRect(renderer,x+12,y+36,7,4);
			
			SDL_SetRenderDrawColor(renderer,200,200,200,255);
			SDL_DrawFilledRect(renderer,x+6,y+11,8,9);
			SDL_DrawFilledRect(renderer,x+2,y+13,3,7);
			SDL_DrawFilledRect(renderer,x+15,y+13,3,7);
			SDL_RenderDrawLine(renderer,x+3,y+12,x+4,y+12);
			SDL_RenderDrawLine(renderer,x+4,y+11,x+4,y+12);
			SDL_RenderDrawLine(renderer,x+15,y+12,x+16,y+12);
			SDL_RenderDrawLine(renderer,x+15,y+11,x+15,y+12);
			
			SDL_SetRenderDrawColor(renderer,87,47,23,255);
			SDL_DrawFilledRect(renderer,x+5,y+21,4,9);
			SDL_DrawFilledRect(renderer,x+11,y+21,4,9);
			SDL_DrawFilledRect(renderer,x+4,y+29,4,7);
			SDL_DrawFilledRect(renderer,x+12,y+29,4,7);
			SDL_DrawFilledRect(renderer,x+9,y+21,2,2);
			
			SDL_SetRenderDrawColor(renderer,243,213,150,255);
			SDL_DrawFilledRect(renderer,x+3,y+21,1,2);
			SDL_DrawFilledRect(renderer,x+16,y+21,1,2);
			SDL_DrawFilledRect(renderer,x+7,y+7,6,3);
			SDL_RenderDrawLine(renderer,x+6,y+3,x+6,y+7);
			SDL_RenderDrawLine(renderer,x+13,y+4,x+13,y+7);
			SDL_RenderDrawLine(renderer,x+6,y+4,x+13,y+4);
			SDL_DrawFilledRect(renderer,x+6,y+3,2,2);
			SDL_DrawFilledRect(renderer,x+9,y+5,2,2);
			
			SDL_SetRenderDrawColor(renderer,0,0,0,255); 
			SDL_DrawFilledRect(renderer,x+6,y+3,8,4);
			SDL_RenderDrawLine(renderer,x+8,y+7,x+11,y+7);
		}
	}
		
}

void QuitGame()
{
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
} 

void BaseInit()
{
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_DrawFilledRect(renderer,0,0,1280,720);
	for(int i=0; i<=1200; i+=80)
	{
		SDL_DrawPavement(renderer,i,296);
		SDL_DrawRoad(renderer,i,316);
		SDL_DrawPavement2(renderer,i,406);
	} //绘制横向道路 
	for(int i=0; i<=640; i+=80)
	{
		SDL_DrawPavement3(renderer,311,i);
		SDL_DrawRoad2(renderer,331,i);
		SDL_DrawPavement4(renderer,421,i);
	} //绘制纵向道路1
	for(int i=0; i<=640; i+=80)
	{
		SDL_DrawPavement3(renderer,841,i);
		SDL_DrawRoad2(renderer,861,i);
		SDL_DrawPavement4(renderer,951,i);
	} //绘制纵向道路2
	for(int i=0; i<=1200; i+=80) SDL_DrawRoad(renderer,i,316); 
	//修整道路重叠部分
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,311,312,16,4);
	SDL_DrawFilledRect(renderer,311,406,16,4);
	SDL_DrawFilledRect(renderer,425,312,16,4);
	SDL_DrawFilledRect(renderer,425,406,16,4);
	//修整人行道重叠部分（纵向道路1） 
	SDL_SetRenderDrawColor(renderer,200,183,130,255);
	SDL_DrawFilledRect(renderer,841,312,16,4);
	SDL_DrawFilledRect(renderer,841,406,16,4);
	SDL_DrawFilledRect(renderer,955,312,16,4);
	SDL_DrawFilledRect(renderer,955,406,16,4);
	//修整人行道重叠部分（纵向道路2） 
	/*
	1280*720
	路宽：130
	1020*590
	
	310*295 400*315 310*295
	310*295 400*315 310*295 
	*/ 
}

void init(int areaid)
{
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	BaseInit();
}

void act(int areaid)
{
	int px,py;
	px=312;
	py=296;
	SDL_Event event;
	pos=1;
	while(SDL_WaitEvent(&event))
	{
		SDL_RenderPresent(renderer);
		init(areaid);
		DrawPlayer(renderer,px,py,1);
		//!(py>=296&&py+40<426)&&!(((px>=311&&px+20<441)||(px>=841&&px+20<971)))
		switch(event.type)
		{
			case SDL_KEYDOWN:
				if((event.key.keysym.sym==SDLK_w||event.key.keysym.sym==SDLK_UP)&&!(!(py-2>=296&&py-2+40<426)&&!(((px>=311&&px+20<441)||(px>=841&&px+20<971))))) 
				{	
					pos=2;
					py-=2;
					if(py<0) py+=2;
					else continue;
				}
				else if((event.key.keysym.sym==SDLK_s||event.key.keysym.sym==SDLK_DOWN)&&!(!(py+2>=296&&py+2+40<426)&&!(((px>=311&&px+20<441)||(px>=841&&px+20<971)))))
				{	
					pos=1;
					py+=2;
					if(py+40>720) py-=2;
					else continue;
				}
				else if((event.key.keysym.sym==SDLK_a||event.key.keysym.sym==SDLK_LEFT)&&!(!(py>=296&&py+40<426)&&!(((px-2>=311&&px-2+20<441)||(px-2>=841&&px-2+20<971)))))
				{						
					px-=2;
					if(px<0) px+=2;
					else continue;
				}
				else if((event.key.keysym.sym==SDLK_d||event.key.keysym.sym==SDLK_RIGHT)&&!(!(py>=296&&py+40<426)&&!(((px+2>=311&&px+2+20<441)||(px+2>=841&&px+2+20<971)))))
				{
					px+=2;
					if(px+20>1280) px-=2;
					else continue;
				}
				else if(event.key.keysym.sym==SDLK_ESCAPE) QuitGame();
		}
	} 
}


int main(int argc, char* args[])
{
	px=311;
	py=296;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Journey to Gallas",100,100,1280,720,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	act(1);
	
	//退出 
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0; 
}
