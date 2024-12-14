#ifndef DOTORI_H
#define DOTORI_H

#include "MoveableObject.h"

class Dotori : public MoveableObject { //MoveableObject�� ��ӹ޴´�
private:
    sf::Sprite sprite; // ���丮�� ��������Ʈ ��ü (�̹���)
    sf::Texture idotori;  // ���丮 ����� �ؽ�ó (�̹��� ����)
    float speed; // ���丮�� �̵� �ӵ�

public:
    // ������ : ���丮 �ʱ� ����
    Dotori();
    // override : �θ𿡼� ��ӹ޾� �������Ѵٴ� �ǹ�
    // ���丮�� �̵� ����
    void move() override;
    // ���丮�� ȭ���� ����� ��
    void resetPositionIfOffScreen() override;
    // ���丮�� ���� ��ġ �Լ�
    void setRandomPosition();
    // ���ٶ���� ���丮�� �浹���� ��
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    // ���丮�� ��������Ʈ ��ȯ
    sf::Sprite& getSprite() override;
};

#endif // DOTORI_H
