//#include "PA9.hpp"
//
//class SpriteSound {
//private:
//	Sound sound;
//	SoundBuffer buffer;
//	string soundDir;
//public:
//	SpriteSound(SoundBuffer buff, Sound soundIn, string dir);
//	void setSound(Sound soundIn);
//	void setBuffer(SoundBuffer buff);
//	void setSoundDir(string dir);
//
//	Sound& getSound();
//	SoundBuffer& getBuffer();
//	string& getSoundDir();
//
//	void PlaySound();
//};
//
//SpriteSound::SpriteSound(SoundBuffer buff, Sound soundIn, string dir) {
//	setSound(soundIn);
//	setBuffer(buff);
//	setSoundDir(dir);
//}
//
//Sound& SpriteSound::getSound() {
//	return sound;
//}
//
//SoundBuffer& SpriteSound::getBuffer() {
//	return buffer;
//}
//
//string& SpriteSound::getSoundDir() {
//	return soundDir;
//}
//
//
//void SpriteSound::setSound(Sound soundIn) {
//	sound = soundIn;
//}
//
//void SpriteSound::setBuffer(SoundBuffer buff) {
//	buffer = buff;
//}
//
//void SpriteSound::setSoundDir(string dir) {
//	soundDir = dir;
//}
//
//void SpriteSound::PlaySound() {
//	if (!buffer.loadFromFile(soundDir))
//		cout << "Unable to Load Sound " << soundDir << endl;
//	sound.play();
//}
