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
 public:
  MyFrame() : wxFrame((wxFrame *) NULL, -1, wxT("Comparison GUI"), wxPoint(50, 50), wxSize(400, 200)) {

  }
 private:
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);
  void OnClose(wxCloseEvent &event);
 DECLARE_EVENT_TABLE();
};