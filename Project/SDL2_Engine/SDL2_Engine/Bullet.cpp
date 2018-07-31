#include "Enemy.h"
#include "Vector2.h"
#include "Engine.h"
#include "Bullet.h"
#include "Physic.h"
#include <iostream>

void GBullet::Update(float _deltaTime)
{
	m_movement.X = m_shootDir.X * 2;
	m_movement.Y = m_shootDir.Y * 2;

	CMoveObject::Update(_deltaTime);

		
}
