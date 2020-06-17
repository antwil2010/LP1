#include <iostream>
#include <string>
#include <fstream>



int main(int argc, char *argv[]){
    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return 1;
    }
    std::string nome;
    nome = argv[1];
    if(nome != "add"){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return 1;
    }
    std::string mensagem;
    std::string terminal;
    std::ofstream arquivo;
    arquivo.open("teste.txt", std::ios::app);
    if(argc == 2){
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, mensagem);
        arquivo << mensagem << std::endl;
        std::cout << "Mensagem: " << mensagem << " Adicionada" << std::endl;
    } else {
        for(size_t i = 2; i < argc; i++){
            terminal += argv[i];
            terminal += " ";
        }
        arquivo << terminal << std::endl;
        std::cout << "Mensagem: " << terminal << "Adicionada" << std::endl;
    }
    arquivo.close();
    return 0;
}