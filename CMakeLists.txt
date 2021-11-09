cmake_minimum_required(VERSION 3.0.0)

project(DesignPattern VERSION 0.1.0)

aux_source_directory(./proxy CPP_LIST2)
add_executable(project ${CPP_LIST2})