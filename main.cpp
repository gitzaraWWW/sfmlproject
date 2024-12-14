// sfmlproject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>  // 음악 관련 헤더
#include <windows.h>
#include <string>
#include<vector>
#include<iostream>
#include "MoveableObject.h" // Leaf,Dotori,ThornBush의 부모 클래스 헤더
#include "Leaf.h" // MoveableObject의 자식 클래스 Leaf
#include "Dotori.h" // MoveableObject의 자식 클래스 Dotori
#include "ThornBush.h" // MoveableObject의 자식 클래스 ThornBush
using namespace sf;
using namespace std;

// 클래스 다람쥐 생성
class Squirrel {
private:
	Sprite sprite;
	Texture iupflysq, idownflysq, isickflysq; // 위, 아래, 멈췄을 때 사용할 텍스처
	float speed; // 이동 속도
	int life; // 날다람쥐의 목숨
	int score;   // 점수
	bool isSick;  // 아픈 상태 여부 = 아픈상태가 되면 멈추게 하기 위함
	Clock sickClock;  // 아픈 상태를 지속하기 위한 타이머 생성

public:
	// 생성자: 날다람쥐의 초기 설정
	Squirrel(float initialSpeed) {
		if (!iupflysq.loadFromFile("image/up-flysq.png")) { // 위로 이동할 때 나올 이미지
			exit(-1); // 이미지 로드 실패시 프로그램 종료
		}
		if (!idownflysq.loadFromFile("image/down-flysq.png")) { // 아래로 이동할 때 나올 이미지
			exit(-1); // 이미지 로드 실패시 프로그램 종료
		}
		if (!isickflysq.loadFromFile("image/sick-flysq.png")) { //나뭇잎에 닿았을때 나올 이미지
			exit(-1); // 이미지 로드 실패시 프로그램 종료
		}
		sprite.setTexture(iupflysq); // 기본 텍스처는 위로 날아가는 이미지
		sprite.setScale(0.5f, 0.5f);  // 크기 줄이기
		sprite.setPosition(50, 300);  // 초기 위치 설정
		speed = initialSpeed;  // 속도 설정
		life = 5; // 기본 목숨은 5개
		score = 0; // 시작 점수는 0
		isSick = false; // 아픈상태 x
	}
	// 이동 함수
	void move() {
		if (isSick) {
			// 아픈 상태일 때 2초가 지나면 원래 상태로 돌아가기
			if (sickClock.getElapsedTime().asSeconds() >= 2.0f) {
				isSick = false; //2초 후 아픈상태 취소
				sprite.setTexture(iupflysq);  // 원래 이미지로 돌아감
			}
		}
		else {
			sprite.move(speed, 0);  // 기본적으로 오른쪽으로 계속 이동함
		}
	}
	// 아플 때 이미지 변환
	void sick() {
		if (!isSick) { //아픈 상태가 아닐때
			isSick = true;  // 아픈 상태로 전환
			sprite.setTexture(isickflysq);  // 아픈 이미지로 변경
			sickClock.restart();  // 타이머 초기화
		}
	}
	// 위로 이동
	void moveUp() {
		if (!isSick) { // 아프지 않을 때를 넣은 이유 : 아픈상태일때 멈추게 하기 위해서
			sprite.move(0, -5); //y축으로 -5칸만큼 이동
			sprite.setTexture(iupflysq);  // 위로 날아가는 이미지 사용
		}
	}
	// 아래로 이동
	void moveDown() {
		if (!isSick) {
			sprite.move(0, 5); //y축으로 5칸만큼 이동
			sprite.setTexture(idownflysq);  // 아래로 날아가는 이미지 사용
		}
	}
	// 오른쪽으로 이동은 아래 speed를 통해 이뤄짐
	
	// 뒤로 이동(왼쪽으로)
	void moveLeft() {
		if (!isSick) { 
			sprite.move(-5, 0);  // x축으로 -5만큼 이동
		}
	}
	// 스프라이트 반환
	Sprite& getSprite() {
		return sprite;
	}
	// 이동 속도 증가
	void increaseSpeed() {
		speed += 0.1f;
	}
	// 이동 속도 감소
	void decreaseSpeed() {
		speed -= 0.1f;
	}
	// 기본 속도로 되돌리기
	void resetSpeed() {
		speed = 1.5f;
	}
	// 속도 멈추기
	void stopSpeed() {
		speed = 0;
	}
	// 체력 감소
	void decreaselife() {
		if (life > 0) {
			life--; // 체력 감소
		}
	}
	// 체력 반환
	int getHealth() {
		return life;
	}
	// 점수 증가
	void increaseScore() {
		score++;
	}
	// 점수 반환
	int getScore() {
		return score;
	}
};

