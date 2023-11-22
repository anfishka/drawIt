#include <SFML/Graphics.hpp>



int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "DrawIt");

	sf::Texture cursorTexture;

	if (!cursorTexture.loadFromFile("C://Users//Hanna//source//repos//circOnClick//pencil.png"))
	{
		return -1;
	}

	sf::Cursor cursor;

	if (!cursor.loadFromPixels(cursorTexture.copyToImage().getPixelsPtr(), { 32,32 }, { 32,32 }))
	{
		return -1;
	}

	window.setMouseCursor(cursor);


	sf::CircleShape greenCirc;
	greenCirc.setFillColor(sf::Color::Green);
	greenCirc.setRadius(1);
	float positionX = 0.0;
	float positionY = 0.0;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{

				window.close();

			}
		}

		if (event.type == sf::Event::MouseMoved) {
			positionX = event.mouseMove.x;
			positionY = event.mouseMove.y;
			greenCirc.setPosition(positionX, positionY);
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				greenCirc.setPosition(positionX, positionY);


			}

		}

		sf::RectangleShape pencilBtn(sf::Vector2f(100, 50));
		pencilBtn.setFillColor(sf::Color::Blue);
		pencilBtn.setPosition(0, 100);
		window.draw(pencilBtn);

		sf::RectangleShape earaserBtn(sf::Vector2f(100, 50));
		earaserBtn.setFillColor(sf::Color::Red);
		earaserBtn.setPosition(0, 200);
		window.draw(earaserBtn);

		sf::RectangleShape shapesBtn(sf::Vector2f(100, 50));
		shapesBtn.setFillColor(sf::Color::Green);
		shapesBtn.setPosition(0, 300);
		window.draw(shapesBtn);

		window.draw(greenCirc);

		window.display();
	}
	return 0;
}






