include ../commake/commake.mk
CC := g++
CFLAGS += -std=c++11

$(call c_compile_objs,value_list,value_list.cpp)

$(call link_target_exe,run,$(value_list_OBJS))

after_comma:
	$(run_OBJS)
