# Permint

## Usage

This tool requires the libsodium repository to be installed. 

On Fedora this can be done with:
sudo dnf install libsodium

## Compilation

Compilation requires the libsodium developer repository.

On Fedora this can be done with:
sudo dnf install libsodium-devel

Then to compile, run:
g++ main.cpp -o build/permint -lsodium
