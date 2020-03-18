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

#include <iostream>
#include <SFML/Graphics.hpp>
#include "header/App.h"
#include "header/screen/SplashScreen.h"
#include "header/screen/GameMenuScreen.h"

using namespace std;
using namespace sf;

#define WindowX 800
#define WindowY 500

App mApp;
SplashScreen mSplashScreen;
GameMenuScreen mGameMenu;
Vector2f theGameWindow_currentDimensions(WindowX, WindowY); // NOLINT(cert-err58-cpp)
Vector2f theGameWindow_perspectiveDimensions(WindowX, WindowY); // NOLINT(cert-err58-cpp)
RenderWindow theGameWindow( // NOLINT(cert-err58-cpp)
		VideoMode(theGameWindow_currentDimensions.x, theGameWindow_currentDimensions.y),
		"Dai Makai-Mura");
Clock inGameClock;

void init();


void inputListener();

void update(float seconds);

void draw();

int main()
{
	Clock clockTime;
	Time speed;

	theGameWindow.setFramerateLimit(60);
	init();

	while (theGameWindow.isOpen())
	{

		inputListener();

		speed = clockTime.restart();
		update(speed.asSeconds());

		theGameWindow.clear();

		draw();

		theGameWindow.display();
	}

	return 0;
}

void init()
{

	inGameClock.restart();

}

void inputListener()
{

	Event event{};

	while (theGameWindow.pollEvent(event))
	{
		if (event.key.code == Keyboard::Escape || event.type == Event::Closed)
		{
			theGameWindow.close();
		}
	}

}

void update(float seconds)
{

}

void draw()
{

	mApp.setCurrentScreen(menu);
	cout<<mApp.getCurrentScreen()<<'\n';
	switch (mApp.getCurrentScreen())
	{
		case splash:
		{
			float sec = inGameClock.getElapsedTime().asSeconds();
			if (sec < 2.0)
			{
				mSplashScreen.draw(theGameWindow);
			} else
			{
//				inGameClock.restart();
				mApp.setCurrentScreen(menu);
			}
		}
		case menu:
		{
//			mGameMenu.draw(theGameWindow);
		}
		case game:
		{

		}
		default:
			break;
	}

}