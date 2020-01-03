#ifndef RIBBON_HPP
#define RIBBON_HPP

#include "RibbonSection.hpp"

#include <SFML/Graphics.hpp>

#include <functional>
#include <map>
#include <string>

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

	void HandleEvents(sf::Event& event);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::RectangleShape shape;
	sf::RectangleShape border;

	sf::Font font;

	std::map<std::string, RibbonSection> sections;

	RibbonSection* openSection = nullptr;

	/*
	void openSection(const std::string& sectionName);
	*/
	void closeSection(const std::string& sectionname);
};

#endif // !RIBBON_HPP
