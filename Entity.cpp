#include "Entity.h"

void Entity::setAscii(Ascii *ascii) 
{
	this->ascii = ascii;
}

void Entity::Render(SDL_Surface* dst)
{
	ascii->setPrintColor(color);
	ascii->printAscii(coord.x, coord.y, ch, dst);
}

Entity::Entity()
{
	Entity(' ');
}

Entity::Entity(unsigned char ch, Color color, Coord coord) : ch(ch), color(color), coord(coord)
{
	
}

Entity::~Entity()
{

}
