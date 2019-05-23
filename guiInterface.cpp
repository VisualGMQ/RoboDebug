#include "guiInterface.hpp"

guiInterface::guiInterface():debug(){
}

const map<string, wxStringProperty*>& guiInterface::getVariables(){
    return sproperty;
}

void guiInterface::updateSP(){
    debug.readAndParse();
    const map<string, string> vars = debug.getVariables();
    /*
    for(auto it = vars.begin();it!=vars.end();it++)
        cout<<"name "<<it->first<<";value "<<it->second<<endl;
    */
    if(debug.isChanged){
        for(auto it = vars.begin();it != vars.end();it++){
                cout<<it->second<<endl;
                if(sproperty.find(it->first) == sproperty.end()){
                    wxStringProperty* sp = new wxStringProperty(it->first, it->second);
                    sproperty[it->first] = sp;
                }else
                    sproperty[it->first]->SetValue(it->second);  
        }
        debug.isChanged = false;
    }
}

guiInterface::~guiInterface(){
    for(auto it=sproperty.begin();it!=sproperty.end();it++)
        delete it->second;
}