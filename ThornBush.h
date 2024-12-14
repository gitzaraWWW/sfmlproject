#ifndef THORNBUSH_H
#define THORNBUSH_H

#include "MoveableObject.h"

class ThornBush : public MoveableObject { //MoveableObject를 상속받는다
private:
    sf::Sprite sprite; // 가시덤불의 스프라이트 객체(이미지)
    sf::Texture ibush; // 가시덤불이 사용할 텍스쳐 (이미지 파일)
    float speed; // 가시덤불의 이동 속도

public:
    // 생성자 : 가시덤불 초기 설정
    ThornBush();
    // override : 부모에서 상속받아 재정의 한다는 의미
    // 가시덤불의 이동 구현
    void move() override;
    // 가시덤불이 화면 밖으로 벗어났을 때
    void resetPositionIfOffScreen() override;
    // 가시덤불의 랜덤 위치 함수
    void setRandomPosition();
    // 가시덤불과 날다람쥐가 충돌했을 때
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    // 가시덤불의 스프라이트 반환
    sf::Sprite& getSprite() override;
};

#endif // THORNBUSH_H