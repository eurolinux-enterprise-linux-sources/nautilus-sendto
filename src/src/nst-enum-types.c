
/* Generated data (by glib-mkenums) */

#include <nautilus-sendto-plugin.h>
#include "nst-enum-types.h"
#include <glib-object.h>

/* enumerations from "nautilus-sendto-plugin.h" */
GType
nst_plugin_capabilities_get_type (void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GFlagsValue values[] = {
      { NAUTILUS_CAPS_NONE, "NAUTILUS_CAPS_NONE", "none" },
      { NAUTILUS_CAPS_SEND_DIRECTORIES, "NAUTILUS_CAPS_SEND_DIRECTORIES", "send-directories" },
      { NAUTILUS_CAPS_SEND_IMAGES, "NAUTILUS_CAPS_SEND_IMAGES", "send-images" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("NstPluginCapabilities", values);
  }
  return etype;
}

/* Generated data ends here */

