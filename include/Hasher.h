#pragma once
#include<iostream>
#include<filesystem>

class Hasher{
    public:
        std::string sha1(const std::string& data);
};