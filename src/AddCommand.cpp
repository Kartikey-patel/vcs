#include "AddCommand.h"

#include <iostream>
#include<fstream>
#include <iterator>

AddCommand::AddCommand(const std::filesystem::path& vcsPath)
    :objectStore(vcsPath / "objects"),
    index(vcsPath / "index")
{
}

void AddCommand::execute(const std::filesystem::path& filePath){
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file " << filePath << '\n';
        return;
    }

    std::string contents{
    std::istreambuf_iterator<char>(file),
    std::istreambuf_iterator<char>()
    };

    std::string hash = hasher.sha1(contents);

    objectStore.storeObject(hash,contents);

    std::filesystem::path normalized = filePath.lexically_normal();

    index.addEntry(hash,normalized);
}