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
	Texture green;
	Texture whiteChecker;
	Texture blackChecker;
	white.loadFromFile("D:\\images\\White.png");
	blue.loadFromFile("D:\\images\\Blue.png");
	green.loadFromFile("D:\\images\\texturesGR.jpg");
	whiteChecker.loadFromFile("D:\\images\\whiteCh.jpg");
	blackChecker.loadFromFile("D:\\images\\blackCh.jpg");

	Sprite whiteSprite(white);
	Sprite blueSprite(blue);
	Sprite greenSprite(green);
	Sprite whiteCheckerSprite(whiteChecker);
	Sprite blackCheckerSprite(blackChecker);

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

		//��������� ���� � ���� �� ����
		int digitStartPosLeftX = 40, digitStartPosRightX = 604;
		for (int i = 1, digitPosY = 83; i < 9; i += 1, digitPosY += 66)
		{
			txt.setPosition(digitStartPosLeftX, digitPosY);
			txt.setString(std::to_string(i));
			app.draw(txt);
		}
		for (int i = 1, digitPosY = 83; i < 9; i += 1, digitPosY += 66)
		{
			txt.setPosition(digitStartPosRightX, digitPosY);
			txt.setString(std::to_string(i));
			app.draw(txt);
		}

		int charPosX = 87, charStartPosTopY = 33, charStartPosBottomY = 594;
		for (char c = 'a'; c < 'i'; c += 1, charPosX += 66)
		{
			txt.setPosition(charPosX, charStartPosTopY);
			txt.setString(c);
			app.draw(txt);
		}
		charPosX = 87;//���������� ������� X � ��������� ��������� ����� ������� �� �����
		for (char c = 'a'; c < 'i'; c += 1, charPosX += 66)
		{
			txt.setPosition(charPosX, charStartPosBottomY);
			txt.setString(c);
			app.draw(txt);
		}

		//��������� �������� �������� (��������� ����)
		RectangleShape rectangle3(Vector2f(63.f, 63.f));
		//���������� ��� � ...
		rectangle3.move(65, 65);
		//������������� ��� ����
		rectangle3.setFillColor(Color(0, 184, 0));
		//��������� ��������������
		app.draw(rectangle3);

		//��� ����� ������� � ��������!!!
		// ������������� ��� � �������� �������...
		greenSprite.setColor(sf::Color(0, 255, 0, 127));//��� ���������� ��������� �������� - �����-�����
		greenSprite.setPosition(128.f, 128.f);
		// ... � ������������
		app.draw(greenSprite);

		//����� ����� ������� � �������� - ������ ����
		//whiteCheckerSprite.setPosition(161.f, 161.f);
		//app.draw(whiteCheckerSprite);
		//blackCheckerSprite.setPosition(161.f, 161.f);
		//app.draw(blackCheckerSprite);

		// ���������� ��� ���������� �� ������
		app.display();

	}
	return 0;
}