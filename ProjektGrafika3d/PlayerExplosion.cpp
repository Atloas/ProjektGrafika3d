#include "PlayerExplosion.h"

#include <SFML\OpenGL.hpp>
#include <gl\GLU.h>

#include "IDs.h"

PlayerExplosion::PlayerExplosion(sf::Vector2f position) : Effect(position)
{
	id = PLAYER_BULLET_EXPLOSION_ID;
}


PlayerExplosion::~PlayerExplosion()
{

}

void PlayerExplosion::draw()
{
	GLUquadric* quadric = gluNewQuadric();
	gluQuadricDrawStyle(quadric, GLU_FILL);
	gluQuadricNormals(quadric, GLU_SMOOTH);
	glPushMatrix();
	glTranslatef(position.x, position.y, height);
	glColor3f(1.0f, 0.7f, 0.0f);
	gluSphere(quadric, 2.0f, 16, 16);
	glPopMatrix();
	gluDeleteQuadric(quadric);
}

void PlayerExplosion::tick(float frameTime)
{
	timer += frameTime;
	if (timer > 1.5f)
		setAlive(false);
}
