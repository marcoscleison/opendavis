project('opendavis', 'c', 'cpp',
        default_options : ['c_std=c11', 'cpp_std=c++17'])


incdir = include_directories(['include','src'])

sfml = dependency('sfml-graphics')



src=[
    'src/main.cpp',
    'src/ui/application.cpp',
]
executable('opendavis', src, dependencies : [sfml],include_directories : incdir)

