//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <string>
//#include<vector>
//#include<iostream>
//#include "Ball.h"
//using namespace sf;
//using namespace std;
//// ���ٶ��� Ŭ����(Squirrel)
//class Squirrel {
//private:
//	Sprite sprite;
//	Texture iupflysq, idownflysq, isickflysq; // ��, �Ʒ��� �̵��� �� ����� �ؽ�ó
//	float speed; // �̵� �ӵ�
//	int life; // ���ٶ��� ���
//	int score;   // ����
//	bool isSick;  // ���� ���� ����
//	Clock sickClock;  // ���� ������ Ÿ�̸�
//
//public:
//	// ������: ���ٶ����� �ʱ� ����
//	Squirrel(float initialSpeed) {
//		if (!iupflysq.loadFromFile("image/up-flysq.png")) { // ���� �̵��� �� ���� �̹���
//			exit(-1); // �̹��� �ε� ���н� ���α׷� ����
//		}
//		if (!idownflysq.loadFromFile("image/down-flysq.png")) { // �Ʒ��� �̵��� �� ���� �̹���
//			exit(-1); // �̹��� �ε� ���н� ���α׷� ����
//		}
//		if (!isickflysq.loadFromFile("image/sick-flysq.png")) { //�����ٿ� ������� ���� �̹���
//			exit(-1); // �̹��� �ε� ���н� ���α׷� ����
//		}
//		sprite.setTexture(iupflysq); // �⺻ �ؽ�ó�� ���� ���ư��� �̹���
//		sprite.setScale(0.5f, 0.5f);  // ũ�� ���̱�
//		sprite.setPosition(50, 300);  // �ʱ� ��ġ ����
//		speed = initialSpeed;  // �ӵ� ����
//		life = 5;
//		score = 0;
//		isSick = false;
//	}
//	// �̵� �Լ� (2�� ���� ���߰�, ���� ���� �̹����� ����)
//	void move() {
//		if (isSick) {
//			// ���� ������ �� 2�ʰ� ������ ���� ���·� ���ư���
//			if (sickClock.getElapsedTime().asSeconds() >= 2.0f) {
//				isSick = false;
//				sprite.setTexture(iupflysq);  // ���� �̹����� ���ư�
//			}
//		}
//		else {
//			sprite.move(speed, 0);  // ���������� ��� �̵�
//		}
//	}
//	// ���� �� �̹��� ��ȯ
//	void sick() {
//		if (!isSick) {
//			isSick = true;  // ���� ���·� ��ȯ
//			sprite.setTexture(isickflysq);  // ���� �̹����� ����
//			sickClock.restart();  // Ÿ�̸� �ʱ�ȭ
//		}
//	}
//
//	// ���� �̵�
//	void moveUp() {
//		if (!isSick) {
//			sprite.move(0, -5);
//			sprite.setTexture(iupflysq);  // ���� ���ư��� �̹��� ���
//		}
//	}
//	// �Ʒ��� �̵�
//	void moveDown() {
//		if (!isSick) {
//			sprite.move(0, 5);
//			sprite.setTexture(idownflysq);  // �Ʒ��� ���ư��� �̹��� ���
//		}
//	}
//	// �ڷ� �̵�(��������)
//	void moveLeft() {
//		if (!isSick) {
//			sprite.move(-5, 0);  // �������� �̵�
//		}
//	}
//	// ��������Ʈ ��ȯ
//	Sprite& getSprite() {
//		return sprite;
//	}
//	// �̵� �ӵ� ����
//	void increaseSpeed() {
//		speed += 0.1f;
//	}
//	// �̵� �ӵ� ����
//	void decreaseSpeed() {
//		speed -= 0.1f;
//	}
//	// �⺻ �ӵ��� �ǵ�����
//	void resetSpeed() {
//		speed = 1.5f;
//	}
//	// �ӵ� ���߱�
//	void stopSpeed() {
//		speed = 0;
//	}
//	// ü�� ����
//	void decreaselife() {
//		if (life > 0) {
//			life--; // ü�� ����
//		}
//	}
//	// ü�� ��ȯ
//	int getHealth() {
//		return life;
//	}
//	// ���� ����
//	void increaseScore() {
//		score++;
//	}
//	// ���� ��ȯ
//	int getScore() {
//		return score;
//	}
//};
//
//// **�θ� Ŭ����**: MoveableObject (���� �������̽� ����)
//class MoveableObject {
//public:
//	virtual void move() = 0; // ���� �Լ��� �����Ͽ� �ڽ� Ŭ�������� ����
//	virtual void resetPositionIfOffScreen() = 0; // ȭ�� ������ ����� ��ġ �缳��
//	virtual Sprite& getSprite() = 0; // ��������Ʈ ��ȯ
//	virtual ~MoveableObject() {} // ���� �Ҹ��� �߰�
//};
//
//// ������ Ŭ���� (Leaf) - MoveableObject ���
//// Leaf Ŭ������ �浹 �˻� �޼��� �߰�
//class Leaf : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture ileaf; // ������ ����� �ؽ�ó
//	float speed; // �̵� �ӵ�
//
//public:
//	// ������: ������ �ʱ� ����
//	Leaf() {
//		if (!ileaf.loadFromFile("image/d-leaf.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(ileaf);
//		sprite.setScale(0.8f, 0.8f);  // ũ�� ���̱�
//		setRandomPosition();
//		speed = 2.0f;
//	}
//
//	// move() �Լ� - �밢������ �̵�
//	void move() override {
//		sprite.move(-speed, speed);  // �밢������ �̵� ���ʾƷ�
//	}
//
//	// ȭ�� ������ ����� ��ġ�� �������� �ٽ� ����
//	void resetPositionIfOffScreen() override {
//		if (sprite.getPosition().x < 0 || sprite.getPosition().y > 720) {
//			setRandomPosition();  // ���� ��ġ�� ����
//		}
//	}
//
//	void setRandomPosition() {
//		float randomX = rand() % 1280;
//		float yPos = 0;
//		sprite.setPosition(randomX, yPos);
//		speed = 5.0f + static_cast<float>(rand() % 6);
//	}
//
//	// �浹 �˻� �޼���
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// ��������Ʈ ��ȯ
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//// ThornBush Ŭ������ �浹 �˻� �޼��� �߰�
//class ThornBush : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture ibush;
//	float speed; // �̵� �ӵ�
//
//public:
//	// ������: ���ô��� �ʱ� ����
//	ThornBush() {
//		if (!ibush.loadFromFile("image/thornbush1.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(ibush);
//		setRandomPosition();
//		speed = 2.0f;
//		sprite.setScale(1.0f, 1.0f);  // ũ�� ����
//	}
//
//	// move() �Լ� - �������� �̵�
//	void move() override {
//		sprite.move(-speed, 0);
//	}
//
//	// ȭ�� ������ ����� ��ġ�� �������� �ٽ� ����
//	void resetPositionIfOffScreen() override {
//		if (sprite.getPosition().x < 0) {
//			setRandomPosition();
//		}
//	}
//
//	void setRandomPosition() {
//		float xPos = 1280;
//		float randomY = rand() % (600 - 250 + 1) + 250;
//		sprite.setPosition(xPos, randomY);
//		speed = 5.0f + static_cast<float>(rand() % 6);
//	}
//
//	// �浹 �˻� �޼���
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// ��������Ʈ ��ȯ
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//
//// Dotori Ŭ������ �浹 �˻� �޼��� �߰�
//class Dotori : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture idotori; // ���丮 ����� �ؽ�ó
//	float speed; // �̵� �ӵ�
//
//public:
//	// ������: ���丮 �ʱ� ����
//	Dotori() {
//		if (!idotori.loadFromFile("image/dotori.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(idotori);
//		sprite.setScale(0.3f, 0.3f);  // ũ�� ���̱�
//		setRandomPosition();
//		speed = 5.0f + static_cast<float>(rand() % 6);
//	}
//
//	// move() �Լ� - �Ʒ��� �̵�
//	void move() override {
//		sprite.move(0, speed);
//	}
//
//	// ȭ�� ������ ����� ��ġ�� �������� �ٽ� ����
//	void resetPositionIfOffScreen() override {
//		if (sprite.getPosition().y > 720) {
//			setRandomPosition();
//		}
//	}
//
//	void setRandomPosition() {
//		float randomX = rand() % 1280;
//		float yPos = 0;
//		sprite.setPosition(randomX, yPos);
//		speed = 5.0f + static_cast<float>(rand() % 6);
//	}
//
//	// �浹 �˻� �޼���
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// ��������Ʈ ��ȯ
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//
//// main �Լ����� ������ ���
//int main() {
//	RenderWindow window(VideoMode(1280, 720), "Mywindow");
//	window.setFramerateLimit(60);
//
//	// ���ȭ�� �����
//	Texture bg;
//	Sprite background;
//	bg.loadFromFile("image/background.png");
//	background.setTexture(bg);
//
//	// ���ٶ��� ����
//	Squirrel squirrel(1.5f);  // �ʱ� �ӵ� 1.5
//	// ������Ʈ ����
//	Leaf leaf;
//	ThornBush thornBush;
//	Dotori dotori;
//
//	// ������ ����
//	vector<MoveableObject*> objects = { &leaf, &thornBush, &dotori };
//
//	// ��Ʈ �����ϱ�
//	Font font;
//	if (!font.loadFromFile("image/maplestory Bold.ttf")) {
//		cout << "��Ʈ�� �ε��� �� �����ϴ�!" << endl;
//		return -1;
//	}
//
//	//��� �ؽ�Ʈ ����
//	Text lifeText;
//	lifeText.setFont(font);
//	lifeText.setCharacterSize(50);
//	lifeText.setFillColor(Color::Red);
//	lifeText.setPosition(1100, 10);  // �ؽ�Ʈ ��ġ ����
//
//	// ���� �ؽ�Ʈ ����
//	Text scoreText;
//	scoreText.setFont(font);
//	scoreText.setCharacterSize(30);
//	scoreText.setFillColor(Color::Black);
//	scoreText.setPosition(10, 10);  // �ؽ�Ʈ ��ġ ����
//
//	while (window.isOpen()) {
//		window.clear(sf::Color::Blue);
//
//		Event event;
//		while (window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		// ������Ʈ�� �̵�
//		for (auto& object : objects) {
//			object->move();  // ������ Ȱ��
//			object->resetPositionIfOffScreen();
//		}
//
//		// �浹 üũ
//		if (leaf.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.stopSpeed();  // �����ٿ� ������ �ӵ� 0���� ��� ����
//			squirrel.sick(); // �����ٿ� ������ �̹��� ����
//			leaf.setRandomPosition(); // �������� �ٽ� ���� ������
//		}
//		if (thornBush.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.decreaselife();  // ���ô��ҿ� ������ ü�� ����
//			thornBush.setRandomPosition(); // ���ô����� �ٽ� ���������� ������
//		}
//		if (dotori.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.increaseScore();  // ���丮�� ������ ���� ����
//			dotori.setRandomPosition(); // ���丮�� �ٽ� ���� ������
//		}
//
//		// ���ٶ��� �ڵ� �̵� (��� ���������� �̵�)
//		squirrel.move();
//
//		// Ű �Է� ó��
//		if (Keyboard::isKeyPressed(Keyboard::D)) {
//			squirrel.increaseSpeed();  // DŰ ������ �� �ӵ� ����
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A)) {
//			squirrel.decreaseSpeed();  // AŰ ������ �� �ӵ� ����
//			squirrel.moveLeft();
//			squirrel.resetSpeed();
//		}
//		if (Keyboard::isKeyPressed(Keyboard::W)) {
//			squirrel.moveUp();  // WŰ ������ �� ���� �̵�
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S)) {
//			squirrel.moveDown();  // SŰ ������ �� �Ʒ��� �̵�
//		}
//
//		// ���� ���� ���� (ü���� 0�� ��� ���� ����)
//		if (squirrel.getHealth() <= 0) {
//			cout << "Game Over!" << endl;
//			window.close();
//		}
//
//		// ���� �� ��� ǥ��
//		scoreText.setString("Score: " + to_string(squirrel.getScore()));
//		// ��� �ؽ�Ʈ ����
//		string lifeString = "";
//		for (int i = 0; i < squirrel.getHealth(); ++i) {
//			lifeString += "V";  // ü�¿� �°� V �߰�
//		}
//		lifeText.setString(lifeString);  // ��� �ؽ�Ʈ ����
//
//		window.draw(background);
//		window.draw(squirrel.getSprite());
//		window.draw(leaf.getSprite());
//		window.draw(thornBush.getSprite());
//		window.draw(dotori.getSprite());
//		window.draw(scoreText);
//		window.draw(lifeText);
//		window.display();
//	}
//	return 0;
//}