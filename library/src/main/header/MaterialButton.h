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

#pragma once
#include <SFML/Graphics.hpp>
#include "../../../../app/src/main/header/App.h"

using namespace sf;

class MaterialButton : public Shape
{

public:
	~MaterialButton();

	explicit MaterialButton(const Vector2f &size = Vector2f(0, 0));

public:
	virtual size_t getPointCount() const;

	virtual Vector2f getPoint(size_t) const;

	void setSize(const Vector2f &);

	bool isClicked(RenderWindow &);

	void setColor(Color);

	void setHoverColor(Color);

	void setActiveColor(Color);

	void setText(std::string);

	void setCharacterSize(int);

	void setBtnPosition(float, float);

	void drawText(RenderWindow &);

	void setApp(App *app);

private:
	Vector2f mySize;
	IntRect btnBounders;
	Color color;
	Color hoverColor;
	Color activeColor;
	Font font;
	Text text;
	String content;
	int characterSize;
	App *mApp;

};
