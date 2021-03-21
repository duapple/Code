
all: 
	@make -C $(MOD_DIR)
	@make -C $(APP_DIR)
	@echo "------------------------------"
	@echo "make all done."
	@echo "------------------------------"
	

.PHONY: clean gsoap_clean onvif_clean cJSON_clean clean_all

clean_all: clean
	-@rm -rf $(BUILD_DIR)

clean:
	-@make -C $(APP_DIR) clean
	-@make -C $(MOD_DIR) clean
	@echo "------------------------------"
	@echo "clean all doen."
	@echo "------------------------------"

gsoap_clean:
	-@make -C $(MOD_DIR) gsoap_clean

onvif_clean:
	-@make -C $(MOD_DIR) onvif_clean

cJSON_clean:
	-@make -C $(MOD_DIR) cJSON_clean