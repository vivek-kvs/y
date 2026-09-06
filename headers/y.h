#pragma once

#include <string>

// Global error flag
extern bool hadError;

// Function declarations
void runFile(const std::string& path);

void runPrompt();

void run(const std::string& source);

void error(int line, const std::string& message);

void report(int line, const std::string& where, const std::string& message);