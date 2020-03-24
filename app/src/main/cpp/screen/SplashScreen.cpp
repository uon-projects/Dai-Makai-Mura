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

#include <SFML/Graphics.hpp>
#include "../../header/screen/SplashScreen.h"
#include "../../../../../library/src/main/header/LoadFont.h"

using namespace sf;

SplashScreen::SplashScreen()
{

	splashScreenBg.setFillColor(Color(21, 21, 21));
	mSplashLogo = mLoader.loadSpriteFromTexture("zeoflow_logo", png);

	font = LoadFont::loadFont();
	text.setFont(font);
	text.setFillColor(Color(88, 52, 235));
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(1);
	text.setString("Dai Makai Mura");
	text.setCharacterSize(40);

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::draw(RenderWindow &window)
{

	splashScreenBg.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(splashScreenBg);

	mSplashLogo.setScale(0.12, 0.12);
	float windowHeightHalf = (float) window.getSize().y / 2;
	float windowWidthHalf = (float) window.getSize().x / 2;
	float spriteHeightHalf = mSplashLogo.getGlobalBounds().height / 2;
	float spriteWidthHalf = mSplashLogo.getGlobalBounds().width / 2;
	mSplashLogo.setPosition(windowWidthHalf - spriteWidthHalf, windowHeightHalf - spriteHeightHalf - 30);
	window.draw(mSplashLogo);

	float textHeightHalf = text.getGlobalBounds().height / 2;
	float textWidthHalf = text.getGlobalBounds().width / 2;
	text.setPosition(windowWidthHalf - textWidthHalf, windowHeightHalf - textHeightHalf + 40);
	window.draw(text);

}
