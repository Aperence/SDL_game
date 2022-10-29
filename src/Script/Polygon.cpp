#include "Script/Polygon.h"
#include "Script/Polygon_Bullet.h"
#include <Math.h>

Polygon::Polygon(Vector2D c, Vector2D d, double speed, int nb, double rotating_speed, double size, Manager *manager, int nb_bullet)
{
	center = c;
	d.normalize();
	direction = d;
	this->speed = speed;
	angle = 2 * M_PI / nb ;
	angle_rotation = rotating_speed * M_PI / 180.0;
	this->size = size;
	manPtr = manager;
	this->nb_bullet = nb_bullet;
	number_sides = nb;
}

void Polygon::init()
{
}

void Polygon::update()
{
	if (loading) {
		if (number_sides > 4) draw_triangle(index*angle);
		draw_inner(index*angle);
		index++;
		if (index >= number_sides) loading = false;
		return;
	}
	center += direction * speed;

	double length = size * sin(this->angle / 2.0);
	double offset_y = size * cos(this->angle / 2.0);
	double top_offset = length * tan(this->angle);
	if ((center + Vector2D(-top_offset - offset_y, 0)).x > Game::width
		|| (center + Vector2D(top_offset + offset_y, 0)).x < 0
		|| (center + Vector2D(0, top_offset + offset_y)).y < 0
		|| (center + Vector2D(0, -top_offset - offset_y)).y > Game::height) {
		entity->destroy();
	}
}

void Polygon::draw_triangle(double angle)
{

	double length = size * sin(this->angle / 2.0);
	double offset_y = size * cos(this->angle / 2.0);
	Vector2D pos = center + Vector2D(-length, -offset_y);
	Vector2D pos2 = center + Vector2D(length, -offset_y);

	Vector2D dir = Vector2D(length, -length*tan(this->angle)) / nb_bullet;
	Vector2D dir2 = Vector2D(-length, -length * tan(this->angle)) / nb_bullet;

	for (int i = 0; i < nb_bullet +1; i++)
	{
		Entity& e = manPtr->pushEntity();
		
		Vector2D temp = pos;
		temp.rotate_rad(angle, center);

		e.addBehaviour<PolygonBullet>(this, direction, speed, angle_rotation, temp);
		pos += dir;
		
		Entity& e2 = manPtr->pushEntity();

		temp = pos2;
		temp.rotate_rad(angle, center);

		e2.addBehaviour<PolygonBullet>(this, direction, speed, angle_rotation, temp);
		pos2 += dir2;
	}
}

void Polygon::draw_inner(double angle)
{
	double length = size * sin(this->angle / 2.0);
	double offset_y = size * cos(this->angle / 2.0);

	Vector2D pos = center + Vector2D(-length, -offset_y);
	Vector2D dir = Vector2D(2 * length, 0) / nb_bullet;

	for (int i = 0; i < nb_bullet+1; i++)
	{
		Entity& e = manPtr->pushEntity();

		Vector2D temp = pos;
		temp.rotate_rad(angle, center);

		e.addBehaviour<PolygonBullet>(this, direction, speed, angle_rotation, temp);
		pos += dir;
	}
}
