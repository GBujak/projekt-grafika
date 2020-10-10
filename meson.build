project('projekt grafika', 'cpp',
    version: '0.0.1',
    license: 'GPLv3')

allegro_dep = dependency('allegro-5')

incdir = include_directories('include')

subdir('src')

executable('projekt-grafika', src_files,
    include_directories: incdir,
    dependencies: allegro_dep
    )