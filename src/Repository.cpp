#include"Repository.h"
#include<filesystem>
#include<iostream>
#include <fstream>

void Repository::init(){
    auto projectRoot = std::filesystem::current_path();
    if(std::filesystem::exists(projectRoot / ".vcs")){
        std::cout <<"Repository already initialized.\n";
        return;
    }
    std::filesystem::create_directory(projectRoot / ".vcs");

    auto repositorePath = projectRoot / ".vcs";

    std::filesystem::create_directory(repositorePath / "objects");
    std::filesystem::create_directory(repositorePath / "refs");
    
    std::ofstream head(repositorePath / "HEAD");
    head << "ref: refs/main";
    head.close();

    std::ofstream index(repositorePath / "index");
    index.close();
    
    std::cout << "Initialized empty VCS repository.\n";
}