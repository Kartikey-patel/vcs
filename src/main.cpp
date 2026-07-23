#include<iostream>
#include"Hasher.h"
#include "AddCommand.h"
#include"Repository.h"

int main(int argc, char* argv[]){

    if(argc > 1 && std::string(argv[1]) == "init"){
        Repository repo;
        repo.init();
    }
    else if (std::string(argv[1]) == "add")
    {
        AddCommand add(".vcs");
        add.execute(argv[2]);
    }
    
}