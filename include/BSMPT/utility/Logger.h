// Copyright (C) 2020  Philipp Basler, Margarete Mühlleitner and Jonas Müller
// SPDX-FileCopyrightText: 2021 Philipp Basler, Margarete Mühlleitner and Jonas
// Müller
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include <fstream>
#include <iostream>
#include <map>

/**
 * @file
 */
namespace BSMPT
{
class Logger;

enum class LoggingLevel
{
  None,
  Default,
  MinimizerDetailed,
  ProgDetailed,
  EWBGDetailed,
  Debug
};

class BSMPTLogger
{
public:
  friend Logger;
  BSMPTLogger(std::ostream &os) : mOstream{os.rdbuf()} {}

private:
  BSMPTLogger(const BSMPTLogger &) = default;
  BSMPTLogger(BSMPTLogger &&)      = default;
  BSMPTLogger &operator=(const BSMPTLogger &) = default;
  BSMPTLogger &operator=(BSMPTLogger &&) = default;

  void SetOStream(std::ostream &Ostream);
  void SetOStream(const std::string &file);
  template <typename T> void Write(LoggingLevel level, const T &toWrite)
  {
    auto pos = mCurrentSetup.find(level);
    if (pos != mCurrentSetup.end() and pos->second)
    {
      mOstream << toWrite << std::endl;
    }
  }
  void SetLevel(const std::map<LoggingLevel, bool> &level);
  void Disable();

  std::ostream mOstream;
  std::ofstream mfilestream;

  std::map<LoggingLevel, bool> mCurrentSetup{
      {LoggingLevel::Default, true},
      {LoggingLevel::EWBGDetailed, false},
      {LoggingLevel::ProgDetailed, false},
      {LoggingLevel::ProgDetailed, false},
      {LoggingLevel::Debug, false}};
};

class Logger
{
public:
  Logger(const Logger &) = delete;
  Logger(Logger &&)      = delete;
  Logger &operator=(const Logger &) = delete;
  Logger &operator=(Logger &&) = delete;

  static void SetLevel(const std::map<LoggingLevel, bool> &Setup)
  {
    Instance().SetLevel(Setup);
  }

  static void SetOStream(std::ostream &Ostream)
  {
    Instance().SetOStream(Ostream);
  }
  static void SetOStream(const std::string &file)
  {
    Instance().SetOStream(file);
  }
  template <typename T> static void Write(LoggingLevel level, const T &toWrite)
  {
    Instance().Write(level, toWrite);
  }

  static void Disable() { Instance().Disable(); }

private:
  static BSMPTLogger &Instance()
  {
    static BSMPTLogger LoggerInstance(std::cout);
    return LoggerInstance;
  }
};

} // namespace BSMPT
