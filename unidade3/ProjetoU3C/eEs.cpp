#include <iostream>
#include <fstream>

int main(){
    std::ofstream arquivo; 
    std::string nome;
    
    std::cin >> nome;
    arquivo.open(nome);

    if(arquivo.is_open()){
    arquivo << "eu ainda irei a praia" << "\n" << "mas não esse ano";
    arquivo.close();
    }

    std::ifstream arquiL(nome);
    std::string linha;
    if(arquiL.is_open()){
        while(getline(arquiL,linha)){
            std::cout << linha << "\n";
        }
    }
    return 0;
}