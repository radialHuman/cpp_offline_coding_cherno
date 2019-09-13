// https://www.youtube.com/watch?v=3dHBFBw//

// log class
// log system level, error, warning and info
// this si just to start, not a production level code

#include <iostream>
#include <string>

class Log
{
public: // for variables
    const int logLevelWarning = 1;
    const int logLevelError = 0;
    const int logLevelInfo = 2; // infromation
private:
    int m_LogLevel = logLevelInfo; // m_ means it is a class member variable, which is private

public: // for functions
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Warn(const char *message)
    {
        if(m_LogLevel >= logLevelWarning)
            std::cout << "[!! Warning]:" << message << std::endl;
    }

    void Info(const char* message)
    {
        if(m_LogLevel >= logLevelInfo)
            std::cout << "[! Information]:" << message << std::endl;
    }

    void Error(const char* message)
    {
        if(m_LogLevel >= logLevelError)
            std::cout << "[!!! Error]:" << message << std::endl;
    }

};


int main()
{
    Log log;
    log.SetLevel(log.logLevelWarning); // log level warning so only two will work below
    log.Warn("Something!");
    log.Info(" Something else!");
    log.Error(" Something completely different!");

}

/*
 * OUTPUT
[!! Warning]:Something!
[!!! Error]: Something completely different!
 */