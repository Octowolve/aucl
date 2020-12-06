#pragma once
#include <string>
#include "imgui/imgui.h"
#include "utils.h"

enum event_type {
	chat_event,
	vote_event,
	vent_event,
	kill_event,
	task_event,
	report_event,
	meeting_event
};

class event_log {
protected:
	std::string player_name;
	std::string chat_text;
	std::string color;
	event_type e_type;
	bool impostor;

public:
	event_log(std::string player_name, bool impostor, std::string color, event_type e_type, std::string chat_text = "") {
		this->player_name = player_name;
		this->impostor = impostor;
		this->color = color;
		this->e_type = e_type;
		this->chat_text = chat_text;
	}
	~event_log() {}
	void log_chat_event() {
		ImGui::Text("[");
		ImGui::SameLine();
#ifdef _DEBUG
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
	event_type get_event_type() { return this->e_type; }
	bool get_is_impostor() { return this->impostor; }
};