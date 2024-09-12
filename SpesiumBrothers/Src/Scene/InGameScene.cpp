
#include <Definition/Definition.h>
#include <DxLib.h>
#include <Manager/SceneManager.h>
#include <Scene/InGameScene.h>

namespace spesium {
    namespace scene {
        InGameScene::InGameScene() {
            monster = new character::Monster();
            camera = new tool::Camera();
        }

        InGameScene::~InGameScene() {
        }

        void InGameScene::Exec() {
            if ( inputManager.lock()->IsKeyPushed( KEY_INPUT_RETURN ) ) {
                SceneManager::Instance().lock()->NextScene = Scene::Result;
            }

            static Vector3 origin { 0.0, 0.0, 0.0 };

            monster->Exec();
            camera->UpdatePos( monster->Pos, origin );
        }

        void InGameScene::Draw() {
            DrawString( 120, 120, "InGame", GetColor( 0, 0, 0 ) );
            monster->Draw();
        }
    }  // namespace scene
}  // namespace spesium
