#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow app(VideoMode(400, 400), "SFML Works!");
	// Ширина клетки
	int width = 32;
	int gridLogic[9][9];
	int gridView[9][9];
	int fieldCell = 8;

	// Загрузка текстуры и создание спрайта ДЛЯ СИНИХ КЛЕТОК
	Texture t;
	t.loadFromFile("D:\\images\\texturesB.jpg");
	Sprite s(t);

	// Загрузка текстуры и создание спрайта ДЛЯ БЕЛО-ЖЕЛТЫХ КЛЕТОК
	Texture text;
	text.loadFromFile("D:\\images\\texturesYW.jpg");
	Sprite g(text);

	for (int i = 1; i <= fieldCell; i++)
		for (int j = 1; j <= fieldCell; j++)
		{
			gridView[i][j] = fieldCell;
		}

	while (app.isOpen())
	{
		app.clear(Color(255, 255, 255, 0));
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}
		for (int i = 1; i <= fieldCell; i+=2)
			for (int j = 1; j <= fieldCell; j+=1)
			{
				// Вырезаем из спрайта нужный нам квадратик текстуры
				s.setTextureRect(IntRect(gridView[i][j] * width, 0, width, width));
				// Устанавливаем его в заданную позицию...
				s.setPosition(i * width, j * width);
				// ... и отрисовываем
				app.draw(s);
			}
		for (int i = 2; i <= fieldCell; i+=2)
			for (int j = 1; j <= fieldCell; j+=1)
			{
				// Вырезаем из спрайта нужный нам квадратик текстуры
				g.setTextureRect(IntRect(gridView[i][j] * width, 0, width, width));
				// Устанавливаем его в заданную позицию...
				g.setPosition(i * width, j * width);
				// ... и отрисовываем
				app.draw(g);
			}
		// Отображаем всю композицию на экране
		app.display();
	}

	return 0;
}