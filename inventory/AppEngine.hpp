#ifndef APP_ENGINE_HPP
#define APP_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class AppState;

struct AppSettings
{
	std::string version = "1";
	std::string title = "inventory " + version;
	bool fullscreen = false;
	bool vsync = true;
	bool debug = true;
	bool console = false;
	int maxfps = 60;
	int width = 1080;
	int height = 720;

	struct CommandLineArguments
	{
		int argc;
		char** argv;
	} launchOptions;
};

class AppEngine
{
public:
	void Init(AppSettings settings_);
	void Cleanup();

	// Note: code after these functions is still executed.
	void ChangeState(AppState* state);
	void PushState(AppState* state);
	void PopState();
	void PopState(int amount);

	void HandleEvents();
	void Update();
	void Draw();

	bool isRunning() { return running; }
	void Quit();

	sf::RenderWindow* window;
	AppSettings settings;

	std::vector<AppState*> states;
	std::vector<sf::Event> events;

private:
	bool running;
};

#endif // !APP_ENGINE_HPP
