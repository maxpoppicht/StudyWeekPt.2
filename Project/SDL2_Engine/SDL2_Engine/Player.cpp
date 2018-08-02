#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE
#include <vector>

#pragma region project include
#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Renderer.h"
#include "Time.h"
#include "Vector2.h" ///TODO: DELETE
#include "Bullet.h"
#include "World.h"
#pragma endregion

#pragma region public override function
// update every frame
bool GPlayer::Update(float _deltaTime)
{
	int mouseX;
	int mouseY;
	m_ShootRate -= _deltaTime;
	

	if(SDL_GetMouseState(&mouseX, &mouseY) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{

		if (m_ShootRate <= 0) 
		{

			SVector2 shootDir = SVector2( CEngine::Get()->GetRenderer()->GetCamera().X - m_position.X + SCREEN_WIDTH / 2 - PLAYER_WIDTH / 2 - mouseX,
				CEngine::Get()->GetRenderer()->GetCamera().Y - m_position.Y + SCREEN_HEIGHT / 2 - PLAYER_HEIGHT / 2 - mouseY);


			shootDir = shootDir * -1;

			// create textured object
			GBullet * m_pBullet = new GBullet(
			m_position,
			SVector2(BULLET_WIDTH, BULLET_HEIGHT),
			CEngine::Get()->GetRenderer(),
			"Texture/Character/Weapons/Bullets/Arrow.png", shootDir);
		
			m_pBullet->SetSpeed(BULLET_SPEED);
			m_pBullet->SetColType(ECollisionType::BULLET);

			// add Bullet to bullet list
			CEngine::Get()->GetCM()->AddBullet(m_pBullet);

			

			m_ShootRate = BULLET_SHOOTRATE;
		}
		

	}

	int KeyPressed = 0;

	// if key space is pressed this frame and jump not active and grounded
	if (CInput::GetKeyDown(SDL_SCANCODE_SPACE) && !m_jump && m_grounded)
	{
		// set jump enable, gravity false and set jump time
		m_jump = true;
		m_jumpTime = PLAYER_JUMP_TIME;
		m_gravity = false;
		KeyPressed = 2;
		m_Idle->SetAnimationActive(false);
		m_Run->SetAnimationActive(false);
		m_Jump->SetAnimationActive(true);

	}

	// movement left
	if (CInput::GetKey(SDL_SCANCODE_A))
	{
		// set movement and mirror
		m_movement.X = -1.0f;
		m_mirror.X = 1.0f;
		KeyPressed = 1;
		if (!m_jump)
		{
			m_Idle->SetAnimationActive(false);
			m_Run->SetAnimationActive(true);
			m_Jump->SetAnimationActive(false);
		}
	}

	// movement right
	else if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// set movemenet and mirror
		m_movement.X = 1.0f;
		m_mirror.X = 0.0f;
		KeyPressed = 1;
		if (!m_jump)
		{
			m_Idle->SetAnimationActive(false);
			m_Run->SetAnimationActive(true);
			m_Jump->SetAnimationActive(false);
		}

	}

	// no movement left or right
	else
	{
		if (!m_jump)
		{
			m_Idle->SetAnimationActive(true);
			m_Run->SetAnimationActive(false);
			m_Jump->SetAnimationActive(false);
		}
		m_movement.X = 0.0f;
	}

	

	m_Idle->SetMirror(m_mirror);
	m_Run->SetMirror(m_mirror);
	m_Jump->SetMirror(m_mirror);


	// update parent
	CMoveObject::Update(_deltaTime);

	// if jump enabled
	if(m_jump)
	{
		// decrease jump time
		m_jumpTime -= _deltaTime;

		// if jump time under 0
		if (m_jumpTime <= 0.0f)
		{
			// deactivate jump and activate gravity
			m_jump = false;
			m_gravity = true;
		}

		// moveable default true
		bool moveable = true;

		// next position
		SVector2 nextPos = m_position;
		nextPos.Y -= PLAYER_JUMP_FORCE * _deltaTime;

		// next rect
		SRect nextRect = m_rect;
		nextRect.x = nextPos.X;
		nextRect.y = nextPos.Y;

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
			m_position.Y -= PLAYER_JUMP_FORCE * _deltaTime;
			m_rect.y = m_position.Y;
		}
	}

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(m_position.X + PLAYER_WIDTH / 2, m_position.Y + PLAYER_HEIGHT / 2)
	);

	/// <summary>
	/// TODO: DELETE
	/// </summary>
	// print player position
	//std::string s = "Position Y: ";
	//s += std::to_string(m_position.Y);
	//LOG_ERROR("", s.c_str());

	return true;
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion