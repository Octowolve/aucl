#pragma once
#include <string>
#include "imgui/imgui.h"
#include "utils.h"

class ChatLog {
protected:
	std::string player_name;
	std::string chat_text;
	std::string color;
	bool impostor;

public:
	ChatLog(std::string player_name, bool impostor, std::string color, std::string chat_text) {
		this->player_name = player_name;
		this->impostor = impostor;
		this->color = color;
		this->chat_text = chat_text;
	}
	~ChatLog() {}
	void log() {
		ImGui::Text("[");
		ImGui::SameLine();
#ifdef DEBUG
		if (this->get_is_impostor())
			ImGui::TextColored(ImVec4(1.f, 0.f, 0.f, 1.f), this->player_name.c_str());
		else
			ImGui::TextColored(ImVec4(1.f, 1.f, 1.f, 1.f), this->player_name.c_str());
#endif // DEBUG
		ImGui::TextColored(ImVec4(0.f, 1.f, 1.f, 1.f), this->player_name.c_str());
		ImGui::SameLine();
		ImGui::Text("|");
		ImGui::SameLine();
		ImGui::Text(this->color.c_str());
		ImGui::SameLine();
		ImGui::Text("]");
		ImGui::SameLine();
		ImGui::TextColored(ImVec4(0.f, 1.f, 0.f, 1.f), this->chat_text.c_str());
	}
	std::string get_playername() { return this->player_name; }
	std::string get_chat_text() { return this->chat_text; }
	std::string get_color() { return this->color; }
	bool get_is_impostor() { return this->impostor; }
};
