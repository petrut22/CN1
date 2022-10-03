############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Tema1Intersection
set_top ci
add_files Tema1Intersection/controlIntersection.cpp
add_files -tb Tema1Intersection/controlIntersection_tb.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb Tema1Intersection/controlIntersection_tb.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7a100t-csg324-1}
create_clock -period 10 -name default
#source "./Tema1Intersection/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
