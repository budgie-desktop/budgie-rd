compositor_mocs = qt5.preprocess(
    moc_headers: [
        'compositor-common.h',
        'compositor.h',
        'surface-item.h',
        'view.h',
        'window.h',
    ],
    include_directories: interface_include_directories,
)


compositor_sources = [
    'compositor.cpp',
    'main.cpp',
    'surface-item.cpp',
    'view.cpp',
    'window.cpp',
    compositor_mocs,
]

compositor_includes = [
    config_h_dir,
    include_directories('.'),
    interface_include_directories,
]

# Our main compositor is the execution environment
compositor = executable(
    'budgie-rd-compositor',
    install: true,
    sources: [
        compositor_sources,
    ],
    include_directories: compositor_includes,
    dependencies: [
        dep_qt_compositor,
        dep_qtcore,
        dep_qtwidgets,
    ],
)

# For now we only know OpenGL
subdir('renderers')
