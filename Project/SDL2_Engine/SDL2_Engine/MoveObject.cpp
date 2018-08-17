#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Player.h"
#include "Scene.h"
#include "GameOver.h"
#include "World.h"
#include "GameWin.h"
#pragma endregion
/// <summary>
/// Max: mehere collision typen geändert neue erstellt etc. 
/// </summary>
#pragma region public override function
// update every frame
bool CMoveObject::Update(float _deltaTime)
{
	if (m_OnHitDeath == true)
	{
		return false;
	}
	// moveable default true
	bool moveable = true;

	// next position
	SVector2 nextPos = m_position + m_movement * m_speed * _deltaTime;

	// next rect
	SRect nextRect = m_rect;
	nextRect.x = nextPos.X;
	nextRect.y = nextPos.Y;

	if (GetColType() == ECollisionType::MOVE)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}

		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				//if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}

	if (GetColType() == ECollisionType::PLAYER)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// if collision type end continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}

		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::ENEMY)
				{
					if (CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						//Collision with Enemy take 1 damage
						m_PlayerLife -= 1;

						printf("%d\n", m_PlayerLife);
						// if Player 0 Health he dead
						if (m_PlayerLife <= 0)
						{
							SVector2 position = m_position;
							CEngine::Get()->GetCM()->RemoveAll();
							CEngine::Get()->ChangeScene(new GGameOver(position));
						}
					}
				}

				// if collision type player enter Win Screen
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				{
					if (CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						//Collision with Enemy take 1 damage
						m_PlayerLife += 1;
						printf("%d\n", m_PlayerLife);
						// if Player 0 Health he dead
						if (m_PlayerLife >= 4)
						{
							SVector2 position = m_position;
							CEngine::Get()->GetCM()->RemoveAll();
							CEngine::Get()->ChangeScene(new GGameWin(position));
						}
					}
				}

				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::OBSTACL)
				{
					if (CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						//Collision with Enemy take 1 damage
						m_PlayerLife -= 1;

						printf("%d\n", m_PlayerLife);
						// if Player 0 Health he dead
						if (m_PlayerLife <= 0)
						{
							SVector2 position = m_position;
							CEngine::Get()->GetCM()->RemoveAll();
							CEngine::Get()->ChangeScene(new GGameOver(position));
						}
					}
				}

				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::DUMMY)
				{
					if (CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						//Collision with Enemy take 1 damage
						m_PlayerLife -= 1;

						printf("%d\n", m_PlayerLife);
						// if Player 0 Health he dead
						if (m_PlayerLife <= 0)
						{
							SVector2 position = m_position;
							CEngine::Get()->GetCM()->RemoveAll();
							CEngine::Get()->ChangeScene(new GGameOver(position));
						}
					}
				}

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}

	if (GetColType() == ECollisionType::ENEMY)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// if collision type end continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}

		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				//if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}

	if (GetColType() == ECollisionType::OBSTACL)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type end continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}



		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}

	if (GetColType() == ECollisionType::DUMMY)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type end continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}



		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}

	if (GetColType() == ECollisionType::BULLET)
	{

		// through all scene objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// if collision type end continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
				continue;

			// if collision type player
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::PLAYER)
				continue;

			//if collision type  bullet continue
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::BULLET)
				continue;

			// if collision type wall
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::WALL)
			{
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());
			}
			continue;
			// if collision type obstacl
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::OBSTACL)
			{
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());
			}
			continue;
		
		}

		// if moveable
		if (moveable)
		{
			// through all persistant objects
			for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				// if collision type none continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// if collision type player continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::PLAYER)
					continue;

				// if collision type end continue
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::END)
					continue;

				// if collision type enemy, kill enemy
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::ENEMY)
				{
					//max: kill on collision
					if(CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						// kills the enemy
						((CTexturedObject*)pObj)->Kill();
						return false;
					}
				}

				// if collision type dummy, kill dummy
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::DUMMY)
				{
					//max: kill on collision
					if (CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()))
					{
						// kills the enemy
						((CTexturedObject*)pObj)->Kill();
						return false;
					}
				}
				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}



	// if moveable
	if (moveable)
	{
		// add position by movement * speed
		m_position = nextPos;

		// set position of rect
		m_rect.x = m_position.X;
		m_rect.y = m_position.Y;
	}

	// if no gravity return
	if (!m_gravity)
		return true;

	// set moveable true
	moveable = true;

	// set next rect down
	nextRect = m_rect;

	// set y value
	nextRect.y += GRAVITY_VALUE * m_fallTime * m_fallTime + 1;

	// through all scene objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
	{
		// if current object is self continue
		if ((CMoveObject*)pObj && pObj == this)
			continue;

		// if collision type none
		if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			continue;

		// set moveable by checking collision
		moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

		// if not moveable cancel collision check
		if (!moveable)
			break;
	}

	// if moveable
	if (moveable)
	{
		// through all persistant objects
		for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if collision type none
			if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
				continue;

			// set moveable by checking collision
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}
	}

	// if still moveable set y position
	if (moveable)
	{
		m_position.Y += GRAVITY_VALUE * m_fallTime * m_fallTime;
		m_rect.y = m_position.Y;
		m_grounded = false;
		m_fallTime += _deltaTime;
	}

	// gravity active and not moveable
	else
	{
		m_fallTime = 0.001f;
		m_grounded = true;
	}
	return true;
}

// render every frame
void CMoveObject::Render(CRenderer * _pRenderer)
{
	CTexturedObject::Render(_pRenderer);
}
#pragma endregion