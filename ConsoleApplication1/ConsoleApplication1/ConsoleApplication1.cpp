#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

#define WINDOW_HIGHT 1024			// Высота окна
#define WINDOW_WIDTH 768			// Ширина окна
#define FILD_SIZE 8					// размер игрового поля
#define CELL_SIZE 66				// Размер ячейки привязан к размеру картинки (чуть больше для создания линий между ячейками)
#define FONT_SIZE 24				// Размер шрифта
#define BLACK Color(0, 0, 0)		// Чёрный цвет
#define WHITE Color(255, 255, 255)	// Белый цвет
#define TEXT_TYPE Text::Bold		// Тип текста
#define TEXT_COLOR Color::Black		// Цвет текста

enum CellType						//Типы ячейки
{
	Blue = 0,
	White = 1,
	Green = 2
};

enum CheckerType					//Типы шашки
{
	BlackChecker = 0,
	WhiteChecker = 1,
	KilledChecker = 2
};

int main()
{
			//Окно
	RenderWindow app(VideoMode(WINDOW_HIGHT, WINDOW_WIDTH), "SFML Checkers!", Style::Close | sf::Style::Titlebar);
	
			//Поля
			// Логическое поле
	int gridLogic[FILD_SIZE][FILD_SIZE];
			// Графическое поле 
	int gridView[FILD_SIZE][FILD_SIZE];
	
			// Загрузка текстур и создание спрайта для клеток
	Texture white;
	Texture blue;
	Texture green;
	Texture blackСhecker;
	Texture whiteСhecker;

	white.loadFromFile("..\\Debug\\textures\\White.png");
	blue.loadFromFile("..\\Debug\\textures\\Blue.png");
	green.loadFromFile("..\\Debug\\textures\\Green.JPG");
	blackСhecker.loadFromFile("..\\Debug\\textures\\blackCh.png");
	whiteСhecker.loadFromFile("..\\Debug\\textures\\whiteCh.png");
	
	Sprite whiteSprite(white);
	Sprite blueSprite(blue);
	Sprite greenSprite(green);
	Sprite blackСheckerSprite(blackСhecker);
	Sprite whiteСheckerSprite(whiteСhecker);
			//

			//Создание текста
	Font font;
	font.loadFromFile("..\\Debug\\fonts\\CyrilicOld.TTF");

	Text txt;
	txt.setFont(font);
	txt.setCharacterSize(FONT_SIZE);
	txt.setFillColor(TEXT_COLOR);
	txt.setStyle(TEXT_TYPE);
			//

			//Заполнить графическое поле значениями
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
	gridView[1][1] = Green;
			//

			//Заполнить логическое поле значениями
	for (int i = 0; i < FILD_SIZE; i++)
		for (int j = 0; j < FILD_SIZE; j++)
		{
			if (i % 2 == 0)
			{
				gridLogic[i][j] = (j % 2 == 0) ? WhiteChecker : BlackChecker;
			}
			else
			{
				gridLogic[i][j] = (j % 2 == 0) ? BlackChecker : WhiteChecker;
			}
		}
			//

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}
			// заливка экрана в чёрный
		app.clear(Color::Black);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		
			//Создаем белый прямоугольник (главная подложка доски) 
		RectangleShape rectangleBoardWhite(Vector2f((FILD_SIZE + 1)* CELL_SIZE, (FILD_SIZE + 1)* CELL_SIZE));
			//Перемещаем его в нижний ряд справа от многоугольника
		rectangleBoardWhite.move(CELL_SIZE / 2, CELL_SIZE / 2);
			//Устанавливаем ему цвет
		rectangleBoardWhite.setFillColor(WHITE);
			//Отрисовка прямоугольника
		app.draw(rectangleBoardWhite);

			//Создаем чёрный прямоугольник (заполнение промежутков между ячейками)
		RectangleShape rectangleBoardBlack(Vector2f(FILD_SIZE * CELL_SIZE + 2, FILD_SIZE * CELL_SIZE + 2));
			//Перемещаем его в нижний ряд справа от многоугольника
		rectangleBoardBlack.move(CELL_SIZE - 2, CELL_SIZE - 2);
			//Устанавливаем ему цвет
		rectangleBoardBlack.setFillColor(BLACK);
			//Отрисовка прямоугольника
		app.draw(rectangleBoardBlack);
		
			//Отрисовка букв и цифр на поле
			//координаты для букв
		int digitStartPosLeftX = CELL_SIZE - CELL_SIZE / 3;
		int digitStartPosRightX = (CELL_SIZE * 9) + CELL_SIZE / 6;
			//координаты для букв
		int charPosX = CELL_SIZE + CELL_SIZE / 3;
		int	charStartPosTopY = CELL_SIZE / 2;
		int	charStartPosBottomY = (CELL_SIZE * 9) ;

		for (int i = 1, digitPosY = (CELL_SIZE + (CELL_SIZE / 4)); i < 9; i += 1, digitPosY += CELL_SIZE)
		{
				//
			txt.setPosition(digitStartPosLeftX, digitPosY);
			txt.setString(std::to_string(i));
			app.draw(txt);
				//
			txt.setPosition(digitStartPosRightX, digitPosY);
			txt.setString(std::to_string(i));
			app.draw(txt);
		}

		for (char ch = 'a'; ch < 'i'; ch += 1, charPosX += CELL_SIZE)
		{
				//
			txt.setPosition(charPosX, charStartPosTopY);
			txt.setString(ch);
			app.draw(txt);
				//
			txt.setPosition(charPosX, charStartPosBottomY);
			txt.setString(ch);
			app.draw(txt);
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

			//рисование определённых квадратов на поле
		for (int i = 0; i < FILD_SIZE; i++)
			for (int j = 0; j < FILD_SIZE; j++)
			{
				if (gridView[i][j] == White)
				{
						// Устанавливаем его в заданную позицию...
					whiteSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
						//	Отрисовывание
					app.draw(whiteSprite);
				} else if (gridView[i][j] == Green) {
						// Устанавливаем его в заданную позицию
					greenSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
						// Отрисовывание
					app.draw(greenSprite);
				}else {
						// Устанавливаем его в заданную позицию
					blueSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
						// Отрисовывание
					app.draw(blueSprite);
				}
			}

			//рисование шашек на поле
		for (int i = 0; i < FILD_SIZE; i++)
			for (int j = 0; j < FILD_SIZE; j++)
			{
				if (gridLogic[i][j] == WhiteChecker)
				{
						// Устанавливаем его в заданную позицию...
					whiteСheckerSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
						//	Отрисовывание
					app.draw(whiteСheckerSprite);
				}else {
						// Устанавливаем его в заданную позицию
					blackСheckerSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
						// Отрисовывание
					app.draw(blackСheckerSprite);
				}
			}
		
			// Отображаем всю композицию на экране
		app.display();
	}
	return 0;
}