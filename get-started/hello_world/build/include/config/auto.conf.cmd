deps_config := \
	D:/esp32/espidf/esp-idf/components/app_trace/Kconfig \
	D:/esp32/espidf/esp-idf/components/aws_iot/Kconfig \
	D:/esp32/espidf/esp-idf/components/bt/Kconfig \
	D:/esp32/espidf/esp-idf/components/driver/Kconfig \
	D:/esp32/espidf/esp-idf/components/efuse/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp32/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp_adc_cal/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp_event/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp_http_client/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp_http_server/Kconfig \
	D:/esp32/espidf/esp-idf/components/esp_https_ota/Kconfig \
	D:/esp32/espidf/esp-idf/components/espcoredump/Kconfig \
	D:/esp32/espidf/esp-idf/components/ethernet/Kconfig \
	D:/esp32/espidf/esp-idf/components/fatfs/Kconfig \
	D:/esp32/espidf/esp-idf/components/freemodbus/Kconfig \
	D:/esp32/espidf/esp-idf/components/freertos/Kconfig \
	D:/esp32/espidf/esp-idf/components/heap/Kconfig \
	D:/esp32/espidf/esp-idf/components/libsodium/Kconfig \
	D:/esp32/espidf/esp-idf/components/log/Kconfig \
	D:/esp32/espidf/esp-idf/components/lwip/Kconfig \
	D:/esp32/espidf/esp-idf/components/mbedtls/Kconfig \
	D:/esp32/espidf/esp-idf/components/mdns/Kconfig \
	D:/esp32/espidf/esp-idf/components/mqtt/Kconfig \
	D:/esp32/espidf/esp-idf/components/nvs_flash/Kconfig \
	D:/esp32/espidf/esp-idf/components/openssl/Kconfig \
	D:/esp32/espidf/esp-idf/components/pthread/Kconfig \
	D:/esp32/espidf/esp-idf/components/spi_flash/Kconfig \
	D:/esp32/espidf/esp-idf/components/spiffs/Kconfig \
	D:/esp32/espidf/esp-idf/components/tcpip_adapter/Kconfig \
	D:/esp32/espidf/esp-idf/components/unity/Kconfig \
	D:/esp32/espidf/esp-idf/components/vfs/Kconfig \
	D:/esp32/espidf/esp-idf/components/wear_levelling/Kconfig \
	D:/esp32/espidf/esp-idf/components/wifi_provisioning/Kconfig \
	D:/esp32/espidf/esp-idf/components/app_update/Kconfig.projbuild \
	D:/esp32/espidf/esp-idf/components/bootloader/Kconfig.projbuild \
	D:/esp32/espidf/esp-idf/components/esptool_py/Kconfig.projbuild \
	D:/esp32/espidf/esp-idf/components/partition_table/Kconfig.projbuild \
	/d/esp32/espidf/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_TARGET)" "esp32"
include/config/auto.conf: FORCE
endif
ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
