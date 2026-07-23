#pragma once

#include<filesystem>

#include "Hasher.h"
#include "ObjectStore.h"
#include "Index.h"


class AddCommand{

private:
    Hasher hasher;
    ObjectStore objectStore;
    Index  index;

public:
    explicit AddCommand(const std::filesystem::path& vcsPath);
    
    void execute(const std::filesystem::path& filePath);
};

