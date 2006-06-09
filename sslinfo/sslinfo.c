/*
 * sslinfo - Gets info about your currently loaded ssl plugin
 * Copyright (C) 2004 Gary Kramlich <amc_grim@users.sf.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#if HAVE_CONFIG_H
# include "../gpp_config.h"
#endif /* HAVE_CONFIG_H */

#define GAIM_PLUGINS

#include <glib.h>
#include <string.h>

#include <notify.h>
#include <plugin.h>
#include <version.h>

#include "../common/i18n.h"

static GaimPlugin *my_plugin = NULL;

static GaimPlugin *
sslinfo_find_ssl_plugin() {
	GaimPlugin *plugin, *ssl_plugin = NULL;
	GList *l;

	for(l = gaim_plugins_get_all(); l; l = l->next) {
		plugin = (GaimPlugin *)l->data;

		if(plugin == my_plugin)
			continue;

		if(plugin->info && plugin->info->id &&
		   !strncmp(plugin->info->id, "ssl-", 4))
		{
			if(gaim_plugin_is_loaded(plugin) || gaim_plugin_load(plugin)) {
				ssl_plugin = plugin;
				break;
			}
		}
	}

	return ssl_plugin;
}

static void
sslinfo_show(GaimPluginAction *action) {
	GaimPlugin *ssl_plugin = NULL;
	GString *text = NULL;
	gchar *escaped = NULL;

	text = g_string_new("");

	ssl_plugin = sslinfo_find_ssl_plugin();
	if(ssl_plugin && ssl_plugin->info) {
		if(ssl_plugin->info->name) {
			escaped = g_markup_escape_text(ssl_plugin->info->name,
										   strlen(ssl_plugin->info->name));
			g_string_append_printf(text, _("<b>Name:</b> %s<br>"), escaped);
			g_free(escaped);
		}

		if(ssl_plugin->info->version) {
			escaped = g_markup_escape_text(ssl_plugin->info->version,
										   strlen(ssl_plugin->info->version));
			g_string_append_printf(text, _("<b>Version:</b> %s<br>"), escaped);
			g_free(escaped);
		}

		if(ssl_plugin->info->author) {
			escaped = g_markup_escape_text(ssl_plugin->info->author,
										   strlen(ssl_plugin->info->author));
			g_string_append_printf(text, _("<b>Author:</b> %s<br>"), escaped);
			g_free(escaped);
		}
	}

	gaim_notify_formatted(action->plugin, _("SSL Info"), _("SSL Info"), NULL,
						  text->str, NULL, NULL);

	g_string_free(text, TRUE);
}

static GList *
sslinfo_actions(GaimPlugin *plugin, gpointer context) {
	GList *l = NULL;
	GaimPluginAction *act = NULL;

	act = gaim_plugin_action_new(_("Get SSL info"), sslinfo_show);
	l = g_list_append(l, act);

	return l;
}

static GaimPluginInfo info = {
	GAIM_PLUGIN_MAGIC,
	GAIM_MAJOR_VERSION,
	GAIM_MINOR_VERSION,
	GAIM_PLUGIN_STANDARD,
	NULL,
	0,
	NULL,
	GAIM_PRIORITY_DEFAULT,

	"core-plugin_pack-sslinfo",
	NULL,
	GPP_VERSION,
	NULL,
	NULL,
	"Gary Kramlich <amc_grim@users.sf.net>",
	GPP_WEBSITE,

	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	sslinfo_actions
};

static void
init_plugin(GaimPlugin *plugin) {
#ifdef ENABLE_NLS
	bindtextdomain(GPP_PACKAGE, LOCALEDIR);
	bind_textdomain_codeset(GPP_PACKAGE, "UTF-8");
#endif /* ENABLE_NLS */

	info.name = _("SSL Info");
	info.summary = _("Displays info about your currently loaded SSL plugin");
	info.description = _("Displays info about your currently loaded SSL plugin.");

	my_plugin = plugin;
}

GAIM_INIT_PLUGIN(sslinfo, init_plugin, info)