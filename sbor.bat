@echo off
call C:\Users\zalun\emsdk\emsdk_env.bat
emcc sepia.c -Os -s WASM=1 -s EXPORTED_FUNCTIONS='['sepia_filter', 'ccall', '_malloc']' -s EXPORTED_RUNTIME_METHODS='["free"]' -o sepia.js
pause

