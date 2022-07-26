#include <string>
#include <argparse/argparse.hpp>
#include "Logger.h"
#include "LogLevel.h"
#include "LoggerSimple.h"
#include "LoggerChained.h"
#include "VersionInfo.h"
#include "FileOutputWriter.h"

Logger *createLogger(const std::string &out) {

    static LoggerSimple simpleLogger;
    static const std::string &output = out;

    if (!output.empty()) {

        auto outputWriterFunction = [](const std::string &what) {

            FileOutputWriter outputWriter;
            outputWriter.setFileName(output);
            outputWriter.write(what);
        };

        static LoggerSimple fileLogger;
        fileLogger.setOutputWriterFunction(outputWriterFunction);

        static LoggerChained loggerChained;
        loggerChained.addLogger(&simpleLogger);
        loggerChained.addLogger(&fileLogger);
        return &loggerChained;
    }


    return &simpleLogger;
}

void tokenize(std::string const &str, const char delim, std::list<std::string> &out) {

    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos) {

        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

int main(int argc, char *argv[]) {

    auto relog = "relog";
    auto version = getVersion();

    argparse::ArgumentParser program(relog, version);

    program.add_argument("-i", "--applicationId")
            .default_value(std::string(""))
            .help("The application identifier");

    program.add_argument("-n", "--applicationVersion")
            .default_value(std::string(""))
            .help("The application version");

    program
            .add_argument("-l", "--level")
            .default_value(std::string("v"))
            .help("Log level: verbose (v), debug (d), info (i), warning (w), error (e)");

    program.add_argument("-t", "--tag")
            .default_value(std::string(""))
            .help("The log tag");

    program.add_argument("-m", "--multiline")
            .default_value(false)
            .implicit_value(true)
            .help("Add row log data to every line for the multi-line entries");

    program.add_argument("-o", "--output")
            .default_value(std::string(""))
            .help("The path for the output to file");

    std::string epilog("Project homepage: ");
    epilog.append(getHomepage());

    program.add_description(getDescription());
    program.add_epilog(epilog);

    try {

        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {

        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    try {

        auto count = 0;
        std::string line;
        std::string message;

        while (getline(std::cin, line)) {

            message.append(line);
            if (count > 0) {

                message.append("\n");
            }
            count++;
        }

        auto multiline = program["--multiline"] == true;
        auto tag = program.get<std::string>("tag");
        auto out = program.get<std::string>("output");
        auto level = program.get<std::string>("level");
        auto appId = program.get<std::string>("applicationId");
        auto appVersion = program.get<std::string>("applicationVersion");

        auto trace = std::list<std::string>();

        auto pos = message.find('\n');
        if (pos != std::string::npos) {

            tokenize(message, '\n', trace);
            message = "\t";
        }

        auto time = std::chrono::duration_cast<std::chrono::milliseconds>
                (std::chrono::system_clock::now().time_since_epoch()).count();


        // verbose (v), debug (d), info (i), warning (w), error (e)
        auto logLevel = LogLevel::verbose;

        if (level == "d" || level == "debug") {

            logLevel = LogLevel::debug;
        }

        if (level == "i" || level == "info") {

            logLevel = LogLevel::info;
        }

        if (level == "w" || level == "warning") {

            logLevel = LogLevel::warning;
        }

        if (level == "e" || level == "error") {

            logLevel = LogLevel::error;
        }

        auto logger = createLogger(out);
        if (multiline) {

            for (const std::string row: trace) {

                logger->logFull(

                        appId,
                        appVersion,
                        time,
                        logLevel,
                        tag,
                        row,
                        std::list<std::string>()
                );
            }
        } else {

            logger->logFull(appId, appVersion, time, logLevel, tag, message, trace);
        }

    } catch (std::logic_error &e) {

        std::cout << "No message provided" << std::endl;
    }

    return 0;
}
