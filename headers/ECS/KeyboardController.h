#ifndef KEYBOARD_CONTR_H
#define KEYBOARD_CONTR_H
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component {
public:
	void update();
};

#endif
