#include <wx/wx.h>
class MyApp : public wxApp
{
public:
	bool OnInit() override;
};
wxIMPLEMENT_APP(MyApp);
class MyFrame : public wxFrame
{
public:
	MyFrame();
private:
	void OnHello(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void button1(wxCommandEvent& event);
	void button2(wxCommandEvent& event);
};
enum
{
	ID_Hello = 1
};
bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show(true);
	return true;
}
MyFrame::MyFrame()
	: wxFrame(nullptr, wxID_ANY, "Hello World")
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "button 1");
	wxButton* button2 = new wxButton(panel, wxID_ANY, "button 2");

	button1->SetSize(0, 2, 200, 50);
	button2->SetSize(140, 58, 100, 30);

	button1->Bind(wxEVT_BUTTON, &MyFrame::button1, this);
	button2->Bind(wxEVT_BUTTON, &MyFrame::button2, this);

	wxMenu* menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
		"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);
	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
	Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets Hello World (Ivanov Sergey from RPO 1) example",
		"About Hello World Qwexaro", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from Qwexaro (Ivanov Sergey from RPO 1)!");
}

void MyFrame::button1(wxCommandEvent& event)
{
	wxMessageBox("you typped button 1", "inf", wxOK | wxICON_INFORMATION);
}

void MyFrame::button2(wxCommandEvent& event)
{
	wxMessageBox("you typped button 2", "inf", wxOK | wxICON_INFORMATION);
}