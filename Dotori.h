#ifndef DOTORI_H
#define DOTORI_H

#include "MoveableObject.h"

class Dotori : public MoveableObject { //MoveableObject를 상속받는다
private:
    sf::Sprite sprite; // 도토리의 스프라이트 객체 (이미지)
    sf::Texture idotori;  // 도토리 사용할 텍스처 (이미지 파일)
    float speed; // 도토리의 이동 속도

public:
    // 생성자 : 도토리 초기 설정
    Dotori();
    // override : 부모에서 상속받아 재정의한다는 의미
    // 도토리의 이동 구현
    void move() override;
    // 도토리가 화면을 벗어났을 때
    void resetPositionIfOffScreen() override;
    // 도토리의 랜덤 위치 함수
    void setRandomPosition();
    // 날다람쥐와 도토리가 충돌했을 때
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    // 도토리의 스프라이트 반환
    sf::Sprite& getSprite() override;
};

#endif // DOTORI_H
