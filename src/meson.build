project('nautilus-sendto', 'c',
        version: '3.8.6',
        default_options: [
          'buildtype=debugoptimized',
          'warning_level=1',
        ],
        meson_version : '>= 0.40.1',
        license: 'GPLv2.0+')

i18n = import('i18n')

# Requirements
gio_req     = '>= 2.25.9'

# Dependencies
gio_dep = dependency('gio-2.0', version : gio_req)

nautilus_sendto_deps = [gio_dep]

# directories
localedir = join_paths(get_option('prefix'), get_option('datadir'), 'locale')
nst_prefix = get_option('prefix')
nst_bindir = join_paths(nst_prefix, get_option('bindir'))
nst_datadir = join_paths(nst_prefix, get_option('datadir'))
nst_mandir = join_paths(nst_prefix, get_option('mandir'))

# Config.h
config_h = configuration_data()
config_h.set_quoted('GETTEXT_PACKAGE', meson.project_name())
config_h.set_quoted('PACKAGE_NAME', meson.project_name())
config_h.set_quoted('PACKAGE_VERSION', meson.project_version())
config_h.set_quoted('LOCALEDIR', localedir)

configure_file(
  output: 'config.h',
  configuration: config_h
)

config_inc = include_directories('.')

# project-wide cflags
add_project_arguments('-D_GNU_SOURCE', language: 'c')

# common warning flags
cc = meson.get_compiler('c')

# Compiler flags
if cc.get_id() == 'msvc'
  # Compiler options taken from msvc_recommended_pragmas.h
  # in GLib, based on _Win32_Programming_ by Rector and Newcomer
  test_cflags = [
    '-we4002', # too many actual parameters for macro
    '-we4003', # not enough actual parameters for macro
    '-w14010', # single-line comment contains line-continuation character
    '-we4013', # 'function' undefined; assuming extern returning int
    '-w14016', # no function return type; using int as default
    '-we4020', # too many actual parameters
    '-we4021', # too few actual parameters
    '-we4027', # function declared without formal parameter list
    '-we4029', # declared formal parameter list different from definition
    '-we4033', # 'function' must return a value
    '-we4035', # 'function' : no return value
    '-we4045', # array bounds overflow
    '-we4047', # different levels of indirection
    '-we4049', # terminating line number emission
    '-we4053', # an expression of type void was used as an operand
    '-we4071', # no function prototype given
    '-we4819', # the file contains a character that cannot be represented in the current code page
  ]
elif cc.get_id() == 'gcc' or cc.get_id() == 'clang'
  test_cflags = [
    '-fno-strict-aliasing',
    '-Wpointer-arith',
    '-Wmissing-declarations',
    '-Wimplicit-function-declaration',
    '-Wformat=2',
    '-Wformat-nonliteral',
    '-Wformat-security',
    '-Wstrict-prototypes',
    '-Wmissing-prototypes',
    '-Wnested-externs',
    '-Wold-style-definition',
    '-Wundef',
    '-Wunused',
    '-Wcast-align',
    '-Wmissing-noreturn',
    '-Wmissing-format-attribute',
    '-Wmissing-include-dirs',
    '-Wlogical-op',
    '-Wno-uninitialized',
    '-Wno-shadow',
    '-Wno-int-conversion',
    '-Wno-discarded-qualifiers',
    '-Werror=redundant-decls',
    '-Werror=implicit',
    '-Werror=nonnull',
    '-Werror=init-self',
    '-Werror=main',
    '-Werror=missing-braces',
    '-Werror=sequence-point',
    '-Werror=return-type',
    '-Werror=trigraphs',
    '-Werror=array-bounds',
    '-Werror=write-strings',
    '-Werror=address',
    '-Werror=int-to-pointer-cast',
    '-Werror=pointer-to-int-cast',
    '-Werror=empty-body',
    '-Werror=write-strings',
  ]
else
  test_cflags = []
endif

extra_warning_cflags = []
foreach cflag: test_cflags
  if cc.has_argument(cflag)
    extra_warning_cflags += [ cflag ]
  endif
endforeach

# man page

install_data(
  'nautilus-sendto.1',
  install_dir: join_paths(nst_mandir, 'man1')
)

# subdirs

subdir('src')
subdir('po')

# config.h
configure_file(output: 'config.h', configuration: config_h)
