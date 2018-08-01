#pragma once
#include "MoveObject.h"
#include <math.h>
#include <iostream>


class GBullet :public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	GBullet(SVector2 _pos) : CMoveObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	GBullet(SVector2 _pos, SVector2 _size) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GBullet(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName, SVector2 _shootDir ) : CMoveObject(_pos, _size, _pRenderer, _pFileName) 
	{
		m_shootDir = _shootDir.normalize();
		m_angle = atan2f(m_shootDir.X, m_shootDir.Y) * 180 / M_PI ;
		m_angle += 180;
		m_angle = 360 - m_angle;
		printf("\n Angle %f \n", m_angle);
		//m_angle = atan2f(-1.0f,0.0f) * 180 / M_PI;
		//std::cout << m_angle << std::endl;
		//std::cout << m_shootDir.X << " " << m_shootDir.Y << std::endl;

	}

	/// <summary>
	/// destructor
	/// </summary>
	~GBullet() {}
#pragma endregion

#pragma region public override function

	SVector2 m_shootDir;


	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;
#pragma endregion
};