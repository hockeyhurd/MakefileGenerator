/*
* MIT License
*
* Copyright (c) 2017 hockeyhurd
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
*/

#pragma once

#ifndef MAKEGEN_FIELD_H
#define MAKEGEN_FIELD_H

#include "types.h"
#include "interpreter.h"

#include <string>

class Field {

protected:

	std::string field;

	explicit Field(std::string &&);
	explicit Field(const std::string &);

public:

	Field(const Field &);
	Field(Field &&);

	Field &operator= (const Field &);
	Field &operator= (Field &&);

	virtual ~Field() = default;

	std::string &getField() const;

	virtual b32 apply(const std::string &, IFlags &) = 0;

	b32 stringStartsWith(const std::string &);
	b32 stringStartsWith(std::string &&);

	class FieldComparer {
		
	public:

		// b32 operator< (const std::string &, const std::string &);
		b32 operator() (const std::string &, const std::string &) const;

	};
	
};

b32 stringStartsWith(const std::string &, const std::string &);

#endif // !MAKEGEN_FIELD_H

