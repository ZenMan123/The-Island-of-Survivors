#pragma once

#include <fstream>
#include <sstream>


// Global constants
constexpr double EPS = 1e-12;
constexpr double PI = 3.141592653589793;


// Global define settings
#define WARNING_LOG_ENABLED


// Game exceptions

// Exception for domain error, inheritor of std::domain_error
class DomainError : public std::domain_error {
public:
    DomainError(const char* filename, const char* function, uint32_t line, const std::string& message);
};

// Exception for invalid argument error, inheritor of std::invalid_argument
class InvalidArgument : public std::invalid_argument {
public:
    InvalidArgument(const char* filename, const char* function, uint32_t line, const std::string& message);
};

// Exception for out of range error, inheritor of std::out_of_range
class OutOfRange : public std::out_of_range {
public:
    OutOfRange(const char* filename, const char* function, uint32_t line, const std::string& message);
};

// Exception for runtime error, inheritor of std::runtime_error
class RuntimeError : public std::runtime_error {
public:
    RuntimeError(const char* filename, const char* function, uint32_t line, const std::string& message);
};


// Main log manager
class LogManager {
private:
    inline static LogManager* log_manager_ = nullptr;

    std::ofstream log_out_;

    LogManager();

public:
    LogManager(const LogManager& other) = delete;

    void operator=(const LogManager&) = delete;

    static LogManager* GetInstance();

    std::ofstream& log_stream() noexcept;
};


// Log functions
#define LOG_MESSAGE(stream, type)                                                                           \
    do {                                                                                                    \
        auto log_stream(std::move(LogManager::GetInstance()->log_stream()));                                \
        log_stream << type << " in file: " << __FILE__;                                                     \
        log_stream << ", function: " << __func__;                                                           \
        log_stream << ", line: " << __LINE__;                                                               \
        log_stream << "\n" << stream << "\n\n";                                                             \
        log_stream.close();                                                                                 \
    } while (false)  

#define LOG_ERROR(stream) LOG_MESSAGE(stream, "ERROR")

#define ENSURE(condition, error_type, stream)                                                               \
    do {                                                                                                    \
        if (!(condition)) {                                                                                 \
            LOG_ERROR(stream);                                                                              \
            std::stringstream str_stream;                                                                   \
            str_stream << stream;                                                                           \
            throw error_type(__FILE__, __func__, __LINE__, str_stream.str());                               \
        }                                                                                                   \
    } while (false)


#ifdef WARNING_LOG_ENABLED

    #define LOG_WARNING(stream) LOG_MESSAGE(stream, "WARNING")
    
    #define CHECK(condition, stream)                                                                        \
        do {                                                                                                \
            if (!(condition)) {                                                                             \
                LOG_WARNING(stream);                                                                        \
            }                                                                                               \
        } while (false)

#else

    #define LOG_WARNING(stream)
    #define CHECK(condition, stream)

#endif


// Common functions

// GRE equality checking up to the EPS value
bool equality(double left, double right) noexcept;

// GRE less or equality checking up to the EPS value
bool less_equality(double left, double right) noexcept;

// GRE composing hash and hasher(value)
template <typename T, class Hasher = std::hash<T>>
void hash_combine(size_t& hash, const T& value, const Hasher& hasher = Hasher()) {
    hash ^= hasher(value) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
}
