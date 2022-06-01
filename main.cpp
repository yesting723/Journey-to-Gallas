#include <bits/stdc++.h>
#include <SDL.h> 
#define PLAYERIMG "images/player1.bmp"
#undef main
using namespace std;

/*
这是一个基于SDL2的2D RPG游戏，由亚瑟丁 (Yesting723)制作。 
------------------------------------------------------------------

*/

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;
SDL_Surface* surface = NULL;
int px,py;

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

void DrawPlayer(SDL_Renderer* renderer,int x,int y,int playerid)
{
	if(playerid==1)
	{
		surface=SDL_LoadBMP(PLAYERIMG);//在surface加载bmp图片 
		texture=SDL_CreateTextureFromSurface(renderer,surface);//从surface创建贴图纹理 
		SDL_Rect dstrect = {x,y,20,40};
		SDL_RenderCopy(renderer,texture,NULL,&dstrect);
	}//player1形象是一个中/青年男子 
}

void BaseInit()
{
	SDL_SetRenderDrawColor(renderer,100,255,100,255);
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
	while(SDL_WaitEvent(&event))
	{
		SDL_RenderPresent(renderer);
		init(areaid);
		bool f1 = py<=295&&(!(px>=310&&(px+20)<=440)&&!(px>=840&&(px+20)<=970));
		bool f2 = py+40>=425&&(!(px>=310&&(px+20)<=440)&&!(px>=840&&(px+20)<=970));
		bool f3 = ((px<=310)||(px<=840&&(px+20)>=440))&&!(py>=295&&(py+40)<=425);
		bool f4 = (((px+20)>=440)||(px<=970&&(px+20)>=840))&&!(py>=295&&(py+40)<=425);
		DrawPlayer(renderer,px,py,1);
		switch(event.type)
		{
			case SDL_KEYDOWN:
				if((event.key.keysym.sym==SDLK_w||event.key.keysym.sym==SDLK_UP)&&!f1&&!(py-2<0)) 
				{
					SDL_Delay(10);
					py-=2;
				}
				else if((event.key.keysym.sym==SDLK_s||event.key.keysym.sym==SDLK_DOWN)&&!f2&&!(py+2+40>720))
				{
					SDL_Delay(10);
					py+=2;
				}
				else if((event.key.keysym.sym==SDLK_a||event.key.keysym.sym==SDLK_LEFT)&&!f3&&!(px-2<0))
				{
					SDL_Delay(10);					
					px-=2;
				}
				else if((event.key.keysym.sym==SDLK_d||event.key.keysym.sym==SDLK_RIGHT)&&!f4&&!(px+2+20>1280))
				{
					SDL_Delay(10);
					px+=2;
				}
		}
	} 
}

int main(int argc, char* args[])
{
	px=311;
	py=296;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Journey to Gallas",100,100,640,480,SDL_WINDOW_MAXIMIZED);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	
	act(1);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	
	
	//退出 
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return 0; 
}
