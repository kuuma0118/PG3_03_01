#include "Component.h"

Component* Component::GetInstance() {
	static Component instance;
	return &instance;
}

void Component::Update() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

bool Component::TriggerKey(BYTE keyNumber) const {
	if (!preKeys_[keyNumber] && keys_[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}

bool Component::PressKey(BYTE keyNumber)const {
	if (keys_[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}

bool Component::ReleaseKey(BYTE keyNumber)const {
	if (preKeys_[keyNumber] && !keys_[keyNumber]) {
		return true;
	}
	else {
		return false;
	}
}