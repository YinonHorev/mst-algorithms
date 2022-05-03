//
//  logger.hpp
//  mst-algorithms
//
//  Created by Yinon Horev on 01/05/2022.
//

#ifndef logger_hpp
#define logger_hpp

#include <iostream>
#include <string>
#include <fstream>

class Logger {
    std::string filename;
    std::ofstream logFile;
    
public:
    
    Logger(std::string _filename)
    {
        filename = _filename;
        logFile.open(filename);
    }
    void Print(std::string logLine)
    {
        std::cout << logLine << std::endl;
        logFile << logLine << std::endl;
    }
    ~Logger() {logFile.close();}
}

#endif /* logger_hpp */

