#pragma once

#include "image.h"
#include "./filters/a_filter.h"

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

class Parser {
public:
    Parser(int argc, const char** argv);
    void Parse();
    const char* GetFileForReading() const;
    const char* GetFileForWriting() const;
    std::vector<std::unique_ptr<Filter>>& GetFilters();

private:
    void Read();
    void ParseCrop();
    void ParseGrayscale();
    void ParseNegative();
    void ParseSharpening();
    void ParseEdge();
    const int argc_;
    const char** argv_;
    int pos_;
    std::unordered_map<std::string, std::function<void()>> commands_;
    const char* file_read_;
    const char* file_write_;
    std::vector<std::unique_ptr<Filter>> filters_;
};