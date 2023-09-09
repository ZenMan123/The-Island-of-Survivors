if not defined in_subprocess (cmd /k set in_subprocess=y ^& %0 %*) & exit

cmake CMakeLists.txt -G Ninja -B build

if %errorlevel% == 0 (
    cd ./build
    ninja
)

if %errorlevel% == 0 (
    The-Island-of-Survivors.exe
    exit
)
