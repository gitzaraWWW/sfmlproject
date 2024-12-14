#include "Dotori.h"
#include <cstdlib>  // rand() 함수

Dotori::Dotori() {
    if (!idotori.loadFromFile("image/dotori.png")) { //도토리 이미지 로드
        exit(-1); //로드 실패시 종료
    }
    sprite.setTexture(idotori); // 이미지 설정
    sprite.setScale(0.3f, 0.3f);  // 크기 줄이기
    setRandomPosition(); // 랜덤한 위치에 생성
    speed = 5.0f + static_cast<float>(rand() % 6);  // 도토리의 초기 속도는 5~10 사이의 랜덤으로
}
//도토리의 이동
void Dotori::move() {
    sprite.move(0, speed);  // y축으로만 이동
}
// 도토리가 화면밖을 벗어났을 때
void Dotori::resetPositionIfOffScreen() {
    if (sprite.getPosition().y > 720) {  // 화면을 벗어나면
        setRandomPosition();  // 랜덤 위치로 설정
    }
}
//도토리의 랜덤 스폰 장소를 설정해주는 함수
void Dotori::setRandomPosition() {
    float randomX = rand() % 1280; //도토리는 x축만 랜덤으로 시작
    float yPos = 0; //y축은 0으로 고정
    sprite.setPosition(randomX, yPos);
    speed = 5.0f + static_cast<float>(rand() % 6); // 도토리의 속도는 5~10 사이의 랜덤으로
}
// 도토리와 날다람쥐의 충돌 여부를 확인하고 반환해주는 함수
bool Dotori::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// 도토리의 스프라이트 반환
sf::Sprite& Dotori::getSprite() {
    return sprite;
}