#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"

class InGameScene : public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	// �V�[������
	virtual void Exec();

	// �V�[���`��
	virtual void Draw();

	// �V�[���I���t���O
	virtual bool IsEnd() const;
};

#endif // !INGAME_SCENE_H
