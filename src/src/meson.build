executable('nautilus-sendto',
           'nautilus-sendto.c',
           include_directories: [config_inc],
           dependencies: [gio_dep],
           install_dir: nst_bindir,
           install: true)

po_dir = join_paths(meson.source_root(), 'po')

i18n.merge_file ('appdata',
                 input: 'nautilus-sendto.metainfo.xml.in',
                 output: 'nautilus-sendto.metainfo.xml',
                 install: true,
                 install_dir: join_paths(nst_datadir, 'appdata'),
                 po_dir: po_dir,)
