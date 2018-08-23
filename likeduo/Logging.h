#ifndef MUDUO_BASE_LOGGING_H
#define MUDUO_BASE_LOGGING_H
#include <iostream>
namespace muduo
{

#define LOG_TRACE std::cout
#define LOG_DEBUG std::cout
#define LOG_INFO std::cout
#define LOG_WARN std::cout
#define LOG_ERROR std::cout
#define LOG_FATAL std::cout
#define LOG_SYSERR std::cout
#define LOG_SYSFATAL std::cout

}

#endif  // MUDUO_BASE_LOGGING_H
