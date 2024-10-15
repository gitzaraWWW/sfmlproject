#include<SFML/Graphics.hpp>
#include<windows.h>
#include<string>
#include<vector>
#include<iostream>
using namespace sf;
using namespace std;

class LunarLander{
private:
	double x, y;//������ġ
	double velocity;//�ӵ�
	double fuel;//����
	string status;//�������
	Texture t1, t2;//�ؽ�ó��ü
	Sprite spaceship, burst;//��������Ʈ��ü
	Font font;//��Ʈ��ü
	Text text;//�ؽ�Ʈ��ü
public:
	LunarLander(double h,double v,double f);//������
	void update(double upforce);
	void draw(RenderWindow& window);
};

//�������Լ�
LunarLander::LunarLander(double h,double v,double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("image/lander.png");
	t2.loadFromFile("image/burst.png");
	spaceship.setTexture(t1);
	burst.setTexture(t2);
	spaceship.setPosition(x,y);
	burst.setPosition(x,y+40);
	if(!font.loadFromFile("Arial.ttf")) {
		cout<<"��Ʈ�����������Ҽ�����!"<<endl;
	}
	text.setFont(font);
}

//���Ӿ���
void LunarLander::update(double upforce) {
	if (fuel <= 0) { 
		fuel = 0;
		upforce = 0;
	}  
	fuel = fuel - upforce;
	velocity = velocity - upforce + 0.8;
	y = y + velocity;
	if (y > 430) {
		y = 430;
		velocity = 0;
	}  
	spaceship.setPosition(x, y);
	burst.setPosition(x, y + 40);
	status = "Pressupkey!\nheight: " + to_string(y) + "\nspeed:" + to_string(velocity) + "\nfuel: " + to_string(fuel);
}

//ȭ�鿡���������Ҳ�,������¸��׸���.
void LunarLander::draw(RenderWindow&window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}