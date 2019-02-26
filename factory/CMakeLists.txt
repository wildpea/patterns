# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.4)
# 项目信息
project (server)
set(TARGET factory)
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(${TARGET} ${DIR_SRCS})


target_compile_features(${TARGET} PRIVATE cxx_range_for)
