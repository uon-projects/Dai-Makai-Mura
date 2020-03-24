/*
 * Copyright (c) 2020 Teodor G. (TeodorHMX1)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 **/

// Created by TeodorHMX1 on 17/03/2020.

#include "../../header/screen/GameMenuScreen.h"

GameMenuScreen::GameMenuScreen()
{

	gameMenuScreenBackground.setFillColor(Color(52, 235, 116));
	rectangle.setSize(Vector2f(100, 50));
	rectangle.setColor(Color(255,224,178));
	rectangle.setHoverColor(Color(255, 255, 255));
	rectangle.setActiveColor(Color(255, 255, 255));
	rectangle.setFillColor(Color(23, 23, 23));

}

GameMenuScreen::~GameMenuScreen()
{

}

void GameMenuScreen::draw(RenderWindow &window)
{

	gameMenuScreenBackground.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(gameMenuScreenBackground);

//	sf::IntRect btnCharactersRect(rectangle.getPosition().x - rectangle.getGlobalBounds().width / 2,
//	                              rectangle.getPosition().y - rectangle.getGlobalBounds().height / 2,
//	                              rectangle.getGlobalBounds().width,
//	                              rectangle.getGlobalBounds().height);
//	if (btnCharactersRect.contains(sf::Mouse::getPosition(window)))
//	{
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
//
//		}
//		rectangle.setFillColor(sf::Color(255, 255, 255));
//	}
//	else
//	{
//		rectangle.setFillColor(sf::Color(255,224,178));
//	}
	rectangle.setPosition((float) window.getSize().x/2, (float) window.getSize().y/2);
	window.draw(rectangle);

}
