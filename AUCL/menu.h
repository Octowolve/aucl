#pragma once
#include "chatlog.hpp"
#include <vector>
#include <string>
namespace menu {
	void render();
	void init();
	inline std::vector<ChatLog*> logs;
}
