from setuptools import find_packages
from setuptools import setup

setup(
    name='capture_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('capture_msgs', 'capture_msgs.*')),
)
