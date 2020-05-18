/*
 *   This file is part of Checkpoint
 *   Copyright (C) 2017-2019 Bernardo Giordano, FlagBrew
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
 *       * Requiring preservation of specified reasonable legal notices or
 *         author attributions in that material or in the Appropriate Legal
 *         Notices displayed by works containing it.
 *       * Prohibiting misrepresentation of the origin of that material,
 *         or requiring that modified versions of such material be marked in
 *         reasonable ways as different from the original version.
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdio.h>
#include <string>
#ifdef DEBUG
#include <switch.h>
#endif

class Logger
{
  public:
	static Logger& getInstance(void)
	{
		static Logger mLogger;
		return mLogger;
	}

	inline static const std::string INFO = "[INFO] ";
	inline static const std::string ERROR = "[ERROR] ";
	inline static const std::string WARN = "[WARN] ";

	void log(const std::string& level, const std::string& format = {});
	void flush(void);
	void cleanup(void);

  private:
	Logger(void)
	{
		buffer = "";

#ifdef DEBUG
		socketInitializeDefault();
		nxlinkStdio();
#endif
	}
	~Logger(void) {}

	Logger(Logger const&) = delete;
	void operator=(Logger const&) = delete;

	const std::string mPath = "gradius_sdl2.log";

	FILE* mFile;

	std::string buffer;
};

#endif