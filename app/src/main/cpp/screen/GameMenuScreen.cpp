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
#include "../../../../../library/src/main/header/LoadFont.h"

GameMenuScreen::GameMenuScreen()
{

	gameMenuScreenBackground.setFillColor(Color(0,150,136));

	exitBtn.setSize(Vector2f(70, 30));
	exitBtn.setColor(Color(244,67,54));
	exitBtn.setHoverColor(Color(211,47,47));
	exitBtn.setActiveColor(Color(198,40,40));
	exitBtn.setText("Exit");
	exitBtn.setCharacterSize(18);

	playBtn.setSize(Vector2f(90, 40));
	playBtn.setColor(Color(156,39,176));
	playBtn.setHoverColor(Color(123,31,162));
	playBtn.setActiveColor(Color(106,27,154));
	playBtn.setText("Play");
	playBtn.setCharacterSize(24);

}

GameMenuScreen::~GameMenuScreen()
{

}

void GameMenuScreen::draw(RenderWindow &window)
{

	gameMenuScreenBackground.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(gameMenuScreenBackground);

	exitBtn.setBtnPosition((float) window.getSize().x - 70, (float) 50);
	if (exitBtn.isClicked(window))
	{
		window.close();
	}
	window.draw(exitBtn);
	exitBtn.drawText(window);

	playBtn.setBtnPosition((float) window.getSize().x/2, (float) 100);
	if (playBtn.isClicked(window))
	{
		this->mApp->setCurrentScreen(choose_lvl);
	}
	window.draw(playBtn);
	playBtn.drawText(window);

}

void GameMenuScreen::setApp(App *app)
{
	this->mApp = app;
	exitBtn.setApp(this->mApp);
	playBtn.setApp(this->mApp);
}
