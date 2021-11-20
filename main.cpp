#include <iostream>
#include "window.h"

#define log(x) std::cout << x << "\n"

MainWindow main_window;
bool server_mode = false;

void host_button_callback(Fl_Widget*w, void* data)
{
    server_mode = true;

    std::string cmd = main_window.java_prefix->value();
    cmd.append(" -S");

    log("running " << cmd);

    //start server
    system(cmd.c_str());
    log("\nFinishing receiving file!");

    server_mode = false;
}


void transfer_button_callback(Fl_Widget*w, void* data)
{
    if(server_mode != false)
        return;

    std::string cmd = main_window.java_prefix->value();
    std::string address = main_window.address_input->value();
    std::string file_path = main_window.file_input->value();
    
    cmd.append(" -c " + address + " -d rec " + file_path);

    log("running " << cmd);

    //send file
    int res = system(cmd.c_str());

    if(res != 0)
    {
        log("\nThere was an error while trying to transfer the files, check your address, java prefix and file name.");
        return;
    }

    log("\nFinishing sending file!");
}

int main(int argc, char **argv)
{
    main_window = MainWindow();
    main_window.configure();

    //attach callbacks
    main_window.host_button->callback(host_button_callback);
    main_window.transfer_button->callback(transfer_button_callback);

    main_window.run(argc, argv);
    return 0;
}