
class Engine {
    Engine();
    ~Engine();

    public:

    /// Disable copy constructor
    Engine(const Engine&) = delete;

    /// Singleton pattern
    static Engine& instance() {
        static Engine engine;
        return engine;
    }

    // End of singleton implementation

    private:

    public:
};