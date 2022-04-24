/* by Wildan R. */

#include "raylib.h"

struct InvisibleFence
{
	Rectangle GetTreeRectangle1()
	{
		return Rectangle{ 980.414f, 280.586f, 150.0f, 560.0f };
	}

	Rectangle GetTreeRectangle2()
	{
		return Rectangle{ GetTreeRectangle1().x + 280.0f, GetTreeRectangle1().y + 180.0f, 150.0f, 450.0f };
	}

	Rectangle GetFenceRectangle1()
	{
		return Rectangle{ 40.0f, 252.0f, 250.0f, 0.2f };
	}

	Rectangle GetFenceRectangle2()
	{
		return Rectangle{ 40.0f, 900.0f, 350.0f, 0.2f };
	}
};


class NaturalObject
{
public:
	NaturalObject()
	{

	}

	~NaturalObject()
	{
		UnloadTexture(m_big_stone);
		UnloadSound(m_mechanical_bling);
	}

	Rectangle GetBigStone1Coll()
	{
		return Rectangle{
			static_cast<float>(m_big_stone1_pos.x + 45.0f),
			static_cast<float>(m_big_stone1_pos.y + 35.0f),
			static_cast<float>(m_big_stone.width * 0.65f),
			static_cast<float>(m_big_stone.height * 0.65f)
		};
	}

	Rectangle GetBigStone2Coll()
	{
		return Rectangle{
			static_cast<float>(m_big_stone2_pos.x + 45.0f),
			static_cast<float>(m_big_stone2_pos.y + 35.0f),
			static_cast<float>(m_big_stone.width * 0.65f),
			static_cast<float>(m_big_stone.height * 0.65f)
		};
	}

	void PlayMechanicalBlingSound()
	{
		PlaySound(m_mechanical_bling);
	}

	void Draw()
	{
		DrawTextureV(m_big_stone, m_big_stone1_pos, WHITE);
		DrawTextureV(m_big_stone, m_big_stone2_pos, WHITE);
	}

private:
	Texture2D m_big_stone{ LoadTexture("textures/natural_objects/big_stone.png") };
	Vector2 m_big_stone1_pos{ 1600.0f, 700.0f };
	Vector2 m_big_stone2_pos{ 3400.0f, 600.0f };
	Sound m_mechanical_bling{ LoadSound("sounds/mechanical_bling.wav") };
};


struct Prop
{
	InvisibleFence invisible_fence;
	NaturalObject natural_obj;

	void Draw()
	{
		natural_obj.Draw();
	}
};