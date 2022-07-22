#ifndef LOGGINGSYSTEM_LOGGERFACTORY_H
#define LOGGINGSYSTEM_LOGGERFACTORY_H

#include <string>
#include <list>
#include <map>

#include "Implementations/LoggerSimple.h"

namespace LoggerFactoryImplementationNames {

    static const std::string &IMPL_LOGGER_SIMPLE() {

        static const std::string IMPL_LOGGER_SIMPLE = "Logger :: Simple";
        return IMPL_LOGGER_SIMPLE;
    }
}

class LoggerFactory {

public:

    LoggerFactory() = delete;

    LoggerFactory(const LoggerFactory &) = delete;

    LoggerFactory(LoggerFactory &&) = delete;

    LoggerFactory &operator=(const LoggerFactory &) = delete;

    LoggerFactory &operator=(LoggerFactory &&) = delete;

    typedef Logger *(*LoggerCreateFunction)();

    typedef std::map<std::string, LoggerCreateFunction> LoggerCreateFunctionMap;

    static Logger *create(const std::string &implementationName) {

        auto it = creators().find(implementationName);
        if (it == creators().end()) {
            return nullptr;
        } else {
            return (it->second)();
        }
    }

    static bool registerImplementation(const std::string &implementationName, LoggerCreateFunction createFunction) {

        return creators()
                .insert(std::pair<std::string, LoggerCreateFunction>(implementationName, createFunction))
                .second;
    }

    static LoggerCreateFunctionMap &creators() {

        static LoggerCreateFunctionMap creators;
        return creators;
    }

    static void initializeDefaultImplementations() {

        if (creators().empty()) {
            registerImplementation(
                    LoggerFactoryImplementationNames::IMPL_LOGGER_SIMPLE(),
                    loggerSimpleCreatorFunction
            );
        }
    }

    static bool clearImplementations() {

        if (!creators().empty()) {
            creators().clear();
            return true;
        }
        return false;
    }

private:

    static Logger *loggerSimpleCreatorFunction() {

        static LoggerSimple loggerSimple;
        return &loggerSimple;
    }
};

#endif //LOGGINGSYSTEM_LOGGERFACTORY_H
