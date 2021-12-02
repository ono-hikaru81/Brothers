#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include<map>
#include<DxLib.h>
#include<Definition/Definition.h>
#include<Utility/Singleton.h>
#include<optional>

namespace spesium
{
	class TextureManager :public Singleton<TextureManager> {
	public:
		TextureManager();
		virtual ~TextureManager();

		/// @brief �e�N�X�`���[�̓ǂݍ���
		/// @param name�F�e�N�X�`���[�̖��O
		/// @param filePath�F�e�N�X�`���[��ۑ����Ă���t�@�C���p�X
		void LoadTexture(const std::string& name, const std::string& filePath);

		/// @brief �e�N�X�`���[�̑S�폜
		void ReleaseTexture();

		/// @brief �e�N�X�`���[�̎擾
		/// @param name�F�e�N�X�`���[�̖��O
		/// @return �e�N�X�`���[�n���h��
		/// @note DrawGraph(X,Y,GetTexture(name),TransFlag)
		std::optional<int32_t> GetTexture(const std::string& name);

	private:
		std::map<std::string, int32_t>TextureList;
	};
}
#endif // !TEXTURE_MANAGER_H
