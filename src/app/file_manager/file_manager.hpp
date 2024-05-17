#include <filesystem>
#include <fstream>
#include <string>

class FileManager {
public:
enum class FileMode {
        Input,
        OutputAppend,
        OutputTruncate
    };
    FileManager(const std::filesystem::path& path, const std::string& file_name, FileMode mode);
    FileManager(const FileManager& file_handler) = delete;
    FileManager(FileManager&& file_handler) = default;
    FileManager& operator=(const FileManager& file_handler) = delete;
    FileManager& operator=(FileManager&& file_handler) = default;
    ~FileManager();

    std::fstream& getFileRef();
    std::string getFilePath() const;
private:
    std::string file_name_;
    std::filesystem::path file_path_;
    std::fstream file_;
};
