#ifndef LOGGINGSYSTEM_MOCKLOGDATAGENERATOR_H
#define LOGGINGSYSTEM_MOCKLOGDATAGENERATOR_H

#include <string>
#include <fstream>

#include "Logger.h"
#include "LogLevel.h"
#include "LoggerFactory.h"
#include "LoggerSimple.h"
#include "LoggerChained.h"
#include "FileOutputWriter.h"
#include "Implementations/LoggerSimpleMocked.h"

namespace LoggingSystemLibrary::MockLogDataGenerator {

    enum class LogMethodVersion {
        message,
        level_message,
        tag_message,
        message_stacktrace,
        level_tag_message,
        level_message_stacktrace,
        tag_message_stacktrace,
        level_tag_message_stacktrace,
        full_log
    };

    static FileOutputWriter &outputWriter() {

        static FileOutputWriter fileOutputWriter;
        return fileOutputWriter;
    }

    static const std::string &mockFileExtension() {

        static const std::string mockFileNameExtension = ".mock";
        return mockFileNameExtension;
    }

    static const std::string &verificationFileExtension() {

        static const std::string mockFileNameExtension = ".verify";
        return mockFileNameExtension;
    }

    static const std::string &fileExtension(bool isMock) {
        if (isMock) {
            return mockFileExtension();
        }
        return verificationFileExtension();
    }

    static const std::string &mockFileNameBeginning() {

        static const std::string mockFileNameBeginning = "logger_simple_mock_MTHD_";
        return mockFileNameBeginning;
    }

    static bool exists(const std::string &name) {

        std::ifstream f(name.c_str());
        return f.good();
    }

    static bool deleteFile(const std::string &name) {

        const char *cstr = name.c_str();
        if (exists(cstr)) {
            return std::remove(cstr) == 0;
        }
        return true;
    }

    static std::string getFileName(
            const LogMethodVersion &version,
            const std::string &fileNameSuffix,
            bool isMock
    ) {
        switch (version) {
            case LogMethodVersion::message:
                return mockFileNameBeginning() + "message" + fileNameSuffix + fileExtension(isMock);

            case LogMethodVersion::level_message:
                return mockFileNameBeginning() + "level_message" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::tag_message:
                return mockFileNameBeginning() + "tag_message" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::message_stacktrace:
                return mockFileNameBeginning() + "message_stacktrace" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::level_tag_message:
                return mockFileNameBeginning() + "level_tag_message" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::level_message_stacktrace:
                return mockFileNameBeginning() + "level_message_stacktrace" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::tag_message_stacktrace:
                return mockFileNameBeginning() + "tag_message_stacktrace" + fileNameSuffix + fileExtension(isMock);
            case LogMethodVersion::level_tag_message_stacktrace:
                return mockFileNameBeginning() + "level_tag_message_stacktrace" + fileNameSuffix +
                       fileExtension(isMock);
            case LogMethodVersion::full_log:
                return mockFileNameBeginning() + "full_log" + fileNameSuffix + fileExtension(isMock);
        }
        return ""; // We return to prevent warning on Linux.
    }

