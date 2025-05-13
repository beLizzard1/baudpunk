#include <stdio.h>
#include "esp_log.h"
#include "baudpunk_config.h"

void baudpunk_print_banner(void) {
    printf("\n");
    printf("===========================================\n");
    printf("   🧃  baudpunk v%s\n", BAUDPUNK_VERSION);
    printf("   📡  Softmodem + USB Audio + CDC-NCM\n");
    printf("   📦  Built for ESP32-S3 (IDF %d)\n", ESP_IDF_VERSION_MAJOR);
    printf("===========================================\n\n");
}