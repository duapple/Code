
all: 
	@make -C cJSON
	# @make -C gsoap
	# @make -C onvif
	# @make -C openssl

.PHONY: clean gsoap_clean onvif_clean cJSON_clean 
clean:
	# -@make -C $(MOD_DIR)/gsoap clean
	# -@make -C $(MOD_DIR)/onvif clean 
	-@make -C $(MOD_DIR)/cJSON clean
	# -@make -C $(MOD_DIR)/openssl clean

# gsoap_clean:
# 	-@make -C $(MOD_DIR)/gsoap clean

# onvif_clean:
# 	-@make -C $(MOD_DIR)/gsoap clean

cJSON_clean:
	-@make -C $(MOD_DIR)/cJSON clean