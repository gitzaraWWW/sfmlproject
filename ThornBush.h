#ifndef THORNBUSH_H
#define THORNBUSH_H

#include "MoveableObject.h"

class ThornBush : public MoveableObject { //MoveableObject�� ��ӹ޴´�
private:
    sf::Sprite sprite; // ���ô����� ��������Ʈ ��ü(�̹���)
    sf::Texture ibush; // ���ô����� ����� �ؽ��� (�̹��� ����)
    float speed; // ���ô����� �̵� �ӵ�

public:
    // ������ : ���ô��� �ʱ� ����
    ThornBush();
    // override : �θ𿡼� ��ӹ޾� ������ �Ѵٴ� �ǹ�
    // ���ô����� �̵� ����
    void move() override;
    // ���ô����� ȭ�� ������ ����� ��
    void resetPositionIfOffScreen() override;
    // ���ô����� ���� ��ġ �Լ�
    void setRandomPosition();
    // ���ô��Ұ� ���ٶ��㰡 �浹���� ��
    bool isCollidingWithSquirrel(sf::Sprite& squirrelSprite);
    // ���ô����� ��������Ʈ ��ȯ
    sf::Sprite& getSprite() override;
};

#endif // THORNBUSH_H