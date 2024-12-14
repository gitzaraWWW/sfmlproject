#ifndef LEAF_H
#define LEAF_H

#include "MoveableObject.h" 

class Leaf : public MoveableObject { //MoveableObject를 상속받는다
private:
    sf::Sprite sprite; // 나뭇잎의 스프라이트 객체 (이미지)
    sf::Texture ileaf;  // 나뭇잎 사용할 텍스처 (이미지 파일)
    float speed; // 나뭇잎의 이동 속도

public:
    // 생성자 : 나뭇잎 초기 설정
    Leaf();
    // override : 부모에서 상속받아 재정의한다는 의미
    // 나뭇잎의 이동 구현
    void move() override;
    // 나뭇잎이 화면을 벗어났을 때
    void resetPositionIfOffScreen() override;
    // 나뭇잎의 랜덤 위치 함수
    void setRandomPosition();
    //날다람쥐와 나뭇잎의 충돌했을 때
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    //나뭇잎의 스프라이트 반환
    sf::Sprite& getSprite() override;
};

#endif // LEAF_H