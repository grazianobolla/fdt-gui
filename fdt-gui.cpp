#include "window.h"
#include "ipv4.h"
#include "utils.h"
#include "os.h"

MainWindow main_window;
bool server_mode = false;
std::string selected_file_path;

void host_button_callback(Fl_Widget *w, void *data)
{
    server_mode = true;

    std::string cmd = main_window.java_prefix->value();
    cmd.append(" -S");

    log("\nRunning '" << cmd << "'");

    //start server cmd
    int res = system(cmd.c_str());

    if (res == 0)
        info("Finishing receiving file!");
    else
        alert("There was a problem while receiving the file.");

    server_mode = false;
}

void transfer_button_callback(Fl_Widget *w, void *data)
{
    if (server_mode == true)
        return;

    std::string cmd = main_window.java_prefix->value();
    std::string address = main_window.address_input->value();
    std::string file_path = selected_file_path;

    if(file_path.empty())
    {
        alert("Invalid file path!");
        return;
    }

    if (!checkIPv4(address))
    {
        alert("Invalid address!");
        return;
    }

    if(get_os() == WINDOWS)
    {
        log("Fixing windows path...");
        windowify_path(file_path);
    }
    
    cmd.append(" -c " + address + " -d rec \"" + file_path + "\"");

    log("Running '" << cmd << "'");

    //send file cmd
    int res = system(cmd.c_str());

    if (res == 0)
        info("Finished sending file!");
    else
        alert("There was an error while trying to transfer the files, check your address, java prefix and file name.");
}

void select_file_button_callback(Fl_Widget *w, void *data)
{
    if (choose_file(selected_file_path) == false)
        return;


    std::string file_name = selected_file_path.substr(selected_file_path.find_last_of("/") + 1).c_str();

    log("Selected file: " << selected_file_path << "(" << file_name.c_str() << ")");

    main_window.path_display->copy_label(file_name.c_str());
}

int main(int argc, char **argv)
{
    main_window = MainWindow();
    main_window.configure();

    //attach callbacks
    main_window.host_button->callback(host_button_callback);
    main_window.transfer_button->callback(transfer_button_callback);
    main_window.select_file_button->callback(select_file_button_callback);

    main_window.run(argc, argv);
    return 0;
}