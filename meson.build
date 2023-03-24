#
# Copyright (C) 2020, 2023  T+A elektroakustik GmbH & Co. KG
#
# This file is part of OffEvent.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA  02110-1301, USA.
#

project('OffEvent', 'c',
    version: '1.3',
    default_options: ['warning_level=3', 'buildtype=plain'])

PACKAGE = 'offevent'

config_data = configuration_data()
config_data.set_quoted('PACKAGE', PACKAGE)
config_data.set_quoted('PACKAGE_NAME', meson.project_name())
config_data.set_quoted('PACKAGE_STRING', meson.project_name() + ' ' + meson.project_version())
config_data.set_quoted('PACKAGE_VERSION', meson.project_version())
config_data.set('abs_srcdir', meson.current_source_dir())
config_data.set('abs_builddir', meson.build_root())
config_data.set('bindir', get_option('prefix') / get_option('bindir'))

add_project_arguments('-DHAVE_CONFIG_H', language: 'c')

config_h = declare_dependency(
    sources: configure_file(input: 'config.h.meson',
                            output: 'config.h',
                            configuration: config_data),
    include_directories: '.'
)

executable('offevent', 'offevent.c', dependencies: config_h, install: true)

markdown = find_program('markdown')

custom_target('documentation',
    output: 'README.html', input: 'README.md',
    command: [markdown, '-o', '@OUTPUT@', '@INPUT@'],
    install: true, install_dir: get_option('datadir') / 'doc' / PACKAGE
)
