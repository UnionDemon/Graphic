#pragma once
#include "SFML/Graphics.hpp"
#include <time.h>
#include <iostream>
#include <string>

#define FILD_SIZE 8					
#define CELL_SIZE 66				
#define FONT_SIZE 24				
#define BLACK Color(0, 0, 0)		
#define WHITE Color(255, 255, 255)	
#define TEXT_TYPE Text::Bold		
#define TEXT_COLOR Color::Black		
#define COUNT_CHECKER 12

using namespace sf;

enum CellType						
{
	Blue = 0,
	White = 1,
	Green = 2
};

enum CheckerTypeBoard				
{
	BlackChecker = 0,
	WhiteChecker = 1,
	KilledChecker = 2,
	EmptyChecker = 3
};

class ModelView
{
private:
	RenderWindow *app;
	Event *e;

	Font font;
	Text *txt;
	
	Texture white;
	Texture blue;
	Texture green;
	Texture black—hecker;
	Texture white—hecker;
	Texture black—heckerSelect;
	Texture white—heckerSelect;
	
	Sprite *whiteSprite;
	Sprite *blueSprite;
	Sprite *greenSprite;
	Sprite *black—heckerSprite;
	Sprite *white—heckerSprite;
	
	Sprite* black—heckerSelectSprite;
	Sprite* white—heckerSelectSprite;

	int windowHight;
	int windowWidth;
	int gridLogic[FILD_SIZE][FILD_SIZE];
	int gridView[FILD_SIZE][FILD_SIZE];
	
	bool isSelect = false;
	
	std::string name;
public:
	ModelView();

	ModelView(std::string name, int windowHight, int windowWidth);

	~ModelView() 
	{
		free(app);
		free(e);
		free(txt);
	}

	void Start();
	void GameBoardInit();
	void GameBoardUpdate();
	void LoadTextures();
	void Select—heckers();
	
};

