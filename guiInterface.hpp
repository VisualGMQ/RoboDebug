#ifndef __GUIINTERFACE_HPP__
#define __GUIINTERFACE_HPP__
#include "wx/wx.h"
#include "wx/propgrid/propgrid.h"
#include "debugger.hpp"
#include <map>
using namespace std;

class guiInterface{
public:
    guiInterface();
    const map<string, wxStringProperty*>& getVariables();
    void updateSP();
    ~guiInterface();
private:
    debugger debug;
    map<string, wxStringProperty*> sproperty;
};
#endif