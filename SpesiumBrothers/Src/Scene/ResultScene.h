#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"
#include "../Manager/InputManager.h"

class ResultScene : public SceneBase
{
public:
	ResultScene();
	virtual ~ResultScene();

	// �V�[������
	virtual void Exec();

	// �V�[���`��
	virtual void Draw();

	// �V�[���I���t���O
	virtual bool IsEnd() const;
};

#endif // !RESULT_SCENE_H
