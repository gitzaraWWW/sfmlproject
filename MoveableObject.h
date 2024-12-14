#ifndef MOVEABLEOBJECT_H
#define MOVEABLEOBJECT_H

#include <SFML/Graphics.hpp>
using namespace sf;
//Leaf, Dotori, ThornBush�� �θ� Ŭ���� ����
class MoveableObject { 
public:
    virtual void move() = 0;  // ���� �Լ��� �����Ͽ� �ڽ� Ŭ�������� ����
    virtual void resetPositionIfOffScreen() = 0;  // �����Լ�. ȭ�� ������ ����� ��ġ �缳��
    virtual Sprite& getSprite() = 0;  // ���� �Լ�, ��������Ʈ ��ȯ
    virtual ~MoveableObject() {}  // ���� �Ҹ��� �߰� (�ʼ�)
};

#endif 