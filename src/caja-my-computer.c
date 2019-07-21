/* vi: set sw=4 ts=4 wrap ai: */
/*
 * caja-my-computer.c: This file is part of ____
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
 #include <config.h> /* for GETTEXT_PACKAGE */
#endif

#include <libcaja-extension/caja-widget-view-provider.h>
#include <glib/gi18n-lib.h>
#include <gtk/gtk.h>

#include "caja-my-computer.h"

static void caja_my_computer_iface_init (CajaWidgetViewProviderIface *iface);

struct _CajaMyComputer {
	GObject parent;
    GtkWidget *widget;
};

G_DEFINE_DYNAMIC_TYPE_EXTENDED (CajaMyComputer, caja_my_computer, G_TYPE_OBJECT,
                                0,
                                G_IMPLEMENT_INTERFACE_DYNAMIC (CAJA_TYPE_WIDGET_VIEW_PROVIDER,
                                                       caja_my_computer_iface_init));

static void caja_my_computer_class_finalize (CajaMyComputerClass *klass)
{

}

static void
caja_my_computer_class_init (CajaMyComputerClass *class)
{
}

static void
caja_my_computer_init (CajaMyComputer *self)
{
}

GtkWidget *caja_my_computer_get_widget (CajaWidgetViewProvider *provider)
{
    CajaMyComputer *self;
    GtkWidget *view;
    GtkWidget *box;
    GtkWidget *widget = NULL;

    self = CAJA_MY_COMPUTER(provider);

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
    widget = gtk_label_new("这里将显示计算机的界面");
    gtk_box_pack_start(GTK_BOX(box), widget, TRUE, TRUE, 0);

    view = gtk_calendar_new ();
    gtk_box_pack_start(GTK_BOX(box), view, TRUE, TRUE, 0);
    gtk_widget_show_all(box);
    self->widget = box;
    return self->widget;
}


gboolean caja_my_computer_supports_uri (CajaWidgetViewProvider *provider,
                                        const char *uri,
                                        GFileType file_type,
                                        const char *mime_type)
{
	//if (g_str_has_prefix(uri, "computer://")) {
	if (g_str_has_prefix(uri, "file:///tmp")) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void caja_my_computer_add_file (CajaWidgetViewProvider *provider, CajaFile *file)
{
    printf("call here\n");
    CajaMyComputer *self;
    GtkWidget *label;

    self = CAJA_MY_COMPUTER(provider);

    label = gtk_label_new(caja_file_info_get_name(file));
    //label = gtk_label_new("a");
    gtk_widget_show(label);
    gtk_box_pack_start(GTK_BOX(self->widget), label, TRUE, TRUE, 0);
}

void caja_my_computer_set_uri (CajaWidgetViewProvider *provider, const char *uri)
{
}

void caja_my_computer_set_window (CajaWidgetViewProvider *provider, GtkWindow *window)
{
}

static void
caja_my_computer_iface_init (CajaWidgetViewProviderIface *iface)
{
	iface->get_widget = caja_my_computer_get_widget;
	iface->supports_uri = caja_my_computer_supports_uri;
	iface->add_file = caja_my_computer_add_file;
	iface->set_uri = caja_my_computer_set_uri;
	iface->set_window = caja_my_computer_set_window;
}

GType register_caja_my_computer_plugin (GTypeModule *type_module)
{
	caja_my_computer_register_type (type_module);
	return caja_my_computer_get_type ();
}
