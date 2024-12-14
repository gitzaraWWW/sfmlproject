#ifndef MOVEABLEOBJECT_H
#define MOVEABLEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace sf;
//Leaf, Dotori, ThornBush의 부모 클래스 생성
class MoveableObject { 
public:
    virtual void move() = 0;  // 가상 함수로 선언하여 자식 클래스에서 구현
    virtual void resetPositionIfOffScreen() = 0;  // 가상함수. 화면 밖으로 벗어나면 위치 재설정
    virtual Sprite& getSprite() = 0;  // 가상 함수, 스프라이트 반환
    virtual ~MoveableObject() {}  // 가상 소멸자 추가 (필수)
};

#endif 