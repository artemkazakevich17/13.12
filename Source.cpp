#include "setting.h"
#include "header.h"
using namespace sf;
int main() {
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//создание объектов игры
	//ракетки
	RectangleShape leftBat, rightBat;

	initBat(leftBat, leftBatColor, leftBatStartPos);
	initBat(rightBat, rightBatColor, rightBatStartPos);
	rightBat.setPosition(WINDOW_WIDTH - batOffset, (WINDOW_HEIGHT - batHeight) / 2);
	float leftBatSpeedY = 0.f;
	float rightBatSpeedY = 0.f;

	//шарик
	CircleShape ball(ballRadius);
	ball.setFillColor(ballColor);
	ball.setPosition((WINDOW_WIDTH - 2 * ballRadius) / 2,
		(WINDOW_HEIGHT - 2 * ballRadius) / 2);

	float arr_speed[]{ -5.f, -4.f, -3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4.f, 5.f };
	float index = rand() % 10;
	float ball_speedx = arr_speed [index];
	index = rand() % 10;
	float ball_speedy = arr_speed [index];
	// Cчет
	int leftPlayerScore = 0;
	int rightPlayerScore = 0;
	Font font;
	font.loadFromFile("ds-digib.ttf");
	Text leftPlayerScoreText;
	leftPlayerScoreText.setString(std::to_string(leftPlayerScore)); //передать строкук для отображения
	leftPlayerScoreText.setFont(font);
	leftPlayerScoreText.setCharacterSize(64);
	leftPlayerScoreText.setPosition(200.f, 10.f);

	Text rightPlayerScoreText;
	rightPlayerScoreText.setString(std::to_string(rightPlayerScore));
	rightPlayerScoreText.setFont(font);
	rightPlayerScoreText.setCharacterSize(64);
	rightPlayerScoreText.setPosition(550.f, 10.f);


		// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		//1 Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//2 Обновление объектов
		//шарик
		//движение шарика
		ball.move(ball_speedx, ball_speedy);
		//попал-вышел за левую
		if (ball.getPosition().x <= 0)
		{
			// скорость оси x сменилась на противоположную
			ball_speedx = -ball_speedx;
			// правый игрок забил гол
			rightPlayerScore++;
		}
		//ИЛИ ПРАВУЮ ГРАНИЦУ

		if (ball.getPosition().x >= (WINDOW_WIDTH - 2 * ballRadius))
		{
			//сккорость по оси X сменилась на противоположную
			ball_speedx = -ball_speedx;
			leftPlayerScore++;
		}
		//Проверка нажатий клавиш
		//если клавиша W нажата
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			leftBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			leftBatSpeedY = batSpeed;
		}
		//двигаем ракетку
		leftBat.move(0, leftBatSpeedY);
		// и сразу же обнуляем скорость
		leftBatSpeedY = 0;

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			rightBatSpeedY = -batSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			rightBatSpeedY = batSpeed;
		}
		

		//3 Отрисовка окна
		//3.1 Очистка окна
		window.clear() {
			//3.2 Отрисовка объектов (В ПАМЯТИ!)
			window.draw(leftBat);
			window.draw(rightBat);
			window.draw(ball);
			window.draw(leftPlayerText);
		//3.3 вывод на экран
		window.display()
		return 0;
	}
	}
