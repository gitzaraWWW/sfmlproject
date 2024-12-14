#include "Leaf.h"
#include <cstdlib>  // rand() 함수

Leaf::Leaf() {
    if (!ileaf.loadFromFile("image/d-leaf.png")) { //나뭇잎의 이미지 로드
        exit(-1); //로드 실패시 종료
    }
    sprite.setTexture(ileaf); // 이미지 설정
    sprite.setScale(0.8f, 0.8f);  // 크기 줄이기
    setRandomPosition(); // 랜덤한 위치에 생성
    speed = 2.0f; // 나뭇잎의 초기 속도 설정
}
// 나뭇잎의 이동
void Leaf::move() {
    sprite.move(-speed, speed);  // 왼쪽 아래 대각선으로 이동 
}
// 나뭇잎이 화면을 벗어났을 때
void Leaf::resetPositionIfOffScreen() {
    if (sprite.getPosition().x < 0 || sprite.getPosition().y > 720) {
        setRandomPosition();  // 랜덤 위치로 설정
    }
}
// 나뭇잎이 떨어지는 좌표를 설정해 주는 함수
void Leaf::setRandomPosition() {
    float randomX = rand() % 1280; // x축만 랜덤으로 시작
    float yPos = 0; //y축은 0으로 고정
    sprite.setPosition(randomX, yPos);
    speed = 5.0f + static_cast<float>(rand() % 6); // 생성되는 나뭇잎의 속도는 0~5사이에서 랜덤 
}
// 나뭇잎이 날다람쥐와 충돌여부를 반환하는 함수
bool Leaf::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// 나뭇잎의 스프라이트 반환
sf::Sprite& Leaf::getSprite() {
    return sprite;
}