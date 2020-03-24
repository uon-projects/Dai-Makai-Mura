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

// Created by TeodorHMX1 on 19/03/2020.

#include <iostream>
#include "../header/MaterialButton.h"

MaterialButton::~MaterialButton()
{

}

MaterialButton::MaterialButton(const Vector2f &size)
{
	mySize = size;
	color = Color::Black;
	hoverColor = Color::Black;
	activeColor = Color::Black;
	std::cout<<"here";
	update();
}

void MaterialButton::setSize(const Vector2f &size)
{
	mySize = size;
	setOrigin(mySize.x/2, mySize.y/2);
	btnBounders = IntRect(getPosition().x - getGlobalBounds().width / 2,
	                  getPosition().y - getGlobalBounds().height / 2,
	                  getGlobalBounds().width,
	                  getGlobalBounds().height);
	update();
}

size_t MaterialButton::getPointCount() const
{
	return 4;
}

Vector2f MaterialButton::getPoint(size_t index) const
{
	switch (index)
	{
		default:
		case 0: return Vector2f(0, 0);
		case 1: return Vector2f(mySize.x, 0);
		case 2: return Vector2f(mySize.x, mySize.y);
		case 3: return Vector2f(0, mySize.y);
	}
}

void MaterialButton::setColor(Color newColor)
{
	color = newColor;
}

void MaterialButton::setHoverColor(Color newHoverColor)
{
	hoverColor = newHoverColor;
}

void MaterialButton::setActiveColor(Color newActiveColor)
{
	activeColor = newActiveColor;
}
