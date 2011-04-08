/* The MIT License
 *
 * Copyright (c) 2010 OTClient, https://github.com/edubart/otclient
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "uibutton.h"
#include "../fonts.h"
#include "../font.h"

UIButton::UIButton(const std::string& text) :
    m_text(text),
    m_state(UI::ButtonUp)
{
    m_imageButtonUp = ImagePtr(new BorderedImage("ui.png",
                                                 Rect(45,139,1,18),
                                                 Rect(130,139,1,18),
                                                 Rect(46,138,84,1),
                                                 Rect(46,157,84,1),
                                                 Rect(45,138,1,1),
                                                 Rect(130,138,1,1),
                                                 Rect(45,157,1,1),
                                                 Rect(130,157,1,1),
                                                 Rect(46,139,84,18)));
}

void UIButton::render()
{
    m_imageButtonUp->draw(m_rect);

    g_fonts.get("tibia-8px-antialised")->renderText(m_text, m_rect, ALIGN_CENTER);
}