// 게임 타이틀 화면을 출력하는 함수
void showTitleScreen(RenderWindow& window) {
	Texture titleTexture;
	Sprite titleSprite;
	if (!titleTexture.loadFromFile("image/title.png")) {
		//이미지 업로드에 실패할 시 디버깅을 위함
		cout << "타이틀 이미지를 로드할 수 없습니다!" << endl;
		return;
	}
	titleSprite.setTexture(titleTexture);

	// 타이틀 화면 표시
	window.clear();
	window.draw(titleSprite);
	window.display();
}

// 게임 설명 화면을 보여주는 함수
void showExplanation(RenderWindow& window) {
	Texture explanationTexture;
	Sprite explanationSprite;
	if (!explanationTexture.loadFromFile("image/rule.png")) {
		//이미지 업로드에 실패할 시 디버깅을 위함.
		cout << "설명 이미지를 로드할 수 없습니다!" << endl;
		return;
	}
	explanationSprite.setTexture(explanationTexture);

	// 설명화면 표시
	window.clear();
	window.draw(explanationSprite);
	window.display();
}

// 게임 오버 화면을 표시하는 함수
void showGameOverScreen(RenderWindow& window) {
	Texture gameOverTexture;
	Sprite gameOverSprite;
	if (!gameOverTexture.loadFromFile("image/gameover.png")) {
		//이미지 업로드에 실패할 시 디버깅을 위함.
		cout << "게임 오버 이미지를 로드할 수 없습니다!" << endl;
		return;
	}
	gameOverSprite.setTexture(gameOverTexture);

	// 게임 오버 화면 표시
	window.clear();
	window.draw(gameOverSprite);
	window.display();
}

