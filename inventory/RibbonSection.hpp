#ifndef RIBBON_SECTION_HPP
#define RIBBON_SECTION_HPP

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

// TODO: allow setting color

class RibbonSection : public sf::Drawable
{
public:
	RibbonSection();
	RibbonSection(const std::string& title, size_t xOffset, sf::Font* font);

	size_t getXSize() const;

	RibbonSectionOption& addOption(const std::string& optionName);
	bool hasOption(const std::string& option) const;
//	RibbonSectionOption& getOption(const std::string& option) const;
	void removeOption(const std::string& option);

	bool isOpen() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::map<std::string, RibbonSectionOption> options;

	sf::Text text;
	sf::RectangleShape shape;
	 
	bool open = false;
};

#endif // !RIBBON_SECTION_HPP
