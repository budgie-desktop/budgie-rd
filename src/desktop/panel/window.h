/*
 * This file is part of budgie-rd
 *
 * Copyright © 2017 Budgie Desktop Developers
 *
 * budgie-rd is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 */

#pragma once

#include "../taskmon/task-monitor.h"

#include <QQuickView>

namespace Panel
{
    class Window : public QQuickView
    {
        Q_OBJECT
        Q_ENUMS(Position)

    public:
        enum Position {
            Undetermined,
            Top,
            Left,
            Right,
            Bottom,
        };

        explicit Window(QQmlEngine *engine);
        void updateGeometry(QRect &rect, Position p = Position::Bottom);

    private:
        int intendedSize;
        QScopedPointer<Task::Monitor> monitor;
        void demoCode();

    private slots:
        void windowOpened(Task::Window *window);
        void windowClosed(Task::Window *window);
    };
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