
#ifndef INPUT_CONTROLLER_MANAGER_H
#define INPUT_CONTROLLER_MANAGER_H

#include <DxLib.h>
#include <Manager/InputState.h>
#include <Utility/Singleton.h>

#include <Utility/Vector.hpp>
#include <array>

namespace spesium {
    namespace input {
        class InputControllerManager : public Singleton<InputControllerManager> {
           public:
            InputControllerManager();
            ~InputControllerManager() {}

           public:
            ///@brief �R���g���[���[�̍X�V
            ///@note ���[�v���ɂ���x�����Ăяo��
            void UpdateControllerStatus();

            ///@brief �W���C�p�b�h�L�[�̉��������u��
            ///@param Key �W���C�p�b�h�̎w��L�[
            ///@note Dxlib.h��XINPUT�̒�`�Q��
            bool IsPadKeyPushed( const int32_t& Key );

            ///@brief �W���C�p�b�h�L�[�̉�����Ă���
            ///@param Key �W���C�p�b�h�̎w��L�[
            ///@note XINPUT�̒�`�Q��
            bool IsPadKeyHold( const int32_t& Key );

            ///@brief �W���C�p�b�h�L�[�̗�����
            ///@param Key �W���C�p�b�h�̎w��L�[
            ///@note XINPUT�̒�`�Q��
            bool IsPadKeyReleased( const int32_t& Key );

            ///@brief ���X�e�B�b�N�̒l
            ///@return -32767�`32767
            ReadonlyProperty<Vector2<double>> LeftStick { leftStick };

            ///@brief �E�X�e�B�b�N�̒l
            ///@return -32767�`32767
            ReadonlyProperty<Vector2<double>> RightStick { rightStick };

            ///@brief ���g���K�[�̒l(LT)
            ///@return 0�`255
            const uint8_t& LeftTrigger() { return leftTrigger; }

            ///@brief //�E�g���K�[�̒l(RT)
            ///@return 0�`255
            const uint8_t& RightTrigger() { return rightTrigger; }

           private:
            /// @brief �R���g���[���[�̐ڑ���
            void FindPadNum();

           private:
            static constexpr int32_t MAX_PAD_KEY { 16 };

            XINPUT_STATE inputXbox {};
            int32_t padNum {};

            std::array<bool, MAX_PAD_KEY> previousButtonList {};
            std::array<InputState, MAX_PAD_KEY> buttonStateList {};
            Vector2<double> leftStick {};
            Vector2<double> rightStick {};

            uint8_t leftTrigger {};
            uint8_t rightTrigger {};
        };
    }  // namespace input
}  // namespace spesium

#endif  // !INPUT_CONTROLLER_MANAGER_H
