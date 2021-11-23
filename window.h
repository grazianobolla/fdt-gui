#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>

class MainWindow
{
public:
    MainWindow() {}

    Fl_Window *window;
    Fl_Button *host_button, *transfer_button, *select_file_button;
    Fl_Input *address_input, *java_prefix;
    Fl_Box *path_display;

    void configure()
    {
        //window
        window = new Fl_Window(510, 100, "Fast Data Transfer Gui");
        window->begin();

        //buttons
        host_button = new Fl_Button(10, 10, 100, 20, "Host Server");
        transfer_button = new Fl_Button(10, 40, 100, 20, "Transfer File");
        select_file_button = new Fl_Button(10, 70, 100, 20, "Select File");

        //inputs
        path_display = new Fl_Box(300, 10, 200, 20, "No File Selected");
        path_display->box(FL_ENGRAVED_BOX);

        address_input = new Fl_Input(300, 40, 200, 20, "Remote Address");
        address_input->value("192.168.");

        java_prefix = new Fl_Input(300, 70, 200, 20, "Java Prefix");
        java_prefix->value("java -jar fdt.jar");

        //image
        // Fl_Box *img_box = new Fl_Box(550, 60, 0, 0, "");
        // img_box->image(new Fl_JPEG_Image("img.jpg"));
        // img_box->redraw();
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
        java_prefix->deactivate();
    }

    void allow_all()
    {
        transfer_button->activate();
        address_input->activate();
        java_prefix->activate();
    }
};