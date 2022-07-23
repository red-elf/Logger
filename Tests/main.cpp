#include <iostream>
#include <chrono>

#include "Logger.h"
#include "LogLevel.h"
#include "LoggerSimple.h"
#include "LoggerFactory.h"
#include "LoggerLibrary.h"

namespace Test {

    static Logger *createSimpleLogger() {

        static LoggerSimple loggerSimple;
        return &loggerSimple;
    }
}

int main() {
    std::cout << "Logger Library version " << LoggerLibrary::Info::getVersion() << "\n";

    // Work in progress:
    LoggerFactory::initializeDefaultImplementations();
    std::cout << "Creators count A: " << LoggerFactory::creators().size() << "\n";
    auto registered = LoggerFactory::registerImplementation(LoggerFactoryImplementationNames::IMPL_LOGGER_SIMPLE(),
                                                            Test::createSimpleLogger);
    std::cout << "Creators count B: " << LoggerFactory::creators().size() << ", registered: " << registered << "\n";
    registered = LoggerFactory::registerImplementation("DUMMY", Test::createSimpleLogger);
    std::cout << "Creators count C: " << LoggerFactory::creators().size() << ", registered: " << registered << "\n";

    auto logger = Test::createSimpleLogger();
    logger->log("Test 123");
    logger->logFull(
            "a",
            "a",
            std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count(),
            LogLevel::verbose,
            "a",
            "a a a",
            std::list<std::string>()
    );

    LoggerSimple logger2;
    const std::string &msg = "Test 123";
    logger2.log(msg);
    logger2.logFull(
            "a",
            "a",
            std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count(),
            LogLevel::verbose,
            "a",
            "a a a 2",
            std::list<std::string>()
    );

    std::list<std::string> items;
    items.emplace_back("Milos");
    items.emplace_back(" voli ");
    items.emplace_back("Olgu");
    auto logger3 = LoggerFactory::create(LoggerFactoryImplementationNames::IMPL_LOGGER_SIMPLE());
    logger3->setApplicationVersion("dummy version");
    logger3->setApplicationId("dummy id");
    logger3->logFull(
            "a",
            "a",
            std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch()).count(),
            LogLevel::verbose,
            "a",
            "a a a 3",
            std::list<std::string>()
    );
    logger3->log("Milos i Olga <3");

    auto logger4 = dynamic_cast<LoggerSimple *>(logger3);
    logger4->setUsingDynamicTabs(false);
    logger4->setApplicationId("Logger Tryout App");
    logger4->setApplicationVersion("1.0");
    logger4->setTabWidthTag(2);
    logger4->setTabWidthTime(2);
    logger4->setTabWidthApplicationId(2);
    logger4->setTabWidthApplicationVersion(2);
    logger4->log("Milos i Olga <3 <3 <3");
    logger4->log(LogLevel::info, "Milos i Olga <3 <3 <3 <3");
    logger4->setTabWidthTag(10);
    logger4->setTabWidthTime(10);
    logger4->setTabWidthApplicationId(10);
    logger4->setTabWidthApplicationVersion(10);
    logger4->log("Dumy Tag", "Milos i Olga <3 <3 <3");
    logger4->log("Milos i Olga <3 <3 <3 <3", items);
    logger4->log(LogLevel::info, "Dumy Tag", "Milos i Olga <3 <3 <3 <3");
    logger4->log(LogLevel::info, "Milos i Olga <3 <3 <3", items);
    logger4->log("Dumy Tag", "Milos i Olga <3 <3 <3 <3", items);
    logger4->log(LogLevel::info, "Dumy Tag", "Milos i Olga <3 <3 <3", items);
    logger4->log(LogLevel::error, "Dumy Tag", "Milos i Olga <3 <3 <3 <3", items);
    logger4->log(LogLevel::debug, "Dumy Tag", "Milos i Olga <3 <3 <3", items);

    logger4->setTabWidthTime(30);
    logger4->log(LogLevel::warning, "Aleksandra's show! :)");
    logger4->log("Aleksandra's show! :)");

    logger4->resetTabWidths();
    logger4->log(LogLevel::error, "Aleksandra's show! :)");
    logger4->log(LogLevel::info, "Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :)");

    logger4->setUsingDynamicTabs(true);
    logger4->log(LogLevel::error, "Aleksandra's show! :)", "Aleksandra's show! :)");
    logger4->log(LogLevel::info, "Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::warning, "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)",
                 "Aleksandra's show! :) Aleksandra's show! :) Aleksandra's show! :)");
    logger4->log(LogLevel::error, "<3 <3 <3", "Aleksandra's show! :)");

    logger4->setUsingDynamicTabs(false);
    logger4->log(LogLevel::warning, "Aleksandra's show! :)");
    logger4->log("Aleksandra's show! :)");
    logger4->setTabWidthTag(3);
    logger4->setTabWidthTime(3);
    logger4->setTabWidthApplicationId(3);
    logger4->setTabWidthApplicationVersion(3);
    logger4->log(LogLevel::warning, "Aleksandra's show! :)");
    logger4->log("Aleksandra's show! :)");

    logger4->setUsingDynamicTabs(true);
    logger4->setShowTimeInNanos(true);
    logger4->resetDynamicTabs();
    for (int x = 0; x < 10; x++) {
        logger4->log("JA VOLIM OLGU!!!");
    }
    // Work in progress - END.

    return 0;
}
