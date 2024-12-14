#include "ThornBush.h"
#include <cstdlib>  // rand() 함수

ThornBush::ThornBush() {
    if (!ibush.loadFromFile("image/thornbush1.png")) { // 가시덤불의 이미지 로드
        exit(-1); //로드 실패시 종료
    }
    sprite.setTexture(ibush); // 이미지 설정
    setRandomPosition(); // 랜덤한 위치에 생성
    speed = 2.0f; // 가시덤불의 초기속도 설정
}
//가시덤불의 이동
void ThornBush::move() {
    sprite.move(-speed, 0);  // X축 (오른쪽에서 왼쪽)으로 이동
}
// 가시덤불이 화면 밖으로 벗어났을 때
void ThornBush::resetPositionIfOffScreen() {
    if (sprite.getPosition().x < 0) {  // 화면을 벗어나면
        setRandomPosition();  // 랜덤 위치로 설정
    }
}
// 가시덤불이 생성되는 좌표를 설정해주는 함수
void ThornBush::setRandomPosition() {
    float xPos = 1280; // x축은 1280으로 오른쪽 끝 고정
    float randomY = rand() % (600 - 250 + 1) + 250; // y좌표는 250에서 600까지 랜덤 값 생성. 이는 높이를 랜덤하게 만든다.
    sprite.setPosition(xPos, randomY);
    speed = 5.0f + static_cast<float>(rand() % 6); // 가시덤불의 속도는 5에서 6중 랜덤
}
// 가시덤불이 날다람쥐와 충돌여부를 반환해주는 함수
bool ThornBush::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// 가시덤불의 스프라이트 반환
sf::Sprite& ThornBush::getSprite() {
    return sprite;
}