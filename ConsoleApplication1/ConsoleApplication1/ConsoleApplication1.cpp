#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

#define WiNDOW_HIGHT 1024			// Высота окна
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
	White = 1
};



int main()
{
	//Окно
	RenderWindow app(VideoMode(WiNDOW_HIGHT, WINDOW_WIDTH), "SFML Сheckers!", Style::Close | sf::Style::Titlebar);
	
	//Поля
	int gridLogic[FILD_SIZE][FILD_SIZE]; // Логическое поле
	int gridView[FILD_SIZE][FILD_SIZE]; // Графическое поле 
	
	// Загрузка текстур и создание спрайта для клеток
	Texture white;
	Texture blue;
	white.loadFromFile("..\\Debug\\textures\\White.png");
	blue.loadFromFile("..\\Debug\\textures\\Blue.png");
	
	Sprite whiteSprite(white);
	Sprite blueSprite(blue);
	//

	//Создание текста
	Font font;
	font.loadFromFile("..\\Debug\\fonts\\CyrilicOld.TTF");

	Text txt;
	txt.setFont(font);
	txt.setPosition(50, 50); // надо убрать
	txt.setString("TESSSSSTT");
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
	//

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		app.clear(Color::Black); // заливка экрана в чёрный
			
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
		

		//рисование определённых квадратов на поле
		for (int i = 0; i < FILD_SIZE; i++)
			for (int j = 0; j < FILD_SIZE; j++)
			{
				
				if (gridView[i][j] == 1)
				{
					// Устанавливаем его в заданную позицию...
					whiteSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
					//	Отрисовывание
					app.draw(whiteSprite);
				}else {
					// Устанавливаем его в заданную позицию
					blueSprite.setPosition((i + 1) * CELL_SIZE, (j + 1) * CELL_SIZE);
					// Отрисовывание
					app.draw(blueSprite);
				}
			}
		// Отображаем всю композицию на экране
		app.draw(txt);
		app.display();

	}
	return 0;
}


//#include <SFML/Graphics.hpp>
//
//using namespace sf;
//
//int main()
//{
//	// Объект, который, собственно, является главным окном приложения
//	RenderWindow window(VideoMode(1024, 768), "SFML Checkers", Style::Close | sf::Style::Titlebar);
//
//	
//	// Главный цикл приложения. Выполняется, пока открыто окно
//	while (window.isOpen())
//	{
//		window.clear(Color(250, 220, 100, 0));
//		
//		// Обрабатываем очередь событий в цикле
//		Event event;
//		while (window.pollEvent(event))
//		{
//			// Пользователь нажал на «крестик» и хочет закрыть окно?
//			if (event.type == Event::Closed)
//				// тогда закрываем его
//				window.close();
//		}
//		// Создаем переменную текстуры
//		Texture texture;
//
//		// Подгружаем нашу текстуру из файла texture.png
//		texture.loadFromFile("D:\\TEST\\ConsoleApplication1\\Debug\\test.jpg");
//		
//		// Создаем спрайт для примера
//		Sprite sprite(texture);
//		
//		// Позиция
//		sprite.setPosition(10, 10); // сначала сдвинем наш спрайт в сторону
//		sprite.scale(0.4, 0.4); // смещение параметров масштабирования относительно текущих значений (1600X1598)
//		
//		sprite.setTextureRect(IntRect(0, 0, 18, 18));
//		
//		window.draw(sprite);
//		
//		// Создаем прямоугольник размером 70х100
//		//RectangleShape rectangle(Vector2f(70.f, 70.f));
//
//		// Перемещаем его в нижний ряд справа от многоугольника
//		//rectangle.move(42.2, 42.5);
//
//		// Устанавливаем ему цвет
//		//rectangle.setFillColor(Color(0, 0, 0, 128));
//
//		// Отрисовка прямоугольника
//		//window.draw(rectangle);
//
//		// Отрисовка окна	
//		window.display();
//	}
//
//	return 0;
//}
