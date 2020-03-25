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

// Created by TeodorHMX1 on 25/03/2020.

#include "../../header/screen/LvlChooseScreen.h"

LvlChooseScreen::LvlChooseScreen()
{

	lvlChooseScreenBackground.setFillColor(Color(0,150,136));

	exitBtn.setSize(Vector2f(90, 30));
	exitBtn.setColor(Color(244,67,54));
	exitBtn.setHoverColor(Color(211,47,47));
	exitBtn.setActiveColor(Color(198,40,40));
	exitBtn.setText("Go Back");
	exitBtn.setCharacterSize(18);

}

LvlChooseScreen::~LvlChooseScreen()
{

}


void LvlChooseScreen::draw(RenderWindow &window)
{

	lvlChooseScreenBackground.setSize(Vector2f(window.getSize().x, window.getSize().y));
	window.draw(lvlChooseScreenBackground);

	exitBtn.setBtnPosition((float) 90, (float) 50);
	if (exitBtn.isClicked(window))
	{
		this->mApp->setCurrentScreen(menu);
	}
	window.draw(exitBtn);
	exitBtn.drawText(window);

}

void LvlChooseScreen::setApp(App *app)
{
	this->mApp = app;
	exitBtn.setApp(this->mApp);
}