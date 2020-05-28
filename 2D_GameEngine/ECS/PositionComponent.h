#pragma once
#include "ECS.h"

class PositionComponent : public Component
{
private:
	int xpos;
	int ypos;

public:
	PositionComponent();
	PositionComponent(int iXpos, int iYpos);

	int getx();
	int gety();
	void setPos(int iXpos, int iYpos);
	void update();
};


