
#ifndef IN_GAME_SCENE_H
#define IN_GAME_SCENE_H

#include <Camera/Camera.h>
#include <Character/Monster.h>
#include <Scene/SceneBase.h>

namespace spesium {
    namespace scene {
        class InGameScene : public SceneBase {
           public:
            InGameScene();

            virtual ~InGameScene();

            virtual void Exec();

            virtual void Draw();

           private:
            character::Monster* monster { nullptr };
            tool::Camera* camera { nullptr };
        };
    }  // namespace scene
}  // namespace spesium

#endif  // !IN_GAME_SCENE_H
