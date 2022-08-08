#include "Bullet.h"
#include "Utils.h"
#include "Game.h"

vector<float> Bullet::F(vector<float> v) {
	vector<float> ret = vector<float>(v.size());
	ret[0] = v[2];   // xpos = x_speed
	ret[1] = v[3];	 // ypos = y_speed
	ret[2] = v[4];   // x_speed = x_acc
	ret[3] = v[5];   // y_speed = y_acc
	ret[4] = v[4];
	ret[5] = v[5];
	return ret;
}

void Bullet::setPhysic(float xv, float yv, float xa, float ya) {
	v[2] = xv;
	v[3] = yv;
	v[4] = xa;
	v[5] = ya;
}

void Bullet::update() {
	v = Utils::RK4(v, Bullet::F, 1.0/60.0);
	xpos = (int) v[0];
	ypos = (int) v[1];
	GameObject::update();

}