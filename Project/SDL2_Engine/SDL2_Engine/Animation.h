#pragma once
#include "TexturedObject.h"
// erstellt von Timo

class CAnimation :
	public CTexturedObject
{
public:
	virtual ~CAnimation();
	CAnimation(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName, int h, int b, int x, int y, float _frameTime);
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual bool Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) override;

	void SetAnimationActive(bool _animationActive);
	

	inline void SetParent(CTexturedObject* _parent)
	{
		m_parent = _parent;
	}


protected:

	CTexturedObject * m_parent;
	bool m_animationActive;
	int m_currentFrame = 0;
	int m_frameTotal = 0;
	SRect m_currentSRect;
	int m_frameX;
	int m_frameY;
	float m_frameTimeLeft;
	float m_frameTime = 0.1f;
};

