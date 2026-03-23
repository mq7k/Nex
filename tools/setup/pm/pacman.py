import subprocess

class Pacman:
    @staticmethod
    def install(package):
        cmd = f'pacman -S {package}'
        return subprocess.run(cmd, shell=True)

    @staticmethod
    def check_version(package):
        pass

