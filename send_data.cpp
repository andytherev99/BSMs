#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include "BSM/bsm.h"
#include "iothub_client.h"
#include "iothub_transport_mqtt.h"

using namespace std;

// Define la cadena de conexión y el nombre del dispositivo
static const char* connectionString = "[Your IoT Hub device connection string]";
static const char* deviceId = "[Your IoT Hub device name]";

// Función que se llama cuando se recibe una confirmación de envío de IoT Hub
static void SendConfirmationCallback(IOTHUB_CLIENT_CONFIRMATION_RESULT result, void* userContextCallback)
{
    cout << "Confirmation received for message with result " << result << endl;
}

int main()
{
    // Crea el objeto BSM
    BSM bsm;

    // Crea el objeto IoT Hub Client
    IOTHUB_CLIENT_HANDLE iotHubClientHandle;
    iotHubClientHandle = IoTHubClient_CreateFromConnectionString(connectionString, MQTT_Protocol);

    // Configura la devolución de llamada para las confirmaciones de envío de IoT Hub
    IoTHubClient_SetMessageCallback(iotHubClientHandle, SendConfirmationCallback, NULL);

    // Bucle infinito para enviar datos a IoT Hub
    while (true)
    {
        // Genera un mensaje aleatorio y lo convierte en una cadena JSON
        char messagePayload[256];
        sprintf(messagePayload, "{\"speed\": %d, \"latitude\": %f, \"longitude\": %f}", rand() % 100, bsm.getLatitude(), bsm.getLongitude());

        // Crea el objeto mensaje de IoT Hub y lo envía
        IOTHUB_MESSAGE_HANDLE messageHandle = IoTHubMessage_CreateFromByteArray((const unsigned char*)messagePayload, strlen(messagePayload));
        IoTHubClient_SendEventAsync(iotHubClientHandle, messageHandle, NULL, NULL);

        // Espera un segundo antes de enviar el siguiente mensaje
        sleep(1);
    }

    // Libera la memoria utilizada por el objeto IoT Hub Client
    IoTHubClient_Destroy(iotHubClientHandle);

    return 0;
}

