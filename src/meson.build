gnome.compile_schemas()

caja_my_computer_sources = [
  'caja-my-computer.c',
  'my-computer.c',
]

caja_my_computer_deps = [
  dependency('glib-2.0'),
  caja_ext_dep
]

shared_module('caja-my-computer', caja_my_computer_sources,
  dependencies: caja_my_computer_deps,
  install_dir : caja_ext_dir,
  install: true,
)

i18n.merge_file(
  input: 'libcaja-my-computer.desktop.in',
  output: 'libcaja-my-computer.caja-extension',
  type: 'desktop',
  args: ['--keyword=Name', '--keyword=Description'],
  po_dir: '../po',
  install: true,
  install_dir : join_paths(get_option('prefix'), get_option('datadir'), 'caja', 'extensions')
)

