#include "PositionComponent.h"

PositionComponent::PositionComponent()
{
	std::cout << "PositionComponent " << xpos << ", " << ypos << std::endl;
	xpos = 0;
	ypos = 0;
}

PositionComponent::PositionComponent(int iXpos, int iYpos)
{
	xpos = iXpos;
	ypos = iYpos;
}

int PositionComponent::getx()
{
	return xpos;
}

int PositionComponent::gety()
{
	return ypos;
}

void PositionComponent::setPos(int iXpos, int iYpos)
{
	xpos = iXpos;
	ypos = iYpos;
}

void PositionComponent::update()
{
	std::cout << "PositionComponent " << xpos << ", " << ypos << std::endl;
	xpos++;
	ypos++;
}