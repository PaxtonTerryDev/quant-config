#ifndef QUANT_CONFIG_CONFIG_HPP
#define QUANT_CONFIG_CONFIG_HPP

#include "quant_config/json.hpp"
#include <iostream>
#include <fstream>

namespace quant_config
{

    class Config
    {
    public:
        Config(int threads = 1, bool logging = false, int precision = 6)
            : thread_count_(threads), logging_enabled_(logging), precision_(precision) {}

        int getThreadCount() const { return thread_count_; }
        bool isLoggingEnabled() const { return logging_enabled_; }
        int getPrecision() const { return precision_; }

        void print() const
        {
            std::cout << "Config:\n"
                      << "  Threads: " << thread_count_ << "\n"
                      << "  Logging: " << (logging_enabled_ ? "Enabled" : "Disabled") << "\n"
                      << "  Precision: " << precision_ << " digits" << std::endl;
        }

        static Config fromJsonFile(const std::string &filename)
        {
            std::ifstream input(filename);
            if (!input.is_open())
            {
                throw std::runtime_error("Could not open config file: " + filename);
            }

            nlohmann::json j;
            input >> j;

            return Config(
                j.value("threads", 1),
                j.value("logging", false),
                j.value("precision", 6));
        }

    private:
        int thread_count_;
        bool logging_enabled_;
        int precision_;
    };

}

#endif // QUANT_CONFIG_CONFIG_HPP
