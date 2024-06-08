#ifndef CC_LOG
#define CC_LOG

#include <string>
#define DEBUG

#if defined DEBUG
    /* since we're only logging when DEBUG is defined, we don't need to include it when NDEBUG is defined since
     * it has empty macros that don't do anything, which means that this will optimize the code
     * speeding up the compile times (I think)
     */
    #include <iostream>
    #include <source_location>

    enum Level { INFO = 1, ERROR = 2, WARNING = 3 };

    #define LOG(...) _LOG(std::clog, Level::INFO, std::source_location::current(), false, __VA_ARGS__)
    #define ERROR(...) _LOG(std::cerr, Level::ERROR, std::source_location::current(), false, __VA_ARGS__)
    #define WARNING(...) _LOG(std::clog, Level::WARNING, std::source_location::current(), false, __VA_ARGS__)

    #define LOG_R(...) _LOG(std::clog, Level::INFO, std::source_location::current(), true, __VA_ARGS__)
    #define ERROR_R(...) _LOG(std::cerr, Level::ERROR, std::source_location::current(), true, __VA_ARGS__)
    #define WARNING_R(...) _LOG(std::clog, Level::WARNING, std::source_location::current(), true, __VA_ARGS__)

    template <typename TF>
    void _LOG(std::ostream &out, Level logLevel, std::source_location location, TF const&first)
    {
        std::string filename(location.file_name());
        size_t lastSlash = filename.find_last_of("/\\");
        std::string file = filename.substr(lastSlash + 1);

        switch (logLevel)
        {
            case Level::INFO:
                out << "[" << file << "] " << "INFO: " << first << std::endl;
                break;
            case Level::ERROR:
                out << "[" << file << "] " << "ERROR: " << first << std::endl;
                break;
            case Level::WARNING:
                out << "[" << file << "] " << "WARNING: " << first << std::endl;
                break;
            default:
                break;
        }
    }

    template <typename TF, typename ...TR>
    void _LOG(std::ostream &out, Level logLevel, std::source_location location, bool overwrite = false, TF const &first = "", TR const &...args)
    {
        std::string filename(location.file_name());
        size_t lastSlash = filename.find_last_of("/\\");
        std::string file = filename.substr(lastSlash + 1);

        if (!overwrite)
        {
            switch (logLevel)
            {
                case Level::INFO:
                    out << "[" << file << "] " << "INFO: " << first;
                    (out << ... << args);
                    out << std::endl;
                    break;
                case Level::ERROR:
                    out << "[" << file << "] " << "ERROR: " << first;
                    (out << ... << args);
                    out << std::endl;
                    break;
                case Level::WARNING:
                    out << "[" << file << "] " << "WARNING: " << first;
                    (out << ... << args);
                    out << std::endl;
                    break;
                default:
                    break;
            }
        }
        else
        {
            switch (logLevel)
            {
                case Level::INFO:
                    out << "[" << file << "] " << "INFO: " << first;
                    (out << ... << args);
                    out << '\r' << std::flush;
                    break;
                case Level::ERROR:
                    out << "[" << file << "] " << "ERROR: " << first;
                    (out << ... << args);
                    out << '\r' << std::flush;
                    break;
                case Level::WARNING:
                    out << "[" << file << "] " << "WARNING: " << first;
                    (out << ... << args);
                    out << '\r' << std::flush;
                    break;
                default:
                    break;
            }
        }
    }

    #define IF_LOG(condition, ...) \
        if (condition) { _LOG(std::clog, Level::INFO, std::source_location::current(), false, __VA_ARGS__); }
    #define IF_ERROR(condition, ...) \
        if (condition) { _LOG(std::cerr, Level::ERROR, std::source_location::current(), false, __VA_ARGS__); }
    #define IF_WARNING(condition, ...) \
        if (condition) { _LOG(std::clog, Level::WARNING, std::source_location::current(), false, __VA_ARGS__); }
#elif defined NDEBUG
    #define LOG(...)
    #define ERROR(...)
    #define WARNING(...)
    #define LOG_R(...)
    #define ERROR_R(...)
    #define WARNING_R(...)
    #define IF_LOG(condition, ...)
    #define IF_ERROR(condition, ...)
    #define IF_WARNING(condition, ...)
#endif // DEBUG

#endif // CC_LOG
