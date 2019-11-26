#ifndef RIBBON_HPP
#define RIBBON_HPP

#include <SFML/Graphics.hpp>

#include <functional>
#include <map>
#include <string>

class RibbonSectionOption
{
public:
	std::string title;
	std::string hotkey;
	std::string iconPath;
	std::function<void()> function;

	// TODO: RibbonSection parent;

	void callFunction();
};

class RibbonSection : public sf::Drawable
{
public:
	RibbonSection();

	void setTitle(const std::string& string);
	std::string getString() const;

	std::map<std::string, RibbonSectionOption> options;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape shape;
};

class Ribbon : public sf::Drawable
{
public:
	Ribbon();

	void setSize(const sf::Vector2f& newSize);
	sf::Vector2f getSize() const;

	// Note:
	// ribbon does not have position related methods because the ribbons position will always be 0,0
	// (for the time being)

	RibbonSection addSection(const std::string& title);
	RibbonSectionOption addOptionToSection(const std::string& section, const std::string& title);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape shape;
	sf::RectangleShape border;

	std::map<std::string, RibbonSection> sections;
};

#endif // !RIBBON_HPP
