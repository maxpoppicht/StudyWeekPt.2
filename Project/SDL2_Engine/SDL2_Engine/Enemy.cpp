#include "Enemy.h"
#include "Physic.h"
#include "Engine.h"

bool GEnemy::Update(float _deltaTime)
{
	m_movement.X = -1.0f;
	m_mirror.X = 1.0f;

	// update parent
	return CMoveObject::Update(_deltaTime);
}