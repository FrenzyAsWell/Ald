#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include <iostream>

int main (int argc, char *argv[]) {
	ftxui::ScreenInteractive entScreen = ftxui::ScreenInteractive::Fullscreen();
	
	std::string strInput;
	
	std::vector<std::string> listNotation_options = {
		"Writing",
		"Construct",
		"Drawing",
	};

	int iSelected_option = 0;
	std::vector<std::string> listOptions_frontend = {
		"Notepad",
		"Tables",
		"Whiteboard",
	};

	ftxui::Component entInput = ftxui::Input(&strInput, "notepad");

	ftxui::MenuOption optMenu_frontend;
	optMenu_frontend.on_enter = entScreen.ExitLoopClosure();

	ftxui::Component entMenu = ftxui::Menu(&listOptions_frontend, &iSelected_option, optMenu_frontend);

	ftxui::Component rMenu = ftxui::Renderer(entMenu, [&]{
		return ftxui::vbox({
			entMenu->Render(),
			ftxui::separator(),
			ftxui::text(listNotation_options[iSelected_option]),
		}) | ftxui::border;
	});

	ftxui::Component rInput = ftxui::Renderer(entInput, [&]{
		return ftxui::vbox({
			entInput->Render() | ftxui::flex,
			ftxui::separator(),
			ftxui::text("Formatted: " + strInput),
		});
	});

	entScreen.Loop(rMenu);

	switch (iSelected_option) {
		case 1: {
			entScreen.Loop(entInput);
			std::cout << "Result is" << ' ' << strInput << '\n';
		};

		default: std::cout << "Needs to be implemented..." << '\n';
	}

	return 0;
}
