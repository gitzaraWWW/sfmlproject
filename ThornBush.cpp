#include "ThornBush.h"
#include <cstdlib>  // rand() �Լ�

ThornBush::ThornBush() {
    if (!ibush.loadFromFile("image/thornbush1.png")) { // ���ô����� �̹��� �ε�
        exit(-1); //�ε� ���н� ����
    }
    sprite.setTexture(ibush); // �̹��� ����
    setRandomPosition(); // ������ ��ġ�� ����
    speed = 2.0f; // ���ô����� �ʱ�ӵ� ����
}
//���ô����� �̵�
void ThornBush::move() {
    sprite.move(-speed, 0);  // X�� (�����ʿ��� ����)���� �̵�
}
// ���ô����� ȭ�� ������ ����� ��
void ThornBush::resetPositionIfOffScreen() {
    if (sprite.getPosition().x < 0) {  // ȭ���� �����
        setRandomPosition();  // ���� ��ġ�� ����
    }
}
// ���ô����� �����Ǵ� ��ǥ�� �������ִ� �Լ�
void ThornBush::setRandomPosition() {
    float xPos = 1280; // x���� 1280���� ������ �� ����
    float randomY = rand() % (600 - 250 + 1) + 250; // y��ǥ�� 250���� 600���� ���� �� ����. �̴� ���̸� �����ϰ� �����.
    sprite.setPosition(xPos, randomY);
    speed = 5.0f + static_cast<float>(rand() % 6); // ���ô����� �ӵ��� 5���� 6�� ����
}
// ���ô����� ���ٶ���� �浹���θ� ��ȯ���ִ� �Լ�
bool ThornBush::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// ���ô����� ��������Ʈ ��ȯ
sf::Sprite& ThornBush::getSprite() {
    return sprite;
}