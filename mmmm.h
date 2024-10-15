#include<SFML/Graphics.hpp>
#include<windows.h>
#include<string>
#include<vector>
#include<iostream>
using namespace sf;
using namespace std;

class LunarLander{
private:
	double x, y;//현재위치
	double velocity;//속도
	double fuel;//연료
	string status;//현재상태
	Texture t1, t2;//텍스처객체
	Sprite spaceship, burst;//스프라이트객체
	Font font;//폰트객체
	Text text;//텍스트객체
public:
	LunarLander(double h,double v,double f);//생성자
	void update(double upforce);
	void draw(RenderWindow& window);
};

//생성자함수
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
		cout<<"폰트파일을오픈할수없음!"<<endl;
	}
	text.setFont(font);
}

//게임업뎃
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

//화면에착륙선과불꽃,현재상태를그린다.
void LunarLander::draw(RenderWindow&window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}