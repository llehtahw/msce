.PHONY: all
all: build
%.o: %.cpp
	g++ -fPIC -std=c++11 -c $< -o $@

%: %.o


define compile_ok
$(eval
TARGETS += $1
RUN_TARGETS += $1
$1: $2
	@echo Building $1
	@g++ -fPIC -std=c++11 $3 $$^ -o $$@ && echo "\tOK...OK"
)
endef

define compile_err
$(eval
TARGETS += $1
$1: $2
	@echo Building $1
	@g++ -fPIC -std=c++11 $3 $$^ -o $$@ 2>$1 || echo "\tERROR...OK"
)
endef

$(call compile_ok,v1h_v1c,v1.cpp,-DV1)
$(call compile_err,v2h_v1c,v1.cpp,-DV2)

$(call compile_ok,v1h_v2c,v2.cpp,-DV1)
$(call compile_ok,v2h_v2c,v2.cpp,-DV2)

$(call compile_ok,v1h_v3c,v3.cpp,-DV1)
$(call compile_ok,v2h_v3c,v3.cpp,-DV2)

$(call compile_ok,v1h_v4c,v4.cpp,-DV1)
$(call compile_ok,v2h_v4c,v4.cpp,-DV2)

.PHONY: run build clean


run: $(RUN_TARGETS)
	@$(foreach i,$(RUN_TARGETS),echo ./$i && ./$i && ) echo ok
clean:
	@rm -rf $(TARGETS)
build: $(TARGETS)
.DEFAULT_GOAL: build
