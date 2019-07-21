project('caja-my-computer', 'c',
  version: '0.2.0',
  meson_version: '>= 0.37.0',
  default_options : ['prefix=/usr'],
)

config_h = configuration_data()
config_h.set_quoted('VERSION', meson.project_version())
config_h.set_quoted('PACKAGE_NAME', meson.project_name())
config_h.set_quoted('PACKAGE_VERSION', meson.project_version())
config_h.set_quoted('GETTEXT_PACKAGE', meson.project_name())
config_h.set_quoted('GETTEXT_PACKAGE', meson.project_name())
config_h.set_quoted('LOCALEDIR', join_paths(get_option('prefix'), get_option('localedir')))
configure_file(
  output: 'config.h',
  configuration: config_h,
)

add_global_arguments([
  '-DHAVE_CONFIG_H',
  '-I' + meson.build_root(),
], language: 'c')

gnome = import('gnome')
i18n = import('i18n')

glib_req_version = '>= 2.32.0'
gio_dep = dependency('gio-2.0', version: glib_req_version)
gio_unix_dep = dependency('gio-unix-2.0', version: glib_req_version)

caja_ext_dep = dependency('libcaja-extension')
caja_ext_dir = caja_ext_dep.get_pkgconfig_variable('extensiondir')

subdir('po')
subdir('src')
