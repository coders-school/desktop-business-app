#include <cstdint>
#include <filesystem>
#include <fstream>
#include <string>


class FileManager
{
  public:
    enum class FileMode : u_int8_t
    {
        Input = 0,
        OutputAppend = 1,
        OutputTruncate = 2
    };
    FileManager(const std::filesystem::path& path, const std::string& file_name, const FileMode mode);
    FileManager(const FileManager& file_handler) = delete;
    FileManager(FileManager&& file_handler) = default;
    FileManager& operator=(const FileManager& file_handler) = delete;
    FileManager& operator=(FileManager&& file_handler) = default;
    std::fstream& getFileRef();
    std::string getFilePath() const;

  private:
    std::string file_name_;
    std::filesystem::path file_path_;
    std::fstream file_;
    void openFile(const FileMode mode);
};
