#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
const float BALL_SPEED = 5.0;

class Ball : public CircleShape
{
public:
	float speedx = BALL_SPEED, speedy = BALL_SPEED;
	Ball(float x, float y) : CircleShape(12.0)
	{
		setPosition(x, y);
		setFillColor(Color(255, 128, 0));
		setOrigin(0, 0);
	}  void update();
};
