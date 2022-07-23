#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "TestCaseSimpleLoggerOutputVerification.h"
#include "MockLogDataGenerator.h"

using namespace LoggingSystemLibrary::MockLogDataGenerator;

std::vector<std::string> getDirectoryFiles(const std::string &dir) {
    std::vector<std::string> files;
    std::shared_ptr<DIR> directory_ptr(opendir(dir.c_str()), [](DIR *dir) { dir && closedir(dir); });
    struct dirent *dirent_ptr;
    if (!directory_ptr) {
        std::cout << "Error opening : " << std::strerror(errno) << dir << std::endl;
        return files;
    }

    while ((dirent_ptr = readdir(directory_ptr.get())) != nullptr) {
        files.emplace_back(std::string(dirent_ptr->d_name));
    }
    return files;
}

bool TestCaseSimpleLoggerOutputVerification::execute() {

    auto lofDataGenerated = generateLogData(false);
    if (ASSERT_TRUE(lofDataGenerated)) {
        std::list<std::string> mocks;
        std::list<std::string> verifications;
        auto files = getDirectoryFiles("./");
        if (ASSERT_FALSE(files.empty())) {
            for (std::string &file : files) {
                if (endsWith(file, mockFileExtension())) {
                    mocks.emplace_back(file);
                    continue;
                }
                if (endsWith(file, verificationFileExtension())) {
                    verifications.emplace_back(file);
                    continue;
                }
            }
            if (ASSERT_FALSE(mocks.empty()) && ASSERT_FALSE(verifications.empty())) {
                if (ASSERT_EQUAL((int) mocks.size(), (int) verifications.size())) {
                    mocks.sort();
                    verifications.sort();
                    auto itMocks = mocks.begin();
                    auto itVerifications = verifications.begin();
                    for (int x = 0; x < (int) mocks.size(); ++x) {
                        std::advance(itMocks, x);
                        std::advance(itVerifications, x);
                        auto mock = *itMocks;
                        auto verification = *itVerifications;

                        std::ifstream mockFile(mock);
                        auto mockCount = std::count(std::istreambuf_iterator<char>(mockFile),
                                                    std::istreambuf_iterator<char>(), '\n');

                        std::ifstream verificationFile(verification);
                        auto verificationCount = std::count(std::istreambuf_iterator<char>(verificationFile),
                                                            std::istreambuf_iterator<char>(), '\n');

                        if (ASSERT_TRUE(mockCount > 0) && ASSERT_TRUE(verificationCount > 0)) {
                            if (ASSERT_EQUAL(mockCount, verificationCount)) {

                                for (long y = 0; y < mockCount; ++y) {
                                    std::string mockLine;
                                    std::getline(mockFile, mockLine);

                                    std::string verificationLine;
                                    std::getline(verificationFile, verificationLine);

                                    if (!ASSERT_EQUAL(mockLine, verificationLine)) {
                                        log("Mock asserting failed: " + mock, OUTPUT_WRITER_PRIORITY_ASSERT_FAILED);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}
