#include "Enemy.h"
#include "Vector2.h"
#include "Engine.h"
#include "Bullet.h"
#include "Physic.h"
#include <iostream>
#include "Engine.h"
#include "ContentManagement.h"

bool GBullet::Update(float _deltaTime)
{
	m_movement.X = m_shootDir.X * 2;
	m_movement.Y = m_shootDir.Y * 2;

	TimeSinceLastShot -= _deltaTime;

	CMoveObject::Update(_deltaTime);

	if (TimeSinceLastShot <= 0)
	{
		return false;
	}
	return true;
}
