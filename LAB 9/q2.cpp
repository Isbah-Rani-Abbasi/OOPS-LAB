#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Auditor;

class LogMessage {
public:
    string message;
    string severity;
    string timestamp;

    LogMessage(const string& msg, const string& sev, const string& time)
        : message(msg), severity(sev), timestamp(time) {}

    friend ostream& operator<<(ostream& os, const LogMessage& log) {
        os << "[" << log.timestamp << "] [" << log.severity << "] " << log.message;
        return os;
    }
};

class Logger {
private:
    vector<LogMessage> logMessages;
    size_t maxMessages;
    Logger(const Logger&);
    Logger& operator=(const Logger&);

    void storeLog(const string& message, const string& severity, const string& timestamp) {
        LogMessage log(message, severity, timestamp);
        if (logMessages.size() >= maxMessages) {
            logMessages.erase(logMessages.begin());
        }
        logMessages.push_back(log);
    }

public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    Logger() : maxMessages(1000) {}

    void logInfo(const string& message) {
        storeLog(message, "INFO", getCurrentTimestamp());
    }

    void logWarning(const string& message) {
        storeLog(message, "WARNING", getCurrentTimestamp());
    }

    void logError(const string& message) {
        storeLog(message, "ERROR", getCurrentTimestamp());
    }

    void logMessage(const string& message, const string& severity) {
        storeLog(message, severity, getCurrentTimestamp());
    }

    friend class Auditor;

    string getCurrentTimestamp() {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
        return string(buffer);
    }
};

class Auditor {
public:
    vector<LogMessage> getLogs() const {
        return Logger::getInstance().logMessages;
    }

    vector<LogMessage> getLogs(const string& severity) const {
        vector<LogMessage> filteredLogs;
        Logger& logger = Logger::getInstance();
        for (const auto& log : logger.logMessages) {
            if (log.severity == severity) {
                filteredLogs.push_back(log);
            }
        }
        return filteredLogs;
    }
};

void simulateSystemActivity() {
    Logger& logger = Logger::getInstance();

    logger.logInfo("System started successfully.");
    logger.logWarning("Low memory detected in Network module.");
    logger.logError("Database connection failed.");
    logger.logInfo("User logged in.");
    logger.logWarning("Configuration file not found, using defaults.");
    logger.logError("File system error: Read-only file modified.");
    logger.logInfo("Email sent successfully.");
    logger.logMessage("Custom message with custom severity", "CUSTOM");
}

int main() {
    simulateSystemActivity();

    Auditor auditor;
    cout << "\n--- All Log Messages ---" << endl;
    vector<LogMessage> allLogs = auditor.getLogs();
    for (const auto& log : allLogs) {
        cout << log << endl;
    }

    cout << "\n--- Error Log Messages ---" << endl;
    vector<LogMessage> errorLogs = auditor.getLogs("ERROR");
    for (const auto& log : errorLogs) {
        cout << log << endl;
    }

    return 0;
}
