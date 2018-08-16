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

// Collision und Enemy bearbeitet von Max | World und Animationen bearbeitet von Timo

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
	
	// Background Layer
	// X = first texture of layer
	// L = second texture of layer
	// Z = third texture of layer
	// B = 4th texture of layer
	// A = 5th texture of layer
	// W = 6th texture of layer
	// M = 7th texture of layer
	// R = 8th texture of layer
	// D = 9th texture of layer
	// V = 10th texture of layer
	// U = 11th texture of layer
	// N = 12th texture of layer

	// Character
	// S = Player
	// E = Ememy
	// H = Enemy dummy

	// Background
	// 1 = Background

	// Environment
	// G = Mountain for World End
	// T = Signpost
	// I = Mountain
	// J = Cart

	// Obstacles
	// Y = Red Pool short
	// F = Cactus
	// K = Platform solid
	// Q = Platform moving
	// C = Spiky pit
	
	// Collider
	// 2 = Invisible Collider for Cart

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
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLJLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLTLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLKLLLLLLLLLLLLLLLLLLLLLLQLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLTLLLLLLLLL\n";
	world += "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL2LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLQLLLLLLLLLLLLQLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "LLLLLLLLLLLFLLLLLSLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLFLLLLLLLLLLLLLLLLLLLLLHLLLLLHLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLHLLLLHLLLLLHLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n";
	world += "RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRRRRLLLLLLRRRRRLLLLLLLLLLLLLLLLLLLLLLLRRRRRRRRRRRRRRRRRR\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXXXXXXXXXLLLLLLXXXXXLLLLLLLLLLLLLLLLLLLLLLLXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAA3XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAY3AYAAAA3XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXYAAAAY3AYAAAA3XXXXXXXXXXXXXXXXXXXXXXXXXYAAAA3XXXXXCAAA3AAAAAA3AAAAAAAA3AAXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX3AAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXXXXXXXXX3AAAAAXXXXXAAAAAAAAAAAAAAAAAAAAAAAXXXXXXXXXXXXXXXXXX\n";
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
			"Texture/World/Layer/Background_Layer1.png"

		);


		// x position of texture in atlas map
		int xPosOfTexture = 0;

		// switch char in world string
		switch (world[i])
		{
		case 'X':
		// Background Layer
		{
			//first texture of layer
			xPosOfTexture = WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}
		case 'L':
		{
			//second texture of layer
			xPosOfTexture = 2 * WORLD_BLOCK_ATLAS_WIDTH;
			
			// set collision type to none
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'Z':
		{
			//third texture of layer
			xPosOfTexture = 3 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'B':
		{
			//4th texture of layer
			xPosOfTexture = 4 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'A':
		{
			//5th texture of layer
			xPosOfTexture = 5 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'W':
		{
			//6th texture of layer
			xPosOfTexture = 6 * WORLD_BLOCK_ATLAS_WIDTH;
			
			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'M':
		{
			//7th texture of layer
			xPosOfTexture = 7 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'R':
		{
			//8th texture of layer
			xPosOfTexture = 8 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::WALL);
			break;
		}
		case 'D':
		{
			//9th texture of layer
			xPosOfTexture = 9 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'V':
		{
			//10th texture of layer
			xPosOfTexture = 10 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'U':
		{
			//11th texture of layer
			xPosOfTexture = 11 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'N':
		{
			//12th texture of layer
			xPosOfTexture = 12 * WORLD_BLOCK_ATLAS_WIDTH;

			
			pObj->SetColType(ECollisionType::NONE);
			break;
		}
		case 'S':
		//Character
		{
			//Player
			
			GPlayer * pPlayer = new GPlayer(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT), 
				SVector2(94, 124),
				CEngine::Get()->GetRenderer(), 
				"");

			pPlayer->SetSpeed(PLAYER_SPEED);
			pPlayer->SetMirror(PLAYER_MIRROR);
			pPlayer->SetColType(ECollisionType::PLAYER);
			pPlayer->ActivateGravity();

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
				"Texture/Character/Animation/SS_Hunter_jump.png", 281, 1652, 7, 1, 0.5f);

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
				"Texture/Character/Animation/SS_Hunter_running.png", 269, 888,4, 1, 0.1f);

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
			//Enemy
			
			GEnemy * pEnemy = new GEnemy(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(95, 125),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Enemy/Zombie.png");

			pEnemy->SetSpeed(ENEMY_SPEED);
			pEnemy->SetMirror(ENEMY_MIRROR);
			pEnemy->SetColType(ECollisionType::ENEMY);
			pEnemy->ActivateGravity();						

			
			CEngine::Get()->GetCM()->AddPersistantObject(pEnemy);
			break;
		}
		case 'H':
		{
			//Enemy Dummy
		
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(100, 140),
				CEngine::Get()->GetRenderer(),
				"Texture/Character/Enemy/Zombie.png");

			pObj->SetColType(ECollisionType::OBSTACL);

		
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case '1':
		//Background
		{
			//Background
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(10752, 1308),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Background/Hintergrund_Level_1.png");

			pObj->SetColType(ECollisionType::NONE);

		
			CEngine::Get()->GetCM()->AddSceneObject(pObj);
			break;
		}
		case 'G':
		//Environment
		{
			//Mountain for World End
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(600, 630),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Environment/Mountain_Beginning.png");

			pObj->SetColType(ECollisionType::WALL);

			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'T':
		{
			//Signpost
		
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(126, 250),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Environment/Signpost.png");

			pObj->SetColType(ECollisionType::NONE);

			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'I':
		{
			//Mountain
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(600, 630),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Environment/Mountain.png");

			pObj->SetColType(ECollisionType::WALL);

			
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'J':
		{
			//Cart
		
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(500, 290),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Environment/Wagen.png");

			pObj->SetColType(ECollisionType::NONE);

			
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'Y':
		// Obstacles
		{
			//Red Pool short

			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(288, 470),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Obstacles/Pool_Red_short.png");

			pObj->SetColType(ECollisionType::OBSTACL);

			
			CEngine::Get()->GetCM()->AddBullet(pObj);
			break;
		}
		case 'F':
		{
			//Cactus
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(75, 140),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Environment/Kaktus.png");

			pObj->SetColType(ECollisionType::OBSTACL);

			
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'K':
		{
			//Platform Solid
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(265, 42),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Obstacles/Plattform_solid.png");

			pObj->SetColType(ECollisionType::WALL);

			
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'Q':
		{
			//Platform moving
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(265, 42),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Obstacles/Plattform_moving.png");

			pObj->SetColType(ECollisionType::WALL);

		
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case 'C':
		{
			//Spiky Pit
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(1104, 200),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Obstacles/Spiky_Pit_DLD.png");

			pObj->SetColType(ECollisionType::NONE);

	
			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
			break;
		}
		case '2':
		//Collider
		{
			//Collider for Cart
			
			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(310, 50),
				CEngine::Get()->GetRenderer(),
				"");

			pObj->SetColType(ECollisionType::WALL);

			
			CEngine::Get()->GetCM()->AddSceneObject(pObj);
			break;
		}
		case '3':
		{
			//Collider for Pits

			CTexturedObject * pObj = new  CTexturedObject(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT),
				SVector2(32, 100),
				CEngine::Get()->GetRenderer(),
				"Texture/World/Layer/test.png");

			pObj->SetColType(ECollisionType::OBSTACL);


			CEngine::Get()->GetCM()->AddPersistantObject(pObj);
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