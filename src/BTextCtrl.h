//
//  Copyright (C) 2004-2014 Andrej Vodopivec <andrej.vodopivec@gmail.com>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef BTEXTCTRL_H
#define BTEXTCTRL_H

#include <wx/wx.h>

class BTextCtrl: public wxTextCtrl
{
public:
  BTextCtrl(wxWindow *parent,
            wxWindowID id,
            const wxString& value,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = 0);
  ~BTextCtrl();
  void SetMatchParens(bool match)
  {
    m_matchParens = match;
  }
  void SetSkipTab(bool skip)
  {
    m_skipTab = skip;
  }
private:
  bool m_matchParens;
  bool m_skipTab;
  bool MatchParenthesis(int code);
  /*

    \todo The variable "insp" isn't used. Can the line containing it be removed?
   */
  void CloseParenthesis(wxString open, wxString close, bool fromOpen);
  void OnChar(wxKeyEvent& event);
  DECLARE_EVENT_TABLE()
};

#endif // BTEXTCTRL_H
