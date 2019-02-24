@echo off
nircmd.exe sendkeypress alt+tab
ping -n 1 localhost>Nul
nircmd.exe sendkeypress home
nircmd.exe sendkeypress shift+end
nircmd.exe sendkeypress ctrl+c
BufferTranslate.exe
nircmd.exe sendkeypress home
nircmd.exe sendkeypress shift+end
nircmd.exe sendkeypress ctrl+v