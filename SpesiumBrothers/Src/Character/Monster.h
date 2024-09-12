
#ifndef MONSTER_H
#define MONSTER_H

#include <Character/CharacterBase.h>

namespace spesium {
    namespace character {
        class Monster : public CharacterBase {
           public:
            Monster();
            ~Monster() override;

           public:
            void Draw() override;

           public:
            /// @brief アクセサ
            /// @param (status.pos) 座標
            BasicProperty<Vector3<double>> Pos { status.pos };
        };
    }  // namespace character
}  // namespace spesium

#endif  // !MONSTER_H
