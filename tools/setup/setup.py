#!/usr/bin/python

import subprocess
import os
import sys
import argparse

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
    # if not os.getcwd().endswith('setup'):
    #     os.chdir('tools/setup')
    file = f'packages/{path}'
    if not os.path.exists(file):
        print(f'File \'{file}\' not found')
        print('Did you execute the script from the correct location?')
        print('Try navigate to \'synapse/tools/setup\' and execute it again.')
        sys.exit(1)

    resolver.do_install(pm, file)

def check_versions(pm):
    pm.check_version(packages)

def main():
    if os.getuid() != 0:
        print('This script requires root privileges to install required packages.')
        sys.exit(1)

    install_packages()

if __name__ == '__main__':
    main()

