#ifndef MQTT_TOPIC_H__
#define MQTT_TOPIC_H__

#include "mqtt_client.h"
#include "esp_log.h"
#include "string.h"


#define MAX_BASE_TOPIC_LEN                  (30)
#define MAX_TOPIC_LEN                       (MAX_BASE_TOPIC_LEN + 30)  
#define MAX_SUB_TOPIC                       (10)
#define MAX_PUB_TOPIC                       (10)
#define MAX_TYPE_ID_PSWD_LEN                (10)

typedef enum {
MQTT_QUALITY_0,
MQTT_QUALITY_1,
MQTT_QUALITY_2
} MQTT_QUALITY;


extern char ucas_base_sub_topic[MAX_SUB_TOPIC][MAX_BASE_TOPIC_LEN];
extern char ucas_base_pub_topic[MAX_PUB_TOPIC][MAX_BASE_TOPIC_LEN];
extern char my_device_type[MAX_TYPE_ID_PSWD_LEN];
extern char my_device_id[MAX_TYPE_ID_PSWD_LEN];
extern char my_device_pswd[MAX_TYPE_ID_PSWD_LEN];
/*
 * function:统一订阅主题：
 * author  :snowden;
 * modify_date    :2019/11/29；
 */
char ucas_mqtt_sub(esp_mqtt_client_handle_t client, const char base_sub_topic[][MAX_BASE_TOPIC_LEN], int topic_num ,int qos);

/*
 * function:发布主题：
 * author  :snowden;
 * modify_date    :2019/11/30；
 */
char ucas_mqtt_pub(esp_mqtt_client_handle_t client, const char base_pub_topic[], char* payload ,int payload_len,int qos);
#endif

            // static long long test_timer = 0;
            // if(platform_tick_get_ms() - test_timer > 1000)
            // {
      
            // }
            // test_timer = platform_tick_get_ms();


