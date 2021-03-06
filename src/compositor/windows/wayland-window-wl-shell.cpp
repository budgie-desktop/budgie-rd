/*
 * This file is part of budgie-rd
 *
 * Copyright © 2017-2018 Budgie Desktop Developers
 *
 * budgie-rd is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#include <QDebug>

#include "wayland-window-wl-shell.h"

using namespace Budgie::Compositor;

WaylandWindowWlShell::WaylandWindowWlShell(SurfaceItem *surface, QWaylandWlShellSurface *wl_shell)
    : WaylandWindow(surface), m_shell(wl_shell)
{
    // Ensure we know about titles and such.
    connect(m_shell,
            &QWaylandWlShellSurface::titleChanged,
            this,
            &WaylandWindowWlShell::wlTitleChanged);
    wlTitleChanged();
}

void WaylandWindowWlShell::wlTitleChanged()
{
    m_title = m_shell->title();
}

const QString &WaylandWindowWlShell::title()
{
    return m_title;
}

/*
 * Editor modelines  -  https://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=4 expandtab:
 * :indentSize=4:tabSize=4:noTabs=true:
 */
