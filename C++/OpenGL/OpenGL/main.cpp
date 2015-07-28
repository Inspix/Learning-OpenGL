#include <iostream>
#include <SDL.h>

int main(int n,char **args) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	return 0;
}
