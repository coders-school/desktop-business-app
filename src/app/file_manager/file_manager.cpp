#include "file_manager.hpp"
#include <iostream>
#include <stdexcept>

FileManager::FileManager(const std::filesystem::path& path, const std::string& file_name, FileMode mode)
    : file_name_(file_name),
      file_path_(std::filesystem::absolute(std::filesystem::current_path().parent_path() / path / file_name))
{
    if (!std::filesystem::exists(file_path_))
    {
        file_path_ = std::filesystem::absolute(std::filesystem::current_path() / path / file_name);
    }

    switch (mode)
    {
    case FileMode::Input:
        file_.open(file_path_, std::ios::in);
        break;

    case FileMode::OutputAppend:
        file_.open(file_path_, std::ios::out | std::ios::app);
        break;

    case FileMode::OutputTruncate:
        file_.open(file_path_, std::ios::out | std::ios::trunc);
        break;

    default:
        throw std::invalid_argument{"Invalid file mode"};
    }
    if (!file_.is_open())
    {
        throw std::runtime_error{"Cannot open file"};
    }
}

FileManager::~FileManager()
{
    file_.close();
}

std::fstream& FileManager::getFileRef()
{
    return file_;
}

std::string FileManager::getFilePath() const
{
    return file_path_;
}
