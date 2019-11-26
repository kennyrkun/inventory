#include "AppEngine.hpp"
#include "MainMenuState.hpp"

#include <SFUI/Theme.hpp>

int main(int argc, char* argv[])
{
	SFUI::Theme::loadFont("resource/tahoma.ttf");
	SFUI::Theme::loadTexture("resource/texture_square.png");
	SFUI::Theme::textCharacterSize = 11;
	SFUI::Theme::click.textColor = SFUI::Theme::hexToRgb("#191B18");
	SFUI::Theme::click.textColorHover = SFUI::Theme::hexToRgb("#191B18");
	SFUI::Theme::click.textColorFocus = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::input.textColor = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::input.textColorHover = SFUI::Theme::hexToRgb("#CC7A00");
	SFUI::Theme::input.textColorFocus = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::windowBgColor = SFUI::Theme::hexToRgb("#dddbde");
	SFUI::Theme::PADDING = 2.f;

	AppSettings options;

	AppEngine app;
	app.Init(options);

	app.PushState(new MainMenuState);

	while (app.isRunning())
	{
		app.HandleEvents();
		app.Update();
		app.Draw();
	}

	return 0;
}
