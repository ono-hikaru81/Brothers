#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <Utility/Singleton.h>

#include <map>

namespace spesium{
	class SoundManager: public Singleton<SoundManager>
	{
	public:
		SoundManager() = default;
		virtual ~SoundManager() = default;

		/// <summary>
		///		BGM���������ɕۑ�����֐�
		/// </summary>
		/// <param name="name">BGM�̖��O</param>
		/// <param name="filePath">BGM��ۑ����Ă���t�@�C���p�X</param>
		void LoadBGM(const std::string& name_, const std::string& filePath_);

		/// <summary>
		///		�������ɂ���BGM�n���h�������ׂč폜
		/// </summary>
		void DeleteBGM();

		/// <summary>
		///		BGM���Đ�
		/// </summary>
		/// <param name="name">BGM�̖��O</param>
		void PlayBGM(const std::string& name_);

		/// <summary>
		///		BGM���~�߂�
		/// </summary>
		void StopBGM();

		/// <summary>
		///		�~�߂Ă���BGM���Đ�
		/// </summary>
		void RePlayBGM();

		/// <summary>
		///		BGM��ς���
		/// </summary>
		/// <param name="name">BGM�̖��O</param>
		void ChangeBGM(const std::string& name_);
		
	private:
		std::map<std::string, int32_t> BGMList{};
		int32_t playingBGM{};
	};
}

#endif // !SOUND_MANAGER_H


