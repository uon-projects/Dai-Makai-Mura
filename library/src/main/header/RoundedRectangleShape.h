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

#include <SFML/Graphics.hpp>

using namespace sf;

class RoundedRectangleShape : public Shape
{

public:
	~RoundedRectangleShape();

public:
	explicit RoundedRectangleShape(const Vector2f &size = Vector2f(0, 0), float radius = 0,
	                               unsigned int cornerPointCount = 0);

	void setSize(const Vector2f &size);

	const Vector2f &getSize() const;

	void setCornersRadius(float radius);

	float getCornersRadius() const;

	void setCornerPointCount(unsigned int count);

	virtual std::size_t getPointCount() const;

	virtual Vector2f getPoint(std::size_t index) const;

private:
	Vector2f mySize;
	float myRadius;
	unsigned int myCornerPointCount;
};