// main 함수
int main() {
	RenderWindow window(VideoMode(1280, 720), "Mywindow"); //화면은 1280x720
	window.setFramerateLimit(60); //프레임을 60으로 설정

	// 게임의 바탕 브금을 위한 객체 생성
	sf::Music bgm;
	if (!bgm.openFromFile("music/gamebgm.mp3")) {  // 배경 음악 파일 로드
		//배경음악 업로드에 실패할 시 디버깅을 위함.
		cout << "배경 음악을 로드할 수 없습니다!" << endl;
		return -1;
	}
	bgm.setLoop(true);  // 음악을 반복 재생하도록 설정
	bgm.play();  // 음악 재생 시작

	// 충돌 효과음을 위한 객체 생성
	// 각각 나뭇잎, 도토리, 가시덤불이다 마찬가지로 
	// 충돌 효과음 업로드에 실패할 시 디버깅을 위한 cout가 존재한다.
	sf::SoundBuffer leafBuffer, dotoriBuffer, thornBushBuffer;
	sf::Sound leafSound, dotoriSound, thornBushSound;
	if (!leafBuffer.loadFromFile("music/leaf.mp3")) {
		cout << "나뭇잎 충돌음 로드 실패!" << endl;
		return -1;
	}
	if (!dotoriBuffer.loadFromFile("music/dotori.mp3")) {
		cout << "도토리 충돌음 로드 실패!" << endl;
		return -1;
	}
	if (!thornBushBuffer.loadFromFile("music/bush.mp3")) {
		cout << "가시덤불 충돌음 로드 실패!" << endl;
		return -1;
	}
	// 각 효과음에 버퍼 연결
	leafSound.setBuffer(leafBuffer);
	dotoriSound.setBuffer(dotoriBuffer);
	thornBushSound.setBuffer(thornBushBuffer);

	// 타이틀 화면 표시
	showTitleScreen(window);

	// 타이틀 화면에서 키 입력 처리 후 게임 시작
	bool gameStarted = false; // 게임 시작 여부
	bool gameOver = false; // 게임 오버 여부
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}

			// 'P' 키를 누르면 게임 시작
			if (Keyboard::isKeyPressed(Keyboard::P) && !gameStarted) {
				gameStarted = true; // 게임 시작
				break;  // 타이틀 화면 종료 후 게임 진행
			}

			// 'X' 키를 누르면 종료
			if (Keyboard::isKeyPressed(Keyboard::X)) {
				window.close();
				return 0;
			}

			// 'E' 키를 누르면 설명화면 표시
			if (Keyboard::isKeyPressed(Keyboard::E)) {
				showExplanation(window);
			}
			// 게임 오버 됐을 때'P' 키를 누르면 재시작
			if (Keyboard::isKeyPressed(Keyboard::P) && gameOver) {
				gameOver = false; // 게임 오버 상태 종료
				gameStarted = true; // 게임 시작
				// 초기화 및 재시작 로직 추가
				break; // 다시 게임을 시작
			}
		}

		if (gameStarted && !gameOver) {
			// 게임 시작 후 게임의 배경 화면생성
			Texture bg;
			Sprite background;
			bg.loadFromFile("image/background.png");
			background.setTexture(bg);

			// 날다람쥐 생성
			Squirrel squirrel(1.5f);  // 초기 속도 1.5
			// 오브젝트 생성
			Leaf leaf;
			ThornBush thornBush;
			Dotori dotori;

			// 다형성 벡터
			vector<MoveableObject*> objects = { &leaf, &thornBush, &dotori };

			// 목숨과 점수를 위한 폰트 지정하기
			Font font;
			if (!font.loadFromFile("image/maplestory Bold.ttf")) {
				cout << "폰트를 로드할 수 없습니다!" << endl;
				return -1;
			}

			//목숨 텍스트 설정
			Text lifeText;
			lifeText.setFont(font);
			lifeText.setCharacterSize(50); // 텍스트 크기
			lifeText.setFillColor(Color::Red); // 텍스트 색
			lifeText.setPosition(1100, 10);  // 텍스트 위치 설정

			// 점수 텍스트 설정
			Text scoreText;
			scoreText.setFont(font); 
			scoreText.setCharacterSize(30); // 텍스트 크기
			scoreText.setFillColor(Color::Black); // 텍스트 색
			scoreText.setPosition(10, 10);  // 텍스트 위치 설정

			// 게임 루프
			while (window.isOpen()) {
				window.clear(sf::Color::Blue);

				Event event;
				while (window.pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						window.close();
				}

				// 오브젝트들 이동
				for (auto& object : objects) {
					object->move();  // 다형성 활용
					object->resetPositionIfOffScreen(); // 화면 밖으로 나갈 시
				}

				// 충돌 체크
				if (leaf.isCollidingWithSquirrel(squirrel.getSprite())) {
					squirrel.stopSpeed();  // 나뭇잎에 닿으면 속도 0으로 잠시 멈춤
					squirrel.sick(); // 나뭇잎에 닿으면 이미지 변경
					leaf.setRandomPosition(); // 나뭇잎을 다시 위로 보내기
					leafSound.play();  // 나뭇잎 충돌음 재생
				}
				if (thornBush.isCollidingWithSquirrel(squirrel.getSprite())) {
					squirrel.decreaselife();  // 가시덤불에 닿으면 체력 감소
					thornBush.setRandomPosition(); // 가시덤불을 다시 오른쪽으로 보내기
					thornBushSound.play();  // 가시덤불 충돌음 재생
				}
				if (dotori.isCollidingWithSquirrel(squirrel.getSprite())) {
					squirrel.increaseScore();  // 도토리를 먹으면 점수 증가
					dotori.setRandomPosition(); // 도토리를 다시 위로 보내기
					dotoriSound.play();  // 도토리 충돌음 재생
				}

				// 날다람쥐 이동시작 (계속 오른쪽으로 이동함)
				squirrel.move();

				// 키 입력 처리
				if (Keyboard::isKeyPressed(Keyboard::D)) {
					squirrel.increaseSpeed();  // D키 눌렀을 때 속도 증가
				}
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					squirrel.decreaseSpeed();  // A키 눌렀을 때 속도 감소
					squirrel.moveLeft(); // 왼쪽으로 이동 후
					squirrel.resetSpeed(); // 속도를 초기속도로 설정
				}
				if (Keyboard::isKeyPressed(Keyboard::W)) {
					squirrel.moveUp();  // W키 눌렀을 때 위로 이동
				}
				if (Keyboard::isKeyPressed(Keyboard::S)) {
					squirrel.moveDown();  // S키 눌렀을 때 아래로 이동
				}

				// 게임 종료 조건 (체력이 0일 경우 게임 종료)
				if (squirrel.getHealth() <= 0) {
					gameStarted = false; // 게임 종료
					gameOver = true; // 게임 오버 상태
					break;  // 게임 오버 화면 표시
				}

				// 점수 및 목숨 표시
				scoreText.setString("Score: " + to_string(squirrel.getScore()));
				// 목숨 텍스트 갱신
				string lifeString = "";
				for (int i = 0; i < squirrel.getHealth(); ++i) {
					lifeString += "V";  // 체력에 맞게 V 추가(기본 5개)
				}
				lifeText.setString(lifeString);  // 목숨 텍스트 갱신

				window.draw(background);
				window.draw(squirrel.getSprite());
				window.draw(leaf.getSprite());
				window.draw(thornBush.getSprite());
				window.draw(dotori.getSprite());
				window.draw(scoreText);
				window.draw(lifeText);
				window.display();
			}
		}
		if (gameOver) {
			// 게임 오버 화면 표시
			showGameOverScreen(window);

			// 'P' 키로 게임 재시작, 'X' 키로 종료
			while (window.isOpen()) {
				Event event;
				while (window.pollEvent(event)) {
					if (Keyboard::isKeyPressed(Keyboard::X)) {
						window.close();  // 게임 종료
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
