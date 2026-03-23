#!/usr/bin/python

import os
import sys

from pm.apt import AptGet
from pm.pacman import Pacman
import resolver

def get_package_manager():
    # Arch-based
    if os.path.exists('/usr/bin/pacman'):
        return (Pacman, 'pacman.json')

    # Debian-based
    if os.path.exists('/usr/bin/apt'):
        return (AptGet, 'apt.json')

    # Red Hat-based
    # if os.path.exists('/usr/bin/yum'):
    #     return Yum()

    # Red Hat-based, successor of yum
    # if os.path.exists('/usr/bin/dnf'):
    #     return Dnf()

    # openSUSE
    # if os.path.exists('/usr/bin/zypper'):
    #     return Zypper()

    # Gentoo
    # if os.path.exists('/usr/bin/portage'):
    #     return Portage() 

    print('Unrecognized package manager')
    sys.exit(1)
    # ...

def install_packages():
    pm, path = get_package_manager()

    file = f'packages/{path}'

    # We navigate to the script directory if we currently
    # are on the project root.
    if not os.path.exists(file) and os.path.exists('tools/setup'):
        os.chdir('tools/setup')

    # If the file is still not found,
    # it means the script was executed from outside
    # the project directory.
    if not os.path.exists(file):
        print(f'File \'{file}\' not found')
        print(f'Please, execute the script from either the project root or the script directory.')
        sys.exit(1)

    resolver.do_install(pm, file)

def main():
    install_packages()

if __name__ == '__main__':
    main()