    static void generateLogLines(
            const LogMethodVersion &version,
            int maxMessageLength,
            const std::string &repeatingContentString,
            Logger &logger
    ) {

        std::list<std::string> messages;
        for (int x = 0; x < maxMessageLength; ++x) {
            std::string message = repeatingContentString;
            for (int y = 0; y < x; ++y) {
                message += repeatingContentString;
            }
            messages.emplace_back(message);
        }

        std::list<LogLevel> logLevels;
        logLevels.emplace_back(LogLevel::verbose);
        logLevels.emplace_back(LogLevel::debug);
        logLevels.emplace_back(LogLevel::info);
        logLevels.emplace_back(LogLevel::warning);
        logLevels.emplace_back(LogLevel::error);

        for (const std::string &message : messages) {

            std::string toPrintBase = message + " mthd.: ";
            std::string toPrint;
            switch (version) {
                case LogMethodVersion::message:
                    toPrint = toPrintBase + "message";
                    logger.log(toPrint);
                    break;
                case LogMethodVersion::level_message:
                    toPrint = toPrintBase + "level, message";
                    for (LogLevel level : logLevels) {
                        logger.log(level, toPrint);
                    }
                    break;
                case LogMethodVersion::tag_message:
                    toPrint = toPrintBase + "tag, message";
                    for (const std::string &tag : messages) {
                        logger.log(tag, toPrint);
                    }
                    break;
                case LogMethodVersion::message_stacktrace:
                    toPrint = toPrintBase + "message, stacktrace";
                    logger.log(toPrint, messages);
                    break;
                case LogMethodVersion::level_tag_message:
                    toPrint = toPrintBase + "level, tag, message";
                    for (LogLevel level : logLevels) {
                        for (const std::string &tag : messages) {
                            logger.log(level, tag, toPrint);
                        }
                    }
                    break;
                case LogMethodVersion::level_message_stacktrace:
                    toPrint = toPrintBase + "level, message, stacktrace";
                    for (LogLevel level : logLevels) {
                        for (const std::string &tag : messages) {
                            logger.log(level, toPrint, messages);
                        }
                    }
                    break;
                case LogMethodVersion::tag_message_stacktrace:
                    toPrint = toPrintBase + "tag, message, stacktrace";
                    for (const std::string &tag : messages) {
                        logger.log(tag, toPrint, messages);
                    }
                    break;
                case LogMethodVersion::level_tag_message_stacktrace:
                    toPrint = toPrintBase + "level, tag, message, stacktrace";
                    for (LogLevel level : logLevels) {
                        for (const std::string &tag : messages) {
                            logger.log(level, tag, toPrint, messages);
                        }
                    }
                    break;
                case LogMethodVersion::full_log:
                    toPrint = toPrintBase + "full log";
                    for (LogLevel level : logLevels) {
                        for (const std::string &applicationId : messages) {
                            for (const std::string &applicationVersion : messages) {
                                for (const std::string &tag : messages) {
                                    logger.logFull(
                                            applicationId,
                                            applicationVersion,
                                            1,
                                            level,
                                            tag,
                                            toPrint,
                                            messages
                                    );
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }

    static bool generateLogData(bool isMock) {

        auto outputWriterFunction = [](const std::string &what) {

            outputWriter().write(what);
        };

        LoggerSimpleMocked destinationLogger;
        destinationLogger.setOutputWriterFunction(outputWriterFunction);
        destinationLogger.setMockedTime(1);

        std::string fileNameSuffix;
        for (int dTabs = 0; dTabs <= 1; ++dTabs) {

            destinationLogger.resetTabWidths();
            destinationLogger.setUsingDynamicTabs(dTabs == 0);
            if (dTabs == 0) {
                fileNameSuffix = "_dtabs";
            } else {
                fileNameSuffix = "_tabs";
            }

            auto fileNameSuffixBeforeNanos = fileNameSuffix;
            for (int nanos = 0; nanos <= 1; ++nanos) {

                destinationLogger.setShowTimeInNanos(nanos == 1);
                if (nanos == 1) {
                    fileNameSuffix = fileNameSuffixBeforeNanos + "_nanos";
                }

                int maxMessageLength = 10;
                auto maxTabsWidth = maxMessageLength + 1;
                const std::string repeatingContentString = "M";

                // Tabs width:
                auto lastTabsWidth = maxTabsWidth;
                if (dTabs == 0) {
                    lastTabsWidth = 1;
                }

                auto fileNameSuffixBeforeTabs = fileNameSuffix;
                for (int tabsWidth = 1; tabsWidth <= lastTabsWidth; ++tabsWidth) {
                    if (dTabs == 0) {
                        destinationLogger.resetTabWidths();
                        destinationLogger.setUsingDynamicTabs(true);
                    } else {
                        fileNameSuffix = fileNameSuffixBeforeTabs + "_tabw_" + std::to_string(tabsWidth);
                        destinationLogger.setUsingDynamicTabs(false);
                        destinationLogger.resetTabWidths();
                        destinationLogger.setTabWidthApplicationId(tabsWidth);
                        destinationLogger.setTabWidthApplicationVersion(tabsWidth);
                        destinationLogger.setTabWidthTag(tabsWidth);
                        destinationLogger.setTabWidthTime(tabsWidth);
                    }

                    std::string outputFile = getFileName(LogMethodVersion::message, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::message,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::level_message, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::level_message,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::tag_message, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::tag_message,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::message_stacktrace, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::message_stacktrace,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::level_tag_message, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::level_tag_message,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::level_message_stacktrace, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::level_message_stacktrace,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::tag_message_stacktrace, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::tag_message_stacktrace,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::level_tag_message_stacktrace, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::level_tag_message_stacktrace,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );

                    outputFile = getFileName(LogMethodVersion::full_log, fileNameSuffix, isMock);
                    outputWriter().setFileName(outputFile);
                    if (!deleteFile(outputFile)) {
                        return false;
                    }
                    generateLogLines(
                            LogMethodVersion::full_log,
                            maxMessageLength,
                            repeatingContentString,
                            destinationLogger
                    );
                }
            }
        }
        return true;
    }
}


#endif //LOGGINGSYSTEM_EXAMPLELOGGER_H
