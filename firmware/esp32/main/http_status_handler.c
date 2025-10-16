#include "http_status_handler.h"

#include "esp_log.h"
#include "esp_http_server.h"
#include "cJSON.h"

static const char *TAG = "http_status";

static esp_err_t status_get_handler(httpd_req_t *req)
{
    cJSON *root = cJSON_CreateObject();
    cJSON_AddStringToObject(root, "status", "placeholder");
    cJSON *nodes = cJSON_AddArrayToObject(root, "nodes");
    cJSON_AddItemToArray(nodes, cJSON_CreateString("master_esp"));
    cJSON_AddItemToArray(nodes, cJSON_CreateString("arduino"));

    char *json = cJSON_PrintUnformatted(root);
    httpd_resp_set_type(req, "application/json");
    httpd_resp_send(req, json, strlen(json));

    cJSON_free(json);
    cJSON_Delete(root);
    return ESP_OK;
}

void http_status_register(httpd_handle_t server)
{
    httpd_uri_t uri = {
        .uri = "/status",
        .method = HTTP_GET,
        .handler = status_get_handler,
        .user_ctx = NULL,
    };
    if (httpd_register_uri_handler(server, &uri) != ESP_OK) {
        ESP_LOGE(TAG, "Failed to register /status handler");
    }
}
