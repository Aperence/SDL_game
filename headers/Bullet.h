#ifndef BULLET_H
#define BULLET_H
#include "SDL.h"
#include "SDL_image.h"
#include "GameObject.h"
#include <vector>

using namespace std;

class Bullet : public GameObject {

public:
	Bullet(const char* texturePath, int x, int y):GameObject(texturePath, x, y){};
	void update();
	void setPhysic(float xv, float yv, float xa, float ya);
	static vector<float> F(vector<float> v);

private:
	vector<float> v = vector<float>({ (float) xpos, (float) ypos, 0.0, 0.0, 0.0, 0.0 });
};

#endif
