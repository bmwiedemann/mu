/*
** Copyright (C) 2023 Dirk-Jan C. Binnema <djcb@djcbsoftware.nl>
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of the GNU General Public License as published by the
** Free Software Foundation; either version 3, or (at your option) any
** later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software Foundation,
** Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
**
*/

#include "config.h"
#include "mu-cmd.hh"

using namespace Mu;

Result<void>
Mu::mu_cmd_remove(Mu::Store& store, const Options& opts)
{
	for (auto&& file: opts.remove.files) {
		const auto res = store.remove_message(file);
		if (!res)
			return Err(Error::Code::File, "failed to remove {}", file.c_str());
		else
			mu_debug("removed message @ {}", file);
	}

	return Ok();
}