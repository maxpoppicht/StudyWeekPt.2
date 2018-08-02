#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "World.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#include "Enemy.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public function
// initialize world
void GWorld::Init()
{
	// string to define world
	string world;

	// add lines to world string
	// string 100x20
	// 1 block is 64 x 64 pixel
	// screen has 20 (width) and 12 (height) blocks
	// X = dirt (outside)
	// 0 = black (free, background)
	// W = way (walk on)
	// L = lava (death)
	// S = start point of player
	// E = start point of Enemy
	// F = Saloon
	// G = Rock
	world += "1ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n";
	world += "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n";
	world += "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n";
	world += "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
	world += "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
	world += "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
	world += "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
	world += "DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n";
	world += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
	world += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
	world += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
	world += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
	world += "UUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU\n";
	world += "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
	world += "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
	world += "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
	world += "GWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWIWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
	world += "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLJLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLTLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLKLLLLLLLLLLLLLLLLLLLLLLQLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLTLLLLLLLLL\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL2LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLQLLLLLLLLLLLLQLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "LLLLLLLLLLLFLLSLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLFLLLLLLLLLLLLLLLLLLLLLHLLLLLHLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLHLLLLHLLLLLHLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLRRRRRLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRR\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLXXXXXLLLLLLLLLLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAYAAYAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAYAAYAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAAXXXXXCAAAAAAAAAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAXXXXXAAAAAAAAAAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";


	// width and height of world
	int width = 0, height = 1;

	// through world string
	for (int i = 0; i < world.length(); i++)
	{
		// increase width
		width++;

		// if end of line increase height and reset width
		if (world[i] == '\n')
		{
			height++;
			width = 0;
			continue;
		}

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT),
			SVector2(WORLD_BLOCK_WIDTH, WORLD_BLOCK_HEIGHT),
			CEngine::Get()->GetRenderer(),
			"Texture/World/Background_Layer1.png"

		);


		// x position of texture in atlas map
		int xPosOfTexture = 0;

		// switch char in world string
		switch (world[i])
		{
		// if dirt set position of texture in atlas map
		case 'X':
		{
			xPosOfTexture = WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}

		// if way set position of texture in atlas map
		case 'W':
		{
			xPosOfTexture = 6 * WORLD_BLOCK_ATLAS_WIDTH;
			
			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}

		// if lava set position of texture in atlas map
		case 'L':
		{
			xPosOfTexture = 2 * WORLD_BLOCK_ATLAS_WIDTH;
			
			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'A':
		{
			xPosOfTexture = 5 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}

		// if lava set position of texture in atlas map
		case 'B':
		{
			xPosOfTexture = 4 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'R':
		{
			xPosOfTexture = 8 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}
		case 'Z':
		{
			xPosOfTexture = 3 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'V':
		{
			xPosOfTexture = 10 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'D':
		{
			xPosOfTexture = 9 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'U':
		{
			xPosOfTexture = 11 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'N':
		{
			xPosOfTexture = 12 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'M':
		{
			xPosOfTexture = 7 * WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'S':
		{
			// create textured objectd
			GPlayer * pPlayer = new GPlayer(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT), 
				SVector2(94, 124),
				CEngine::Get()->GetRenderer(), 
				"");

			// set player values
			pPlayer->SetSpeed(PLAYER_SPEED);
			pPlayer->SetMirror(PLAYER_MIRROR);
			pPlayer->SetColType(ECollisionType::MOVE);
			pPlayer->ActivateGravity();

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);

			CAnimation* pIdle = new CAnimation(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(94, 124),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Player/Hunter_standing.png", 184,137, 1, 1, 0.1f);

			pIdle->SetMirror(PLAYER_MIRROR);
			pIdle->SetParent(pPlayer);
			pIdle->SetColType(ECollisionType::NONE);
			pIdle->SetAnimationActive(true);
			pPlayer->m_Idle = pIdle;
			CEngine::Get()->GetCM()->AddPersistantObject(pIdle);

			CAnimation* pJump = new CAnimation(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(94, 124),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Player/SS_Hunter_jump.png", 281, 1652, 7, 1, 0.5f);

			pJump->SetMirror(PLAYER_MIRROR);
			pJump->SetParent(pPlayer);
			pJump->SetColType(ECollisionType::NONE);
			pJump->SetAnimationActive(false);
			pPlayer->m_Jump = pJump;
			CEngine::Get()->GetCM()->AddPersistantObject(pJump);

			CAnimation* pRun = new CAnimation(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(94, 124),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Player/SS_Hunter_running.png", 269, 888,4, 1, 0.1f);

			pRun->SetMirror(PLAYER_MIRROR);
			pRun->SetParent(pPlayer);
			pRun->SetColType(ECollisionType::NONE);
			pRun->SetAnimationActive(false);
			pPlayer->m_Run = pRun;
			CEngine::Get()->GetCM()->AddPersistantObject(pRun);
			break;
		}

		case 'E':
		{
			// create textured object
			GEnemy * pEnemy = new GEnemy(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Player/Enemy_Skelett.png");

			// set player values
			pEnemy->SetSpeed(ENEMY_SPEED);
			pEnemy->SetMirror(ENEMY_MIRROR);
			pEnemy->SetColType(ECollisionType::MOVE);
			pEnemy->ActivateGravity();

			// add player to persistant list
			CEngine::Get()->GetCM()->AddSceneObject(pEnemy);
			break;
		}
		case 'F':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(75, 140),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Kaktus.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'G':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(600, 630),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Mountain_Beginning.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'T':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(126, 250),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Signpost.png");

			pObj->SetColType(ECollisionType::NONE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'Y':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(288, 470),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Pool_Red_short.png");

			pObj->SetColType(ECollisionType::NONE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'K':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(265, 42),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Plattform_solid.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'Q':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(265, 42),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Plattform_moving.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'J':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(500, 290),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Wagen.png");

			pObj->SetColType(ECollisionType::NONE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'I':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(600, 630),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Mountain.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'C':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(1104, 200),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Spiky_Pit_DLD.png");

			pObj->SetColType(ECollisionType::NONE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'H':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(100, 140),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Player/Zomve.png");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case '1':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(10752, 1308),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Hintergrund_Level_1.png");

			pObj->SetColType(ECollisionType::NONE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddSceneObject(pObj);
			break;
		}
		case '2':
		{
			// create textured objectd
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(310, 50),
				CEngine::Get()->GetRenderer(),
				"");

			pObj->SetColType(ECollisionType::WALL);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddSceneObject(pObj);
			break;
		}

		default:
			break;
		}

		// set source rect of object
		pObj->SetSrcRect(SRect(xPosOfTexture, 0, WORLD_BLOCK_ATLAS_WIDTH, WORLD_BLOCK_ATLAS_HEIGHT));

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
	}
}
#pragma endregion