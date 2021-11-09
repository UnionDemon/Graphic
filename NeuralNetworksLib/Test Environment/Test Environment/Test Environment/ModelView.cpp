#include "ModelView.h"

ModelView::ModelView()
{
	app = new (RenderWindow)(VideoMode(1024, 768), "SFML Checkers!", Style::Close | sf::Style::Titlebar);
	app->setFramerateLimit(45);
	e = new Event;
	LoadTextures();
}

ModelView::ModelView(std::string name, int windowHight, int windowWidth)
{
	app = new (RenderWindow)(VideoMode(windowHight, windowWidth), name, Style::Close | sf::Style::Titlebar);
	app->setFramerateLimit(45);
	e = new Event;
	LoadTextures();
}

void ModelView::LoadTextures()
{
	txt = new Text;
	
	whiteSprite = new Sprite[FILD_SIZE * (FILD_SIZE / 2)];
	blueSprite = new Sprite[FILD_SIZE * (FILD_SIZE / 2)];
	greenSprite = new Sprite[FILD_SIZE * FILD_SIZE];
	black—heckerSprite = new Sprite[COUNT_CHECKER];
	white—heckerSprite = new Sprite[COUNT_CHECKER];
	white—heckerSelectSprite = new Sprite;
	black—heckerSelectSprite = new Sprite;

	font.loadFromFile("..\\Debug\\fonts\\CyrilicOld.TTF");
	white.loadFromFile("..\\Debug\\textures\\White.png");
	blue.loadFromFile("..\\Debug\\textures\\Blue.png");
	green.loadFromFile("..\\Debug\\textures\\Green.JPG");
	black—hecker.loadFromFile("..\\Debug\\textures\\blackCh.png");
	white—hecker.loadFromFile("..\\Debug\\textures\\whiteCh.png");
	black—heckerSelect.loadFromFile("..\\Debug\\textures\\blackChSelect.png");
	white—heckerSelect.loadFromFile("..\\Debug\\textures\\whiteChSelect.png");

	for (size_t i = 0; i < FILD_SIZE * (FILD_SIZE / 2); i++)
	{
		whiteSprite[i].setTexture(white);
		blueSprite[i].setTexture(blue);
	}
	greenSprite->setTexture(green);
	
	for (size_t i = 0; i < COUNT_CHECKER; i++)
	{
		black—heckerSprite[i].setTexture(black—hecker);
		white—heckerSprite[i].setTexture(white—hecker);
	}
	black—heckerSelectSprite->setTexture(black—heckerSelect);
	white—heckerSelectSprite->setTexture(white—heckerSelect);

	txt->setFont(font);
	txt->setCharacterSize(FONT_SIZE);
	txt->setFillColor(TEXT_COLOR);
	txt->setStyle(TEXT_TYPE);
}

void ModelView::Start()
{
	GameBoardInit();

	while (app->isOpen())
	{
		app->clear(Color::Black);
		GameBoardUpdate();

		while (app->pollEvent(*e))
		{
			if (e->type == Event::Closed)
				app->close();

			if (e->type == Event::MouseButtonPressed)
				if (e->key.code == Mouse::Left) {
					Select—heckers();
				}

			app->display();
		}
	}
}

void ModelView::GameBoardInit()
{	
	for (int i = 0; i < FILD_SIZE; i++)
		for (int j = 0; j < FILD_SIZE; j++)
		{
			if (i % 2 == 0)
			{
				gridView[i][j] = (j % 2 == 0) ? White : Blue;
			}
			else
			{
				gridView[i][j] = (j % 2 == 0) ? Blue : White;
			}
		}

	for (int i = 0; i < FILD_SIZE; i++)
		for (int j = 0; j < FILD_SIZE; j++)
		{
			if (i % 2 != 0)
			{
				if (j < FILD_SIZE - 5)
					gridLogic[i][j] = (j % 2 == 0) ? WhiteChecker : EmptyChecker;
				if (j > FILD_SIZE - 4)
					gridLogic[i][j] = (j % 2 == 0) ? BlackChecker : EmptyChecker;
				if((j == 3 || j == 4))
					gridLogic[i][j] = EmptyChecker;
			}
			else
			{
				if (j < FILD_SIZE - 5)
					gridLogic[i][j] = (j % 2 == 0) ? EmptyChecker : WhiteChecker;
				if (j > FILD_SIZE - 4)
					gridLogic[i][j] = (j % 2 == 0) ? EmptyChecker : BlackChecker;
				if ((j == 3 || j == 4))
					gridLogic[i][j] = EmptyChecker;
			}
		}
	//
}

void ModelView::GameBoardUpdate()
{

	RectangleShape rectangleBoardWhite(Vector2f((FILD_SIZE + 1) * CELL_SIZE, (FILD_SIZE + 1) * CELL_SIZE));
	rectangleBoardWhite.move(CELL_SIZE / 2, CELL_SIZE / 2);
	rectangleBoardWhite.setFillColor(WHITE);
	app->draw(rectangleBoardWhite);

	
	RectangleShape rectangleBoardBlack(Vector2f(FILD_SIZE * CELL_SIZE + 2, FILD_SIZE * CELL_SIZE + 2));
	rectangleBoardBlack.move(CELL_SIZE - 2, CELL_SIZE - 2);
	rectangleBoardBlack.setFillColor(BLACK);
	app->draw(rectangleBoardBlack);


	int digitStartPosLeftX = CELL_SIZE - CELL_SIZE / 3;
	int digitStartPosRightX = (CELL_SIZE * 9) + CELL_SIZE / 6;
	int charPosX = CELL_SIZE + CELL_SIZE / 3;
	int	charStartPosTopY = CELL_SIZE / 2;
	int	charStartPosBottomY = (CELL_SIZE * 9);

	for (int i = 1, digitPosY = (CELL_SIZE + (CELL_SIZE / 4)); i < 9; i += 1, digitPosY += CELL_SIZE)
	{
		txt->setPosition(digitStartPosLeftX, digitPosY);
		txt->setString(std::to_string(i));
		app->draw(*txt);
		txt->setPosition(digitStartPosRightX, digitPosY);
		txt->setString(std::to_string(i));
		app->draw(*txt);
	}

	for (char ch = 'a'; ch < 'i'; ch += 1, charPosX += CELL_SIZE)
	{
		txt->setPosition(charPosX, charStartPosTopY);
		txt->setString(ch);
		app->draw(*txt);
		txt->setPosition(charPosX, charStartPosBottomY);
		txt->setString(ch);
		app->draw(*txt);
	}
	
	int whiteSpriteIndex = 0;
	int greenSpriteIndex = 0;
	int blueSpriteIndex = 0;
	int white—heckerSpriteIndex = 0;
	int black—heckerSpriteIndex = 0;
	for (int i = 0; i < FILD_SIZE; i++)
		for (int j = 0; j < FILD_SIZE; j++)
		{
			if (gridView[i][j] == White)
			{
				whiteSprite[whiteSpriteIndex].setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
				app->draw(whiteSprite[whiteSpriteIndex]);
				whiteSpriteIndex++;
			}
			else if (gridView[i][j] == Green) {
				greenSprite[greenSpriteIndex].setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
				app->draw(greenSprite[greenSpriteIndex]);
				greenSpriteIndex++;
			}
			else {
				blueSprite[blueSpriteIndex].setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
				app->draw(blueSprite[blueSpriteIndex]);
				blueSpriteIndex++;
			}
			
			if (gridLogic[i][j] == WhiteChecker)
			{
				white—heckerSprite[white—heckerSpriteIndex].setPosition((i + 1) * CELL_SIZE + CELL_SIZE / 8, (j + 1) * CELL_SIZE + CELL_SIZE / 8);
				app->draw(white—heckerSprite[white—heckerSpriteIndex]);
				white—heckerSpriteIndex++;
			}
			else if (gridLogic[i][j] == BlackChecker) {
				black—heckerSprite[black—heckerSpriteIndex].setPosition((i + 1) * CELL_SIZE + CELL_SIZE / 8, (j + 1) * CELL_SIZE + CELL_SIZE / 8);
				app->draw(black—heckerSprite[black—heckerSpriteIndex]);
				black—heckerSpriteIndex++;
			}
		}
}

void ModelView::Select—heckers()
{
	if (!isSelect)
	{
		for (size_t i = 0; i < FILD_SIZE * FILD_SIZE; i++)
		{
			if ((i < 32) && (whiteSprite[i % 32].getGlobalBounds().contains(e->mouseButton.x, e->mouseButton.y)))
			{
				std::cout << "White: " << i + 1 << std::endl;
				std::cout << "mouse x: " << e->mouseButton.x << std::endl;
				std::cout << "mouse y: " << e->mouseButton.y << "\n" << std::endl;
			}
			if ((i < 32) && (blueSprite[i % 32].getGlobalBounds().contains(e->mouseButton.x, e->mouseButton.y)))
			{
				std::cout << "Blue: " << i + 1 << std::endl;
				std::cout << "mouse x: " << e->mouseButton.x << std::endl;
				std::cout << "mouse y: " << e->mouseButton.y << "\n" << std::endl;
			}
			if ((i < 12) && (white—heckerSprite[i % 12].getGlobalBounds().contains(e->mouseButton.x, e->mouseButton.y)))
			{
				
				std::cout << "White Checker Sprite: " << i + 1 << std::endl;
				std::cout << "mouse x: " << e->mouseButton.x << std::endl;
				std::cout << "mouse y: " << e->mouseButton.y << "\n" << std::endl;
				white—heckerSprite[i].setTexture(white—heckerSelect);
				isSelect = true;
			} 
			if ((i < 12) && (black—heckerSprite[i % 12].getGlobalBounds().contains(e->mouseButton.x, e->mouseButton.y)))
			{
				
				std::cout << "Black Checker Sprite: " << i + 1 << std::endl;
				std::cout << "mouse x: " << e->mouseButton.x << std::endl;
				std::cout << "mouse y: " << e->mouseButton.y << "\n" << std::endl;
				black—heckerSprite[i].setTexture(black—heckerSelect);
				isSelect = true;
			}
		}
	}
	else {

	}
}