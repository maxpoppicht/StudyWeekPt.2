#include "Enemy.h"
#include "Physic.h"
#include "Engine.h"
/// <summary>
/// Bearbeitet von Max
/// </summary>
/// <param name="_deltaTime"></param>
/// <returns></returns>
bool GEnemy::Update(float _deltaTime)
{
	m_movement.X = 0.0f;
	m_mirror.X = 0.0f;

	// update parent
	return CMoveObject::Update(_deltaTime);
}