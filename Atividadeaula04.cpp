#include <iostream>
#include <string>
#include <fstream>

// atividade aula 04
// adicionar list para que liste todas as mensagens em ordem de um txt
// ter a opção add e a opção list para um determinado txt


int main(int argc, char *argv[]){

    if(argc == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return 1;
    }
    std::string nome;
    nome = argv[1];
    if(nome != "add" && nome != "list"){
        std::cout << "Uso: " << argv[0] << " add <mensagem> ou list" << std::endl;
        return 1;
    }
    std::string mensagem;
    std::string terminal;
    std::ofstream arquivo_escrita;
    std::ifstream arquivo_leitura;
    arquivo_escrita.open("teste.txt", std::ios::app);
    if(argc == 2 && nome == "add"){
        std::cout << "Informe a mensagem: " << std::endl;
        std::getline(std::cin, mensagem);
        arquivo_escrita << mensagem << std::endl;
        std::cout << "Mensagem: " << mensagem << " Adicionada" << std::endl;
    } else if(nome == "add"){
        for(size_t i = 2; i < argc; i++){
            terminal += argv[i];
            terminal += " ";
        }
        arquivo_escrita << terminal << std::endl;
        std::cout << "Mensagem: " << terminal << "Adicionada" << std::endl;
    } else {
        arquivo_leitura.open("teste.txt");
        if(!arquivo_leitura.is_open()){
            std::cerr << "Arquivo não existente ou sem permissão de leitura." << std::endl;
            return 1;
        }
        int line_number = 0;
        while(!arquivo_leitura.eof()){
            ++line_number;
            std::getline(arquivo_leitura, mensagem);
            if(mensagem.size() == 0){
                continue;
            }
            std::cout << line_number << ". " << mensagem << std::endl;
        }
    }
    arquivo_leitura.close();
    arquivo_escrita.close();
    return 0;
}