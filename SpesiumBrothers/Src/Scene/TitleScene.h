#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "SceneBase.h"
#include "../Manager/InputManager.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	// �V�[������
	virtual void Exec();

	// �V�[���`��
	virtual void Draw();

	// �V�[���I���t���O
	virtual bool IsEnd() const;
};

#endif // !TITLE_SCENE_H
