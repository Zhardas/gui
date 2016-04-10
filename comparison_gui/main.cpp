#include "main.h"

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
        EVT_MENU(wxID_EXIT, MyFrame::OnExit)
        EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
        EVT_CLOSE(MyFrame::OnClose)
END_EVENT_TABLE()

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
        EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  render_loop_on = false;

  wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
  frame = new MyFrame();

  drawPane = new BasicDrawPane(frame);
  sizer->Add(drawPane, 1, wxEXPAND);

  frame->SetSizer(sizer);
  frame->Show();

  activateRenderLoop(true);
  return true;
}

void MyFrame::OnExit(wxCommandEvent &event) {
  Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("Author: Zhardas - Zhardas@gmail.com",
               "ComparisonGUI - About", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnClose(wxCloseEvent &event) {
  wxGetApp().activateRenderLoop(false);
  event.Skip(); // don't stop event, we still want window to close
}

void MyApp::activateRenderLoop(bool on) {
  if (on && !render_loop_on) {
    Connect(wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(MyApp::OnIdle));
    render_loop_on = true;
  }
  else if (!on && render_loop_on) {
    Disconnect(wxEVT_IDLE, wxIdleEventHandler(MyApp::OnIdle));
    render_loop_on = false;
  }
}
void MyApp::OnIdle(wxIdleEvent &evt) {
  if (render_loop_on) {
    drawPane->paintNow();
    evt.RequestMore(); // render continuously, not only once on idle
  }
}
BasicDrawPane::BasicDrawPane(wxFrame *parent) :
    wxPanel(parent) {
}

void BasicDrawPane::paintEvent(wxPaintEvent &evt) {
  wxPaintDC dc(this);
  render(dc);
}

void BasicDrawPane::paintNow() {
  wxClientDC dc(this);
  render(dc);
}

void BasicDrawPane::render(wxDC &dc) {
  static int frames = 0; frames++;
  auto new_timestamp = std::chrono::high_resolution_clock::now();
  if(std::chrono::duration_cast<std::chrono::seconds>(new_timestamp - timestamp_).count() >= 1){
    timestamp_ = new_timestamp;
    std::stringstream ss;
    ss << "FPS: " << frames;
    frames = 0;
    wxString s = ss.str();
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    dc.DrawText(s, 0, 0);
  }
}