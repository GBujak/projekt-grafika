project('projekt grafika', 'cpp',
    version: '0.0.1',
    license: 'GPLv3',
    default_options: ['cpp_std=c++17'])

sdl2_dependency = dependency('sdl2')

incdir = include_directories('include')

subdir('src')

executable('projekt-grafika', src_files,
    include_directories: incdir,
    dependencies: [sdl2_dependency]
    )