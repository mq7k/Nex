import argparse

class SynParser(argparse.ArgumentParser):
    def error(self, message):
        self.exit(2, f"{message}\n")

