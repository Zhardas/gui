#define UNICODE
#define UNICODE_

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "wx/sizer.h"
#include <sstream>
#include <chrono>

class MyFrame;

class BasicDrawPane: public wxPanel {
 private:
  std::chrono::high_resolution_clock::time_point timestamp_;
 public:
  wxStaticText* label_;
  wxTextCtrl* textbox_;
  wxCheckBox* checkbox_;
  wxComboBox* combobox_;
  wxButton* button_;

  enum {
    LABEL_SAMPLE = wxID_HIGHEST + 1,
    TEXTBOX_SAMPLE = wxID_HIGHEST + 2,
    CHECKBOX_SAMPLE = wxID_HIGHEST + 3,
    COMBOBOX_SAMPLE = wxID_HIGHEST + 4,
    BUTTON_SAMPLE = wxID_HIGHEST + 5
  };

  BasicDrawPane(wxFrame *parent);

  void paintEvent(wxPaintEvent &evt);
  void paintNow();
  void render(wxDC &dc);

 DECLARE_EVENT_TABLE()
};

class MyApp: public wxApp {
  bool render_loop_on;
  bool OnInit();
  void OnIdle(wxIdleEvent &evt);

  MyFrame *frame;
  BasicDrawPane *drawPane;
 public:
  void activateRenderLoop(bool on);
};

class MyFrame: public wxFrame {
 private:
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
  void OnClose(wxCloseEvent &event);
 public:

  MyFrame() : wxFrame((wxFrame *) NULL, -1, wxT("Comparison GUI"), wxPoint(50, 50), wxSize(606, 428)) {
  }

 DECLARE_EVENT_TABLE();
};