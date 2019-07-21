/* vi: set sw=4 ts=4 wrap ai: */
/*
 * my-computer.c: This file is part of ____
 *
 * Copyright (C) 2019 yetist <yetist@yetipc>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "caja-my-computer.h"
#include <libintl.h>

void caja_module_initialize (GTypeModule *module)
{
	g_print ("Initializing caja-my-computer extension\n");

	//caja_my_computer_register_type (module);
	register_caja_my_computer_plugin (module);

	bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
}

void caja_module_shutdown (void)
{
	g_print ("Shutting down caja-my-computer extension\n");
}

void caja_module_list_types (const GType **types, int *num_types)
{
	static GType type_list[1];
	type_list[0] = CAJA_TYPE_MY_COMPUTER;

	*types = type_list;
	*num_types = G_N_ELEMENTS (type_list);
}
