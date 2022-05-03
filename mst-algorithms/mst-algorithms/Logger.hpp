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
#include <sstream>

class Logger
{
    inline static const char* pathToLogFile;
    std::stringstream m_Stream;
    Logger() {}
    
    public:
        static void SetPathToLogFile(const char* _pathToLogFile)
        {
            pathToLogFile = _pathToLogFile;
        }
    
        static Logger& getInstance()
        {
            static Logger instance;
                                  
            return instance;
        }

        Logger(Logger const&) = delete;
        void operator=(Logger const&)  = delete;
    
        template <class T>
        Logger& operator<<(const T& thing) { m_Stream << thing; return *this; }
    
        ~Logger() {
            std::filebuf file;
            
            file.open(pathToLogFile, std::ios::out);
            std::ostream Out(&file);
            
            std::cout << m_Stream.rdbuf();
            m_Stream.seekg(0, std::ios::beg);
            Out << m_Stream.rdbuf();
            Out.flush();
            
            file.close();
        }
};

#endif /* logger_hpp */

