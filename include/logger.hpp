
class Logger {
    public:
    Logger();
    ~Logger();
    enum Level {
        Debug, Warning, Fatal 
    };
    void log(Level level, const char* message) const;
};