#include "functions.hpp"


// Exceptions
DomainError::DomainError(const char* filename, const char* function, uint32_t line, const std::string & message)
    : domain_error("Domain error.\nFilename: " + std::string(filename) + "\nFunction: " + std::string(function) + "\nLine: " + std::to_string(line) + "\nDescription: " + message + "\n\n")
{}

InvalidArgument::InvalidArgument(const char* filename, const char* function, uint32_t line, const std::string & message)
    : invalid_argument("Invalid argument error.\nFilename: " + std::string(filename) + "\nFunction: " + std::string(function) + "\nLine: " + std::to_string(line) + "\nDescription: " + message + "\n\n")
{}

OutOfRange::OutOfRange(const char* filename, const char* function, uint32_t line, const std::string & message)
    : out_of_range("Out of range error.\nFilename: " + std::string(filename) + "\nFunction: " + std::string(function) + "\nLine: " + std::to_string(line) + "\nDescription: " + message + "\n\n")
{}

RuntimeError::RuntimeError(const char* filename, const char* function, uint32_t line, const std::string & message)
    : runtime_error("Runtime error.\nFilename: " + std::string(filename) + "\nFunction: " + std::string(function) + "\nLine: " + std::to_string(line) + "\nDescription: " + message + "\n\n")
{}


// MainLog
LogManager::LogManager() {
}

LogManager* LogManager::GetInstance() {
    if (log_manager_ == nullptr) {
        log_manager_ = new LogManager();
    }
    return log_manager_;
}

std::ofstream& LogManager::log_stream() noexcept {
    log_out_.open("game_log.txt");
    return log_out_;
}


// Common functions

// Comparing
bool equality(double left, double right) noexcept {
    return std::abs(left - right) <= EPS;
}

bool less_equality(double left, double right) noexcept {
    return left < right || equality(left, right);
}
