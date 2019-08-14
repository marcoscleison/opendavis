project('opendavis', 'cpp')

sfml = dependency('sfml-graphics')
gl = dependency('gl')

incdir = include_directories('include')
src =[
    './src/main.cpp',
]

executable('opendavis', src, dependencies :[gl,sfml], cpp_args:['-std=c++1z'], include_directories : incdir)


