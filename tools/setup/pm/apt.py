import subprocess

class AptGet:
    @staticmethod
    def install(package):
        cmd = f'apt-get install -y {package}'
        return subprocess.run(cmd, shell=True)

    @staticmethod
    def check_version(package):
        pass

