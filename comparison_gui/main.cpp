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
  drawPane->SetDoubleBuffered(true);
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
  label_ = new wxStaticText(this, LABEL_SAMPLE, _T("Sample label!"), wxPoint(10, 20));
  textbox_ = new wxTextCtrl(this, TEXTBOX_SAMPLE, _T("Sample text"), wxPoint(10, 50));
  checkbox_ = new wxCheckBox(this, CHECKBOX_SAMPLE, _T("<- Sample checkbox!"), wxPoint(10, 100));
  combobox_ = new wxComboBox(this, COMBOBOX_SAMPLE, _T("Empty"), wxPoint(10, 150));
  button_ = new wxButton(this, BUTTON_SAMPLE, _T("Sample button!"), wxPoint(10, 200), wxDefaultSize, 0);
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
  static int frames = 0;
  frames++;
  static wxString draw_text = "";
  auto new_timestamp = std::chrono::high_resolution_clock::now();

  // Calculate framerate every second
  if (std::chrono::duration_cast<std::chrono::seconds>(new_timestamp - timestamp_).count() >= 1) {
    timestamp_ = new_timestamp;
    std::stringstream ss;
    ss << "FPS: " << frames;
    frames = 0;
    draw_text = ss.str();
  }

  dc.SetBackground(*wxWHITE_BRUSH);
  dc.Clear();
  dc.DrawText(draw_text, 0, 0);
}