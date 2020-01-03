#include "Ribbon.hpp"

#include <iostream>

Ribbon::Ribbon()
{
	shape.setFillColor(sf::Color(230, 230, 230));
	border.setFillColor(sf::Color(200, 200, 200));

	sectionBorder.setFillColor(sf::Color(230, 230, 230));
	sectionBorder.setSize(sf::Vector2f(1, 23));

	font.loadFromFile("./resource/tahoma.ttf");
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
	RibbonSection section(title, sections.empty() ? 0 : sections.rbegin()->second.getXSize(), &font);
	sections.emplace(title, section);
	return section;
}

RibbonSectionOption Ribbon::addOptionToSection(const std::string& section, const std::string& title)
{
	RibbonSectionOption option;
	option.title = title;
	sections[section].addOption(title);
	return option;
}

void Ribbon::HandleEvents(sf::Event& event)
{
	if (event.type == sf::Event::EventType::MouseMoved)
	{

	}
	else if (event.type == sf::Event::EventType::MouseButtonReleased)
	{

	}
}

void Ribbon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape, states);
	target.draw(border, states);

	for (auto& x : sections)
	{
		target.draw(x.second, states);
		target.draw(sectionBorder, states);
	}
}

/*
void Ribbon::openSection(const std::string& sectionName)
{
	/*
	if (openSection)
		openSection->close();

	sections[sectionName].open();

	openSection = sections[sectionName];
}
*/

void Ribbon::closeSection(const std::string& sectionname)
{
}
