#include "app.h"
#include <iostream>
#include <string>
#include <ctime>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "Uso ./prog add <mensagem> ou list" << std::endl;
        return show_usage();
    }

    std::string action = argv[1];
    //std::ofstream filename;
    //std::ifstream filename;
    //filename.open("teste.txt", std::ios::app);
    //filename.open("teste.txt");

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
    } else {
        return show_usage();
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(std::string message)
{
    diary.add(message);
    diary.write(message);
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

int App::show_usage()
{
    return 1;
}