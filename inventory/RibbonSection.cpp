#include "RibbonSection.hpp"

#include <iostream>

// this is a macro because i don't like macros and it'll make me want to find a good solution for it
#define RIBBON_HEIGHT 23

void RibbonSectionOption::callFunction()
{
	function();
}

RibbonSection::RibbonSection()
{
	std::cerr << "fuck me im the default constructor" << std::endl;
}

RibbonSection::RibbonSection(const std::string& title, size_t xOffset, sf::Font* font)
{
	text.setFont(*font);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(16);
	text.setString(title);
	text.move(sf::Vector2f(xOffset + 3, 1));

	shape.move(sf::Vector2f(xOffset, 0));
	shape.setSize(sf::Vector2f(text.getGlobalBounds().width + 11, RIBBON_HEIGHT));
}

size_t RibbonSection::getXSize() const
{
	return shape.getSize().x;
}

RibbonSectionOption& RibbonSection::addOption(const std::string& optionName)
{
	RibbonSectionOption option;
	option.title = optionName;
	options.emplace(optionName, option);
	return option;
}

bool RibbonSection::hasOption(const std::string& option) const
{
	return options.find(option) != options.end();
}

/*
RibbonSectionOption& RibbonSection::getOption(const std::string& option) const
{
	// TODO: return null if option does not exist
	if (!hasOption(option))
		std::cerr << "Option " << option << " does not exist" << std::endl;

	return options[option];
}
*/

void RibbonSection::removeOption(const std::string& option)
{
	options.erase(option);
}

bool RibbonSection::isOpen() const
{
	return open;
}

void RibbonSection::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape, states);
	target.draw(text, states);
}
