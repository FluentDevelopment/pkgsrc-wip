# $NetBSD: setup.py,v 1.1.1.1 2009/09/18 07:40:07 obache Exp $

import distutils
from distutils.core import setup, Extension

expatprefix = '@EXPATPREFIX@'
expatincl = expatprefix + '/include'
expatlib = expatprefix + '/lib'
expatrtprefix = '@EXPATPREFIX@'
expatrtlib = expatrtprefix + '/lib'

setup(
	ext_modules = [
		Extension(
			'_elementtree',
			['Modules/_elementtree.c'],
                        define_macros=[('USE_EXPAT', None)],
			include_dirs=[expatincl],
			library_dirs=[expatlib],
			runtime_library_dirs=[expatrtlib],
			libraries=['expat']
		)
	]
)
