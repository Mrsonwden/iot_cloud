#include "mqtt_topic.h"


static const char *TAG = "MQTT_TOPIC";
// char device_type[2][10] = 
// {
//     "actor",
//     "sensor"
// };


char ucas_base_sub_topic[MAX_SUB_TOPIC][MAX_BASE_TOPIC_LEN]=
{
    "sub/actor/set",
    "sub/actor/get",
    "sub/sensor/get"
} ;

char ucas_base_pub_topic[MAX_PUB_TOPIC][MAX_BASE_TOPIC_LEN]=
{
    "pub/actor/status",
    "pub/sensor/status"
} ;

char my_device_type[MAX_TYPE_ID_PSWD_LEN] = "runner";
char my_device_id[MAX_TYPE_ID_PSWD_LEN]   = "ucas";
char my_device_pswd[MAX_TYPE_ID_PSWD_LEN] = "ucas";


//topic 基本格式： client_type/client_id/client_password/base_topic

char ucas_mqtt_sub(esp_mqtt_client_handle_t client, const char base_sub_topic[][MAX_BASE_TOPIC_LEN], int topic_num ,int qos)
{
     int i = 0;
     char topic[MAX_TOPIC_LEN];
     memset(topic,0,sizeof(topic));
     strcat(topic,my_device_type);
     strcat(topic,"/"); 
     strcat(topic,my_device_id);
     strcat(topic,"/"); 
     strcat(topic,my_device_pswd);
     strcat(topic,"/"); 
     char temp_topic[MAX_TOPIC_LEN];
     char temp[MAX_BASE_TOPIC_LEN];
     ESP_LOGI(TAG, "topic_num  %d",topic_num);
     for(i = 0;i < topic_num; i++)
     {

         memset(temp,0,sizeof(temp));
         strncpy(temp,base_sub_topic[i],MAX_BASE_TOPIC_LEN);
         ESP_LOGI(TAG, "temp %s  ",temp);
         if(0 == strlen(temp))
         {
             ESP_LOGI(TAG, "sub topic  finished i: %d",i);
             break;
         }

         memset(temp_topic,0,sizeof(temp_topic));
         strcpy(temp_topic,topic);
         strcat(temp_topic,temp);
         ESP_LOGI(TAG, "sub topic: %s",temp_topic);

         if(-1 == esp_mqtt_client_subscribe(client, temp_topic, qos))
         {
            ESP_LOGI(TAG, "sent subscribe %s failed",temp_topic);
         }
         else
         {
             ESP_LOGI(TAG, "sent subscribe  %s successed",temp_topic);
         };
         
     } 
     return 0;        
}

// /**
//  * @brief Client to send a publish message to the broker
//  *
//  * Notes:
//  * - Client doesn't have to be connected to send publish message
//  *   (although it would drop all qos=0 messages, qos>1 messages would be enqueued)
//  * - It is thread safe, please refer to `esp_mqtt_client_subscribe` for details
//  *
//  * @param client    mqtt client handle
//  * @param topic     topic string
//  * @param data      payload string (set to NULL, sending empty payload message)
//  * @param len       data length, if set to 0, length is calculated from payload string
//  * @param qos       qos of publish message
//  * @param retain    retain flag
//  *
//  * @return message_id of the publish message (for QoS 0 message_id will always be zero) on success.
//  *         -1 on failure.
//  */
// int esp_mqtt_client_publish(esp_mqtt_client_handle_t client, const char *topic, const char *data, int len, int qos, int retain);


char ucas_mqtt_pub(esp_mqtt_client_handle_t client, const char base_pub_topic[], char* payload ,int payload_len,int qos)
{
     int i = 0;
     char topic[MAX_TOPIC_LEN];
     memset(topic,0,sizeof(topic));
     strcat(topic,my_device_type);
     strcat(topic,"/"); 
     strcat(topic,my_device_id);
     strcat(topic,"/"); 
     strcat(topic,my_device_pswd);
     strcat(topic,"/"); 
     strcat(topic,base_pub_topic);
     ESP_LOGI(TAG, "pub topic  %s",topic);


    if(-1 == esp_mqtt_client_publish(client,topic, payload, payload_len, qos, 0))
    {
       ESP_LOGI(TAG, "sent  pub  %s failed",topic);
       return -1;
    }
    else
    {
        ESP_LOGI(TAG, "sent pub  %s successed",topic);
    }
         
     return 0;        
}