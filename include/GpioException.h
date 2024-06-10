class GpioException : public std::runtime_error {
public:
    explicit GpioException(const char* what_arg)
        : std::runtime_error(what_arg) { }
};
