#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow app(VideoMode(1024, 768), "Minesweeper!", Style::Close | sf::Style::Titlebar);

	// ������ ����
	int w = 66;
	int gridLogic[8][8];
	int gridView[8][8];

	// �������� �������� � �������� �������
	Texture white;
	Texture blue;
	white.loadFromFile("D:\\images\\White.png");
	blue.loadFromFile("D:\\images\\Blue.png");

	Sprite whiteSprite(white);
	Sprite blueSprite(blue);

	Font font;
	font.loadFromFile("D:\\SFML_Tutorial\\Debug\\CyrilicOld.TTF");

	Text txt;
	txt.setFont(font);
	txt.setPosition(50, 50);
	txt.setString("TESSSSSTT");
	txt.setCharacterSize(24);
	txt.setFillColor(Color::Black);
	txt.setStyle(Text::Bold);

	//��������� ��� �������� �����
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0) {
					gridView[i][j] = 1;

				}
				else {
					gridView[i][j] = 0;
				}
			}
			else {
				if (j % 2 == 0) {
					gridView[i][j] = 0;

				}
				else {
					gridView[i][j] = 1;
				}
			}
		}

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		app.clear(Color::Black);

		//��������� ���� �����
		RectangleShape rectangle1(Vector2f(594.f, 594.f));
		//���������� ��� � ������ ��� ������ �� ��������������
		rectangle1.move(33, 33);
		//������������� ��� ����
		rectangle1.setFillColor(Color(255, 255, 255));
		//��������� ��������������
		app.draw(rectangle1);

		RectangleShape rectangle2(Vector2f(530.f, 530.f));
		//���������� ��� � ������ ��� ������ �� ��������������
		rectangle2.move(64, 64);
		//������������� ��� ����
		rectangle2.setFillColor(Color(0, 0, 0));
		//��������� ��������������
		app.draw(rectangle2);

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if (gridView[i][j] == 1)
				{
					// ������������� ��� � �������� �������...
					whiteSprite.setPosition((i + 1) * w, (j + 1) * w);
					// ... � ������������
					app.draw(whiteSprite);
				}
				else {
					// ������������� ��� � �������� �������...
					blueSprite.setPosition((i + 1) * w, (j + 1) * w);
					// ... � ������������
					app.draw(blueSprite);
				}
			}

		//��������� ���� � ����
		int digitStartPosX = 40;
		int digitPosY = 83;
		for (int i = 1; i < 9; i += 1, digitPosY += 66)
		{
			txt.setPosition(digitStartPosX, digitPosY);
			txt.setString(std::to_string(i));
			app.draw(txt);
		}

		int charPosX = 83;
		int charStartPosY = 33;
		for (char c = 'a'; c < 'i'; c += 1, charPosX += 66)
		{
			txt.setPosition(charPosX, charStartPosY);
			txt.setString(c);
			app.draw(txt);
		}
		
		

		// ���������� ��� ���������� �� ������
		app.display();

	}
	return 0;
}