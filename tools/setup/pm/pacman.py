import subprocess

class Pacman:
    @staticmethod
    def install(package):
        cmd = f'pacman -S --noconfirm {package}'
        return subprocess.run(cmd, shell=True)

    @staticmethod
    def check_version(package):
        pass

