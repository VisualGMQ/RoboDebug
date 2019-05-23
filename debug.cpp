#include "guiInterface.hpp"
#define TIMER_ID 1001

class myApp:public wxApp{
public:
    virtual bool OnInit();
};

class myFrame:public wxFrame{
public:
    myFrame(string title, wxSize& size);
private:
    void onTimer(wxTimerEvent& event);
    wxTimer m_timer;
    guiInterface guiIF;
    wxPropertyGrid* pg;
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(myFrame,wxFrame)
EVT_TIMER(TIMER_ID, myFrame::onTimer)
wxEND_EVENT_TABLE()

bool myApp::OnInit(){
    wxSize size(400, 800);
    myFrame* frame = new myFrame("debugger", size);
    frame->Show(true);
    return true;
}

myFrame::myFrame(string title, wxSize& size):wxFrame(nullptr, wxID_ANY,title, wxDefaultPosition, size){
    guiIF.updateSP();
    pg = new wxPropertyGrid(this, wxID_ANY, wxPoint(0,0), wxSize(400, 800));
    const map<string, wxStringProperty*> sps = guiIF.getVariables();
    for(auto it=sps.begin();it!=sps.end();it++)
        pg->Append(it->second);
    m_timer.Start(10);
    Center();
}

void myFrame::onTimer(wxTimerEvent& event){
    guiIF.updateSP();
}

IMPLEMENT_APP(myApp);