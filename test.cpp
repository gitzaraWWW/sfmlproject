//#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <string>
//#include<vector>
//#include<iostream>
//#include "Ball.h"
//using namespace sf;
//using namespace std;
//// 날다람쥐 클래스(Squirrel)
//class Squirrel {
//private:
//	Sprite sprite;
//	Texture iupflysq, idownflysq, isickflysq; // 위, 아래로 이동할 때 사용할 텍스처
//	float speed; // 이동 속도
//	int life; // 날다람쥐 목숨
//	int score;   // 점수
//	bool isSick;  // 아픈 상태 여부
//	Clock sickClock;  // 아픈 상태의 타이머
//
//public:
//	// 생성자: 날다람쥐의 초기 설정
//	Squirrel(float initialSpeed) {
//		if (!iupflysq.loadFromFile("image/up-flysq.png")) { // 위로 이동할 때 나올 이미지
//			exit(-1); // 이미지 로드 실패시 프로그램 종료
//		}
//		if (!idownflysq.loadFromFile("image/down-flysq.png")) { // 아래로 이동할 때 나올 이미지
//			exit(-1); // 이미지 로드 실패시 프로그램 종료
//		}
//		if (!isickflysq.loadFromFile("image/sick-flysq.png")) { //나뭇잎에 닿았을때 나올 이미지
//			exit(-1); // 이미지 로드 실패시 프로그램 종료
//		}
//		sprite.setTexture(iupflysq); // 기본 텍스처는 위로 날아가는 이미지
//		sprite.setScale(0.5f, 0.5f);  // 크기 줄이기
//		sprite.setPosition(50, 300);  // 초기 위치 설정
//		speed = initialSpeed;  // 속도 설정
//		life = 5;
//		score = 0;
//		isSick = false;
//	}
//	// 이동 함수 (2초 동안 멈추고, 이후 원래 이미지로 복귀)
//	void move() {
//		if (isSick) {
//			// 아픈 상태일 때 2초가 지나면 원래 상태로 돌아가기
//			if (sickClock.getElapsedTime().asSeconds() >= 2.0f) {
//				isSick = false;
//				sprite.setTexture(iupflysq);  // 원래 이미지로 돌아감
//			}
//		}
//		else {
//			sprite.move(speed, 0);  // 오른쪽으로 계속 이동
//		}
//	}
//	// 아플 때 이미지 변환
//	void sick() {
//		if (!isSick) {
//			isSick = true;  // 아픈 상태로 전환
//			sprite.setTexture(isickflysq);  // 아픈 이미지로 변경
//			sickClock.restart();  // 타이머 초기화
//		}
//	}
//
//	// 위로 이동
//	void moveUp() {
//		if (!isSick) {
//			sprite.move(0, -5);
//			sprite.setTexture(iupflysq);  // 위로 날아가는 이미지 사용
//		}
//	}
//	// 아래로 이동
//	void moveDown() {
//		if (!isSick) {
//			sprite.move(0, 5);
//			sprite.setTexture(idownflysq);  // 아래로 날아가는 이미지 사용
//		}
//	}
//	// 뒤로 이동(왼쪽으로)
//	void moveLeft() {
//		if (!isSick) {
//			sprite.move(-5, 0);  // 왼쪽으로 이동
//		}
//	}
//	// 스프라이트 반환
//	Sprite& getSprite() {
//		return sprite;
//	}
//	// 이동 속도 증가
//	void increaseSpeed() {
//		speed += 0.1f;
//	}
//	// 이동 속도 감소
//	void decreaseSpeed() {
//		speed -= 0.1f;
//	}
//	// 기본 속도로 되돌리기
//	void resetSpeed() {
//		speed = 1.5f;
//	}
//	// 속도 멈추기
//	void stopSpeed() {
//		speed = 0;
//	}
//	// 체력 감소
//	void decreaselife() {
//		if (life > 0) {
//			life--; // 체력 감소
//		}
//	}
//	// 체력 반환
//	int getHealth() {
//		return life;
//	}
//	// 점수 증가
//	void increaseScore() {
//		score++;
//	}
//	// 점수 반환
//	int getScore() {
//		return score;
//	}
//};
//
//// **부모 클래스**: MoveableObject (공통 인터페이스 정의)
//class MoveableObject {
//public:
//	virtual void move() = 0; // 가상 함수로 선언하여 자식 클래스에서 구현
//	virtual void resetPositionIfOffScreen() = 0; // 화면 밖으로 벗어나면 위치 재설정
//	virtual Sprite& getSprite() = 0; // 스프라이트 반환
//	virtual ~MoveableObject() {} // 가상 소멸자 추가
//};
//
//// 나뭇잎 클래스 (Leaf) - MoveableObject 상속
//// Leaf 클래스에 충돌 검사 메서드 추가
//class Leaf : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture ileaf; // 나뭇잎 사용할 텍스처
//	float speed; // 이동 속도
//
//public:
//	// 생성자: 나뭇잎 초기 설정
//	Leaf() {
//		if (!ileaf.loadFromFile("image/d-leaf.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(ileaf);
//		sprite.setScale(0.8f, 0.8f);  // 크기 줄이기
//		setRandomPosition();
//		speed = 2.0f;
//	}
//
//	// move() 함수 - 대각선으로 이동
//	void move() override {
//		sprite.move(-speed, speed);  // 대각선으로 이동 왼쪽아래
//	}
//
//	// 화면 밖으로 벗어나면 위치를 랜덤으로 다시 설정
//	void resetPositionIfOffScreen() override {
//		if (sprite.getPosition().x < 0 || sprite.getPosition().y > 720) {
//			setRandomPosition();  // 랜덤 위치로 설정
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
//	// 충돌 검사 메서드
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// 스프라이트 반환
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//// ThornBush 클래스에 충돌 검사 메서드 추가
//class ThornBush : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture ibush;
//	float speed; // 이동 속도
//
//public:
//	// 생성자: 가시덤불 초기 설정
//	ThornBush() {
//		if (!ibush.loadFromFile("image/thornbush1.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(ibush);
//		setRandomPosition();
//		speed = 2.0f;
//		sprite.setScale(1.0f, 1.0f);  // 크기 설정
//	}
//
//	// move() 함수 - 왼쪽으로 이동
//	void move() override {
//		sprite.move(-speed, 0);
//	}
//
//	// 화면 밖으로 벗어나면 위치를 랜덤으로 다시 설정
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
//	// 충돌 검사 메서드
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// 스프라이트 반환
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//
//// Dotori 클래스에 충돌 검사 메서드 추가
//class Dotori : public MoveableObject {
//private:
//	Sprite sprite;
//	Texture idotori; // 도토리 사용할 텍스처
//	float speed; // 이동 속도
//
//public:
//	// 생성자: 도토리 초기 설정
//	Dotori() {
//		if (!idotori.loadFromFile("image/dotori.png")) {
//			exit(-1);
//		}
//		sprite.setTexture(idotori);
//		sprite.setScale(0.3f, 0.3f);  // 크기 줄이기
//		setRandomPosition();
//		speed = 5.0f + static_cast<float>(rand() % 6);
//	}
//
//	// move() 함수 - 아래로 이동
//	void move() override {
//		sprite.move(0, speed);
//	}
//
//	// 화면 밖으로 벗어나면 위치를 랜덤으로 다시 설정
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
//	// 충돌 검사 메서드
//	bool isCollidingWithSquirrel(Sprite& squirrelSprite) {
//		return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
//	}
//
//	// 스프라이트 반환
//	Sprite& getSprite() override {
//		return sprite;
//	}
//};
//
//// main 함수에서 다형성 사용
//int main() {
//	RenderWindow window(VideoMode(1280, 720), "Mywindow");
//	window.setFramerateLimit(60);
//
//	// 배경화면 만들기
//	Texture bg;
//	Sprite background;
//	bg.loadFromFile("image/background.png");
//	background.setTexture(bg);
//
//	// 날다람쥐 생성
//	Squirrel squirrel(1.5f);  // 초기 속도 1.5
//	// 오브젝트 생성
//	Leaf leaf;
//	ThornBush thornBush;
//	Dotori dotori;
//
//	// 다형성 벡터
//	vector<MoveableObject*> objects = { &leaf, &thornBush, &dotori };
//
//	// 폰트 지정하기
//	Font font;
//	if (!font.loadFromFile("image/maplestory Bold.ttf")) {
//		cout << "폰트를 로드할 수 없습니다!" << endl;
//		return -1;
//	}
//
//	//목숨 텍스트 설정
//	Text lifeText;
//	lifeText.setFont(font);
//	lifeText.setCharacterSize(50);
//	lifeText.setFillColor(Color::Red);
//	lifeText.setPosition(1100, 10);  // 텍스트 위치 설정
//
//	// 점수 텍스트 설정
//	Text scoreText;
//	scoreText.setFont(font);
//	scoreText.setCharacterSize(30);
//	scoreText.setFillColor(Color::Black);
//	scoreText.setPosition(10, 10);  // 텍스트 위치 설정
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
//		// 오브젝트들 이동
//		for (auto& object : objects) {
//			object->move();  // 다형성 활용
//			object->resetPositionIfOffScreen();
//		}
//
//		// 충돌 체크
//		if (leaf.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.stopSpeed();  // 나뭇잎에 닿으면 속도 0으로 잠시 멈춤
//			squirrel.sick(); // 나뭇잎에 닿으면 이미지 변경
//			leaf.setRandomPosition(); // 나뭇잎을 다시 위로 보내기
//		}
//		if (thornBush.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.decreaselife();  // 가시덤불에 닿으면 체력 감소
//			thornBush.setRandomPosition(); // 가시덤불을 다시 오른쪽으로 보내기
//		}
//		if (dotori.isCollidingWithSquirrel(squirrel.getSprite())) {
//			squirrel.increaseScore();  // 도토리를 먹으면 점수 증가
//			dotori.setRandomPosition(); // 도토리를 다시 위로 보내기
//		}
//
//		// 날다람쥐 자동 이동 (계속 오른쪽으로 이동)
//		squirrel.move();
//
//		// 키 입력 처리
//		if (Keyboard::isKeyPressed(Keyboard::D)) {
//			squirrel.increaseSpeed();  // D키 눌렀을 때 속도 증가
//		}
//		if (Keyboard::isKeyPressed(Keyboard::A)) {
//			squirrel.decreaseSpeed();  // A키 눌렀을 때 속도 감소
//			squirrel.moveLeft();
//			squirrel.resetSpeed();
//		}
//		if (Keyboard::isKeyPressed(Keyboard::W)) {
//			squirrel.moveUp();  // W키 눌렀을 때 위로 이동
//		}
//		if (Keyboard::isKeyPressed(Keyboard::S)) {
//			squirrel.moveDown();  // S키 눌렀을 때 아래로 이동
//		}
//
//		// 게임 종료 조건 (체력이 0일 경우 게임 종료)
//		if (squirrel.getHealth() <= 0) {
//			cout << "Game Over!" << endl;
//			window.close();
//		}
//
//		// 점수 및 목숨 표시
//		scoreText.setString("Score: " + to_string(squirrel.getScore()));
//		// 목숨 텍스트 갱신
//		string lifeString = "";
//		for (int i = 0; i < squirrel.getHealth(); ++i) {
//			lifeString += "V";  // 체력에 맞게 V 추가
//		}
//		lifeText.setString(lifeString);  // 목숨 텍스트 갱신
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