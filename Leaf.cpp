#include "Leaf.h"
#include <cstdlib>  // rand() �Լ�

Leaf::Leaf() {
    if (!ileaf.loadFromFile("image/d-leaf.png")) { //�������� �̹��� �ε�
        exit(-1); //�ε� ���н� ����
    }
    sprite.setTexture(ileaf); // �̹��� ����
    sprite.setScale(0.8f, 0.8f);  // ũ�� ���̱�
    setRandomPosition(); // ������ ��ġ�� ����
    speed = 2.0f; // �������� �ʱ� �ӵ� ����
}
// �������� �̵�
void Leaf::move() {
    sprite.move(-speed, speed);  // ���� �Ʒ� �밢������ �̵� 
}
// �������� ȭ���� ����� ��
void Leaf::resetPositionIfOffScreen() {
    if (sprite.getPosition().x < 0 || sprite.getPosition().y > 720) {
        setRandomPosition();  // ���� ��ġ�� ����
    }
}
// �������� �������� ��ǥ�� ������ �ִ� �Լ�
void Leaf::setRandomPosition() {
    float randomX = rand() % 1280; // x�ุ �������� ����
    float yPos = 0; //y���� 0���� ����
    sprite.setPosition(randomX, yPos);
    speed = 5.0f + static_cast<float>(rand() % 6); // �����Ǵ� �������� �ӵ��� 0~5���̿��� ���� 
}
// �������� ���ٶ���� �浹���θ� ��ȯ�ϴ� �Լ�
bool Leaf::isCollidingWithSquirrel(sf::Sprite& squirrelSprite) {
    return sprite.getGlobalBounds().intersects(squirrelSprite.getGlobalBounds());
}
// �������� ��������Ʈ ��ȯ
sf::Sprite& Leaf::getSprite() {
    return sprite;
}