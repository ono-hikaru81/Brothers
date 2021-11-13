#include "CharacterBase.h"

#include "DxLib.h"

namespace character
{
	void character::CharacterBase::Move()
	{
		// �E�ړ�
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) ||
			inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT))
		{
			status.speedVec.x += status.speed;

			if (status.speedVec.x > status.maxSpeed)
			{
				status.speedVec.x = status.maxSpeed;
			}
		}

		// ���ړ�
		if (inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) ||
			inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT))
		{
			status.speedVec.x -= status.speed;

			if (status.speedVec.x < (status.maxSpeed * -1))
			{
				status.speedVec.x = (status.maxSpeed * -1);
			}
		}
	}

	void character::CharacterBase::Jump()
	{
		if (!inputManager.lock()->IsKeyPushed(KEY_INPUT_UP)) { return; }

		if (IsStanding())
		{
			status.speedVec.y = status.jumpPower;
		}
	}

	void CharacterBase::UpdateDirection()
	{
		// �E�����ɕύX
		if (status.speedVec.x > 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT)))
		{
			status.angle = 270.0f;
		}

		// �������ɕύX
		if (status.speedVec.x < 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT)))
		{
			status.angle = 90.0f;
		}
	}

	void character::CharacterBase::Gravity()
	{
		status.speedVec.y -= gravityVec;
	}

	bool character::CharacterBase::IsStanding() const
	{
		if (status.pos.y < 0)
		{
			return true;
		}

		return false;
	}

	void character::CharacterBase::KineticFriction()
	{
		// �E�ړ�
		if (status.speedVec.x > 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_RIGHT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_RIGHT)))
		{
			status.speedVec.x -= frictionVec;

			status.angle = 270.0f;

			if (status.speedVec.x < 0)
			{
				status.speedVec.x = 0;
			}
		}

		// ���ړ�
		if (status.speedVec.x < 0 && (!inputManager.lock()->IsKeyPushed(KEY_INPUT_LEFT) || !inputManager.lock()->IsKeyHeld(KEY_INPUT_LEFT)))
		{
			status.speedVec.x += frictionVec;

			status.angle = 90.0f;

			if (status.speedVec.x > 0)
			{
				status.speedVec.x = 0;
			}
		}
	}

	void character::CharacterBase::UpdatePos()
	{
		// X���W
		status.moveVec.x = static_cast<double>(status.speedVec.x);
		status.pos.x += status.moveVec.x;
		// Y���W
		status.moveVec.y = static_cast<double>(status.speedVec.y);
		status.pos.y += status.moveVec.y;
	}

}
