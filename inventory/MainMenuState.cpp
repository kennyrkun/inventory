#include "AppEngine.hpp"
#include "MainMenuState.hpp"

#include <SFUI/SFUI.hpp>

#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

enum CALLBACK
{
	RIFLE_LIST,
	CHECKOUT_RIFLE,
	ADMIN,
	ABOUT,
	EXIT
};

void MainMenuState::Init(AppEngine* app_)
{
	std::cout << "MainMenuState Init" << std::endl;
	app = app_;

	RibbonSection file = ribbon.addSection("file");
	RibbonSection help = ribbon.addSection("help");

	ribbon.setSize(sf::Vector2f(app->window->getSize().x, 23));

	menu = buildMainMenu();

	std::cout << "MainMenuState ready" << std::endl;
}

void MainMenuState::Cleanup()
{
	std::cout << "Cleaning up MainMenuState" << std::endl;

	delete menu;

	std::cout << "MainMenuState Cleanup" << std::endl;
}

void MainMenuState::Pause()
{
	std::cout << "MainMenuState paused" << std::endl;
}

void MainMenuState::Resume()
{
	std::cout << "MainMenuState resumed" << std::endl;
}

void MainMenuState::HandleEvents()
{
	sf::Event event;

	while (app->window->pollEvent(event))
	{
		ribbon.HandleEvents(event);

		if (event.type == sf::Event::EventType::Closed)
		{
			app->Quit();
			return;
		}
		else if (event.type == sf::Event::EventType::Resized)
		{
			sf::Vector2u newSize(event.size.width, event.size.height);

			sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);
			app->window->setView(sf::View(visibleArea));
		}

		int id = menu->onEvent(event);

		switch (id)
		{
		case CALLBACK::EXIT:
			app->Quit();
			return;
		}
	}
}

void MainMenuState::Update()
{
}

void MainMenuState::Draw()
{
	app->window->clear(SFUI::Theme::windowBgColor);
	
	app->window->draw(ribbon);
	app->window->draw(*menu);

	app->window->display();
}

SFUI::Menu* MainMenuState::buildMainMenu()
{
	SFUI::Menu* newMenu = new SFUI::Menu(*app->window);
	newMenu->setPosition(sf::Vector2f(8, 35));

	SFUI::HorizontalBoxLayout* panelContainer= newMenu->addHorizontalBoxLayout();

	SFUI::VerticalBoxLayout* leftPanel = panelContainer->addVerticalBoxLayout();
	leftPanel->addButton("Rifle List", CALLBACK::RIFLE_LIST);
	leftPanel->addButton("Checkout Rifle", CALLBACK::CHECKOUT_RIFLE);

	SFUI::VerticalBoxLayout* rightPanel = panelContainer->addVerticalBoxLayout();
	rightPanel->addButton("About", CALLBACK::ABOUT);
	rightPanel->addButton("Admin", CALLBACK::ADMIN);

	newMenu->addHorizontalBoxLayout();

	newMenu->addButton("Exit", CALLBACK::EXIT);

	return newMenu;
}
