#ifndef LEAF_H
#define LEAF_H

#include "MoveableObject.h" 

class Leaf : public MoveableObject { //MoveableObject�� ��ӹ޴´�
private:
    sf::Sprite sprite; // �������� ��������Ʈ ��ü (�̹���)
    sf::Texture ileaf;  // ������ ����� �ؽ�ó (�̹��� ����)
    float speed; // �������� �̵� �ӵ�

public:
    // ������ : ������ �ʱ� ����
    Leaf();
    // override : �θ𿡼� ��ӹ޾� �������Ѵٴ� �ǹ�
    // �������� �̵� ����
    void move() override;
    // �������� ȭ���� ����� ��
    void resetPositionIfOffScreen() override;
    // �������� ���� ��ġ �Լ�
    void setRandomPosition();
    //���ٶ���� �������� �浹���� ��
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    //�������� ��������Ʈ ��ȯ
    sf::Sprite& getSprite() override;
};

#endif // LEAF_H