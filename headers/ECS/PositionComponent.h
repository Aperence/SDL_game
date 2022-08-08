#pragma once
#include "ECS.h"

class PositionComponent : public Component {
private:
	int xpos, ypos;
public:
	PositionComponent() {
		xpos = ypos = 0;
	};
	PositionComponent(int x, int y) {
		xpos = x;
		ypos = y;
	}
	int x() { return xpos; }
	int y() { return ypos; }
	void setX(int x) { xpos = x; }
	void setY(int y) { ypos = y; }
	void setPos(int x, int y) { xpos = x; ypos = y; }

	void update() override {
		xpos++;
		ypos++;
	}
	void render() override{}
	void init() override {}
};