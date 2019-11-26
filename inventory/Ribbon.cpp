#include "Ribbon.hpp"

#include <iostream>

Ribbon::Ribbon()
{
	shape.setFillColor(sf::Color(230, 230, 230));
	border.setFillColor(sf::Color(200, 200, 200));
}

/*
Ribbon::~Ribbon()
{
}
*/

void Ribbon::setSize(const sf::Vector2f& newSize)
{
	shape.setSize(newSize);

	border.setPosition(sf::Vector2f(0, newSize.y));
	border.setSize(sf::Vector2f(newSize.x, 1));
}

sf::Vector2f Ribbon::getSize() const
{
	return shape.getSize();
}

RibbonSection Ribbon::addSection(const std::string& title)
{
	RibbonSection section;
	section.setTitle(title);
	sections.emplace(title, section);
	return section;
}

RibbonSectionOption Ribbon::addOptionToSection(const std::string& section, const std::string& title)
{
	RibbonSectionOption option;
	option.title = title;
	sections[section].options.emplace(title, option);
	return option;
}

void Ribbon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape, states);
	target.draw(border, states);

	for (auto& x : sections)
		target.draw(x.second, states);
}

void RibbonSectionOption::callFunction()
{
	function();
}

RibbonSection::RibbonSection()
{
	shape.setSize(sf::Vector2f(50, 23));

	font = sf::Font();
	font.loadFromFile("resource/tahoma.ttf");
	text = sf::Text("", font);
}

void RibbonSection::setTitle(const std::string& string)
{
	std::cout << "string set to " << string << std::endl;
	text.setString(string);
}

std::string RibbonSection::getString() const
{
	return text.getString().toAnsiString();
}

void RibbonSection::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape, states);
	target.draw(text, states);
}
