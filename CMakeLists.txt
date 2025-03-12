cmake_minimum_required(VERSION 3.10)

# Configuración del proyecto
project(Calculadora VERSION 1.0 LANGUAGES CXX)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir la carpeta de código fuente
set(SOURCE_DIR src)

# Agregar el ejecutable, asegurando que solo se cree dentro de build/
add_executable(calculadora ${SOURCE_DIR}/main.cpp)
