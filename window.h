#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>

class MainWindow
{
public:
    MainWindow() {}

    Fl_Window* window;
    Fl_Button *host_button, *transfer_button;
    Fl_Input *address_input, *file_input, *java_prefix;

    void configure()
    {
        //window
        window = new Fl_Window(600, 100, "FDT GUI");
        window->begin();
        
        //buttons
        host_button = new Fl_Button(10, 10, 100, 20, "Host Server");
        transfer_button = new Fl_Button(10, 40, 100, 20, "Transfer File");

        //inputs
        address_input = new Fl_Input(300, 10, 200, 20, "Remote Address");
        file_input = new Fl_Input(300, 40, 200, 20, "File to Transfer Path");
        java_prefix = new Fl_Input(300, 70, 200, 20, "Java Prefix");
        java_prefix->value("java -jar fdt.jar");
    }

    int run(int argc, char **argv)
    {
        //show
        window->end();
        window->show(argc, argv);

        return Fl::run();
    }

    void block_all()
    {
        transfer_button->deactivate();
        address_input->deactivate();
        file_input->deactivate();
        java_prefix->deactivate();
    }

    void allow_all()
    {
        transfer_button->activate();
        address_input->activate();
        file_input->activate();
        java_prefix->activate();
    }
};