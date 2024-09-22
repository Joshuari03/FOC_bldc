#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__

#define MW_MULTI_TASKING_MODE 1
#include "MW_ArduinoHWInit.h"

#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE ESP32-WROOM(Arduino Compatible)
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERSIZE 250
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_LOGGINGBUFFERNUM 3
#define MW_EXTMODEPROTOCOLINFO_XCPONSERIAL_MAXCONTIGSAMPLES 10
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_HOSTINTERFACE Simulink
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERAUTO 1
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERSIZE 250
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_LOGGINGBUFFERNUM 3
#define MW_EXTMODEPROTOCOLINFO_XCPONWIFI_MAXCONTIGSAMPLES 10
#define MW_CONNECTIONINFO_XCPONSERIAL_BAUDRATE codertarget.arduinobase.registry.getBaudRate
#define MW_CONNECTIONINFO_XCPONSERIAL_COMPORT codertarget.arduinobase.internal.getExternalModeMexArgs('Serial')
#define MW_CONNECTIONINFO_XCPONSERIAL_VERBOSE 0
#define MW_CONNECTIONINFO_XCPONWIFI_IPADDRESS codertarget.arduinobase.internal.getExternalModeMexArgs('Wifi')
#define MW_CONNECTIONINFO_XCPONWIFI_PORT 17725
#define MW_CONNECTIONINFO_XCPONWIFI_VERBOSE 0
#define MW_EXTMODE_CONFIGURATION XCP on Serial
#define MW_EXTMODE_COMPORTBAUD 921600
#define MW_EXTMODE_TARGETPOLLINGTIMEMODE 0
#define MW_EXTMODE_TARGETPOLLINGTIME 2
#define MW_EXTMODE_USEREALTIMESTAMPLOGGING 0
#define MW_EXTMODE_RUNNING on
#define MW_RTOS FreeRTOS
#define MW_RTOSBASERATETASKPRIORITY 14
#define MW_DETECTTASKOVERRUNS 0.000000
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_ESP32_ESP32_BOARD -1
#define MW_ESP32_BOOTBUTTONPRESSCHECKBOX 0
#define MW_RUNTIME_BUILDACTION 1
#define MW_RUNTIME_DISABLEPARALLELBUILD 0
#define MW_RUNTIME_FORCEBUILDSTATICLIBRARY 0
#define MW_RUNTIME_VERBOSEOUTPUT 0
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_PORT_SOURCE 2
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_COMPORT_SPECIFY 4
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_BAUD 0
#define MW_HOSTBOARDCONNECTION_APPDOWNLOAD_BAUD_SPECIFY 
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_SERIAL_PORT 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_PORT_SOURCE1 2
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_PORT_SOURCE2 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_COMPORT_SPECIFY 4
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_BAUD 0
#define MW_HOSTBOARDCONNECTION_CONNECTEDIO_BAUD_SPECIFY 
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_SERIAL_PORT 0
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_PORT_SOURCE1 2
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_PORT_SOURCE2 0
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_COMPORT_SELECT -1
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_COMPORT_SPECIFY 4
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_BAUD -1
#define MW_HOSTBOARDCONNECTION_EXTERNALMODE_BAUD_SPECIFY 
#define MW_CONNECTEDIO_CONNECTEDIOMODE 0
#define MW_CONNECTEDIO_ACTIONONOVERRUN 0
#define MW_OVERRUNDETECTION_ENABLE_OVERRUN_DETECTION 0
#define MW_OVERRUNDETECTION_DIGITAL_OUTPUT_TO_SET_ON_OVERRUN 13
#define MW_ANALOGINREFVOLTAGE_ANALOG_INPUT_REFERENCE_VOLTAGE 0.000000
#define MW_SERIAL_SERIAL0_BAUD_RATE 8
#define MW_SERIAL_SERIAL0_BAUD_SPECIFY 921600
#define MW_SERIAL_SERIAL0_CONFIG 3
#define MW_SERIAL_SERIAL0_TX_PIN 1
#define MW_SERIAL_SERIAL0_RX_PIN 3
#define MW_SERIAL_SERIAL1_BAUD_RATE 8
#define MW_SERIAL_SERIAL1_BAUD_SPECIFY 921600
#define MW_SERIAL_SERIAL1_CONFIG 3
#define MW_SERIAL_SERIAL1_TX_PIN 33
#define MW_SERIAL_SERIAL1_RX_PIN 32
#define MW_SERIAL_SERIAL2_BAUD_RATE 8
#define MW_SERIAL_SERIAL2_BAUD_SPECIFY 921600
#define MW_SERIAL_SERIAL2_CONFIG 3
#define MW_SERIAL_SERIAL2_TX_PIN 17
#define MW_SERIAL_SERIAL2_RX_PIN 16
#define MW_I2C_I2C0BUSSPEEDHZ 100000
#define MW_I2C_I2C0_SDA_PIN 21
#define MW_I2C_I2C0_SCL_PIN 22
#define MW_SPI_SPI0_CLOCK_OUT_FREQUENCY 1
#define MW_SPI_SPI0_MODE 0
#define MW_SPI_SPI0_BITORDER 0
#define MW_SPI_SPI0_SDO_PIN 23
#define MW_SPI_SPI0_SDI_PIN 19
#define MW_SPI_SPI0_SCK_PIN 18
#define MW_SPI_SDSLAVESELECT 5.000000
#define MW_SPI_SPI1_CLOCK_OUT_FREQUENCY 1
#define MW_SPI_SPI1_MODE 0
#define MW_SPI_SPI1_BITORDER 0
#define MW_SPI_SPI1_SDO_PIN 13
#define MW_SPI_SPI1_SDI_PIN 12
#define MW_SPI_SPI1_SCK_PIN 14
#define MW_WIFI_WIFI_SSID yourNetwork
#define MW_WIFI_SET_WIFI_ENCRYPTION 0
#define MW_WIFI_WIFI_WEP_KEY D0D0DEADF00DABBADEAFBEADED
#define MW_WIFI_WIFI_WEP_KEY_INDEX 0
#define MW_WIFI_WIFI_WPA_PASSWORD secretPassword
#define MW_WIFI_WIFI_WPA2_USERNAME username
#define MW_WIFI_WIFI_WPA2_PASSWORD password
#define MW_WIFI_IP_ADDRESS_ASSIGNMENT 0
#define MW_WIFI_WIFI_IP_ADDRESS 192.168.1.20
#define MW_WIFI_WIFI_DNS_SERVER_ADDRESS 192.168.1.0
#define MW_WIFI_WIFI_GATEWAY_ADDRESS 192.168.1.0
#define MW_WIFI_WIFI_SUBNET_MASK 255.255.255.0
#define MW_THINGSPEAK_ENABLE_CUSTOMSERVER 48
#define MW_THINGSPEAK_IP_ADDRESS 184.106.153.149
#define MW_THINGSPEAK_PORT 80
#define MW_PWM_PWM_DEFAULT_FREQUENCY 1000
#define MW_BLE_PERIPHERAL_DEVICE_NAME Arduino
#define MW_BLE_PERIPHERAL_LOCAL_NAME Arduino
#define MW_BLE_ADVERTISING_INTERVAL 160
#define MW_BLE_MIN_CONNECTION_INTERVAL 6
#define MW_BLE_MAX_CONNECTION_INTERVAL 3200
#define MW_MQTT_BROKERSERVICE 0
#define MW_MQTT_BROKERADDRESS mqtt3.thingspeak.com
#define MW_MQTT_BROKERPORT 1883
#define MW_MQTT_USERNAME 
#define MW_MQTT_PASSWORD 
#define MW_MQTT_CLIENTID 
#define MW_HTTP_ENABLE_CUSTOM_CA_CERTIFICATE 0
#define MW_HTTP_CUSTOM_CA_CERTIFICATE_FILE 
#define MW_IOBLOCKSMODE deployed
#define MW_DATAVERSION 2016.02
#define MW_DASHBOARDCODEGENINFO_ENABLECODEGEN 0
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.circularGauge
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_CIRCULARGAUGE_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.lcdTextDisplay
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_DISPLAYBLOCK_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_CODEGEN 1
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_BLOCKCLASS codertarget.targetHiddenBlkInsert.internal.pushButton
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_REGFCN codertarget.arduinobase.blocks.registerDashboardBlk
#define MW_DASHBOARDCODEGENINFO_PUSHBUTTON_VALIDATEFCN codertarget.targetHiddenBlkInsert.internal.isDashboardBlockCodegenEnabled

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
