#pragma once
#include <Novice.h>

class Component
{
public:
	static Component* GetInstance();

	Component() = default;

	void Update();

	bool TriggerKey(BYTE keyNumber) const;

	bool PressKey(BYTE keyNumber) const;

	bool ReleaseKey(BYTE keyNumber) const;

private:
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};