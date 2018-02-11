import os
from setuptools import (
    setup,
    find_packages,
)


def read(fname):
    filename = os.path.join(os.path.dirname(__file__), fname)
    with open(filename, 'r') as f:
        return f.read()


PACKAGE='stratum_mining'
setup(
    name = PACKAGE,
    version = "1.0",
    author = "Drew Ditthardt",
    author_email = "drew.ditthardt@gmail.com",
    description = "Stratum Server Implementation",
    url = "https://github.com/DorianGray/stratum-mining",
    packages=find_packages(exclude=['test']),
    package_data={
        PACKAGE: ['*'],
    },
    include_package_data=True,
    long_description=read('README.md'),
)
