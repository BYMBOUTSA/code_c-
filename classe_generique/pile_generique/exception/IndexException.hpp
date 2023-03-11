#pragma once
#include <iostream>
#include <exception>
#include <string>



class IndexException : public std::exception {
    protected:
        std::string msg;
    public:
        IndexException(std::string m) : msg(m) {}
        IndexException(const IndexException & e) : msg(e.msg) {}
        // redefinition de what
        virtual const char * what() const noexcept override {
            return msg.c_str();
        }
};

class IndexOverFlow : public IndexException {
    public:
        IndexOverFlow(const int i) :
            IndexException("Index overflow: " + std::to_string(i)) {}
};

class IndexUnderFlow : public IndexException {
    public:
        IndexUnderFlow(const int i) :
            IndexException("Index underflow : " + std::to_string(i)) {}
        
};