import os
import shutil

def unlink(path, *, raise_error_on_failure=False):
    if not os.path.exists(path) and not raise_error_on_failure:
        return

    if os.path.isdir(path) and not os.path.islink(path):
        shutil.rmtree(path)
    else:
        os.remove(path)

def create_symlink(target, link_name):
    unlink(link_name)
    os.symlink(src = target, dst = link_name)
