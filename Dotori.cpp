#include "Dotori.h"
#include <cstdlib>  // rand() �Լ�

Dotori::Dotori() {
    if (!idotori.loadFromFile("image/dotori.png")) { //���丮 �̹��� �ε�
        exit(-1); //�ε� ���н� ����
    }
    sprite.setTexture(idotori); // �̹��� ����
    sprite.setScale(0.3f, 0.3f);  // ũ�� ���̱�
    setRandomPosition(); // ������ ��ġ�� ����
    speed = 5.0f + static_cast<float>(rand() % 6);  // ���丮�� �ʱ� �ӵ��� 5~10 ������ ��������
}
//���丮�� �̵�
void Dotori::move() {
    sprite.move(0, speed);  // y�����θ� �̵�
}
// ���丮�� ȭ����� ����� ��
void Dotori::resetPositionIfOffScreen() {
    if (sprite.getPosition().y > 720) {  // ȭ���� �����
        setRandomPosition();  // ���� ��ġ�� ����
    }
}
//���丮�� ���� ���� ��Ҹ� �������ִ� �Լ�
void Dotori::setRandomPosition() {
    float randomX = rand() % 1280; //���丮�� x�ุ �������� ����
    float yPos = 0; //y���� 0���� ����
    sprite.setPosition(randomX, yPos);
    speed = 5.0f + static_cast<float>(rand() % 6); // ���丮�� �ӵ��� 5~10 ������ ��������
}
// ���丮�� ���ٶ����� �浹 ���θ� Ȯ���ϰ� ��ȯ���ִ� �Լ�
bool Dotori::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// ���丮�� ��������Ʈ ��ȯ
sf::Sprite& Dotori::getSprite() {
    return sprite;
}