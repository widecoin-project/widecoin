
Debian
====================
This directory contains files used to package widecoind/widecoin-qt
for Debian-based Linux systems. If you compile widecoind/widecoin-qt yourself, there are some useful files here.

## widecoin: URI support ##


widecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install widecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your widecoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/widecoin128.png` to `/usr/share/pixmaps`

widecoin-qt.protocol (KDE)

